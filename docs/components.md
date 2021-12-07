---
title: 'Components'
---

[Back](/fractool)

Engines
-------------------------------------------------------------------------------------

Two (or Three) engines will be available. Each engine will have it's own 
implementation of the fractal algorithms that are better geared towards 
each system. Each engine will be it's own library.

- Mandelbrot
- Julia-set
    - Parameter: c (complex)
- Burning-Ship
- Parallel Mandelbrot
- Newton's Method
    - Parameter: roots (array of complex)

### ftensp

Will run on single processor. Mainly used to develop algorithms but will remain as
an option until a later date. It may also be useful for fractal algorithms that
can't be as easily parallelized

### ftenmp

Will be multithreaded using OpenMP. Default to ftensp if need be

### ftengpu

Will use CUDA hardware acceleration library. This will default to ftenmp if unavailable


Applications
-------------------------------------------------------------------------------------

### CLI

```bash
$ fractool \
    --use-gpu | --no-use-gpu \
    --algorithm zsquare-seed \
    --parameter 'c=(-0.4,0.6)' \
    --translate-x 20 \
    --translate-y 40 \
    --rotate 45 \
    --zoom 1.3 \
    --colormap flower \
    --image-size-x 1920 \
    --image-size-y 1080 \
    --filename 'fractal.png'
```

Or

```bash
$ fractool --load 'fractal-file.yml'
```

Parameter Groups

| Group                 | Params                                                 |
|:----------------------|:-------------------------------------------------------|
| Algorithm             | `--algorithm`, `--parameter`                           |
| Transform             | `--translate-x`, `--translate-y`, `--rotate`, `--zoom` |
| Postprocessing        | `--colormap`                                           |
| Image                 | `--image-size-x`, `--image-size-y`, `--filename`       |
| Hardware Acceleration | `--use-gpu`, `--no-use-gpu`                            |

### GUI

![GUI](/assets/gui.svg)

~~Should use a generic software or can be a multi-platform system~~

Planning on using wxWidgets lib

- Real time display of fractal view
- Select between different algorithms
- Set parameters for algorithm
- Dynamically transform fractal using view
- Select colormap
- Set image dimensions and filename
- Save image
- Save parameters

### Colormap Utility

Can use the same GUI but be used to create and save colormaps

Miscellaneous
-------------------------------------------------------------------------------------

Originally `ftcore`

A library `ftmisc` containing miscellaneous, shared components across different 
engines and applications

- Image/Movie Writing: Use OpenCV
- Fractal File Reading/Writing: Use YAML
- Colormap File Reading/Writing: Custom

Fractal File format: YAML file structure. Can contain one or more documents (called
jobs)

```yaml
---
algorithm: zsquare-seed
parameters:
    c:
        real: -0.4
        imag: 0.6
transform:
    translate:
        x: 20
        y: 40
    rotate: 45
    zoom: 1.3
postprocessing:
    colormap: flower
image:
    size:
        x: 1920
        y: 1080
    filename: fractal.png
---
.
.
.
```

Colormap file data structure: A binary file 
representing an array of colormap objects

```c++
#define NAME_MAX_LEN 64
#define MAX_COLORS 256
#define NUM_CHANNELS 3

struct colormap {
    char name[NAME_MAX_LEN];
    unsigned char colors[MAX_COLORS][NUM_CHANNELS];
};
```