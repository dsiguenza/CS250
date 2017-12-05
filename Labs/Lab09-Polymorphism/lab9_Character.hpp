#ifndef _CHARACTER
#define _CHARACTER

#include <string>
using namespace std;

enum TurnChoice { ATTACK = 0, HEAL = 1 };

class ICharacter {
protected: 
	int m_hp;
	int m_atk;
	int m_mag;
	string m_name;
public:
	int GetAttack();
	int GetHealing();
	void Setup(const string&, int, int);
	int GetHP();
	void SubtractDamage(int);
	string GetName();
	virtual TurnChoice GetChoice() = 0;
private:
};

class NPC : public ICharacter {
public:
	virtual TurnChoice GetChoice();
};

class Player : public ICharacter 
{
public:
	virtual TurnChoice GetChoice();
};
#endif
