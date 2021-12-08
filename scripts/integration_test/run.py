#!/usr/bin/env python3
import unittest
import subprocess
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
        # Run
        self.result = subprocess.run([self.executable], capture_output=True)
        self.assertEqual(self.result.returncode, 0)


# Run unittests
if __name__ == '__main__':
    unittest.main(verbosity=2)