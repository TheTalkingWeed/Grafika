#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

static int WIN_WIDTH = 600;
static int WIN_HEIGHT = 600;

float colorWhite[3] = { 1.0, 1.0, 1.0 };

float vertices[] = {
		-0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		-0.5f,  0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f, 

		-0.5f, -0.5f,  0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 
		-0.5f, -0.5f,  0.5f, 

		-0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f, -0.5f,  
		-0.5f, -0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f, 
		-0.5f, -0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 

		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 

		-0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f, -0.5f,  0.5f, 
		-0.5f, -0.5f,  0.5f, 
		-0.5f, -0.5f, -0.5f, 

		-0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f, -0.5f, 
};

float vertices_up[] = {
		-0.5f, -0.5f,  1.5f,
		 0.5f, -0.5f,  1.5f,
		 0.5f,  0.5f,  1.5f,
		 0.5f,  0.5f,  1.5f,
		-0.5f,  0.5f,  1.5f,
		-0.5f, -0.5f,  1.5f,

		-0.5f, -0.5f,  2.5f,
		 0.5f, -0.5f,  2.5f,
		 0.5f,  0.5f,  2.5f,
		 0.5f,  0.5f,  2.5f,
		-0.5f,  0.5f,  2.5f,
		-0.5f, -0.5f,  2.5f,

		-0.5f,  0.5f,  2.5f,
		-0.5f,  0.5f,  1.5f,
		-0.5f, -0.5f,  1.5f,
		-0.5f, -0.5f,  1.5f,
		-0.5f, -0.5f,  2.5f,
		-0.5f,  0.5f,  2.5f,

		 0.5f,  0.5f,  2.5f,
		 0.5f,  0.5f,  1.5f,
		 0.5f, -0.5f,  1.5f,
		 0.5f, -0.5f,  1.5f,
		 0.5f, -0.5f,  2.5f,
		 0.5f,  0.5f,  2.5f,

		-0.5f, -0.5f,  1.5f,
		 0.5f, -0.5f,  1.5f,
		 0.5f, -0.5f,  2.5f,
		 0.5f, -0.5f,  2.5f,
		-0.5f, -0.5f,  2.5f,
		-0.5f, -0.5f,  1.5f,

		-0.5f,  0.5f,  1.5f,
		 0.5f,  0.5f,  1.5f,
		 0.5f,  0.5f,  2.5f,
		 0.5f,  0.5f,  2.5f,
		-0.5f,  0.5f,  2.5f,
		-0.5f,  0.5f,  1.5f,
};

float vertices_down[] = {
		-0.5f, -0.5f, -1.5f,
		 0.5f, -0.5f, -1.5f,
		 0.5f,  0.5f, -1.5f,
		 0.5f,  0.5f, -1.5f,
		-0.5f,  0.5f, -1.5f,
		-0.5f, -0.5f, -1.5f,

		-0.5f, -0.5f, -2.5f,
		 0.5f, -0.5f, -2.5f,
		 0.5f,  0.5f, -2.5f,
		 0.5f,  0.5f, -2.5f,
		-0.5f,  0.5f, -2.5f,
		-0.5f, -0.5f, -2.5f,

		-0.5f,  0.5f, -2.5f,
		-0.5f,  0.5f, -1.5f,
		-0.5f, -0.5f, -1.5f,
		-0.5f, -0.5f, -1.5f,
		-0.5f, -0.5f, -2.5f,
		-0.5f,  0.5f, -2.5f,

		 0.5f,  0.5f, -2.5f,
		 0.5f,  0.5f, -1.5f,
		 0.5f, -0.5f, -1.5f,
		 0.5f, -0.5f, -1.5f,
		 0.5f, -0.5f, -2.5f,
		 0.5f,  0.5f, -2.5f,

		-0.5f, -0.5f, -1.5f,
		 0.5f, -0.5f, -1.5f,
		 0.5f, -0.5f, -2.5f,
		 0.5f, -0.5f, -2.5f,
		-0.5f, -0.5f, -2.5f,
		-0.5f, -0.5f, -1.5f,

		-0.5f,  0.5f, -1.5f,
		 0.5f,  0.5f, -1.5f,
		 0.5f,  0.5f, -2.5f,
		 0.5f,  0.5f, -2.5f,
		-0.5f,  0.5f, -2.5f,
		-0.5f,  0.5f, -1.5f,
};


/* Vertex buffer objektum �s vertex array objektum az adatt�rol�shoz.*/
GLuint VBO;
GLuint VAO;
GLuint VBO1;
GLuint VAO1;
GLuint VBO2;
GLuint VAO2;

float r = 8.0f;
float radian = 0.0f;

bool UP;
bool DOWN;
bool LEFT;
bool RIGHT;
bool W;
bool S;

GLuint renderingProgram;

glm::vec3 cameraPos = glm::vec3(r, 0.0f, 0.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
glm::mat4 view, projection = glm::perspective(glm::radians(55.0f), (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f);


bool checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		cout << "glError: " << glErr << endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

void printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "Shader Info Log: " << log << endl;
		free(log);
	}
}

void printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << "Program Info Log: " << log << endl;
		free(log);
	}
}

string readShaderSource(const char* filePath) {
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";

	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

GLuint createShaderProgram(const char* fragmentFile) {

	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	string vertShaderStr = readShaderSource("vertexShader.glsl");
	string fragShaderStr = readShaderSource(fragmentFile);
	//string fragShaderStr = readShaderSource("fragmentShader.glsl");

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	glCompileShader(vShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		cout << "vertex compilation failed" << endl;
		printShaderLog(vShader);
	}


	glCompileShader(fShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
		cout << "fragment compilation failed" << endl;
		printShaderLog(fShader);
	}

	// Shader program objektum l�trehoz�sa. Elt�roljuk az ID �rt�ket.
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);

	glLinkProgram(vfProgram);
	checkOpenGLError();
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		cout << "linking failed" << endl;
		printProgramLog(vfProgram);
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	return vfProgram;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		switch (key) {
		case GLFW_KEY_UP:
			UP = true;
			break;
		case GLFW_KEY_DOWN:
			DOWN = true;
			break;
		case GLFW_KEY_LEFT:
			LEFT = true;
			break;
		case GLFW_KEY_RIGHT:
			RIGHT = true;
			break;
		case GLFW_KEY_W:
			W = true;
			break;
		case GLFW_KEY_S:
			S = true;
			break;
		}
	}

	if (action == GLFW_RELEASE)
	{
		switch (key) {
		case GLFW_KEY_UP:
			UP = false;
			break;
		case GLFW_KEY_DOWN:
			DOWN = false;
			break;
		case GLFW_KEY_LEFT:
			LEFT = false;
			break;
		case GLFW_KEY_RIGHT:
			RIGHT = false;
			break;
		case GLFW_KEY_W:
			W = false;
			break;
		case GLFW_KEY_S:
			S = false;
			break;
		}
	}
}

void cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
{

}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void computeCameraMatrices()
{
	/* A paramйterek rendre: az ъj koordinбtarendszerьnk kцzйppontja (hol a kamera), merre nйz a kamera, mit tekintьnk ,,fцlfele" irбnynak */
	view = glm::lookAt(cameraPos, cameraTarget, up);
}

void init(GLFWwindow* window) {
	renderingProgram = createShaderProgram("fragmentShader.glsl");
	glUseProgram(renderingProgram);

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &VBO1);
	glGenVertexArrays(1, &VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_up), vertices_up, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &VBO2);
	glGenVertexArrays(1, &VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_down), vertices_down, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/** A jelenet�nk ut�ni takar�t�s. */
void cleanUpScene()
{
	/** T�r�lj�k a vertex puffer �s vertex array objektumokat. */
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	/** T�r�lj�k a shader programot. */
	glDeleteProgram(renderingProgram);
}

void display(GLFWwindow* window, double currentTime) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // fontos lehet minden egyes alkalommal t�r�lni!

	/*Csatoljuk a vertex array objektumunkat. */
	/** Z-bufferez�s enged�lyez�se. */
	glEnable(GL_DEPTH_TEST);

	// aktiv�ljuk a shader-program objektumunkat.
	glUseProgram(renderingProgram);

	if (UP)
	{
		cameraPos.z += 0.1f;
	}
	if (DOWN)
	{
		cameraPos.z -= 0.1f;
	}
	if (LEFT)
	{
		radian -= 1;
	}
	if (RIGHT)
	{
		radian += 1;
	}
	if (W)
	{
		r += 0.1f;
	}
	if (S)
	{
		r -= 0.1f;
	}

	cameraPos.x = r * sin(glm::radians(radian));
	cameraPos.y = r * cos(glm::radians(radian));

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));

	computeCameraMatrices();

	unsigned int modelLoc = glGetUniformLocation(renderingProgram, "model");
	unsigned int viewLoc = glGetUniformLocation(renderingProgram, "view");
	unsigned int projectionLoc = glGetUniformLocation(renderingProgram, "projection");
	unsigned int myColor = glGetUniformLocation(renderingProgram, "myColor");

	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	/*Csatoljuk a vertex array objektumunkat. */
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glUniform3fv(myColor, 1, colorWhite);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
	glBindVertexArray(0);

	glBindVertexArray(VAO1);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices_up));
	glBindVertexArray(0);

	glBindVertexArray(VAO2);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices_down));
	glBindVertexArray(0);


}

int main(void) {

	/* Pr�b�ljuk meg inicializ�lni a GLFW-t! */
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	/* A k�v�nt OpenGL verzi� (4.3) */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/* Pr�b�ljuk meg l�trehozni az ablakunkat. */
	GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Beadando", NULL, NULL);

	/* V�lasszuk ki az ablakunk OpenGL kontextus�t, hogy haszn�lhassuk. */
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetCursorPosCallback(window, cursorPosCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	/* Incializ�ljuk a GLEW-t, hogy el�rhet�v� v�ljanak az OpenGL f�ggv�nyek. */
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);

	/* Az alkalmaz�shoz kapcsol�d� el�k�sz�t� l�p�sek, pl. hozd l�tre a shader objektumokat. */
	init(window);

	while (!glfwWindowShouldClose(window)) {
		/* a k�d, amellyel rajzolni tudunk a GLFWwindow ojektumunkba. */
		display(window, glfwGetTime());
		/* double buffered */
		glfwSwapBuffers(window);
		/* esem�nyek kezel�se az ablakunkkal kapcsolatban, pl. gombnyom�s */
		glfwPollEvents();
	}

	/* t�r�lj�k a GLFW ablakot. */
	glfwDestroyWindow(window);
	/* Le�ll�tjuk a GLFW-t */

	cleanUpScene();

	glfwTerminate();
	exit(EXIT_SUCCESS);
}