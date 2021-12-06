#include "Physic.h"

Scene::Scene(
	glm::vec3 position,
	PhysicalObject* first, PhysicalObject* second,
	glm::vec3 sizes, float borderSize, float frictionCoefficient
)
{
	if (!first) throw exception("first object is null");
	if (!second) throw exception("second object is null");
	_firstObject = first;
	_firstObject->Position = position + glm::vec3({ first->getRadius(),first->getRadius(),0.001});
	
	_secondObject = second;
	_secondObject->Position = position + glm::vec3({ sizes.x - second->getRadius(), sizes.y - second->getRadius(), 0.001});

	_ground = Ground(position, sizes.x, sizes.y, frictionCoefficient);

	_border.resize(4);
	_border[0] = Parallelepiped(
		position-glm::vec3(borderSize, borderSize, 0),
		{ borderSize, sizes.y + borderSize, sizes.z }
	);
	_border[1] = Parallelepiped(
		position -glm::vec3(0, borderSize, 0),
		{ sizes.x + borderSize, borderSize, sizes.z }
	);
	_border[2] = Parallelepiped(
		position + glm::vec3(sizes.x, 0, 0),
		{ borderSize, borderSize + sizes.y, sizes.z }
	);
	_border[3] = Parallelepiped(
		position + glm::vec3(-borderSize, sizes.y, 0),
		{ sizes.x + borderSize, borderSize, sizes.z }
	);
}

void Scene::Draw()
{
	glPushMatrix();
	glColor3f(0, 0.3, 0);
	_ground.Draw();

	glColor3f(1, 1, 1);
	for (Parallelepiped border : _border)
		border.Draw();

	//glColor3f(0.7, 0.1, 0.3);
	_firstObject->Draw();
	_secondObject->Draw();

	glPopMatrix();
}

void Scene::Update()
{
	Edges(_firstObject);
	Edges(_secondObject);

	if (_firstObject->CheckCollision(*_secondObject))
		_firstObject->CollideWith(*_secondObject);

	_ground.Frict(*_firstObject);
	_firstObject->Update();

	_ground.Frict(*_secondObject);
	_secondObject->Update();

}

void Scene::Edges(PhysicalObject* object) const
{
	if (object->Position.y - _ground.Position.y >= _ground.getWidth() - object->getRadius())
	{
		object->Position.y = _ground.Position.y + _ground.getWidth() - object->getRadius();
		object->Velocity.y *= -1;
	}
	if (object->Position.y - _ground.Position.y <= object->getRadius())
	{
		object->Position.y = _ground.Position.y + object->getRadius();
		object->Velocity.y *= -1;
	}

	if (object->Position.x - _ground.Position.x >= _ground.getLenght() - object->getRadius())
	{
		object->Position.x = _ground.Position.x + _ground.getLenght() - object->getRadius();
		object->Velocity.x *= -1;
	}
	if (object->Position.x -_ground.Position.x <= object->getRadius())
	{
		object->Position.x = _ground.Position.x + object->getRadius();
		object->Velocity.x *= -1;
	}
}

