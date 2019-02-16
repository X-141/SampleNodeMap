# SampleNodeMap
This is a sample project coded in C++ that generates a nodemap with specific values. The user can travel through the node map until they reach the tailnode. The user selects the value associated to the node to move through the map. This is a only a sample program, but i have left documentation explaining how to make a nodemap file.

# Requirements
1. C/C++ compilier -> 
  * Linux gcc/g++ v8.2.1 tested -> working
  * MacOS AppleClang v10.0.0 tested -> working
  * Windows MingW gcc/g++ v6.3.0 tested -> working
2. Make -> minimum version tested 3.81
3. Cmake -> minimum required 3.12

# How to Compile
Windows w/ Mingw
1. Make a build directory -> "mkdir build"
1. in the project directory -> "cd build"
2. compile using cmake -> "cmake -G "Unix Makefiles" .."
3. after compilation finishes -> "make"
4. A windows executable named "SampleNodeMap.exe" should've been created
5. "./Run"

Linux/Unix
1. Make a build directory -> "mkdir build"
1. in the project directory -> "cd build"
2. compile using cmake -> "cmake .."
3. after compilation finishes -> "make"
4. executable file named "SampleNodeMap" should've been created
5. "./Run"
