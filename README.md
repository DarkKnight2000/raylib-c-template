# Simple Raylib template in C

## Features:

- Includes raylib. No need to install anything. Makes it easy to update raylib without breaking other projects

- Obj files are created in a separate folder to keep the working tree clean
- Incremental building. Build only compilation units that are changed
- Separate build directories based on version and platform
- Tested on Windows for Desktop and Android platforms. Uses Makefiles from raylib repo with some modifications, so it should work for other platforms also
- Includes a Makefile.Reset file which recompiles raylib to required platform and starts building the project. Useful when switching and testing between different platforms


## Intial Setup

- Run the following commands to download and build the project

```
git clone https://github.com/DarkKnight2000/raylib-c-template.git
cd raylib-c-template
make setup
make rebuild
make
```
- Download the project with `git clone` command (Skip if you already downloaded) and `cd` into the root of the project.
- `make setup` will download raylib and setup directories
- `make rebuild` will compile raylib for desktop platform
- `make` will compile the project and run the executable
- If you are running on Windows, use `mingw32-make` instead of `make`

- Look at [Directory Structure](#directory-structure) for more info about folders


## Usage

- All these commands should be run in the project root
- For building and testing on desktop platform run

```
# for Desktop
make

# for Android
make PLATFORM=PLATFORM_ANDROID
```

- When switching platforms, run this command to build/rebuild raylib to required platform and build the project

```
# for Desktop
make rebuild

# for Android
make rebuild PLATFORM=PLATFORM_ANDROID
```

- For Android, look at Makefile.Android file and set `JAVA_HOME`, `ANDROID_HOME`, `ANDROID_NDK` paths correctly. The Makefile.Android is taken from `raylib` repo, look at [Raylib Wiki](https://github.com/raysan5/raylib/wiki/Working-for-Android) for details.

## Directory Structure:

- .vscode/
  - Containes some useful settings when working with Visual Studio Code
  - Use shortcut `Ctrl + Shift + B` to automatically open a terminal and run `Make`.
  - Includes settings to hide some files in the explorer to keep it clean.
  - Adds `include\` folder to VSCode Intellisense path
- bin/
  - All the executable files are created here ready for shipping along with assets
- vendor/
  - Containes raylib source code. No need to install raylib or any dependencies. Added raylib repo as a git submodule. Run `make setup` to download latest stable version of raylib
- include/
  - Folder for your project header files here
- res/
  - Folder for your assets
  - Copy folder this to bin directory to distribute your game/software
  - Use the path `res/{asset-name}` in the code to reference the assets
- src/
  - Folder for C source files
