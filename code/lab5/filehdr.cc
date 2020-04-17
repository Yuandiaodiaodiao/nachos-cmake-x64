// filehdr.cc
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector,
//
//      Unlike in a real system, we do not keep track of file permissions,
//	ownership, last modification date, etc., in the file header.
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "filehdr.h"
#include "system.h"

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------

FileHeader::FileHeader() {
    numBytes = 0;
    numSectors = 0;
    for ( int i = 0; i < NumDirect; i++ ) {
        dataSectors[ i ] = 0;
    }
}

bool FileHeader::Allocate( BitMap *freeMap, int fileSize ) {
    numBytes = fileSize;
    numSectors = divRoundUp( fileSize, SectorSize );
    if ( freeMap->NumClear() < numSectors ) return FALSE; // not enough space

    for ( int i = 0; i < numSectors; i++ )
        dataSectors[ i ] = freeMap->Find();
    return TRUE;
}

bool FileHeader::Allocate( BitMap *freeMap, int filesize, int incrementBytes ) {
    if ( numSectors > 30 ) {//单文件扇区限制
        return 0;
    }
    bool newFile = false;
    if ( filesize == 0 && incrementBytes > 0 ) //新文件
    {
        if ( freeMap->NumClear() < 1 ) {//查看有无空闲扇区
            return 0;
        }
        dataSectors[ 0 ] = freeMap->Find();//分配1扇区给数据区
        numSectors = 1;
        numBytes = 0;
        newFile = true;
    }

    numBytes = filesize;

    int newsectorBytes;
    if ( newFile ) {
        //新建文件 已有0号扇区分配
        newsectorBytes = incrementBytes - SectorSize;
    } else {
        int offset = numBytes % SectorSize;
        newsectorBytes = offset == 0 ? incrementBytes : incrementBytes - ( SectorSize - offset ); //总增量-最后扇区的可用空间
    }
    //最后扇区的占用大小
    //需要在新扇区放置的bit
    if ( newsectorBytes <= 0 ) {
        numBytes = numBytes + incrementBytes;
        return 1;
    } // last sector can fit 填充最后的sector

    int moreSectors = divRoundUp( newsectorBytes, SectorSize ); //新增扇区数量
    if ( numSectors + moreSectors > 30 )                        //文件大小溢出
    {
        return 0;
    }
    if ( freeMap->NumClear() < moreSectors ) //余额不足
        return 0;

    for ( int i = numSectors; i < numSectors + moreSectors; i++ )
        dataSectors[ i ] = freeMap->Find(); //找空余sector占用

    numBytes = numBytes + incrementBytes;  //更新文件大小
    numSectors = numSectors + moreSectors; //更新扇区大小
    return 1;
}

//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

void FileHeader::Deallocate( BitMap *freeMap ) {
    for ( int i = 0; i < numSectors; i++ ) {
        ASSERT( freeMap->Test( (int) dataSectors[ i ] ) ); // ought to be marked!
        freeMap->Clear( (int) dataSectors[ i ] );
    }
}

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk.
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void FileHeader::FetchFrom( int sector ) { synchDisk->ReadSector( sector, (char *) this ); }

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk.
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void FileHeader::WriteBack( int sector ) { synchDisk->WriteSector( sector, (char *) this ); }

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int FileHeader::ByteToSector( int offset ) { return ( dataSectors[ offset / SectorSize ] ); }

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int FileHeader::FileLength() { return numBytes; }

//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void FileHeader::Print() {
    int   i, j, k;
    char *data = new char[ SectorSize ];

    printf( "FileHeader contents.  File size: %d.  File blocks:\n", numBytes );
    for ( i = 0; i < numSectors; i++ )
        printf( "%d ", dataSectors[ i ] );
    printf( "\nFile contents:\n" );
    for ( i = k = 0; i < numSectors; i++ ) {
        synchDisk->ReadSector( dataSectors[ i ], data );
        for ( j = 0; ( j < SectorSize ) && ( k < numBytes ); j++, k++ ) {
            if ( '\040' <= data[ j ] && data[ j ] <= '\176' ) // isprint(data[j])
                printf( "%c", data[ j ] );
            else
                printf( "\\%x", (unsigned char) data[ j ] );
        }
        printf( "\n" );
    }
    delete[] data;
}
