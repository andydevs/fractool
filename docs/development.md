---
title: 'Development'
---

[back](/fractool/)

Building
---------------------------------------------------------------------------------

FracTool uses CMake to generate the build system.

### Building on Unix (MacOS/Linux)

Clone the repository and include submodules with `git clone --recurse-submodules`

Run `source env/dev.sh` to configure development environment. Then build 
dependencies using `env/build-deps.sh`

Then run `configure` to configure cmake and `build` to build the project. 

Run `install` to install a test build in a test directory within build (required 
for integration_tests)

### Building on Windows

Reccomend using Visual Studio for this project.

Before configuring, run `.\env\dev.ps1` to set the environment and 
`.\env\build-deps.ps1` to build dependencies on Windows.

Then you can configure and build using Visual Studio

Install using Visual Studio's install command before running integration tests

Integration Tests
---------------------------------------------------------------------------------

FracTool uses python and pytest for integration (recommend using python 3.9 or 
greater). Make sure python3 is installed, along with pip.

Make sure you install a test build (as outlined above), and have run either 
`source env/dev.sh` or `.\env\dev.ps1` depending on OS.

Navigate to `python` directory and run `pip install -r requirements.txt`

Finally, navigate to `integration_test` and run `python run.py` to run 
integration tests.