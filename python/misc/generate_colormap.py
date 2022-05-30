import numpy as np
import yaml


# File format parts
header = """#ifndef __FRACTOOL_COLORMAP_H__
#define __FRACTOOL_COLORMAP_H__

// Includes
#include <fractool/macros.hpp>
#include <map>
#include <string>"""
cmap_wrapper_fmt = """// Colormap {name}
const colormap COLORMAP_{uname} = {{
{array}
}};"""
cmap_element_fmt = '\t{0:3d}, {1:3d}, {2:3d}'
lookup_wrapper_fmt = """// Colormap lookup table
const std::map<std::string, colormap> cmap_lookup = {{
{array}    
}};"""
lookup_element_fmt = '\t{{ "{name}", COLORMAP_{uname} }}'
footer = "#endif // __FRACTOOL_COLORMAP_H__"


def format_cmap(cmap, name):
    """
    Format colormap into c++ representation
    """
    fmt_colors = ',\n'.join(cmap_element_fmt.format(*color) for color in cmap)
    return cmap_wrapper_fmt.format(name=name, uname=name.upper(), array=fmt_colors)


def format_lookup(names):
    """
    Generate lookup table
    """
    fmt_elements = ',\n'.join(lookup_element_fmt.format(name=name.lower(), uname=name.upper()) for name in names)
    return lookup_wrapper_fmt.format(array=fmt_elements)


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


def parse_colormap(doc):
    """
    Parse colormap from document
    """
    name = doc['name']
    if doc['type'] == 'gradient':
        cmap = gradient(doc['from'], doc['to'])
    elif doc['type'] == 'sinusoidal':
        cmap = sinusoidal(doc['freqs'], doc['phases'])
    else:
        print('Invalid type for colormap {name}: {type}'.format(**doc))
        cmap = gradient([0, 0, 0], [255, 255, 255])
    return cmap, name


# Write colormap
if __name__ == '__main__':
    with open('colormap.hpp', 'w+') as file, \
        open('../../colormaps.yml', 'r') as cmapfile:
        colormaps = yaml.safe_load(cmapfile)['colormaps']
        file.write(header)
        file.write('\n\n')
        for doc in colormaps:
            cmap, name = parse_colormap(doc)
            file.write(format_cmap(cmap, name))
            file.write('\n\n')
        file.write(format_lookup([ doc['name'] for doc in colormaps]))
        file.write('\n\n')
        file.write(footer)