#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//Shark
		-0.916f,0.39f,0.0f,   0.431f,0.815f,0.968f,  // C //Cian
		-0.76f,0.55f,0.0f,   0.431f,0.815f,0.968f,  // D
		-0.6f,0.39f,0.0f,  0.431f,0.815f,0.968f,  // E
		-0.76f,0.39f,0.0f,   1.0f,0.0f,0.0f, // F //Rojo
		-0.69f,0.30f,0.0f,   1.0f,0.0f,0.0f, //G
		-0.6f,0.39f,0.0f,  1.0f,0.0f,0.0f,  // E1
		-0.76f,0.55f,0.0f,   0.443f,0.749f,0.27f,  // D1 //Verde
		-0.56f,0.55f,0.0f,   0.443f,0.749f,0.27f, //H
		-0.56f,0.34f,0.0f,	0.443f,0.749f,0.27f, //I
		-0.51f,0.66f,0.0f,  0.816f,0.816f,0.823f, //J //Gris
		-0.62f,0.55f,0.0f, 0.816f,0.816f,0.823f, //K
		-0.51f,0.55f,0.0f, 0.816f,0.816f,0.823f, //L
		-0.56f,0.55f,0.0f,  1.0f,0.76f,0.058f, //H1 //Amarillo
		-0.44f,0.55f,0.0f,	1.0f,0.76f,0.058f, //M
		-0.44f,0.44f,0.0f,	1.0f,0.76f,0.058f, //N
		-0.56f,0.44f,0.0f,	1.0f,0.76f,0.058f, //O
		-0.44f,0.55f,0.0f,	0.686f,0.666f,0.827, //M1 //Lila
		-0.44f,0.44f,0.0f,	0.686f,0.666f,0.827, //N1
		-0.33f,0.55f,0.0f,	0.686f,0.666f,0.827, //P
		-0.33f,0.66f,0.0f,	0.686f,0.666f,0.827, //Q
		-0.33f,0.74f,0.0f,	0.96f,0.505f,0.125f, //R //Naranaja
		-0.33f,0.59f,0.0f,  0.96f,0.505f,0.125f, //S
		-0.17f,0.59f,0.0f,	0.96f,0.505f,0.125f, //T

		//Boat

		0.32f,-0.22f,0.0f, 0.443f,0.749f,0.27f, //C Verde
		0.53f,-0.43f,0.0f, 0.443f,0.749f,0.27f, //D
		0.32f, -0.65f, 0.0f, 0.443f,0.749f,0.27f,//E
		0.75f, -0.65f, 0.0f, 0.431f,0.815f,0.968f,//F Cian
		0.14f, -0.65f, 0.0f,  0.96f,0.505f,0.125f, //G Naranja
		0.28f, -0.81f, 0.0f, 0.96f,0.505f,0.125f, //H
		0.43f, -0.65f, 0.0f, 0.96f,0.505f,0.125f, //I
		0.43f, -0.81f, 0.0f, 0.816f,0.816f,0.823f, // J Gris
		0.59f, -0.65f, 0.0f, 1.0f,0.76f,0.058f,//L Amarillo
		0.59f, -0.81f, 0.0f, 1.0f,0.76f,0.058f, //K
		0.90f, -0.65f, 0.0f, 0.686f,0.666f,0.827,// M Lila
		0.75f, -0.81f, 0.0f, 0.686f,0.666f,0.827, //N
	
	};
	unsigned int indices[] = {  // note that we start from 0!
		0,1,2,
		3,4,5,
		6,7,8,
		9,10,11,
		12,13,14,
		12,14,15,
		16,17,18,
		16,18,19,
		20,21,22,
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Desenlazamos de memoria el VAO


	
	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aqu�
		OurShader.Use();
		glBindVertexArray(VAO);
		glPointSize(10);
		//glDrawArrays(GL_LINES, 0, 4);
	    glDrawElements(GL_TRIANGLES,27, GL_UNSIGNED_INT, (GLvoid*)(0*sizeof(GLfloat)));
	
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}