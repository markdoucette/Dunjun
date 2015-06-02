#include <Dunjun/Common.hpp>

#include <GLFW/glfw3.h>
#include <iostream>



GLOBAL int WIN_WIDTH = 1024;
GLOBAL int WIN_HEIGHT = 768;
GLOBAL char* TITLE = "Da Dunjun";

int main(int argc, char** argv)
{
	GLFWwindow* window;

	if (!glfwInit()) {
		return EXIT_FAILURE;
	}
	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, TITLE, nullptr, nullptr);

	if (!window) {
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	bool running = true;
	bool fullscreen = false;

	while (running)
	{
		glClearColor(0.5f, 0.69f, 1.0f, 1.0f); // set color of Sky Blue
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			running = false;
		}

		if (glfwGetKey(window, GLFW_KEY_F11)) {
			fullscreen = !fullscreen; // flip the bool

			GLFWwindow* newWindow;
			if (fullscreen)
			{
				GLFWmonitor* monitor = glfwGetPrimaryMonitor();
				const GLFWvidmode* mode = glfwGetVideoMode(monitor);
				newWindow = glfwCreateWindow(mode->width, mode->height, TITLE, glfwGetPrimaryMonitor(), window);
			}
			else {
				newWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, TITLE, nullptr, window);
			}

			glfwDestroyWindow(window);
			window = newWindow;
			glfwMakeContextCurrent(window);
		}
	}


	glfwDestroyWindow(window);
	glfwTerminate();

	return EXIT_SUCCESS;
}