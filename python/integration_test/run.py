#!/usr/bin/env python3
import pytest
from PIL import Image
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
help_message = re.compile(b"""\\$ fractool \\[options\\](\\r?\n){2}\
Configuration options:\\r?\n\
\\s*\\-h \\[ \\-\\-help \\]\\s*Produce help message\\r?\n\
\\s*\\-m \\[ \\-\\-colormaps \\]\\s*List colormaps\\r?\n\
\\s*\\-a \\[ \\-\\-algorithm \\] arg\\s*Set algorithm type \\(julia\\|mbrot\\)\\r?\n\
\\s*\\-u \\[ \\-\\-image\\-size\\-x \\] arg\\s*Set horizontal image size\\r?\n\
\\s*\\-v \\[ \\-\\-image\\-size\\-y \\] arg\\s*Set vertical image size\\r?\n\
\\s*\\-C \\[ \\-\\-colormap \\] arg\\s*Set colormap""", re.M)

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
    ('no-options.png',        []),
    ('algorithm-julia.png',   ['--algorithm', 'julia']),
    ('algorithm-mbrot.png',   ['--algorithm', 'mbrot']),
    ('set-image-size-x.png',  ['--image-size-x', '900']),
    ('set-image-size-y.png',  ['--image-size-y', '900']),
    ('colormap-blue2red.png', ['--colormap', 'blue2red']),
    ('colormap-flower.png',   ['--colormap', 'flower']),
    ('colormap-ink.png',      ['--colormap', 'ink']),
    ('colormap-red2blue.png', ['--colormap', 'red2blue']),
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


@pytest.mark.parametrize('arg', ['--help', '-h'])
def test_print_help_message(tmp_env, arg):
    """
    Test command line prints help message
    """
    expected = tmp_env
    result = sp.run([executable, arg], capture_output=True)
    assert result.returncode == 0
    assert help_message.search(result.stdout)


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
    assert help_message.search(result.stdout)


def test_invalid_algorithm_type(tmp_env):
    """
    Test command line tool errors when given invalid argument type
    """
    result = sp.run([executable, '--algorithm', 'foobar'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid algorithm type: foobar' in result.stdout
    assert help_message.search(result.stdout)


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
    if len(sys.argv) > 1:
        filepath = sys.argv[1]
        os.environ['PATH'] = filepath + ';' + os.environ.get('PATH', '')
    sys.exit(pytest.main(['--verbose', 'run.py']))