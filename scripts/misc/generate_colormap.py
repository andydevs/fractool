import numpy as np

# File format parts
header = """#ifndef __FRACTOOL_COLORMAP_H__
#define __FRACTOOL_COLORMAP_H__"""
wrapper_fmt = """// {name} Colormap
const unsigned char COLORMAP_{uname}[256][3] = {{
{array}
}};"""
element_fmt = '\t{{{0:3d}, {1:3d}, {2:3d}}}'
footer = "#endif // __FRACTOOL_COLORMAP_H__"


def format_cmap(cmap, name):
    """
    Format colormap into c++ representation
    """
    fmt_colors = ',\n'.join(element_fmt.format(*color) for color in cmap)
    return wrapper_fmt.format(name=name, uname=name.upper(), array=fmt_colors)


# Input space
t = np.meshgrid(np.arange(3), np.linspace(0, 1, 256))[1]


def gradient(frm, to):
    """
    Return gradient colormap
    """
    frma = np.array([ frm ])
    toa = np.array([ to ])
    return (frma * (1 - t) + toa * t).astype(np.uint0)


def sinusoidal(freqs, phases):
    """
    Return sinusoidal colormap
    """
    freq = np.array([ freqs ])
    phase = np.array([ phases ])
    return (127 * np.sin(t * freq * 2 * np.pi + phase) + 128).astype(np.uint8)


# Colormaps (EDIT TO MAKE MORE COLORMAPS)
colormaps = {
    'Ink': gradient(frm=[255, 255, 255], to=[0, 0, 0]),
    'Red2blue': gradient(frm=[0, 0, 255], to=[255, 0, 0]),
    'Blue2red': gradient(frm=[255, 0, 0], to=[0, 0, 255]),
    'Flower': sinusoidal(freqs=[0.7, 0.7, 0.7], phases=[-1.0, -2.0, -2.0])
}


# Write colormap
if __name__ == '__main__':
    with open('colormap.hpp', 'w+') as file:
        file.write(header)
        file.write('\n\n')
        for name, cmap in colormaps.items():
            file.write(format_cmap(cmap, name))
            file.write('\n\n')
        file.write(footer)