from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class ConsumerConan(ConanFile):
    """Test consumer to verify algorithms package."""

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    requires = "algorithms/0.1"

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        cmd = "hello_world_consumer"
        self.run(cmd, cwd="bin")
