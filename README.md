# APIagb

A library to manage the GBA hardware, built with C and with compatibility with C, C++ and Assembly.

[![forthebadge](https://forthebadge.com/images/badges/compatibility-club-penguin.svg)](https://forthebadge.com)

## Getting Started

Follow these instructions to build the library and the various demos.

### Prerequisites

Install GNU make:

```
sudo apt-get install build-essential
```

Read [this guide](https://devkitpro.org/wiki/Getting_Started) to install DevkitARM.

### Building the library.

First, go to the directory where you downloaded the library:

```bash
cd /path/to/lib/
```

And then build the library:

```bash
make APIagb
```
Or:
```bash
make lib
```

If you see a file named `libAPIagb.a`, then the build was succesfull.

You can run `make` to see the list of demos.

## Building the demos.

### Mode3Demo

This demo shows the line, circle, frame and rectangle drawing algorithms for mode 3. You can build it like this:

```bash
make Mode3Demo
```

### Mode3ImageDemo

This demo shows the image copying routine for mode 3. You can build it like this:

```bash
make Mode3ImageDemo
```

### Mode4Demo

This demo shows the line, circle, frame and rectangle drawing algorithms for mode 4, and the mode 4 page flip handler. You can build it like this:

```bash
make Mode4Demo
```

### Mode4ImageDemo

This demo shows the image and palette copying routines for mode 4, and the mode 4 page flip handler. You can build it like this:

```bash
make Mode4ImageDemo
```

### Mode5Demo

This demo shows the line, circle, frame and rectangle drawing algorithms for mode 5, and the mode 5 page flip handler. You can build it like this:

```bash
make Mode5Demo
```

### Mode5ImageDemo

This demo shows the image copying routine for mode 5, and the mode 5 page flip handler. You can build it like this:

```bash
make Mode5ImageDemo
```

### Mode5Demo

This demo shows the keypad handler routines. You can build it like this:

```bash
make InputDemo
```

### SpriteDemo

This demo shows the object handlers and a working sprite:

```bash
make SpriteDemo
```

### BgDemo

This demo shows the background handlers and a working BG:

```bash
make BgDemo
```

### ExtendedBgDemo

This demo shows an extended BG and a technique I like to call "Map Banking":

```bash
make ExtendedBgDemo
```

### AffineSpriteDemo

This demo shows an affine sprite and applies transformations to it:

```bash
make AffineSpriteDemo
```

### AffineBgDemo

This demo shows an affine background and applies transformations to it:

```bash
make AffineBgDemo
```

### MosaicDemo

This demo shows a background and a sprite, and applies a mosaic on them:

```bash
make MosaicDemo
```

## Testing on a real GBA

All the demos were built for cartridges, but you can change this to multiboot by changing the `SPECS` variable of the demo Makefile to `gba_mb`.

## Contributing

To contribute, see [CONTRIBUTING.md](https://github.com/LinoBigatti/APIagb-dev/blob/developement/CONTRIBUTING.md).

## Built With

* [DevkitPro](https://github.com/devkitPro) - The DevkitARM provider.
* [GNU Make](https://www.gnu.org/software/make/) - The build system.
* [GBATek](https://problemkaputt.de/gbatek.htm) - The holy grail of GBA development.
* [TONC](https://www.coranac.com/tonc/text/toc.htm) - The guide to GBA.

## Authors

* **Lino Bigatti** - *Main library & demo coder.*

To appear here, contribute to the library and/or its demos.

## Acknowledgments

* [TONC](https://www.coranac.com/tonc/text/toc.htm), because some of my functions are based on TONC's ones.
* [Compumax](https://github.com/CompuMaxx), because he helps me when my code don't works.
* [Kaiser](https://github.com/kaisermg5), Idem.
