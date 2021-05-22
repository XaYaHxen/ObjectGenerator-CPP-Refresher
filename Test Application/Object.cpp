#include "Object.h"

Object::Object()
{
	m_Health = 0;
	m_Weight = 0;
	bCanBeDamaged = false;
}

Object::Object(std::string Name, int Health, int Weight, bool CanBeDamaged)
{
	m_Name = Name;
	m_Health = Health;
	m_Weight = Weight;
	bCanBeDamaged = CanBeDamaged;
}
