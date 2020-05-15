// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "syscall.h"
#include "system.h"
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions
//	are in machine.h.
//----------------------------------------------------------------------
AddrSpace *userSpace = nullptr;
Thread *   userThread = nullptr;

void StartProcess( int a ) {

    currentThread->space = userSpace;
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState();
    machine->Run();
}

void ExceptionHandler( ExceptionType which ) {
    int type = machine->ReadRegister( 2 );
    if ( which == SyscallException ) {
        if ( type == SC_Halt ) {
            DEBUG( 'a', "Shutdown, initiated by user program.\n" );
            interrupt->Halt();
        } else if ( type == SC_Exec ) {

            int  arg1_address = machine->ReadRegister( 4 ); // arg1
            char temp[ 100 ] = {1};
            for ( int i = 0; temp[ (i-1)>0?(i-1):0 ] != '\0'; i++ ) {
                machine->ReadMem( arg1_address + i, 1, (int *) &temp[ i ] );
            }
            printf( "Exec %s \n", temp );

            OpenFile *executable = fileSystem->Open( temp );
            userSpace = new AddrSpace( executable ); //分配内存空间
            delete executable;
            userThread = new Thread( "fork" );
            userThread->Fork( (VoidFunctionPtr) StartProcess, 1 );

            currentThread->Yield();
            machine->WriteRegister( 2, userSpace->pid );
            machine->WriteRegister( PCReg, machine->ReadRegister( PCReg ) + 4 );
            machine->WriteRegister( NextPCReg, machine->ReadRegister( NextPCReg ) + 4 );

        } else if ( type == SC_Exit ) {
            printf("EXIT!!! \n");
             currentThread->Finish();
            machine->WriteRegister( PCReg, machine->ReadRegister( PCReg ) + 4 );
            machine->WriteRegister( NextPCReg, machine->ReadRegister( NextPCReg ) + 4 );
        }

    } else {
        printf( "Unexpected user mode exception %d %d\n", which, type );
        ASSERT( FALSE );
    }
}
