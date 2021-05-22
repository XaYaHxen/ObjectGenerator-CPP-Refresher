#pragma once

#include <string>

class Object
{
public:
	Object();
	Object(std::string Name, int Health, int Weight, bool CanBeDamaged);
	~Object();

	int GetHealth() { return m_Health; }
	int GetWeight() { return m_Weight; }
	bool GetCanBeDamaged()	{ return bCanBeDamaged; }
	std::string GetName() { return m_Name; }


private:
	int m_Health;
	int m_Weight;
	bool bCanBeDamaged;
	std::string m_Name;
};

