#!/usr/bin/env python3
import pytest
from PIL import Image
import subprocess as sp
import numpy as np
import os
import sys

expected_rel = 'expected'
executable_rel = '../../build/out/fractool/fractool'

# Help message
help_message = b"""$ fractool [options]

Configuration options:
  -h [ --help ]             Produce help message
  -a [ --algorithm ] arg    Set algorithm type (julia|mbrot)
  -u [ --image-size-x ] arg Set horizontal image size
  -v [ --image-size-y ] arg Set vertical image size"""


@pytest.fixture
def tmp_env(tmp_path):
    """
    Create temporary environment for each integration tests
    """
    curr = os.getcwd()
    print(curr)
    print(os.listdir(os.path.join(curr, '../..')))
    print(os.listdir(os.path.join(curr, '../../build')))
    print(os.listdir(os.path.join(curr, '../../build/out')))
    print(os.listdir(os.path.join(curr, '../../build/out/fractool')))
    print(os.listdir(os.path.join(curr, 'expected')))
    executable = os.path.join(curr, executable_rel)
    print(os.stat(executable).st_mode)
    print(os.access(executable, os.X_OK))
    expected = os.path.join(curr, expected_rel)
    os.chdir(tmp_path)
    yield executable, expected
    os.chdir(curr)


@pytest.mark.parametrize('expected_file,args', [
    ('no-options.png',       []),
    ('algorithm-julia.png',  ['--algorithm', 'julia']),
    ('algorithm-mbrot.png',  ['--algorithm', 'mbrot']),
    ('set-image-size-x.png', ['--image-size-x', '900']),
    ('set-image-size-y.png', ['--image-size-y', '900'])
])
def test_cli(tmp_env, expected_file, args):
    """
    Test command line tool with option combinations
    """
    executable, expected = tmp_env
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
    executable, expected = tmp_env
    result = sp.run([executable, arg], capture_output=True)
    assert result.returncode == 0
    assert help_message in result.stdout


def test_invalid_algorithm_type(tmp_env):
    """
    Test command line tool errors when given invalid argument type
    """
    executable, _ = tmp_env
    result = sp.run([executable, '--algorithm', 'foobar'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid algorithm type: foobar' in result.stdout
    assert help_message in result.stdout


def test_invalid_option(tmp_env):
    """
    Test command line tool errors when given invalid option
    """
    executable, _ = tmp_env
    result = sp.run([executable, '--foobar'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid option: --foobar' in result.stdout
    assert help_message in result.stdout


# Run unittests
if __name__ == '__main__':
    sys.exit(pytest.main(['--verbose', 'run.py']))