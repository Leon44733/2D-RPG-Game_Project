# Libs folder for project libraries

This folder contains external libraries required to build the project on Windows.

## Windows Setup

On Windows, you must manually copy the required library files here:

### Required Libraries

1. **SDL3**
   - Download the **MinGW development library** (e.g., `SDL3-devel-*-mingw.zip`) from: https://github.com/libsdl-org/SDL/releases
   - Extract the ZIP file and open `x86_64-w64-mingw32` (64-bit)
   - Copy the `include` folder into `libs/SDL3/`
   - Copy the `lib` folder into `libs/SDL3/`
   - Copy the `bin` folder into `libs/SDL3/` (contains SDL3.dll)

2. **SDL3_image**
   - Download the **MinGW development library** from: https://github.com/libsdl-org/SDL_image/releases
   - Extract the ZIP file and open `x86_64-w64-mingw32` (64-bit)
   - Copy the `include` folder into `libs/SDL3_image/`
   - Copy the `lib` folder into `libs/SDL3_image/`
   - Copy the `bin` folder into `libs/SDL3_image/` (contains SDL3_image.dll)

### Important: Use MinGW Variants

Make sure to download the **MinGW** versions, not the Visual C++ versions. The MinGW libraries are compiled with GCC and work with your MSYS2/MinGW toolchain.

If you already have SDL3 installed via MSYS2/MinGW (e.g., via `pacman -S mingw-w64-x86_64SDL3`), you can also copy the files from your MSYS2 installation folder:
```
C:/msys64/mingw64/x86_64-w64-mingw32/
```

### Important Notes

- The `.dll.a` files in this folder are **import libraries** that link to the `.dll` files
- At **runtime**, the `.dll` files must be in your PATH or next to the executable
- Without the `.dll` files, the program will fail to start with a "missing DLL" error

## Linux Setup

On Linux, this folder can remain **empty** because:

- CMake uses `find_package(SDL3 REQUIRED)` to find system-installed libraries
- System package managers (apt, pacman, dnf) install SDL3 automatically
- Libraries are found via pkg-config or CMake's built-in FindSDL3 module

## CMake Configuration

The `CMakeLists.txt` in the project root automatically detects the platform:

- **Windows**: Uses libraries from this `libs/` folder
- **Linux/macOS**: Uses system-installed libraries via `find_package()`

This approach ensures the project builds on both platforms with minimal manual configuration.