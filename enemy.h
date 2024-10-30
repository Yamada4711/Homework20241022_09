#ifndef ENEMY_H_20241029_1314
#define ENEMY_H_20241029_1314

class Hero; // 前方宣言

class Enemy
{
public:
	// 演算子オーバーロード
	void operator=(const Enemy& other);

	// コピーコンストラクタ
	Enemy(const Enemy& other);

	Enemy(char* m_name, int m_hp);
	~Enemy();
	void damageSetter(int damage);
	int defGetter() const;
	int hpGetter() const;
	int atkGetter() const;
	char* nameGetter() const;
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
