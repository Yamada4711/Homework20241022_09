#ifndef HERO_H_20241029_1312
#define HERO_H_20241029_1312

class Enemy;

class Hero
{
public:
	// 演算子オーバーロード
	void operator=(const Hero& other);

	// コピーコンストラクタ
	Hero(const Hero& other);

	Hero(char* m_name, int m_hp);
	~Hero();
	void damageSetter(int damage);
	int defGetter() const;
	int hpGetter() const;
	int atkGetter() const;
	char* nameGetter() const;
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
