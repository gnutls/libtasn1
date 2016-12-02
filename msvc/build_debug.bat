@echo off

echo build 32 bit DEBUG
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=32 clean >nul
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=32 
gmake -f test_parser.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=32 
echo build 64 bit DEBUG
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=64 clean >nul
gmake -f libtasn1.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=64 
gmake -f test_parser.mak VSTOOLSET=VS140 CONFIG=Debug ARCH=64

