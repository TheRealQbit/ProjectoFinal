# Project: WiFi-Collector
    Authors: Yago Martínez & Alberto Villarroel.
    Course: 2023/2024 
    Subject: Systems Architecture.
    Teacher: Boni García.
## Commands
This is a list of all the commands that can be used in this project.
Note that in order to compile the project, you need to be running a Linux distribution or WSL.
- `Install` to install all the dependencies. This is an easy way to install all the dependencies needed to run the project. You can also install them manually if you prefer. IMPORTANT: if you decide to not use this command please add a folder called export in the root of the project, if not mode 8 will not work.
```bash
./scripts/install.sh
```
- `Make` to compile the project with no debugging.
```bash
make
```
- `Make debug` to compile the project with memory debugging.
```bash	
make debug_memory
```
- `Make clean` to clean the project of all previously built files.
```bash
make clean
```
## Dependencies
This is a list of all the dependencies that are needed to run the project.
- `GCC` to compile the project.
- `CMake` to run the compilation.
- `Valgrind` to debug memory leaks.

## Project structure
This is project is structured in a modular way so that it is easy to add new features, maintain the code and use part of this code in other projects.
The project is structured in the following way:
- `scripts` folder contains all the scripts that we use to set up the project among other useful stuff.
- `libs` folder contains all the libraries that we use in the project.
- `cells` folder contains the files we will use to read the data from the cells.

