from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy


class AlgorithmsConan(ConanFile):
    name = "algorithms"
    version = "0.1"
    license = "MIT"
    author = ""
    url = ""
    description = "Small algorithms library"
    topics = ("algorithms",)

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    exports_sources = "src/*", "include/*", "test/*", "CMakeLists.txt"

    def requirements(self):
        self.requires("gtest/1.13.0", headers=True, libs=True)

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(
            self,
            "*.h",
            src=self.source_folder,
            dst=self.package_folder,
            keep_path=False,
        )
        copy(
            self,
            "*.hpp",
            src=self.source_folder,
            dst=self.package_folder,
            keep_path=False,
        )
        copy(
            self,
            "*.lib",
            src=self.build_folder,
            dst=self.package_folder,
            keep_path=False,
        )
        copy(
            self, "*.a", src=self.build_folder, dst=self.package_folder, keep_path=False
        )
        copy(
            self,
            "*.so",
            src=self.build_folder,
            dst=self.package_folder,
            keep_path=False,
        )

    def package_info(self):
        self.cpp_info.includedirs = ["include"]
        self.cpp_info.libs = ["algorithms"]
