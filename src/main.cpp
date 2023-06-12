
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
#include <vector>
extern "C" {
	_declspec(dllexport) int NvOptimusEnablement = 0x00000001;
}
constexpr float PI = 3.1415926535897f;
#pragma region ��������
//��ʮ������Ķ���
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

	// λ������       // ��������
	// ǰ��
	-0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  // ���½Ƕ���
	0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,  // ���½Ƕ���
	0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,  // ���ϽǶ���

	-0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  // ���½Ƕ���
	-0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 1.0f,  // ���ϽǶ���
	0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,  // ���ϽǶ���

	// ����
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  // ���½Ƕ���
	0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,  // ���½Ƕ���
	0.5f, 0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  // ���ϽǶ���

	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  // ���½Ƕ���
	-0.5f, 0.5f, -0.5f,   0.0f, 0.0f, -1.0f,  // ���ϽǶ���
	0.5f, 0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  // ���ϽǶ���

	// �����
	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	-0.5f, -0.5f, 0.5f,   -1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	-0.5f, 0.5f, 0.5f,    -1.0f, 0.0f, 0.0f,  // ���ϽǶ���

	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	-0.5f, 0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,  // ���ϽǶ���
	-0.5f, 0.5f, 0.5f,    -1.0f, 0.0f, 0.0f,  // ���ϽǶ���

	// �Ҳ���
	0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	0.5f, -0.5f, 0.5f,    1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	0.5f, 0.5f, 0.5f,     1.0f, 0.0f, 0.0f,  // ���ϽǶ���

	0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,  // ���½Ƕ���
	0.5f, 0.5f, -0.5f,    1.0f, 0.0f, 0.0f,  // ���ϽǶ���
	0.5f, 0.5f, 0.5f,     1.0f, 0.0f, 0.0f,  // ���ϽǶ���

	// ������
	-0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,  // ���½Ƕ���
	0.5f, 0.5f, 0.5f,     0.0f, 1.0f, 0.0f,  // ���½Ƕ���
	0.5f, 0.5f, -0.5f,    0.0f, 1.0f, 0.0f,  // ���ϽǶ���

	-0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,  // ���½Ƕ���
	-0.5f, 0.5f, -0.5f,   0.0f, 1.0f, 0.0f,  // ���ϽǶ���
	0.5f, 0.5f, -0.5f,    0.0f, 1.0f, 0.0f,  // ���ϽǶ���

	// �ײ���
	-0.5f, -0.5f, 0.5f,   0.0f, -1.0f, 0.0f,  // ���½Ƕ���
	0.5f, -0.5f, 0.5f,    0.0f, -1.0f, 0.0f,  // ���½Ƕ���
	0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,  // ���ϽǶ���
	-0.5f, -0.5f, 0.5f,   0.0f, -1.0f, 0.0f,  // ���½Ƕ���
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f,   // ���ϽǶ���
	0.5f, -0.5f, 0.5f,    0.0f, -1.0f, 0.0f,  // ���½Ƕ���
};
//���嶥��
std::vector<float> sphereVertices;
std::vector<int> sphereIndices;
std::vector<float> sphereNormal;
//������ݻ��ֳ�50*50������
const int Y_SEGMENTS = 50;
const int X_SEGMENTS = 50;
void calculateSphereData()
{
	/*2-�������嶥��*/
//������Ķ���
	for (int y = 0; y <= Y_SEGMENTS; y++)
	{
		for (int x = 0; x <= X_SEGMENTS; x++)
		{
			float xSegment = (float)x / (float)X_SEGMENTS;
			float ySegment = (float)y / (float)Y_SEGMENTS;
			float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
			float yPos = std::cos(ySegment * PI);
			float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
			sphereVertices.push_back(xPos);
			sphereVertices.push_back(yPos);
			sphereVertices.push_back(zPos);
		}
	}

	//�������Indices
	for (int i = 0; i < Y_SEGMENTS; i++)
	{
		for (int j = 0; j < X_SEGMENTS; j++)
		{
			sphereIndices.push_back(i * (X_SEGMENTS + 1) + j);
			sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j);
			sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j + 1);

			sphereIndices.push_back(i * (X_SEGMENTS + 1) + j);
			sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j + 1);
			sphereIndices.push_back(i * (X_SEGMENTS + 1) + j + 1);
			int index1 = i * (X_SEGMENTS + 1) + j;
			int index2 = (i + 1) * (X_SEGMENTS + 1) + j;
			int index3 = (i + 1) * (X_SEGMENTS + 1) + j + 1;
			int index4 = i * (X_SEGMENTS + 1) + j + 1;

			// ������ķ�����
			glm::vec3 vertex1(sphereVertices[index1 * 3], sphereVertices[index1 * 3 + 1], sphereVertices[index1 * 3 + 2]);
			glm::vec3 vertex2(sphereVertices[index2 * 3], sphereVertices[index2 * 3 + 1], sphereVertices[index2 * 3 + 2]);
			glm::vec3 vertex3(sphereVertices[index3 * 3], sphereVertices[index3 * 3 + 1], sphereVertices[index3 * 3 + 2]);
			glm::vec3 vertex4(sphereVertices[index4 * 3], sphereVertices[index4 * 3 + 1], sphereVertices[index4 * 3 + 2]);

			glm::vec3 normal1 = glm::normalize(glm::cross(vertex2 - vertex1, vertex3 - vertex1));

			sphereNormal.push_back(normal1.x);
			sphereNormal.push_back(normal1.y);
			sphereNormal.push_back(normal1.z);
			sphereNormal.push_back(normal1.x);
			sphereNormal.push_back(normal1.y);
			sphereNormal.push_back(normal1.z);

		}
	}
}
#pragma endregion ��������

unsigned int VAO, VBO;
unsigned int VAO_sphere, VBO_sphere,EBO_sphere;
#pragma region ��ɫ��Դ��
// flat��Phong������ɫ��Դ��
const char* vertexShaderSourceDefault = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;       // ����λ������
    layout (location = 1) in vec3 aNormal;    // ���㷨������

    out vec3 FragPos;   // Ƭ��λ������
    out vec3 Normal;    // ��������

    uniform mat4 model;         // ģ�;���
    uniform mat4 view;          // ��ͼ����
    uniform mat4 projection;    // ͶӰ����

    void main()
    {
        FragPos = vec3(model * vec4(aPos, 1.0));    // ������λ��ת������������ϵ
        Normal = mat3(transpose(inverse(model))) * aNormal;    // �����㷨��ת������������ϵ
        gl_Position = projection * view * vec4(FragPos, 1.0);    // �������յĲü��ռ�����
    }
)";

// Gouraud������ɫ��Դ��
// ������λ�úͷ���ת������������ϵ�����������յĲü��ռ����ꡣͬʱ���������˶��㵽��Դ�ķ���������
// Gouraud������ɫ��Դ��
const char* vertexShaderSourceGouraud = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;       // ����λ������
    layout (location = 1) in vec3 aNormal;    // ���㷨������

    out vec3 FragPos;   // Ƭ��λ������
    out vec3 Normal;    // ��������
    out vec3 LightDir;  // ��Դ��������

    uniform mat4 model;         // ģ�;���
    uniform mat4 view;          // ��ͼ����
    uniform mat4 projection;    // ͶӰ����
    uniform vec3 lightPos;      // ��Դλ��

    void main()
    {
        FragPos = vec3(model * vec4(aPos, 1.0));    // ������λ��ת������������ϵ
        Normal = mat3(transpose(inverse(model))) * aNormal;    // �����㷨��ת������������ϵ
        LightDir = normalize(lightPos - FragPos);    // �����Դ���������������㵽��Դ�ķ���
        gl_Position = projection * view * vec4(FragPos, 1.0);    // �������յĲü��ռ�����
    }
)";

// flat Ƭ����ɫ��Դ��
const char* fragmentShaderSourceFlat = R"(
    #version 330 core
    out vec4 FragColor;    // ���Ƭ����ɫ

    in vec3 FragPos;       // Ƭ��λ������
    in vec3 Normal;        // ��������

    uniform vec3 lightColor;    // ��Դ��ɫ
    uniform vec3 lightPos;      // ��Դλ��
    uniform vec3 objectColor;   // ������ɫ
    uniform float diffLight;    // ���������ǿ��

    void main()
    {
        vec3 lightDir = normalize(lightPos - FragPos);    // �����Դ������������Ƭ�ε���Դ�ķ���
        float diff = max(dot(Normal, lightDir), diffLight);    // �������������ǿ��
        vec3 diffuse = diff * lightColor * objectColor;    // ������������յ���ɫ

        FragColor = vec4(diffuse, 1.0);    // �������Ƭ����ɫ
    }
)";

// Phong Ƭ����ɫ��Դ��
const char* fragmentShaderSourcePhong = R"(
    #version 330 core
    out vec4 FragColor;    // ���Ƭ����ɫ

    in vec3 FragPos;       // Ƭ��λ������
    in vec3 Normal;        // ��������
	
	uniform float ambientLight;        // ��������ǿ��
	uniform float mirrorReflectLight;  // ���淴�����ǿ��
	uniform float diffLight;           // ���������ǿ��
    uniform vec3 lightColor;           // ��Դ��ɫ
    uniform vec3 lightPos;             // ��Դλ��
    uniform vec3 objectColor;          // ������ɫ
    uniform vec3 viewPos;              // �ӵ�λ��

    void main()
    {
        // ��������
        vec3 ambient = lightColor * ambientLight;

        // ���������
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), diffLight);
        vec3 diffuse = diff * lightColor * objectColor;

        // ���淴�����
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
        vec3 specular = spec * lightColor * mirrorReflectLight;

        vec3 result = ambient + diffuse + specular;
        FragColor = vec4(result * objectColor, 1.0);    // �������Ƭ����ɫ
    }
)";
// GouraudƬ����ɫ��Դ��
const char* fragmentShaderSourceGouraud = R"(
    #version 330 core
    out vec4 FragColor;    // ���Ƭ����ɫ

    in vec3 FragPos;       // Ƭ��λ������
    in vec3 Normal;        // ��������
    in vec3 LightDir;      // ��Դ��������

    uniform vec3 lightColor;    // ��Դ��ɫ
    uniform vec3 objectColor;   // ������ɫ
	uniform float diffLight;    // ���������ǿ��

    void main()
    {
        // ���������
        vec3 norm = normalize(Normal);
        float diff = max(dot(norm, LightDir), diffLight);
        vec3 diffuse = diff * lightColor * objectColor;

        FragColor = vec4(diffuse, 1.0);    // �������Ƭ����ɫ
    }
)";

// ����ƬԪ��ɫ����û�й���ģ��
const char* fragmentShaderSourceSimple = R"(
    #version 330 core
    out vec4 FragColor;

    uniform vec3 objectColor;

    void main()
    {
        FragColor = vec4(objectColor,1.0);
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

//ģ�;���
glm::mat4 model;

//��Դλ��
glm::vec3 lightPos = glm::vec3(1.0f, 1.0f, 0.8f);
float ambientLight = 0.1f;
float mirrorReflectLight = 16.0f;
float diffLight = 0.1f;

// �����ر���
GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool firstMouse = true;
// ���ֿ��Ʋ���
GLfloat aspect = 45.0f;
GLfloat scrollSensitive = 2.0f;

// ������ر���
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
bool keys[512];

// ��¼��һ֡��ʱ��
float lastFrameTime = 0.0f;

// ������ƶ��ٶ�
const float cameraSpeed = 2.5f;


//�����ر���
glm::mat4 view = glm::mat4(1.0f);
glm::vec3 initialCameraPos = glm::vec3(0.0f, 0.0f, 3.0f);   // �����ʼλ��
glm::vec3 initialCameraFront = glm::vec3(0.0f, 0.0f, -1.0f);  // �����ʼ����
glm::vec3 initialCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);      // �����ʼ�Ϸ���
glm::vec3 targetPos = glm::vec3(0.0f, 0.0f, 0.0f);
float cameraDistance = 10.0f;

//imgui��ʾ��ز���
bool isShowImGui = false;
unsigned char* renderer = nullptr;
unsigned char* version = nullptr;

// �л�������ɫ��
enum SHADER_TYPE
{
	Flat = 0x00,
	Phong = 0x01,
	Gouraud = 0x02,
};
//������ɫ��ѡ��
int shaderType = SHADER_TYPE::Flat;

// ����ƶ��ص�����
/*
* ������������ʱ����������λ��ƫ�Ƽ�����ת�Ƕȣ���������ת��������תģ�͡�
  ��������û�а���ʱ����������λ��ƫ�Ƽ��������ƫ���Ǻ͸����ǣ�Ȼ�������Щ�Ƕȼ��������ǰ����������
*/
void mouseCallback(GLFWwindow* window, double xPos, double yPos)
{

	// ����������Ƿ���
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
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

// ���ֻص�����
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
	// ��ȡ��ǰ֡��ʱ��
	float currentFrameTime = glfwGetTime();
	// ����ʱ����
	float deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	// �ٶȳ���ʱ������ʹ�ƶ��ٶ�ƽ��
	float velocity = cameraSpeed * deltaTime;
	// ����WSAD��ʱ�ı������λ��
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

// ��������ص�����
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	//0.4f Ϊ�־ð��¼����¼�ʱ�䣬���Է�ֹ����һ����֮����󴥡�
	//��ʱ�������Ҫ���������ݲ�ͬ����Ⱦ������
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
		isShowImGui = !isShowImGui;  // �л�ImGui�Ŀɼ���״̬
	}
	//�任��ͬ�Ĺ�����Ⱦ��ʽ
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
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowBorderSize = 0.0f;
	style.WindowRounding = 0.0f;
	style.PopupBorderSize = 0.0f;
	style.PopupRounding = 0.0f;
	style.Alpha = 0.75f;
	// ��ȾImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	// ��ImGui����Ⱦ����
	ImGui::SetWindowFontScale(2.0); // �����������ű���
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
		printf("[-] Failed to compile shader...\n%s\n", infoLog);
	}

	return shader;
}

// ������ɫ������
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

	// ������Ӵ���
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
	
	calculateSphereData();

	// ���� VAO �� VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// ����ʮ������
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

	// �������
	// ���� VAO �� VBO
	glGenVertexArrays(1, &VAO_sphere);
	glGenBuffers(1, &VBO_sphere);
	// ����ʮ������
	// �� VAO
	glBindVertexArray(VAO_sphere);

	// �� VBO �����ö�������
	glBindBuffer(GL_ARRAY_BUFFER, VBO_sphere);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sphereVertices.size(), &sphereVertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &EBO_sphere);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_sphere);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphereIndices.size() * sizeof(int), &sphereIndices[0], GL_STATIC_DRAW);

	// ���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sphereNormal.size(), &sphereNormal[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(1);
	// ��� VAO �� VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	// ������ɫ������
	unsigned shaderProgram = 0;
	unsigned int FlatShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourceFlat);
	unsigned int PhongShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourcePhong);
	unsigned int GouraudShaderProgram = createShaderProgram(vertexShaderSourceGouraud, fragmentShaderSourceGouraud);
	unsigned int SimpleShaderProgram = createShaderProgram(vertexShaderSourceDefault, fragmentShaderSourceSimple);
	// ע��ص�����
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetScrollCallback(window, scrollCallback);
	// ���ز���׽���
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// ��ѭ��



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

		// �����ɫ�������Ȼ���
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
		
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

		// ����ͶӰ����
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		float aspectRatio = static_cast<float>(width) / height;
		glm::mat4 projection = glm::perspective(glm::radians(aspect), aspectRatio, 0.1f, 100.0f);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// �����������
		// ������ͼ����
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3f(viewPos, cameraPos.x, cameraPos.y, cameraPos.z);

		// ����ģ�;���
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// �� VAO
		glBindVertexArray(VAO);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// ������ʮ������

		//������Ȳ���
		glEnable(GL_DEPTH_TEST);
		//�������޳�
		glEnable(GL_CULL_FACE);
		//���ö��ز�������ݣ���ѡ��
		glfwWindowHint(GLFW_SAMPLES, 16);
		glEnable(GL_MULTISAMPLE);
		
		glDrawArrays(GL_TRIANGLES, 0, 108);
		//glLineWidth(16.0f);
		//glDrawArrays(GL_LINE_STRIP, 0, 108);

		// ��� VAO
		glBindVertexArray(0);

		// ��Ⱦ�ڶ���������
		//glUseProgram(SimpleShaderProgram);
		glm::mat4 model2 = glm::mat4(1.0f);
		model2 = glm::translate(model2, lightPos); 
		model2 = glm::scale(model2, glm::vec3(0.1f)); // ����ģ��
		;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model2));
		glUniform3f(glGetUniformLocation(shaderProgram, "objectColor"), 0.1f,0.1f,0.1f);
		glBindVertexArray(VAO);

		glDrawArrays(GL_LINE_STRIP, 108, 36);

		// ��� VAO
		glBindVertexArray(0);

		//��������
		//������Ȳ���
		glEnable(GL_DEPTH_TEST);
		//�������޳�
		glEnable(GL_CULL_FACE);
		//���ö��ز�������ݣ���ѡ��
		glfwWindowHint(GLFW_SAMPLES, 16);
		glEnable(GL_MULTISAMPLE);

		glBindVertexArray(VAO_sphere);

		glm::mat4 model3 = glm::mat4(1.0f);
		model3 = glm::translate(model3, glm::vec3(-2.0f));
		model3 = glm::scale(model3, glm::vec3(1.0f)); // ����ģ��

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model3));
		glUniform3f(glGetUniformLocation(shaderProgram, "objectColor"), 0.5f, 0.7f, 0.3f);
		glDrawElements(GL_TRIANGLES, X_SEGMENTS * Y_SEGMENTS * 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		if (isShowImGui)
		{
			ImGuiRender();
		}

		// �������岢����¼�
		glfwSwapBuffers(window);


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
