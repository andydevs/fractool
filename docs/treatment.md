Frac Tool
=================================================================

FracTool is a tool used for generating images/videos
of 2D fractals using various algorithms.

Components
-----------------------------------------------------------------

### Core

Shared components across different engines and applications

#### Image Writing

Use OpenCV

#### Filesystem

YAML File format

```yaml
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
```

### Engines

- CPU: use OpenMP
- GPU: use CUDA. Default to CPU if no device available

### Applications

#### CLI

    $ fractool \
        --use-gpu | --no-use-gpu \
        --algorithm zsquare-seed \
        --parameter 'c=-0.4 + 0.6j' \
        --translate-x 20 \
        --translate-y 40 \
        --rotate 45 \
        --zoom 1.3 \
        --colormap flower \
        --image-size-x 1920 \
        --image-size-y 1080 \
        --filename 'fractal.png'

Or

    $ fractool --do 'fractal-file.yml'

Parameter Groups

| Group                  | Params                                                 |
|:-----------------------|:-------------------------------------------------------|
| Algorithm              | `--algorithm`, `--parameter`                           |
| Transform              | `--translate-x`, `--translate-y`, `--rotate`, `--zoom` |
| Postprocessing         | `--colormap`                                           |
| Image                  | `--image-size-x`, `--image-size-y`, `--filename`       |
| Hardware Acceleeration | `--use-gpu`, `--no-use-gpu`                            |

#### GUI

Should use a generic software or can be a multi-platform system

- Real time display of fractal view
- Select between different algorithms
- Set parameters for algorithm
- Dynamically transform fractal using view
- Select colormap
- Set image dimensions and filename
- Save image
- Save parameters