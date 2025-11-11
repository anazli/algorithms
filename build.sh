#!/bin/bash
# Build script for Algorithms library with Conan 2.x

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Default build type
BUILD_TYPE="${1:-Release}"

if [ "$BUILD_TYPE" != "Release" ] && [ "$BUILD_TYPE" != "Debug" ]; then
    echo "Usage: $0 [Release|Debug]"
    echo "  Default: Release"
    exit 1
fi

# Set directories
if [ "$BUILD_TYPE" = "Release" ]; then
    BUILD_DIR="build"
else
    BUILD_DIR="build_debug"
fi

echo "=== Building $BUILD_TYPE ==="
echo "Build directory: $BUILD_DIR"

# Activate virtual environment
if [ ! -d ".venv" ]; then
    echo "Creating virtual environment..."
    python3 -m venv .venv
fi

source .venv/bin/activate

# Ensure Conan is installed
if ! command -v conan &> /dev/null; then
    echo "Installing Conan..."
    pip install conan
fi

# Create Conan profile if needed
if [ ! -f ~/.conan2/profiles/default ]; then
    echo "Creating Conan profile..."
    conan profile detect --force
fi

# Install dependencies
echo "Installing Conan dependencies..."
conan install . -of "$BUILD_DIR" -s build_type="$BUILD_TYPE" --build=missing

# Configure
echo "Configuring with CMake..."
TOOLCHAIN_PATH="$BUILD_DIR/build/${BUILD_TYPE}/generators/conan_toolchain.cmake"
cmake -S . -B "$BUILD_DIR" \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_PATH" \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE"

# Build
echo "Building..."
cmake --build "$BUILD_DIR" -j4

# Run tests
echo "Running tests..."
ctest --test-dir "$BUILD_DIR" --output-on-failure

echo ""
echo "=== Build successful! ==="
echo "Build artifacts in: $BUILD_DIR"
