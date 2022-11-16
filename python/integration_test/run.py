#!/usr/bin/env python3
import pytest
from PIL import Image
from platform import system
import subprocess as sp
import numpy as np
import os
import re
import sys
import yaml

# Directory environment
expected_rel = 'expected'
executable = 'fractool'

# Help message
help_options = [
    ('h', 'help', ''),
    ('m', 'colormaps', ''),
    ('a', 'algorithm', 'arg'),
    ('i', 'image-size', 'width,height'),
    ('C', 'colormap', 'arg'),
    ('p', 'parameter', 'param=value')
]
option_template = "\\s*\\-{0} \\[ \\-\\-{1} \\] ?{2}"

# Colormap names list from yaml
colormaps = []
with open('../../colormaps.yml', 'r') as cmapfile:
    documents = yaml.safe_load(cmapfile)['colormaps']
    colormaps = [ doc['name'] for doc in documents ]


@pytest.fixture
def tmp_env(tmp_path):
    """
    Create temporary environment for each integration tests
    """
    curr = os.getcwd()
    expected = os.path.join(curr, expected_rel)
    os.chdir(tmp_path)
    yield expected
    os.chdir(curr)


@pytest.mark.parametrize('expected_file,args', [
    ('no-options.png',                          []),
    ('algorithm-julia.png',                     ['--algorithm', 'julia']),
    ('algorithm-mbrot.png',                     ['--algorithm', 'mbrot']),
    ('set-image-size.png',                      ['--image-size', '1600,900']),
    ('algorithm-julia-parameter-c-p38-p20.png', ['--algorithm', 'julia', '--parameter', 'c=0.38,0.2'])
])
def test_generator_output(tmp_env, expected_file, args):
    """
    Test command line tool with option combinations
    """
    expected = tmp_env
    result = sp.run([executable] + args, capture_output=True)
    assert result.returncode == 0
    with Image.open('fractal.png') as actual, \
        Image.open(os.path.join(expected, expected_file)) as expected:
        aAct = np.array(actual)
        aExp = np.array(expected)
        np.testing.assert_array_equal(aAct, aExp)


@pytest.mark.parametrize('expected_file,args', [
    ('colormap-blue2red.png', ['--colormap', 'blue2red']),
    ('colormap-flower.png',   ['--colormap', 'flower']),
    ('colormap-ink.png',      ['--colormap', 'ink']),
    ('colormap-red2blue.png', ['--colormap', 'red2blue'])
])
def test_colormap_output(tmp_env, expected_file, args):
    """
    Test various colormaps with command line tool
    """
    expected = tmp_env
    result = sp.run([executable] + args, capture_output=True)
    assert result.returncode == 0
    with Image.open('fractal.png') as actual, \
        Image.open(os.path.join(expected, expected_file)) as expected:
        aAct = np.array(actual)
        aExp = np.array(expected)
        np.testing.assert_array_equal(aAct, aExp)


@pytest.mark.parametrize('arg', ['--help', '-h'])
def test_print_help_message(tmp_env, arg):
    """
    Test command line prints help message
    """
    expected = tmp_env
    result = sp.run([executable, arg], capture_output=True)
    assert result.returncode == 0
    for short, long, value in help_options:
        option_check = option_template.format(short, long, value)
        assert re.search(option_check.encode('utf-8'), result.stdout)


@pytest.mark.parametrize('arg', ['--colormaps', '-m'])
def test_list_colormaps(tmp_env, arg):
    """
    Test command line prints colormaps
    """
    expected = tmp_env
    result = sp.run([executable, arg], capture_output=True)
    assert result.returncode == 0
    for colormap in colormaps:
        assert bytes(colormap, 'utf-8') in result.stdout


def test_invalid_option(tmp_env):
    """
    Test command line tool errors when given invalid option
    """
    result = sp.run([executable, '--foobar'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid option: --foobar' in result.stdout
    for short, long, value in help_options:
        option_check = option_template.format(short, long, value)
        assert re.search(option_check.encode('utf-8'), result.stdout)


def test_invalid_algorithm_type(tmp_env):
    """
    Test command line tool errors when given invalid argument type
    """
    result = sp.run([executable, '--algorithm', 'foobar'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid algorithm type: foobar' in result.stdout
    for short, long, value in help_options:
        option_check = option_template.format(short, long, value)
        assert re.search(option_check.encode('utf-8'), result.stdout)


def test_invalid_colormap_name(tmp_env):
    """
    Test command line tool prints message given invalid colormap type
    but generates default colormap
    """
    expected = tmp_env
    expected_file = 'invalid-colormap.png'
    result = sp.run([executable, '--colormap', 'foobar'], capture_output=True)
    assert result.returncode == 0
    assert b'Invalid colormap name: foobar. Defaulting to flower.' in result.stdout
    with Image.open('fractal.png') as actual, \
        Image.open(os.path.join(expected, expected_file)) as expected:
        aAct = np.array(actual)
        aExp = np.array(expected)
        np.testing.assert_array_equal(aAct, aExp)


# Run unittests
if __name__ == '__main__':
    # Path mod
    separator = ';' if system() == 'Windows' else ':'
    if len(sys.argv) > 1:
        filepath = sys.argv[1]
        os.environ['PATH'] = sys.argv[1] \
            + separator \
            + os.environ.get('PATH', '')

    # Run tests
    sys.exit(pytest.main(['--verbose', 'run.py']))