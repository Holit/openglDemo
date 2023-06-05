
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <iostream>
#include <math.h>

extern "C" {
	_declspec(dllexport) int NvOptimusEnablement = 0x00000001;
}
#pragma region 顶点数据
//正十二面体的顶点
float vertices[] = {
		-0.93f, 0.00f, -0.36f,  -0.41, -0.25f, -0.00f,
		-0.58f, -0.58f, -0.58f, -0.41, -0.25f, -0.00f,
		-0.36f, -0.93f, 0.00f,  -0.41, -0.25f, -0.00f,
		-0.93f, 0.00f, -0.36f,  -0.41, -0.25f, -0.00f,
		-0.36f, -0.93f, 0.00f,  -0.41, -0.25f, -0.00f,
		-0.93f, 0.00f, 0.36f,   -0.41, -0.25f, -0.00f,
		-0.93f, 0.00f, 0.36f,   -0.41, -0.25f, -0.00f,
		-0.36f, -0.93f, 0.00f,  -0.41, -0.25f, -0.00f,
		-0.58f, -0.58f, 0.58f,  -0.41, -0.25f, -0.00f,
		-0.58f, -0.58f, 0.58f,  0.00, -0.41f, 0.25f,
		-0.36f, -0.93f, 0.00f,  0.00, -0.41f, 0.25f,
		0.36f, -0.93f, 0.00f,   0.00, -0.41f, 0.25f,
		0.00f, -0.36f, 0.93f,   0.00, -0.41f, 0.25f,
		-0.58f, -0.58f, 0.58f,  0.00, -0.41f, 0.25f,
		0.36f, -0.93f, 0.00f,   0.00, -0.41f, 0.25f,
		0.00f, -0.36f, 0.93f,   0.00, -0.41f, 0.25f,
		0.36f, -0.93f, 0.00f,   0.00, -0.41f, 0.25f,
		0.58f, -0.58f, 0.58f,   0.00, -0.41f, 0.25f,
		0.00f, 0.36f, 0.93f,    0.25, 0.00f, 0.41f,
		0.00f, -0.36f, 0.93f,   0.25, 0.00f, 0.41f,
		0.58f, -0.58f, 0.58f,   0.25, 0.00f, 0.41f,
		0.00f, 0.36f, 0.93f,    0.25, 0.00f, 0.41f,
		0.58f, -0.58f, 0.58f,   0.25, 0.00f, 0.41f,
		0.93f, 0.00f, 0.36f,    0.25, 0.00f, 0.41f,
		0.00f, 0.36f, 0.93f,    0.25, 0.00f, 0.41f,
		0.93f, 0.00f, 0.36f,    0.25, 0.00f, 0.41f,
		0.58f, 0.58f, 0.58f,    0.25, 0.00f, 0.41f,
		-0.58f, 0.58f, -0.58f,  -0.41, 0.25f, 0.00f,
		-0.93f, 0.00f, -0.36f,  -0.41, 0.25f, 0.00f,
		-0.93f, 0.00f, 0.36f,   -0.41, 0.25f, 0.00f,
		-0.58f, 0.58f, -0.58f,  -0.41, 0.25f, 0.00f,
		-0.93f, 0.00f, 0.36f,   -0.41, 0.25f, 0.00f,
		-0.58f, 0.58f, 0.58f,   -0.41, 0.25f, 0.00f,
		-0.58f, 0.58f, -0.58f,  -0.41, 0.25f, 0.00f,
		-0.58f, 0.58f, 0.58f,   -0.41, 0.25f, 0.00f,
		-0.36f, 0.93f, 0.00f,   -0.41, 0.25f, 0.00f,
		-0.93f, 0.00f, 0.36f,   -0.25, -0.00f, 0.41f,
		-0.58f, -0.58f, 0.58f,  -0.25, -0.00f, 0.41f,
		0.00f, -0.36f, 0.93f,   -0.25, -0.00f, 0.41f,
		-0.93f, 0.00f, 0.36f,   -0.25, -0.00f, 0.41f,
		0.00f, -0.36f, 0.93f,   -0.25, -0.00f, 0.41f,
		-0.58f, 0.58f, 0.58f,   -0.25, -0.00f, 0.41f,
		-0.58f, 0.58f, 0.58f,   -0.25, -0.00f, 0.41f,
		0.00f, -0.36f, 0.93f,   -0.25, -0.00f, 0.41f,
		0.00f, 0.36f, 0.93f,    -0.25, -0.00f, 0.41f,
		-0.36f, 0.93f, 0.00f,   -0.00, 0.41f, 0.25f,
		-0.58f, 0.58f, 0.58f,   -0.00, 0.41f, 0.25f,
		0.00f, 0.36f, 0.93f,    -0.00, 0.41f, 0.25f,
		-0.36f, 0.93f, 0.00f,   -0.00, 0.41f, 0.25f,
		0.00f, 0.36f, 0.93f,    -0.00, 0.41f, 0.25f,
		0.58f, 0.58f, 0.58f,    -0.00, 0.41f, 0.25f,
		-0.36f, 0.93f, 0.00f,   -0.00, 0.41f, 0.25f,
		0.58f, 0.58f, 0.58f,    -0.00, 0.41f, 0.25f,
		0.36f, 0.93f, 0.00f,    -0.00, 0.41f, 0.25f,
		0.36f, 0.93f, 0.00f,    0.41, 0.25f, 0.00f,
		0.58f, 0.58f, 0.58f,    0.41, 0.25f, 0.00f,
		0.93f, 0.00f, 0.36f,    0.41, 0.25f, 0.00f,
		0.36f, 0.93f, 0.00f,    0.41, 0.25f, 0.00f,
		0.93f, 0.00f, 0.36f,    0.41, 0.25f, 0.00f,
		0.93f, 0.00f, -0.36f,   0.41, 0.25f, 0.00f,
		0.36f, 0.93f, 0.00f,    0.41, 0.25f, 0.00f,
		0.93f, 0.00f, -0.36f,   0.41, 0.25f, 0.00f,
		0.58f, 0.58f, -0.58f,   0.41, 0.25f, 0.00f,
		0.93f, 0.00f, -0.36f,   0.41, -0.25f, 0.00f,
		0.93f, 0.00f, 0.36f,    0.41, -0.25f, 0.00f,
		0.58f, -0.58f, 0.58f,   0.41, -0.25f, 0.00f,
		0.93f, 0.00f, -0.36f,   0.41, -0.25f, 0.00f,
		0.58f, -0.58f, 0.58f,   0.41, -0.25f, 0.00f,
		0.36f, -0.93f, 0.00f,   0.41, -0.25f, 0.00f,
		0.93f, 0.00f, -0.36f,   0.41, -0.25f, 0.00f,
		0.36f, -0.93f, 0.00f,   0.41, -0.25f, 0.00f,
		0.58f, -0.58f, -0.58f,  0.41, -0.25f, 0.00f,
		-0.36f, 0.93f, 0.00f,   -0.00, 0.41f, -0.25f,
		0.00f, 0.36f, -0.93f,   -0.00, 0.41f, -0.25f,
		-0.58f, 0.58f, -0.58f,  -0.00, 0.41f, -0.25f,
		-0.36f, 0.93f, 0.00f,   -0.00, 0.41f, -0.25f,
		0.36f, 0.93f, 0.00f,    -0.00, 0.41f, -0.25f,
		0.00f, 0.36f, -0.93f,   -0.00, 0.41f, -0.25f,
		0.36f, 0.93f, 0.00f,    -0.00, 0.41f, -0.25f,
		0.58f, 0.58f, -0.58f,   -0.00, 0.41f, -0.25f,
		0.00f, 0.36f, -0.93f,   -0.00, 0.41f, -0.25f,
		0.00f, 0.36f, -0.93f,   0.25, 0.00f, -0.41f,
		0.58f, 0.58f, -0.58f,   0.25, 0.00f, -0.41f,
		0.93f, 0.00f, -0.36f,   0.25, 0.00f, -0.41f,
		0.00f, 0.36f, -0.93f,   0.25, 0.00f, -0.41f,
		0.93f, 0.00f, -0.36f,   0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  0.25, 0.00f, -0.41f,
		0.93f, 0.00f, -0.36f,   0.25, 0.00f, -0.41f,
		0.58f, -0.58f, -0.58f,  0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  0.00, -0.41f, -0.25f,
		0.58f, -0.58f, -0.58f,  0.00, -0.41f, -0.25f,
		0.36f, -0.93f, 0.00f,   0.00, -0.41f, -0.25f,
		0.00f, -0.36f, -0.93f,  0.00, -0.41f, -0.25f,
		0.36f, -0.93f, 0.00f,   0.00, -0.41f, -0.25f,
		-0.36f, -0.93f, 0.00f,  0.00, -0.41f, -0.25f,
		0.00f, -0.36f, -0.93f,  0.00, -0.41f, -0.25f,
		-0.36f, -0.93f, 0.00f,  0.00, -0.41f, -0.25f,
		-0.58f, -0.58f, -0.58f, 0.00, -0.41f, -0.25f,
		-0.58f, 0.58f, -0.58f,  -0.25, 0.00f, -0.41f,
		0.00f, 0.36f, -0.93f,   -0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  -0.25, 0.00f, -0.41f,
		-0.58f, 0.58f, -0.58f,  -0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  -0.25, 0.00f, -0.41f,
		-0.93f, 0.00f, -0.36f,  -0.25, 0.00f, -0.41f,
		-0.93f, 0.00f, -0.36f,  -0.25, 0.00f, -0.41f,
		0.00f, -0.36f, -0.93f,  -0.25, 0.00f, -0.41f,
		-0.58f, -0.58f, -0.58f, -0.25, 0.00f, -0.41f,

	// 位置坐标       // 法线向量
	// 前面
	-0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  // 左下角顶点
	0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,  // 右下角顶点
	0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,  // 右上角顶点

	-0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  // 左下角顶点
	-0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 1.0f,  // 左上角顶点
	0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,  // 右上角顶点

	// 背面
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  // 左下角顶点
	0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,  // 右下角顶点
	0.5f, 0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  // 右上角顶点

	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  // 左下角顶点
	-0.5f, 0.5f, -0.5f,   0.0f, 0.0f, -1.0f,  // 左上角顶点
	0.5f, 0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  // 右上角顶点

	// 左侧面
	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,  // 左下角顶点
	-0.5f, -0.5f, 0.5f,   -1.0f, 0.0f, 0.0f,  // 右下角顶点
	-0.5f, 0.5f, 0.5f,    -1.0f, 0.0f, 0.0f,  // 右上角顶点

	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,  // 左下角顶点
	-0.5f, 0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,  // 左上角顶点
	-0.5f, 0.5f, 0.5f,    -1.0f, 0.0f, 0.0f,  // 右上角顶点

	// 右侧面
	0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,  // 左下角顶点
	0.5f, -0.5f, 0.5f,    1.0f, 0.0f, 0.0f,  // 右下角顶点
	0.5f, 0.5f, 0.5f,     1.0f, 0.0f, 0.0f,  // 右上角顶点

	0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,  // 左下角顶点
	0.5f, 0.5f, -0.5f,    1.0f, 0.0f, 0.0f,  // 左上角顶点
	0.5f, 0.5f, 0.5f,     1.0f, 0.0f, 0.0f,  // 右上角顶点

	// 顶部面
	-0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,  // 左下角顶点
	0.5f, 0.5f, 0.5f,     0.0f, 1.0f, 0.0f,  // 右下角顶点
	0.5f, 0.5f, -0.5f,    0.0f, 1.0f, 0.0f,  // 右上角顶点

	-0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,  // 左下角顶点
	-0.5f, 0.5f, -0.5f,   0.0f, 1.0f, 0.0f,  // 左上角顶点
	0.5f, 0.5f, -0.5f,    0.0f, 1.0f, 0.0f,  // 右上角顶点

	// 底部面
	-0.5f, -0.5f, 0.5f,   0.0f, -1.0f, 0.0f,  // 左下角顶点
	0.5f, -0.5f, 0.5f,    0.0f, -1.0f, 0.0f,  // 右下角顶点
	0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,  // 右上角顶点
	-0.5f, -0.5f, 0.5f,   0.0f, -1.0f, 0.0f,  // 左下角顶点
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f,   // 左上角顶点
	0.5f, -0.5f, 0.5f,    0.0f, -1.0f, 0.0f,  // 右下角顶点
};
#pragma endregion 顶点数据

unsigned int VAO, VBO;
unsigned int VAO_cube, VBO_cube;
#pragma region 着色器源码
// flat、Phong顶点着色器源码
const char* vertexShaderSourceDefault = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    out vec3 FragPos;
    out vec3 Normal;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main()
    {
        FragPos = vec3(model * vec4(aPos, 1.0));
        Normal = mat3(transpose(inverse(model))) * aNormal;
        gl_Position = projection * view * vec4(FragPos, 1.0);
    }
)";
// Gouraud顶点着色器源码
const char* vertexShaderSourceGouraud = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    out vec3 FragPos;
    out vec3 Normal;
    out vec3 LightDir;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
    uniform vec3 lightPos;

    void main()
    {
        FragPos = vec3(model * vec4(aPos, 1.0));
        Normal = mat3(transpose(inverse(model))) * aNormal;
        LightDir = normalize(lightPos - FragPos);
        gl_Position = projection * view * vec4(FragPos, 1.0);
    }
)";
// flat 片段着色器源码
const char* fragmentShaderSourceFlat = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;

    uniform vec3 lightColor;
    uniform vec3 lightPos;
    uniform vec3 objectColor;
	uniform float diffLight;

    void main()
    {
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(Normal, lightDir), diffLight);
        vec3 diffuse = diff * lightColor * objectColor;

        FragColor = vec4(diffuse, 1.0);
    }
)";
// Phong 片段着色器源码
const char* fragmentShaderSourcePhong = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;
	
	uniform float ambientLight;
	uniform float mirrorReflectLight;
	uniform float diffLight;
    uniform vec3 lightColor;
    uniform vec3 lightPos;
    uniform vec3 objectColor;
    uniform vec3 viewPos;

    void main()
    {
        // Ambient
        vec3 ambient = lightColor *ambientLight ;  // 常量环境光照强度

        // Diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), diffLight);
        vec3 diffuse = diff * lightColor * objectColor;

        // Specular
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);  // 镜面反射高光强度
        vec3 specular = spec * lightColor;

        vec3 result = ambient + diffuse + specular;
        FragColor = vec4(result * objectColor, 1.0);
    }
)";
// Gouraud片段着色器源码
const char* fragmentShaderSourceGouraud = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;
    in vec3 LightDir;

    uniform vec3 lightColor;
    uniform vec3 objectColor;
	uniform float diffLight;

    void main()
    {
        // Diffuse
        vec3 norm = normalize(Normal);
        float diff = max(dot(norm, LightDir), diffLight);
        vec3 diffuse = diff * lightColor * objectColor;

        FragColor = vec4(diffuse, 1.0);
    }
)";
// 基本片元着色器，没有光照模型
const char* fragmentShaderSourceSimple = R"(
    #version 330 core
    out vec4 FragColor;

    uniform vec3 objectColor;

    void main()
    {
        FragColor = vec4(objectColor,1.0);
    }
)";
#pragma endregion 着色器源码
// 窗口大小
const GLuint WIDTH = 1920, HEIGHT = 1080;

// 初始视角
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);

//模型矩阵
glm::mat4 model;

//光源位置
glm::vec3 lightPos = glm::vec3(1.0f, 1.0f, 0.8f);
float ambientLight = 0.1f;
float mirrorReflectLight = 16.0f;
float diffLight = 0.1f;

// 鼠标相关变量
GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool firstMouse = true;
// 滚轮控制参数
GLfloat aspect = 45.0f;
GLfloat scrollSensitive = 2.0f;

// 键盘相关变量
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
bool keys[512];

// 记录上一帧的时间
float lastFrameTime = 0.0f;

// 摄像机移动速度
const float cameraSpeed = 2.5f;


//相机相关变量
glm::mat4 view = glm::mat4(1.0f);
glm::vec3 initialCameraPos = glm::vec3(0.0f, 0.0f, 3.0f);   // 相机初始位置
glm::vec3 initialCameraFront = glm::vec3(0.0f, 0.0f, -1.0f);  // 相机初始朝向
glm::vec3 initialCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);      // 相机初始上方向
glm::vec3 targetPos = glm::vec3(0.0f, 0.0f, 0.0f);
float cameraDistance = 10.0f;

//imgui显示相关参数
bool isShowImGui = false;
unsigned char* renderer = nullptr;
unsigned char* version = nullptr;

// 切换光照着色器
enum SHADER_TYPE
{
	Flat = 0x00,
	Phong = 0x01,
	Gouraud = 0x02,
};
//光照着色器选择
int shaderType = SHADER_TYPE::Flat;

// 鼠标移动回调函数
void mouseCallback(GLFWwindow* window, double xPos, double yPos)
{

	// 检查鼠标左键是否按下
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// 计算鼠标位置的偏移量
		double xOffset = xPos - lastX;
		double yOffset = lastY - yPos;
		lastX = xPos;
		lastY = yPos;

		// 设置旋转速度
		float rotationSpeed = 0.1f;

		// 计算旋转角度
		float angleX = xOffset * rotationSpeed;
		float angleY = yOffset * rotationSpeed;

		// 构建旋转矩阵
		glm::mat4 rotationMatrixX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotationMatrixY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotationMatrix = rotationMatrixX * rotationMatrixY;
		model = rotationMatrix* model ;
	}
	else
	{
		GLfloat xOffset = xPos - lastX;
		GLfloat yOffset = lastY - yPos;
		lastX = xPos;
		lastY = yPos;

		GLfloat sensitivity = 0.05f;
		xOffset *= sensitivity;
		yOffset *= sensitivity;

		yaw += xOffset;
		pitch += yOffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(front);
	}
}

// 滚轮回调函数
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	bool isFaster = isFaster = keys[GLFW_KEY_LEFT_ALT];
	if (keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_Z])
	{
		ambientLight += yOffset* scrollSensitive * (isFaster? 1 : 0.005);
	}
	else if ((keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_X]))
	{
		mirrorReflectLight += yOffset * scrollSensitive * (isFaster ? 1 : 0.05);
	}
	else if ((keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_C]))
	{
		diffLight += yOffset * scrollSensitive * (isFaster ? 1 : 0.005);
	}
	else
	{
		aspect -= yOffset * scrollSensitive;
	}
	if (ambientLight < 0.01f)ambientLight = 0.01f;
	if (mirrorReflectLight < 0.01f)mirrorReflectLight = 0.01f;
	if (diffLight < 0.01f)diffLight = 0.01f;
}
void objectMove()
{
	// 获取当前帧的时间
	float currentFrameTime = glfwGetTime();
	// 计算时间间隔
	float deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	// 速度乘以时间间隔，使移动速度平滑
	float velocity = cameraSpeed * deltaTime;
	// 按下WSAD键时改变摄像机位置
	if (keys[GLFW_KEY_LEFT_CONTROL])
	{
		if (keys[GLFW_KEY_W])
			lightPos.y += velocity;
		if (keys[GLFW_KEY_S])
			lightPos.y -= velocity;
		if (keys[GLFW_KEY_Q])
			lightPos.z += velocity;
		if (keys[GLFW_KEY_E])
			lightPos.z -= velocity;
		if (keys[GLFW_KEY_A])
			lightPos.x += velocity;
		if (keys[GLFW_KEY_D])
			lightPos.x -= velocity;
	}
	else {
		if (keys[GLFW_KEY_W])
			cameraPos += velocity * cameraFront;
		if (keys[GLFW_KEY_S])
			cameraPos -= velocity * cameraFront;
		if (keys[GLFW_KEY_A])
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
		if (keys[GLFW_KEY_D])
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
	}
	
}

// 键盘输入回调函数
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	//0.4f 为持久按下键的事件时间，可以防止按下一个键之后的误触。
	//此时间可能需要调整，根据不同的渲染环境。
	if (action == GLFW_PRESS)
	{
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		keys[key] = false;
	}
	if (key == GLFW_KEY_F2 && action == GLFW_PRESS)
	{
		isShowImGui = !isShowImGui;  // 切换ImGui的可见性状态
	}
	//变换不同的光照渲染方式
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		shaderType++;
		if (shaderType == 0x03)
		{
			shaderType = 0x00;
		}
	}
}
// 回调函数：渲染ImGui的内容
void ImGuiRender()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowBorderSize = 0.0f;
	style.WindowRounding = 0.0f;
	style.PopupBorderSize = 0.0f;
	style.PopupRounding = 0.0f;
	style.Alpha = 0.75f;
	// 渲染ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	// 在ImGui中渲染内容
	ImGui::SetWindowFontScale(2.0); // 设置字体缩放比例
	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::SetWindowSize(ImVec2(640, 480));
	switch (shaderType)
	{
	case Phong:
		ImGui::Text("Phong shader");
		break;
	case Gouraud:
		ImGui::Text("Gouraud shader");
		break;
	case Flat:
	default:
		ImGui::Text("Flat/Default shader");
		break;
	}
	if (renderer != nullptr)
	{
		ImGui::Text("%s", renderer);
	}
	if (version != nullptr)
	{
		ImGui::Text("OpenGL: %s", version);
	}
	GLint dedicatedMemory = 0;
	GLint totalMemory = 0;
	GLint availableMemory = 0;

#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX 0x9047
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX 0x9048
#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX 0x9049
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX 0x904A
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX 0x904B

#define GLEW_NVX_gpu_memory_info GLEW_GET_VAR(__GLEW_NVX_gpu_memory_info)

	glad_glGetIntegerv(GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX, &dedicatedMemory);
	glGetIntegerv(GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX, &totalMemory);
	glGetIntegerv(GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX, &availableMemory);

	float memoryUsage = (float)(totalMemory - availableMemory) / totalMemory * 100.0f;
	ImGui::Text("%.2f FPS, %.2fMB/%.2fMB", ImGui::GetIO().Framerate, dedicatedMemory /1024.0, totalMemory/1024.0);
	ImGui::Text("Camera: X:%.1f,Y:%.1f,Z:%.1f", cameraPos[0], cameraPos[1], cameraPos[2]);
	ImGui::Text("Perspective: X:%.2f,Y:%.2f,Z:%.2f", cameraFront[0], cameraFront[1], cameraFront[2]);
	ImGui::Text("Light: X:%.2f,Y:%.2f,Z:%.2f", lightPos[0], lightPos[1], lightPos[2]);
	ImGui::Text("Model: %+.1f,%+.1f,%+.1f,%+.1f", model[0][0], model[0][1], model[0][2], model[0][3]);
	ImGui::Text("       %+.1f,%+.1f,%+.1f,%+.1f", model[1][0], model[1][1], model[1][2], model[1][3]);
	ImGui::Text("       %+.1f,%+.1f,%+.1f,%+.1f", model[2][0], model[2][1], model[2][2], model[2][3]);
	ImGui::Text("       %+.1f,%+.1f,%+.1f,%+.1f", model[3][0], model[3][1], model[3][2], model[3][3]);

	if (keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_Z])
	{
		ImGui::Text("ambientLight=%.2f",ambientLight);
	}
	else if ((keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_X]))
	{
		ImGui::Text("mirrorReflectLight=%.1f", mirrorReflectLight);
	}
	else if ((keys[GLFW_KEY_LEFT_CONTROL] && keys[GLFW_KEY_C]))
	{
		ImGui::Text("diffLight=%.2f", diffLight);
	}

	// 完成ImGui的渲染
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// 编译着色器
unsigned int compileShader(unsigned int type, const char* source)
{
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	// 检查编译错误
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		printf("[-] Failed to compile shader...\n%s\n", infoLog);
	}

	return shader;
}

// 创建着色器程序
unsigned int createShaderProgram(const char* vertexShaderSource , const char* fragmentShaderSource)
{
	printf("[+] Compiling vertex shader...\n");
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	printf("[+] Compiling fragment shader...\n");
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// 检查链接错误
	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
		printf("[-] Failed to compile shader...\n%s\n", infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

int main()
{
	// 初始化 GLFW
	glfwInit();

	// 创建窗口
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Real Shading Dodecahedron", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	// 将窗口设置为当前上下文
	glfwMakeContextCurrent(window);

	// 初始化 GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 获取渲染设备信息

	renderer = (unsigned char*)glGetString(GL_RENDERER);
	version = (unsigned char*)glGetString(GL_VERSION);

	// 初始化ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	
	// 创建 VAO 和 VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// 绑定正十二面体
	// 绑定 VAO
	glBindVertexArray(VAO);

	// 绑定 VBO 并设置顶点数据
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// 解绑 VAO 和 VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// 创建着色器程序
	unsigned shaderProgram = 0;
	unsigned int FlatShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourceFlat);
	unsigned int PhongShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourcePhong);
	unsigned int GouraudShaderProgram = createShaderProgram(vertexShaderSourceGouraud, fragmentShaderSourceGouraud);
	unsigned int SimpleShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourceSimple);
	// 注册回调函数
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetScrollCallback(window, scrollCallback);
	// 隐藏并捕捉鼠标
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// 主循环



	model = glm::mat4(1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);
		objectMove();
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// 清空颜色缓冲和深度缓冲
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
		
		// 使用着色器程序
		switch (shaderType)
		{
		case Phong:
			glUseProgram(PhongShaderProgram);
			shaderProgram = PhongShaderProgram;
			break;
		case Gouraud:
			glUseProgram(GouraudShaderProgram);
			shaderProgram = GouraudShaderProgram;
			break;
		case Flat:
		default:
			glUseProgram(FlatShaderProgram);
			shaderProgram = FlatShaderProgram;
			break;
		}

		// 设置着色器中的 uniform 变量
		int objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
		int lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
		int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
		int modelLoc = glGetUniformLocation(shaderProgram, "model");
		int viewLoc = glGetUniformLocation(shaderProgram, "view");
		int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
		int viewPos = glGetUniformLocation(shaderProgram, "viewPos");
		int ambientLightLoc = glGetUniformLocation(shaderProgram, "ambientLight");
		int mirrorReflectLightLoc = glGetUniformLocation(shaderProgram, "diffLight");
		int diffLightLoc = glGetUniformLocation(shaderProgram, "diffLight");

		glUniform3f(objectColorLoc, 0.2f, 0.4f,0.2f);
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
		glUniform1f(ambientLightLoc, ambientLight);
		glUniform1f(mirrorReflectLightLoc, mirrorReflectLight);
		glUniform1f(diffLightLoc, diffLight);

		// 计算投影矩阵
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		float aspectRatio = static_cast<float>(width) / height;
		glm::mat4 projection = glm::perspective(glm::radians(aspect), aspectRatio, 0.1f, 100.0f);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// 更新相机矩阵
		// 计算视图矩阵
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3f(viewPos, cameraPos.x, cameraPos.y, cameraPos.z);

		// 计算模型矩阵
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// 绑定 VAO
		glBindVertexArray(VAO);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// 绘制正十二面体

		//启用深度测试
		glEnable(GL_DEPTH_TEST);
		//启用面剔除
		glEnable(GL_CULL_FACE);
		//启用多重采样抗锯齿（可选）
		glfwWindowHint(GLFW_SAMPLES, 16);
		glEnable(GL_MULTISAMPLE);
		glDrawArrays(GL_TRIANGLES, 0, 108);

		// 解绑 VAO
		glBindVertexArray(0);

		// 渲染第二个正方体
		//glUseProgram(SimpleShaderProgram);
		glm::mat4 model2 = glm::mat4(1.0f);
		model2 = glm::translate(model2, lightPos); 
		model2 = glm::scale(model2, glm::vec3(0.1f)); // 缩放模型
		;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model2));
		glUniform3f(glGetUniformLocation(shaderProgram, "objectColor"), 0.1f,0.1f,0.1f);
		glBindVertexArray(VAO);

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		//启用多重采样抗锯齿（可选）
		glDrawArrays(GL_LINE_STRIP, 108, 36);

		// 解绑 VAO
		glBindVertexArray(0);
		if (isShowImGui)
		{
			ImGuiRender();
		}

		// 交换缓冲并检查事件
		glfwSwapBuffers(window);


	}

	// 清理资源
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// 清理ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// 终止 GLFW
	glfwTerminate();

	return 0;
}
