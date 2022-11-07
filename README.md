FracTool
======================================================================

Generate fractal images.

[Website](https://andydevs.github.io/fractool/)

Usage
----------------------------------------------------------------------

### Install

- Download appropriate binary from 
    [releases](https://github.com/andydevs/fractool/releases/) page. 
- For *Windows*, simply run the installer.
- For *Linux* and *MacOS*, run the self-extracting tar file (.sh) with 
    the argument `--prefix=\[install-directory\]`

### Running the CLI

Running `$ fractool` generates a fractal and saves it in the current 
working directory as `fractal.png`

The default algorithm to generate an image is the mandelbrot algorithm 
for the equation "z = z^2 + c". To change the fractal generation 
algorithm use `--algorithm`.

Run `$ fractool --help` for a full list of commands.