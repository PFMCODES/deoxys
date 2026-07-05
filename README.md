<div style="display: flex; align-item: center; justify-content: center;">

<picture>
  <source
    media="(prefers-color-scheme: dark)"
    src="./icons/white.svg">

  <source
    media="(prefers-color-scheme: light)"
    src="./icons/black.svg">

  <img
    src="./icons/white.svg"
    alt="Deoxys Logo"
    style="max-width: 500px">
</picture>

</div>



# Deoxys
> An Experimental Embeddable Browser Engine

## how to build
requirements:
CMake
Windows SDK
C++ Development Packages and Executables by VS 2026 Studio

```bash
cd build
cmake ..
cmake --build .
```

an executable will be generated at build/Debug/
with the name deoxys

Licensed under the MIT License