#ifndef ENEMY_H_20241029_1314
#define ENEMY_H_20241029_1314

class Hero; // ‘O•ûéŒ¾

class Enemy
{
public:
	Enemy(char* m_name, int m_hp);
	~Enemy();
	void dSetter(int damage);
	int dGetter();
	int hGetter();
	char* nGetter();
	void attack(Hero* hero);
	void heal();
	void battleAI(Hero* hero);

private:
	char* name;
	int maxHp;
	int hp;
	int atk;
	int def;
};

#endif // !ENEMY_H_20241029_1314
