#ifndef GRAPHICSENGING_H
#define GRAPHICSENGING_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SOIL.h>
#include "SafeQueue.h"

namespace visual {
	namespace graphics {
		class GraphicEngine {
		public:
			static GraphicEngine* getInstance();
			GLuint getShaderProgramId(void);
			static bool isRunning(void) { return running; }
			static void enqueueSquare(GLuint modelId, std::string filename);
			static void enqueueModel(GLuint modelId, std::string filename);
			static void enqueueText(GLuint modelId, std::string text);

			int getWindowHeight(void) { return height; }
			int getWindowWidth(void) { return width; }

		private:
			static bool running;

			static GraphicEngine* singleInstance;
			static GLFWwindow* window;
			static std::string title;
			static int width;
			static int height;

			struct modelQueueEntry {
				GLuint modelId;
				std::string filename;
			};

			static SafeQueue<modelQueueEntry>* squareQueue;
			static SafeQueue<modelQueueEntry>* modelQueue;
			static SafeQueue<modelQueueEntry>* textQueue;

			static GLuint shaderProgramId;

			enum shaderType {VERTEX, FRAGMENT, GEOMETRY};

			GraphicEngine();
			~GraphicEngine();

			static void worker();
			void processQueue();

			int createWindow(const std::string title, int width, int height);
			int createOpenGLContext(void);
			
			static GLuint createShader(const std::string filename, const shaderType);
			static GLuint createShaderProgram(const GLuint vertexShaderId, const GLuint fragmentShaderId);
			static GLuint createShaderProgram(const std::string vertexShaderFilename, const std::string fragmentShaderfilename);
			static void deleteShaderProgram(const GLuint shaderProgramId);
		};
	}
}

#endif