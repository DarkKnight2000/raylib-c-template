# Simple Raylib template in C

## Features:

- Includes raylib. No need to install anything. Makes it easy to update raylib without breaking other projects

- Obj files are created in a separate folder to keep the working tree clean
- Incremental building. Build only compilation units that changed ( dependency tracking with `.d` files )
- Separate build directories based on version and platform
- Tested on Windows for Desktop, Web and Android platforms. Uses Makefiles from raylib repo with some modifications, so it should work for other platforms also
- Includes a `rebuild` recipe to build raylib to the required platform. For eg. `make rebuild PLATFORM=PLATFORM_WEB` will rebuild raylib library to WEB platform


## Intial Setup

- Run the following commands to download and build the project

```
git clone https://github.com/DarkKnight2000/raylib-c-template.git
cd raylib-c-template
make setup
make rebuild
make
```
### Commands explanation
- Download the project with `git clone` command (Skip if you already downloaded) and `cd` into the root of the project.
- `make setup` will download raylib and setup directories
  - If you don't want to download raylib or have a local copy you can use it by setting `GET_RAYLIB=FALSE` and `RAYLIB_PATH=<path-to-raylib-root>` in the `Makefile`
- `make rebuild` will compile raylib for Desktop platform
- `make` will compile the project and run the executable
- If you are running on Windows, use `mingw32-make` instead of `make`

- Look at [Directory Structure](#directory-structure) for more info about folders


## Usage
- All these commands should be run in the project root
- If building to Web or Android, make sure all the [Makefile Settings](#makefile-settings) are correctly set.
- If you are using `C`, change `USE_CPP` to `FALSE` in `Makefile` (default is `TRUE` which compiles to C++)

- For building and running the program
```
# for Desktop
make

# for Android
make PLATFORM=PLATFORM_ANDROID

# for Web
make PLATFORM=PLATFORM_WEB
```


- We need to build both raylib and this project to the same platform with same settings. If raylib is built to the platform you are currently working on, no need to build it again. If not, then you can run this command to build/rebuild raylib to required platform and then build the project.

```
# for Desktop
make rebuild

# for Android
make rebuild PLATFORM=PLATFORM_ANDROID

# for Web
make rebuild PLATFORM=PLATFORM_WEB
```


## Makefile settings
### Android
- In `Makefile` file and set the following paths correctly.
  - `JAVA_HOME`
  - `ANDROID_HOME`
  - `ANDROID_NDK`
- Allowed values for `ANDROID_ARCH` are `arm` (most common and default), `arm-64`, `x86`, `x86_64`
- The `Makefile.Android` file is taken from `raylib` repo, refer [Raylib Wiki - Working for Android](https://github.com/raysan5/raylib/wiki/Working-for-Android) for more details. Rebuild raylib when any of these settings is changed.

### Web
- In `Makefile` file and set the following paths correctly.
  - `EMSDK_PATH`
    - path to where you downloaded `emsdk`
  - `PYTHON_PATH`
    - go to `python` folder inside the `emsdk` folder and set the correct python version installed
    - If not set correctly, you may get `'"python"' not found` error.
  - `NODE_PATH`
    - go to `node` folder inside the `emsdk` folder and set the correct node version installed
- Refer [Working for Web (HTML5)](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)) for more details. Rebuild raylib when any of these settings is changed.

## Directory Structure:

- .vscode/
  - Containes some useful settings when working with Visual Studio Code
  - Use shortcut `Ctrl + Shift + B` to automatically open a terminal and run `Make`.
  - Includes settings to hide some files in the explorer to keep it clean.
  - Adds `include\` folder to VSCode Intellisense path
- bin/
  - All the executable files are created here ready for shipping along with assets
  - For Desktop, you need to copy the `res/` folder next to the executable. Both the executable and `res/` folder should be shipped together.
- vendor/
  - Containes raylib source code. No need to install raylib or any dependencies. Added raylib repo as a git submodule. Run `make setup` to download latest stable version of raylib
- include/
  - Folder for your project header files here
- res/
  - Folder for your assets
  - Use the path `res/{asset-name}` in the code to reference the assets
- src/
  - Folder for C source files
  - New source files (ending with '.c') will be automatically added to build
  - `minshell.html` file is required for building to web. It can be removed if you don't target that platform
