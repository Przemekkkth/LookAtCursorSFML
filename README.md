# LookAtCursorSFML
An app that visualizes multiple eyes staring at a cursor. It is based on [repository](https://github.com/OneLoneCoder/Javidx9/blob/master/PixelGameEngine/SmallerProjects/OneLoneCoder_PGE_PeriodicNumbers.cpp) 
(consider seeing this repo).

## Video

https://user-images.githubusercontent.com/28188300/232335848-1f670777-bd77-433f-9669-5e4b01f785d5.mp4

### Installing

1) Using QMake
A step by step series  that tell you how to get a execute project.
Get it from GitHub
```
git clone git@github.com:Przemekkkth/LookAtCursorSFML.git
```
Compile
```
qmake && make
```

2) Using CMake

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```
```
cd build/
```
```
make -j4
```
```
cp -r ../res/ .
```
You can copy res directory using other method ie by GUI. Next, you can play it.

## Addons
* [SFML](https://www.sfml-dev.org/) - page of SFML project
* [Github](https://github.com/OneLoneCoder) - Github profile author of project concept 
* [Eye sprite](https://opengameart.org/content/observers) - Page of authors on opengameart.org
