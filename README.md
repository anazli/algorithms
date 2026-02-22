# Algorithms

A small collection of algorithms and data structures.

## Data Structures

- **[Containers](include/cool/containers)**
  - **[Sequential](include/cool/containers/sequential)**
    - **[Dynamic Array](include/cool/containers/sequential/vector.h)**
    - **[Linked List](include/cool/containers/sequential/list.h)**


## Building

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

# Build Debug
conan install . -of build_debug -s build_type=Debug --build=missing
cmake -S . -B build_debug \
  -DCMAKE_TOOLCHAIN_FILE=build_debug/build/Debug/generators/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build build_debug
ctest --test-dir build_debug --output-on-failure
```

### CMake + FetchContent (no Conan)

```bash
# Configure out-of-source build
cmake -S . -B build

# Build
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure
```
