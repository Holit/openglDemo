# openglDemo
![](https://img.shields.io/badge/-OpenGL-blue)
![](https://img.shields.io/badge/lang-C%2B%2B-red)
![](https://img.shields.io/badge/lang-GLSL-red)

这是一个计算机图形学的实验项目，主要目的是完成作业和学习OpenGL在Windows上的图形编程策略，学习现代图形学概念和实践。  
最终目标：实现基于简单光照模型的十二面体真实感显示(flat明暗处理)以及光滑着色。  
抱歉本README不提供英文版本。你可以自己翻译。（但是release提供（也许））      
## Flags!  
* ~~正十二面体的渲染~~![](https://img.shields.io/badge/feat-done!-green)
* ~~简单光照模型~~![](https://img.shields.io/badge/feat-done!-green)
* ~~处理键盘输入~~![](https://img.shields.io/badge/feat-done!-green)
* ~~处理鼠标动作~~![](https://img.shields.io/badge/feat-done!-green)
* ~~展示详细的数据~~![](https://img.shields.io/badge/feat-done!-green)
* ~~Flat光照模型~~![](https://img.shields.io/badge/feat-done!-green)
* ~~Phong光照模型~~![](https://img.shields.io/badge/feat-done!-green)
* ~~Gouraud光照模型~~![](https://img.shields.io/badge/feat-done!-green)
* 试着实现其他的新的光照模型
* 半透明渲染/玻璃板材质、半透明玻璃材质、毛玻璃材质
* **Impossible的任务：光线追踪！**
## 使用指南

程序启动时将自动要求调用NIVIDA显卡，同时渲染一个正十二面体和一个正方体光源线框。  
* `WSAD` 移动摄像机视角，可以理解为第一人称视角的移动  
* `Ctrl` + `QWEASD`   移动光源立方体，`WS`控制y轴移动，`QE`控制z轴移动，`AD`控制x轴移动  
* `Ctrl` + `Z` + 鼠标滚轮   调整环境光强，同时按下`Alt`键加快调整速度    
* `Ctrl` + `X` + 鼠标滚轮   调整镜面反射光强，同时按下`Alt`键加快调整速度  
* `Ctrl` + `C` + 鼠标滚轮   调整漫反射光强，同时按下`Alt`键加快调整速度  
    * 上述三个参数的变更可能会很大程度的影响渲染结果。
* `F1`  在三种光照模型间切换
* `F2`  显示/隐藏调试器界面。调试器界面将显示下述内容：
      ![image](https://github.com/Holit/openglDemo/assets/20926583/ef918d25-51d7-4d3a-ab08-62e290307737)
    * 光照模型
    * 渲染器（显卡）名称
    * 本渲染器所支持的最高OpenGL版本
    * 帧率、显存占用情况
    * 摄像机位置
    * 视角向量
    * 光源位置
    * 模型变换矩阵（4x4齐次矩阵）
    * 按下`Ctrl+Z/X/C`键时，将显示对应的参数。
* `Esc` 退出程序
* 鼠标左键按住并拖动 旋转正十二面体  

其他按键指令正在缓慢开发中。每次release都会更新此表。  

本最终效果只是某一个release版本的渲染效果，不一定是最终版本的渲染效果。  

![animation](https://github.com/Holit/openglDemo/assets/20926583/6e5d9852-92a5-481f-bb24-ac3f2ff93170)

## 其他说明  
### 如何编译和调试

本程序使用地IDE为Visual Studio 2022 (v143)，`.sln`文件可以直接编译，只要你原样下载了Dependencies文件夹，依赖就会自动满足。Windows SDK版本10.0 (最新安装的版本)。如果你要使用其他编译器（例如msvc、gcc等）请同时编译所有cpp文件，包括imgui的依赖cpp文件。  
本程序只支持x64版本，我把另一个版本（Win32）删掉了，因为我不打算支持x86.

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

以及感谢ChatGPT 3.5（咳咳
## 参考教材

[1] [孔令德. 计算机图形学基础教程（Visual C++版）（第2版）[M]. 2-22. 清华大学出版社, 2013.03.01 :264-265.](http://www.tup.com.cn/bookscenter/book_04364006.html)

## 开源协议

本项目公开之后基于[MIT License](https://github.com/Holit/openglDemo/blob/master/LICENSE.txt)。
