[Components](/fractool/components)
[Roadmap](/fractool/roadmap)

Current Features
-------------------------------------------------------------

### Fractool CLI

- Can generate Mandelbrot and Jula fractal images
    - Both algorithms use `z = z^2 + c`
    - Julia sets `c` to `-0.4 + 0.6i`
    - Set algorithm with `--algorithm`
- Set image dimensions and preset colormaps
    - List colormaps using `--colormaps`

Project Scope
-------------------------------------------------------------

FracTool is a personal application for generating fractal
images. It will mainly be used by individuals for the
purposes of creating such images for use in wallpapers,
banner images for social media, creative image assets, etc.

FracTool will _not_ implement a web solution, and will _not_
expose an API for use in other programs. FracTool will also
_not_ be containerized, and will remain a client-side
application.
