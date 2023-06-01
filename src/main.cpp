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
extern "C" {
	_declspec(dllexport) int NvOptimusEnablement = 0x00000001;
}
#pragma region ��������

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
};

#pragma endregion ��������

unsigned int VAO, VBO;
#pragma region ��ɫ��Դ��
// flat��Phong������ɫ��Դ��
const char* vertexShaderSourceFlatPhong = R"(
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
// Gouraud������ɫ��Դ��
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
// flat Ƭ����ɫ��Դ��
const char* fragmentShaderSourceFlat = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;

    uniform vec3 lightColor;
    uniform vec3 lightPos;
    uniform vec3 objectColor;

    void main()
    {
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(Normal, lightDir), 0.2);
        vec3 diffuse = diff * lightColor * objectColor;

        FragColor = vec4(diffuse, 1.0);
    }
)";
// Phong Ƭ����ɫ��Դ��
const char* fragmentShaderSourcePhong = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;

    uniform vec3 lightColor;
    uniform vec3 lightPos;
    uniform vec3 objectColor;
    uniform vec3 viewPos;

    void main()
    {
        // Ambient
        vec3 ambient = lightColor * 0.1;  // ������������ǿ��

        // Diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor * objectColor;

        // Specular
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16.0);  // ���淴��߹�ǿ��
        vec3 specular = spec * lightColor;

        vec3 result = ambient + diffuse + specular;
        FragColor = vec4(result * objectColor, 1.0);
    }
)";
// GouraudƬ����ɫ��Դ��
const char* fragmentShaderSourceGouraud = R"(
    #version 330 core
    out vec4 FragColor;

    in vec3 FragPos;
    in vec3 Normal;
    in vec3 LightDir;

    uniform vec3 lightColor;
    uniform vec3 objectColor;

    void main()
    {
        // Diffuse
        vec3 norm = normalize(Normal);
        float diff = max(dot(norm, LightDir), 0.2);
        vec3 diffuse = diff * lightColor * objectColor;

        FragColor = vec4(diffuse, 1.0);
    }
)";
#pragma endregion ��ɫ��Դ��
// ���ڴ�С
const GLuint WIDTH = 1920, HEIGHT = 1080;

// ��ʼ�ӽ�
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);

// �����ر���
GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool firstMouse = true;

// ������ر���
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
// ������ƶ��ٶ�
const float cameraSpeed = 2.5f;
// ��¼��һ֡��ʱ��
float lastFrameTime = 0.0f;

//�����ر���
int viewLoc = -255;
glm::mat4 view;
glm::vec3 initialCameraPos = glm::vec3(0.0f, 0.0f, 3.0f);   // �����ʼλ��
glm::vec3 initialCameraFront = glm::vec3(0.0f, 0.0f, -1.0f);  // �����ʼ����
glm::vec3 initialCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);      // �����ʼ�Ϸ���
glm::vec3 targetPos = glm::vec3(0.0f, 0.0f, 0.0f);
float cameraDistance = 10.0f;

//imgui��ʾ
bool isShowImGui = false;
unsigned char* renderer = nullptr;
unsigned char* version = nullptr;

// �л�������ɫ��
enum SHADER_TYPE
{
	Flat = 0x00,
	Phong = 0x01,
	Gouraud = 0x02
};
//������ɫ��ѡ��
int shaderType = SHADER_TYPE::Flat;


// ����ƶ��ص�����
void mouseCallback(GLFWwindow* window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}
	// ����������Ƿ���
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && viewLoc != -255)
	{
		// �������λ�õ�ƫ����
		double xOffset = xPos - lastX;
		double yOffset = lastY - yPos;
		lastX = xPos;
		lastY = yPos;

		// ������ת�ٶ�
		float rotationSpeed = 0.1f;

		// ������ת�Ƕ�
		float angleX = xOffset * rotationSpeed;
		float angleY = yOffset * rotationSpeed;

		// ������ת����
		glm::mat4 rotationMatrixX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotationMatrixY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotationMatrix = rotationMatrixX * rotationMatrixY;

		// �������λ����ԭ����ת
		glm::vec4 cameraPos4 = glm::vec4(cameraPos, 1.0f);
		glm::vec4 rotatedCameraPos4 = rotationMatrix * cameraPos4;
		cameraPos = glm::vec3(rotatedCameraPos4);

		// �����������
		view = glm::lookAt(cameraPos, glm::vec3(0.0f), cameraUp);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
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

// ���ֻص�����
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	// ���ݹ��ֵ�ƫ����������������
	float scaleFactor = 1.0f + yOffset * 0.1f;

	// ���������λ����ʵ������Ч��
	cameraPos *= scaleFactor;

}
// ��������ص�����
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	// ��ȡ��ǰ֡��ʱ��
	float currentFrameTime = glfwGetTime();
	// ����ʱ����
	float deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	//printf("delta time:%lf\n", deltaTime);
	// �ٶȳ���ʱ������ʹ�ƶ��ٶ�ƽ��
	float velocity = cameraSpeed * deltaTime;

	//0.4f Ϊ�־ð��¼����¼�ʱ�䣬���Է�ֹ����һ����֮����󴥡�
	//��ʱ�������Ҫ���������ݲ�ͬ����Ⱦ������
	if (deltaTime <= 0.4f)
	{
		// ����WSAD��ʱ�ı������λ��
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPos += velocity * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPos -= velocity * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
	}
	if (key == GLFW_KEY_F2 && action == GLFW_PRESS)
	{
		isShowImGui = !isShowImGui;  // �л�ImGui�Ŀɼ���״̬
	}
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		shaderType++;
		if (shaderType == 0x03)
		{
			shaderType = 0x00;
		}
	}
}
// �ص���������ȾImGui������
void ImGuiRender()
{
	// ��ȾImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// ��ImGui����Ⱦ����
	ImGui::SetWindowFontScale(2.0); // �����������ű���
	ImGui::SetNextWindowPos(ImVec2(10, 10));
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
		ImGui::Text("%s", version);
	}
	ImGui::Text("Frame Rate: %.1f FPS", ImGui::GetIO().Framerate);
	ImGui::Text("X:%.1f,Y:%.1f,Z:%.1f", cameraPos[0], cameraPos[1], cameraPos[2]);
	// ���ImGui����Ⱦ
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// ������ɫ��
unsigned int compileShader(unsigned int type, const char* source)
{
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	// ���������
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cout << "Shader compilation failed:\n" << infoLog << std::endl;
	}

	return shader;
}

// ������ɫ������
unsigned int createShaderProgram(const char* vertexShaderSource , const char* fragmentShaderSource)
{
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// ������Ӵ���
	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
		std::cout << "Shader program linking failed:\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

int main()
{
	// ��ʼ�� GLFW
	glfwInit();

	// ��������
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Real Shading Dodecahedron", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	// ����������Ϊ��ǰ������
	glfwMakeContextCurrent(window);

	// ��ʼ�� GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ��ȡ��Ⱦ�豸��Ϣ

	renderer = (unsigned char*)glGetString(GL_RENDERER);
	version = (unsigned char*)glGetString(GL_VERSION);

	// ��ʼ��ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");

	// ���� VAO �� VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// �� VAO
	glBindVertexArray(VAO);

	// �� VBO �����ö�������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// ��� VAO �� VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// ������ɫ������
	unsigned shaderProgram = 0;
	unsigned int FlatShaderProgram = createShaderProgram(vertexShaderSourceFlatPhong, fragmentShaderSourceFlat);
	unsigned int PhongShaderProgram = createShaderProgram(vertexShaderSourceFlatPhong, fragmentShaderSourcePhong);
	unsigned int GouraudShaderProgram = createShaderProgram(vertexShaderSourceGouraud, fragmentShaderSourceGouraud);
	// ע��ص�����
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetScrollCallback(window, scrollCallback);
	// ���ز���׽���
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// ��ѭ��

	//������Ȳ���
	glEnable(GL_DEPTH_TEST);
	//�������޳�
	glEnable(GL_CULL_FACE);
	//���ö��ز�������ݣ���ѡ��
	glfwWindowHint(GLFW_SAMPLES, 16);
	glEnable(GL_MULTISAMPLE);

	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// �����ɫ�������Ȼ���
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ʹ����ɫ������
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

		// ������ɫ���е� uniform ����
		int objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
		int lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
		int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
		int modelLoc = glGetUniformLocation(shaderProgram, "model");
		viewLoc = glGetUniformLocation(shaderProgram, "view");
		int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
		int viewPos = glGetUniformLocation(shaderProgram, "viewPos");
		glUniform3f(objectColorLoc, 0.2f, 0.4f,0.2f);
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
		glUniform3f(lightPosLoc, 16.0f, 16.0f, 16.0f);

		// ����ͶӰ����
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		float aspectRatio = static_cast<float>(width) / height;
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// �����������
		// ������ͼ����
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3f(viewPos, cameraPos.x, cameraPos.y, cameraPos.z);

		// ����ģ�;���
		glm::mat4 model = glm::mat4(1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// �� VAO
		glBindVertexArray(VAO);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// ����������
		glDrawArrays(GL_TRIANGLES, 0, 108);


		// ��� VAO
		glBindVertexArray(0);

		if (isShowImGui)
		{
			ImGuiRender();
		}

		// �������岢����¼�
		glfwSwapBuffers(window);
		glfwPollEvents();


	}

	// ������Դ
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// ����ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// ��ֹ GLFW
	glfwTerminate();

	return 0;
}
