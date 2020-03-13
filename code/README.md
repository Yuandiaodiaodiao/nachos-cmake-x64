## notice
 - change GCCDIR in Makefile.dep to suit your mips-gcc
 - you may need to exec 
```shell  
sudo chmod +x /bin/exePreBuild/coff2flat"  
```  
 and   
```shell  
sudo chmod +x /bin/exePreBuild/coff2flat  
```  
when failed to exec make in /test

## dependency
sudo apt-get install cmake
sudo apt-get install lib32stdc++6
sudo apt-get install libc6-dev-i386
sudo apt-get install g++-multilib  
sudo apt-get install build-essential module-assistant 
sudo apt-get install g++