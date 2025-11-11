# Algorithms Library

A small algorithms library.

## Quick Start

**Easiest method: Use the build script**

```bash
# Build Release (default)
./build.sh

# Build Debug
./build.sh Debug
```

**Manual method:**

```bash
# One-time setup
python3 -m venv .venv
source .venv/bin/activate
pip install conan
conan profile detect --force

# Build Release
conan install . -of build -s build_type=Release --build=missing
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure

# Build Debug (optional)
conan install . -of build_debug -s build_type=Debug --build=missing
cmake -S . -B build_debug \
  -DCMAKE_TOOLCHAIN_FILE=build_debug/build/Debug/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build build_debug
ctest --test-dir build_debug --output-on-failure
```

## Project Structure

```
.
├── include/           # Public headers
│   └── hello_world.h
├── src/               # Implementation files
│   └── hello_world.cpp
├── test/              # Unit tests (GoogleTest)
│   ├── CMakeLists.txt
│   └── test_hello_world.cpp
├── consumer/          # Example consumer for testing package creation
│   ├── CMakeLists.txt
│   ├── conanfile.py
│   └── main.cpp
├── CMakeLists.txt     # Root CMake configuration
├── conanfile.py       # Conan package recipe
├── build.sh           # Convenient build script
└── README.md          # This file
```

## Building with CMake

### Prerequisites
- CMake >= 3.15
- C++20 capable compiler
- GoogleTest (will be fetched automatically or provided by Conan)

### CMake + FetchContent (no Conan)

```bash
# Configure out-of-source build
cmake -S . -B build

# Build
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure
```

## Building with Conan

### Prerequisites
- Conan 2.x (see `conanfile.py`)
- CMake >= 3.15
- C++20 capable compiler
- Python virtual environment with Conan installed

### Initial Setup (One-time)

```bash
# Create and activate virtual environment
python3 -m venv .venv
source .venv/bin/activate

# Install Conan
pip install conan

# Create Conan profile
conan profile detect --force
```

### Build Release (Default)

```bash
# Activate virtual environment
source .venv/bin/activate

# Install Conan dependencies for Release build
conan install . -of build -s build_type=Release --build=missing

# Configure CMake with Conan toolchain
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build -j4

# Run tests
ctest --test-dir build --output-on-failure
```

### Build Debug

```bash
# Activate virtual environment
source .venv/bin/activate

# Install Conan dependencies for Debug build
conan install . -of build_debug -s build_type=Debug --build=missing

# Configure CMake with Conan toolchain
cmake -S . -B build_debug \
  -DCMAKE_TOOLCHAIN_FILE=build_debug/build/Debug/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build build_debug -j4

# Run tests
ctest --test-dir build_debug --output-on-failure
```

### Create and Test Package

Export the recipe to your local Conan cache:

```bash
source .venv/bin/activate

# Create Release package
conan create . -s build_type=Release --build=missing

# Create Debug package (optional)
conan create . -s build_type=Debug --build=missing
```

### Test the Consumer

The `consumer/` folder contains a minimal example of consuming the `algorithms` library as a Conan dependency.

```bash
source .venv/bin/activate

# From the project root, test the package via the consumer
cd consumer

# Install the algorithms package (Release)
conan install . -of build -s build_type=Release

# Configure and build the consumer
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Run the consumer
./build/hello_world_consumer

cd ..
```

### Full Workflow Example

```bash
source .venv/bin/activate

# 1. Build and test the library (Release)
conan install . -of build -s build_type=Release --build=missing
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure

# 2. Create the package in Conan cache
conan create . -s build_type=Release --build=missing

# 3. Test consuming the package
cd consumer
conan install . -of build -s build_type=Release
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/hello_world_consumer
cd ..

## Troubleshooting

### Virtual environment not activated
If you get `command not found: conan` or CMake errors:
```bash
source .venv/bin/activate
```

### Conan profile not found
Create the default profile:
```bash
conan profile detect --force
```

### CMake cannot find GTest
Ensure you've run `conan install` before `cmake -S`:
```bash
conan install . -of build -s build_type=Release --build=missing
```

### Clean rebuild
Remove all build artifacts and rebuild:
```bash
rm -rf build build_debug consumer/build
conan install . -of build -s build_type=Release --build=missing
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## License

MIT