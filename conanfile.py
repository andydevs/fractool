from conan import ConanFile
from conan.tools.cmake import cmake_layout


class FracTool(ConanFile):
    name = 'fractool'
    version = '0.2.0'
    settings = 'os', 'arch', 'build_type', 'compiler'
    generators = 'CMakeDeps', 'CMakeToolchain'

    def requirements(self):
        self.requires('boost/1.86.0')
        self.requires('zlib/1.3.1')
        self.requires('libpng/1.6.43')

    def layout(self):
        cmake_layout(self)