# IMG2TIM
An Image to PlayStation TIM File Converter

This tool converts almost any image file into a PlayStation TIM image file for PlayStation homebrew development. Uses the FreeImage library for loading image files of almost any file format.

## Features
* Uses the same arguments used in bmp2tim with special additional arguments.
* Supports alpha channel (if available) with threshold control as transparency mask.
* Color-key and index-key transparency masking.
* Basic RGB to color-index image conversion.

## Download
The latest precompiled Win32 binary of this program can be downloaded here:
[img2tim_(v0.75).zip](http://lameguy64.github.io/img2tim/img2tim_(v0.75).zip)

Previous versions:
[img2tim_(v0.60).zip](http://lameguy64.github.io/img2tim/img2tim_(v0.60).zip)

## Building

You can build the `img2tim` binary executable using either _Code Blocks_ or _CMake_ right away as long as you have the _FreeImage_ library installed on your system (and, of course, either _Code Blocks_ or _CMake_ as well).

### Using Code Blocks

Open the already-provided `img2tim.cbp` file in _CodeBlocks_, assuming that the editor is already properly configured on your side: you should be able to build everything from there.

### Using CMake

Open a bash terminal, navigate to the root of the project and run the following command:
`mkdir -p build && cd build && cmake -S ..`
This will create a `build/` folder, then _CMake_ will generate the build files in it.
You will be notified in case of failure if, for example, the _FreeImage_ library could not be found.

Then, assuming the default _CMake_ generator was targeting _make_: just run `make` to build the program.
If it was targeting _ninja_ instead: run `ninja`.

At the end of it: the `img2tim` executable (with `.exe` extension on Windows) will be ready in the `build/` folder.

#### Custom CMake generator

You can select which generator you prefer by using the `-G` option with `cmake`, you can even generate a whole _Code Blocks_ project file from it, for example:
`cmake -G "CodeBlocks - Unix Makefiles" -B build` will produce a `img2tim.cbp` file in `build/`, which you can open with _Code Blocks_ (and it will use `make` behind the curtains to build the project).

To see the list of all available generators on your system: just run `cmake --help`.

## Changelog
**Version 0.75**
* Fixed a bug where a false error message is thrown when converting 4-bit images with -bpp 4.
* Fixed a pixel order bug when converting images from either RGB or 4-bit depth to 4-bit color depth.

**Version 0.60**
* Initial release.