# Simple Raylib template in C

## Features:

- Includes raylib. No need to install anything. Makes it easy to update raylib without breaking other projects

- Obj files are created in a separate folder to keep the working tree clean
- Incremental building. Build only compilation units that are changed
- Separate build directories based on version and platform
- Automatically copy all assets (in res/ folder) to build directory along with the app. Makes it easier to ship your game
- Tested on Windows for Desktop and Android platforms. Uses Makefiles from raylib repo with some modifications, so it should work for other platforms also
- Includes a Makefile.Reset file which recompiles raylib to required platform and starts building the project. Useful when switching and testing between different platforms


## Setup


    git clone https://github.com/DarkKnight2000/raylib-c-template.git
    cd raylib-c-template
    make setup

- If you are running on Windows, use `mingw32-make` instead of `make`

- Look at [Directory Structure](#directory-structure) for more info about folders


## Usage

- All these commands should be run in the project root
- When building for first time or switching platforms. This rebuilds raylib to required platform and builds the project
```
# for Desktop
make -f Makefile.Reset desktop

# for Android
make -f Makefile.Reset android
```

- For Android, look at Makefile.Android file and set `JAVA_HOME`, `ANDROID_HOME`, `ANDROID_NDK` paths correctly. The Makefile.Android is taken from `raylib` repo, look at [Raylib Wiki](https://github.com/raysan5/raylib/wiki/Working-for-Android) for details.

- For subsequent builds

```
make
```

## Directory Structure:

- .vscode/
  - Containes some useful settings when working with Visual Studio Code
- bin/
  - All the executable files are created here ready for shipping along with assets
- vendor/
  - Containes raylib source code. No need to install raylib or any dependencies. Added raylib repo as a git submodule.
- include/
  - Folder for your project header files here
- res/
  - Folder for your assets
  - Copied on each build to the bin directory
  - Use the path `res/{asset-name}` in the code to reference the assets
- src/
  - Folder for C source files
