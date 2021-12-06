#include "Physic.h"

int Circle::Segments = 60;

Circle::Circle(glm::vec3 position, float radius)
	: Shape(position)
{
	_radius = radius;
}
	
void Circle::Draw()
{
    //TODO Сделать нормали для теней
    glPushMatrix();
    Shape::TranslateToPosition();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= Segments; i++) {
        auto angle = (float)i / (float)Segments * M_PI * 2.0f;
        auto x = _radius * cos(angle);
        auto y = _radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

float Circle::DimensionalMeasure()
{
    return M_PI * _radius * _radius;
}

float Circle::getRadius() const
{
    return _radius;
}
