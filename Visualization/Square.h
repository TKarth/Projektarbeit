#ifndef SQUARE_H
#define SQUARE_H

#include "Model.h"
#include "TextureSoil.h"

namespace visual {
	namespace model {
		class Square : public Model {
		private:
			GLuint vertexArrayId; /** Referenz auf das VAO (Vertex Array Object) */
			GLuint positionBufferId; /** Referenz auf den Buffer f�r die Positionen */
			GLuint colorBufferId; /** Referenz auf den Buffer f�r die Farben */
			GLuint textureBufferId; /** Referenz auf den Buffer f�r die Textur */
			GLuint textureId;

			TextureSoil* texture;

		public:
			Square();
			~Square();

			GLboolean loadModel(void);

			/** Zeichnet das Modell
			* @author Stefan Landgrebe
			*/
			virtual void draw(void);
		};
	}
}


#endif