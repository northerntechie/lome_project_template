# C++ Project Template for Lome Demo

## Build instructions

The project uses `cmake`, `clang++` compiler and `make` build systems.

From the project_template root directory,

	$ mkdir build
	$ cd build
	$ cmake --preset clang-release ..
	$ cd clang-release
	$ ninja

The build_doc script can be ran from the project root to run the documentation build process.
