# 003_miniRT
## Basic ray-tracing. 5 primitives, colored only, cast hard shadows, multiple and ambient lighting. Using MinilibX, working on MacOS an Ubuntu. 
_Thanks to Kain2250 for mentoring and tutoring in this project. Thanks to cvignar and MaudClam for help in debugging._

>_This project is an introduction to the beautiful world of Raytracing.
Once completed you will be able to render simple Computer-Generated-Images and you
will never be afraid of implementing mathematical formulas again_

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/sapogov1978/003_miniRT?style=for-the-badge)
![Lines of code](https://img.shields.io/tokei/lines/github/sapogov1978/003_miniRT?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/sapogov1978/003_miniRT?style=for-the-badge)
![GitHub top language](https://img.shields.io/github/languages/top/sapogov1978/003_miniRT?style=for-the-badge)

## Usage

### Requirements

The project is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
MLX Library provided and will be choosend during compilation depends on platform.

### Instructions

**1. Compiling the Project**

To compile the Project, run:

```shell
$ cd path/to/miniRT && make
```

**2. Syntaxis**

To open a window with raytracing result:

```shell
miniRT scenes/[scene_name].rt
```
Use "~" to switch cameras if many.

this command will save a .bmp file with raytraicing result to renders/[scene_name].bmp:

```shell
miniRT scenes/[scene_name].rt --save
```
## Gallery

![alt text](https://github.com/sapogov1978/003_miniRT/blob/master/gallery/01.jpg?raw=true)
