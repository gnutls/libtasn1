@echo off

echo build 32 bit RELEASE
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Release ARCH=32 clean 
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Release ARCH=32 
echo build 64 bit RELEASE
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Release ARCH=64 clean 
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Release ARCH=64 

