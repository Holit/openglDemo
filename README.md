# openglDemo

最终目标：实现基于简单光照模型的十二面体真实感显示(flat明暗处理)

以及光滑着色

## 简介

这是一个计算机图形学的实验项目，主要目的是完成作业和学习OpenGL在Windows上的图形编程策略，学习现代图形学概念和实践。

## 开发环境和调试环境

Visual Studio 2022 (v143)

Windows SDK版本10.0 (最新安装的版本)

### GLFW版本和依赖说明

```C
/*************************************************************************
 * GLFW 3.3 - www.glfw.org
 * A library for OpenGL, window and input
 *------------------------------------------------------------------------
 * Copyright (c) 2002-2006 Marcus Geelnard
 * Copyright (c) 2006-2019 Camilla Löwy <elmindreda@glfw.org>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would
 *    be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not
 *    be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 *    distribution.
 *
 *************************************************************************/
```

使用`lib-vc2022`

### GLAD依赖说明

```C
/*

    OpenGL loader generated by glad 0.1.36 on Fri May 12 14:56:46 2023.

    Language/Generator: C/C++
    Specification: gl
    APIs: gl=3.3
    Profile: compatibility
    Extensions:
        
    Loader: True
    Local files: False
    Omit khrplatform: False
    Reproducible: False

    Commandline:
        --profile="compatibility" --api="gl=3.3" --generator="c" --spec="gl" --extensions=""
    Online:
        https://glad.dav1d.de/#profile=compatibility&language=c&specification=gl&loader=on&api=gl%3D3.3
*/
```

编译和调试基于x64环境

## 参考和学习网址

[主页 - LearnOpenGL CN (learnopengl-cn.github.io)](https://learnopengl-cn.github.io/)，这是主要的参考网站。

[(31) Welcome to OpenGL - YouTube](https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2)，感谢cherno的教程，国内版本[最好的OpenGL教程之一_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1MJ411u7Bc/)

参考教材

没有参考教材，一切都是从网上弄的。

## 开源协议

本项目公开之后基于[MIT License](https://github.com/Holit/openglDemo/blob/master/LICENSE.txt)。
