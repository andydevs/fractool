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
    ('no-options.png',      []),
    ('algorithm-julia.png', ['--algorithm', 'julia'])
])
def test_cli(tmp_env,expected_file,args):
    """
    Test command line tool with various option combinations
    """
    executable, expected = tmp_env
    result = sp.run([executable] + args, capture_output=True)
    assert result.returncode == 0
    with Image.open('fractal.png') as actual, \
        Image.open(os.path.join(expected, expected_file)) as expected:
        aAct = np.array(actual)
        aExp = np.array(expected)
        np.testing.assert_array_equal(aAct, aExp)


# Run unittests
if __name__ == '__main__':
    pytest.main(['--verbose', 'run.py'])