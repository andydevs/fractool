#!/usr/bin/env python3
import pytest
from PIL import Image
import subprocess as sp
import numpy as np
import os

expected_rel = 'expected'
executable_rel = '../../build/out/fractool/fractool'


@pytest.fixture
def tmp_env(tmp_path):
    """
    Create temporary environment for each integration tests
    """
    curr = os.getcwd()
    executable = os.path.join(curr, executable_rel)
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


def test_invalid_algorithm_type(tmp_env):
    """
    Test command line tool errors when given invalid argument type
    """
    executable, _ = tmp_env
    result = sp.run([executable, '--algorithm', 'booboo'], capture_output=True)
    assert result.returncode != 0
    assert b'Invalid algorithm type: booboo' in result.stdout


# Run unittests
if __name__ == '__main__':
    pytest.main(['--verbose', 'run.py'])