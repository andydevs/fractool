#!/usr/bin/env python3
import unittest
from PIL import Image
import subprocess as sp
import numpy as np
import os


class CLIIntegrationTestCase(unittest.TestCase):
    """
    Test fractool cli under various conditions
    """
    envdir = 'tmp'
    expected = '../expected'
    executable = '../../../build/out/fractool/fractool'

    @classmethod
    def setUpClass(cls):
        if not os.path.exists(cls.envdir): 
            os.mkdir(cls.envdir)
        os.chdir(cls.envdir)
        super().setUpClass()

    def test_no_options(self):
        self.expected_file = 'no-options.png'
        self.args = []
        self.result = sp.run([self.executable] + self.args, capture_output=True)
        self.assertEqual(self.result.returncode, 0)
        with Image.open('fractal.png') as actual, \
            Image.open(f'{self.expected}/{self.expected_file}') as expected:
            aAct = np.array(actual)
            aExp = np.array(expected)
            np.testing.assert_array_equal(aAct, aExp)

    def test_algorithm_julia(self):
        self.expected_file = 'algorithm-julia.png'
        self.args = ['--algorithm', 'julia']
        self.result = sp.run([self.executable] + self.args, capture_output=True)
        self.assertEqual(self.result.returncode, 0)
        with Image.open('fractal.png') as actual, \
            Image.open(f'{self.expected}/{self.expected_file}') as expected:
            aAct = np.array(actual)
            aExp = np.array(expected)
            np.testing.assert_array_equal(aAct, aExp)


# Run unittests
if __name__ == '__main__':
    unittest.main(verbosity=2)