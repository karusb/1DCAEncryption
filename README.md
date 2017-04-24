# 1DCAEncryption
XOR Based Encryption Using Cellular Automata
*Use GNU GCC Compiler
# Compiling the program using windows
- Use MINGW Library for compiling the program, download from here https://sourceforge.net/projects/mingw/files/
- If IDE is not available to compile, run mingw32-g++.exe with following commands:" -Wall -fexceptions -g  -c C:\Users\your_source_directory\main.cpp -o main.o" to create an object
- Create an executable using the following commands with mingw32-g++.exe : "-o main.exe main.o"
- Run the executable created as main.exe. DONE!
- Note : It's easier to download CodeBlocks (download here:http://www.codeblocks.org/downloads/26) with mingw package and simply compile and run the program with one click.
# Compiling the program using linux
- Use g++ library in from the linux repository. If not available simply run "sudo apt-get install g++" on command line.
- change to the source directory on command line and run "g++ -o main.o -c main.c" then link with "g++ -o main main.o" and run the executable with "./main" DONE!
- NOTE: Some system functions are used therefore those might not be supported by your OS though it does not affect the algorith itself.
# Running postprocessing on Matlab
- Import cryptolinear.m to Matlab.
- Make sure the directories for the imported datafiles are correctly set.
- Make sure to use pokerfile outputs for variables denoted with Px and "nonlinearity" files with variables denoted with Sx
- It has predefined 6 examples that are included in the repository at /data
- Poker results are given as Pxres where x is the sample number on Matlab console and standard deviations are given as MPx1
- For monobit tests, only the mean is given as Mx on Matlab console where x is the sample number

# Algorithm Flowchart
![Algorithm Flowchart](https://github.com/karusb/1DCAEncryption/blob/master/encflow.jpg)
