#ifndef ENEMY_H_20241029_1314
#define ENEMY_H_20241029_1314

class Hero; // �O���錾

class Enemy
{
public:
	// ���Z�q�I�[�o�[���[�h
	void operator=(const Enemy& other);

	// �R�s�[�R���X�g���N�^
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
