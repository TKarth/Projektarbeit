#ifndef MANAGER_H
#define MANAGER_H

#include "Square.h"
#include "AssimpModel.h"
#include "Text.h"
#include "GraphicEngine.h"
#include <map>

namespace visual {
	class Manager {
	public:
		static Manager* getInstance(void);

		void doSomething(std::string s);
		GLuint addModel(const ::std::string filename);
		GLuint addPoint(const ::std::string textureFilename = "sample.png");
		GLuint addText(const std::string text);

		GLboolean isModelCreated(GLuint modelId);

		GLboolean positionModel(GLuint modelId, glm::vec3 position);
		GLboolean rotateModel(GLuint modelId, GLfloat degrees, glm::vec3 axis);
		GLboolean scaleModel(GLuint modelId, glm::vec3 scale);

		void addToModelList(GLuint modelId, model::AssimpModel* model);
		void addToSquareList(GLuint modelId, model::Square* model);
		void addToTextList(GLuint modelId, gui::Text* text);

		void draw(void);
	private:
		static Manager* instance;

		GLuint modelInstantiationCounter = 0;
		std::map<GLuint, model::AssimpModel*> assimpModelList;
		std::map<GLuint, model::Square*> squareList;
		std::map<GLuint, gui::Text*> textList;

		model::Square* square = 0;
		model::AssimpModel* assimpModel = 0;

		Manager(void);

		GLboolean isRunning(void);
	};
}

#endif