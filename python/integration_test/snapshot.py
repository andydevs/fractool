#!/usr/bin/env/python3
import os
import shutil
import subprocess as sp
from sys import argv

# Config
executable = 'fractool'
pending_dir = 'pending'
accepted_dir = 'expected'
images = [
    ('no-options.png',                          []),
    ('algorithm-julia.png',                     ['--algorithm', 'julia']),
    ('algorithm-mandelbrot.png',                ['--algorithm', 'mandelbrot']),
    ('set-image-size.png',                      ['--image-size', '1600,900']),
    ('algorithm-julia-parameter-c-p38-p20.png', ['--algorithm', 'julia', '--parameter', 'c=(0.38,0.2)']),
    ('colormap-blue2red.png',                   ['--colormap', 'blue2red']),
    ('colormap-flower.png',                     ['--colormap', 'flower']),
    ('colormap-ink.png',                        ['--colormap', 'ink']),
    ('colormap-red2blue.png',                   ['--colormap', 'red2blue'])
]


def generate():
    print('Generating...')
    if not os.path.isdir(f'./{pending_dir}'):
        os.mkdir(pending_dir)
    for filename, args in images:
        print('fractool', *args, '==>>', filename)
        result = sp.run([executable] + args, capture_output=True)
        os.rename('./fractal.png', f'./{pending_dir}/{filename}')


def accept():
    print('Accepting snapshot...')
    shutil.copytree(f'./{pending_dir}', f'./{accepted_dir}', dirs_exist_ok=True)
    shutil.rmtree(f'./{pending_dir}')


if __name__ == '__main__':
    # Parse options
    options = ('generate', 'accept')
    option = 'generate'
    if len(argv) > 1 and argv[1] in options:
        option = argv[1]

    # Run based on option
    if option == 'generate':
        generate()
    elif option == 'accept':
        accept()