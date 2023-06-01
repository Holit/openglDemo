#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
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
unsigned int VAO, VBO;

// ������ɫ��Դ��
const char* vertexShaderSource = R"(
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

// Ƭ����ɫ��Դ��
const char* fragmentShaderSource = R"(
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
// ���ڴ�С
const GLuint WIDTH = 1024, HEIGHT = 768;

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

// ����ƶ��ص�����
void mouseCallback(GLFWwindow* window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

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

// ��������ص�����
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	GLfloat cameraSpeed = 125.0f * deltaTime;
	if (key == GLFW_KEY_W)
		cameraPos += cameraSpeed * cameraFront;
	if (key == GLFW_KEY_S)
		cameraPos -= cameraSpeed * cameraFront;
	if (key == GLFW_KEY_A)
		cameraPos -= cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
	if (key == GLFW_KEY_D)
		cameraPos += cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
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
unsigned int createShaderProgram()
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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Flat Shading Cube", nullptr, nullptr);
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
	unsigned int shaderProgram = createShaderProgram();
	// ע��ص�����
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetKeyCallback(window, keyCallback);

	// ���ز���׽���
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// ��ѭ��
	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glEnable(GL_DEPTH_TEST); 
		// �����ɫ�������Ȼ���
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ʹ����ɫ������
		glUseProgram(shaderProgram);

		// ������ɫ���е� uniform ����
		int objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
		int lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
		int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
		int modelLoc = glGetUniformLocation(shaderProgram, "model");
		int viewLoc = glGetUniformLocation(shaderProgram, "view");
		int projectionLoc = glGetUniformLocation(shaderProgram, "projection");

		glUniform3f(objectColorLoc, 0.2f, 0.4f,0.2f);
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
		glUniform3f(lightPosLoc, 16.0f, 16.0f, 16.0f);

		// ����ͶӰ����
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		float aspectRatio = static_cast<float>(width) / height;
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glfwPollEvents();
		glm::mat4 view;
		// �����������
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		// ������ͼ����
		//view = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		// ����ģ�;���
		glm::mat4 model = glm::mat4(1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// �� VAO
		glBindVertexArray(VAO);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// ����������
		glDrawArrays(GL_TRIANGLES, 0, 108);

		 
		//glBindVertexArray(VAO);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glColor3f(1.0, 1.0, 1.0);  // �����߿����ɫΪ��ɫ
		//glLineWidth(2.0);  // �����߿�
		//// ����������
		//glDrawArrays(GL_TRIANGLES, 0, 108);
		//glEnd();

		// ��� VAO
		glBindVertexArray(0);

		// �������岢����¼�
		glfwSwapBuffers(window);

	}

	// ������Դ
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// ��ֹ GLFW
	glfwTerminate();

	return 0;
}
