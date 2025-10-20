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

## Compiling

This project relies on `PkgConfig` to resolve the necessary dependencies. Esnure that
it is present on your system and the `freeimage` library is installed.

To initialise the project, run:
```shell
cmake -B ./build .
```

If need be you can directly specify the toolchain if you are using vcpkg:

```shell
cmake -DCMAKE_TOOLCHAIN_FILE=<path to vcpkg>/vcpkg/scripts/buildsystems/vcpkg.cmake -B ./build .
```

Then run the program via:
```shell
./build/Img2TIM <args>
```

## Changelog
**Version 0.75**
* Fixed a bug where a false error message is thrown when converting 4-bit images with -bpp 4.
* Fixed a pixel order bug when converting images from either RGB or 4-bit depth to 4-bit color depth.

**Version 0.60**
* Initial release.
