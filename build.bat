@echo off
if "%~1" == "v" (
    @echo on
)
echo ---CLEANING---
rm -r ./build
echo ---CMAKE---
mkdir build
cmake -S . -B ./build
cd ./build
make
echo ---DONE---