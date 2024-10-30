#ifndef HERO_H_20241029_1312
#define HERO_H_20241029_1312

class Enemy;

class Hero
{
public:
	Hero(char* m_name, int m_hp);
	~Hero();
	void dSetter(int damage);
	int dGetter();
	int hGetter();
	char* nGetter();
	void attack(Enemy* enemy);
	void heal();

private:
	char* name;
	int maxHp;
	int hp;
	int atk;
	int def;
};

#endif // !HERO_H_20241029_1312
