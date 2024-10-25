#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

class Hero; // �O���錾
class Enemy;

const int ARRAY_SIZE = 20;

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

Hero::Hero(char* m_name, int m_hp)
{
	name = new(nothrow) char[strlen(m_name) + 1];
	if (name != nullptr)
	{
		for (int i = 0; i < strlen(m_name); ++i)
		{
			name[i] = m_name[i];
		}
		name[strlen(m_name)] = '\0';
	}
	maxHp = m_hp;
	hp = m_hp;
	atk = 11;
	def = 4;
}

Enemy::Enemy(char* m_name, int m_hp)
{
	name = new(nothrow) char[strlen(m_name) + 1];
	if (name != nullptr)
	{
		for (int i = 0; i < strlen(m_name); ++i)
		{
			name[i] = m_name[i];
		}
		name[strlen(m_name)] = '\0';
	}
	maxHp = m_hp;
	hp = m_hp;
	atk = 9;
	def = 6;
}

Hero::~Hero()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

Enemy::~Enemy()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Hero::dSetter(int damage) // �_���[�W�Z�b�^�[
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

void Enemy::dSetter(int damage) // �_���[�W�Z�b�^�[
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Hero::dGetter() // �f�B�t�F���X�Q�b�^�[
{
	return def;
}

int Enemy::dGetter() // �f�B�t�F���X�Q�b�^�[
{
	return def;
}

int Hero::hGetter() // HP�Q�b�^�[
{
	return hp;
}

int Enemy::hGetter() // HP�Q�b�^�[
{
	return hp;
}

char* Hero::nGetter() // ���O�Q�b�^�[
{
	return name;
}

char* Enemy::nGetter() // ���O�Q�b�^�[
{
	return name;
}

void Hero::attack(Enemy* enemy)
{
	int eDef = enemy->dGetter();
	int damage = atk - eDef;
	if (atk > eDef) enemy->dSetter(damage);
	cout << name << "��" << enemy->nGetter() << "�ɁA" << damage << "�̃_���[�W��^�����B" << endl
		<< enemy->nGetter() << "��HP�͎c��" << enemy->hGetter() << "�ƂȂ����B" << endl;
}

void Enemy::attack(Hero* hero)
{
	int hDef = hero->dGetter();
	int damage = atk - hDef;
	if (atk > hDef) hero->dSetter(damage);
	cout << name << "�̍U����" << damage << "�̃_���[�W���󂯁A" << endl
		<< hero->nGetter() << "��HP��" << hero->hGetter() << "�Ɍ��������B" << endl;
}

void Hero::heal()
{
	hp += 4;
	if (hp > maxHp) hp = maxHp;
	cout << name << "�͉񕜂��AHP��" << hp << "�ɂȂ����B" << endl;
}

void Enemy::heal()
{
	hp += 3;
	if (hp > maxHp) hp = maxHp;
	cout << name << "�͉񕜂��AHP��" << hp << "�ɂȂ����B" << endl;
}

void Enemy::battleAI(Hero* hero)
{
	if (hero->hGetter() <= 5 || hp > 4) attack(hero);
	else if (hp != 0) heal();
	else cout << name << "�͗͐s�����I" << endl;
}

enum State
{
	WIN = 0,
	DRAW = 1,
	LOSE = 2,
	OTHERS = 3
};


int main()
{
	char heroName[] = "Yamada";
	char enemyName[] = "StinkBugs";// Stink bugs = �J�����V
	int heroHp = 30;
	int enemyHp = 25;
	State state = OTHERS;
	Hero hero(heroName, heroHp);
	Enemy enemy(enemyName, enemyHp); 
	do
	{
		char input = ' ';
		do
		{
			cout << "�U���Ȃ� a ���A�񕜂Ȃ� h ����͂��Ă��������B" << endl;
			cin >> input;

			if (!(input == 'a' || input == 'A' || input == 'h' || input == 'H'))
			{
				cout << "���͂����������Ԉ���Ă��܂��B" << endl;
			}

		} while (!(input == 'a' || input == 'A' || input == 'h' || input == 'H'));

		if (input == 'a' || input == 'A') hero.attack(&enemy);
		else hero.heal();

		enemy.battleAI(&hero);

		if (hero.hGetter() <= 0 && enemy.hGetter() <= 0)
		{
			state = DRAW;
			break;
		}
		else if (enemy.hGetter() <= 0)
		{
			state = WIN; 
			break;
		}
		else if (hero.hGetter() <= 0)
		{
			state = LOSE; 
			break;
		}

	} while (true);

	switch (state)
	{
	case WIN:
		cout << hero.nGetter() << " �� " << enemy.nGetter() << " �ɏ������B";
		break;

	case DRAW:
		cout << hero.nGetter() << " �� " << enemy.nGetter() << " �͑��ł��ɂȂ����B";
		break;

	case LOSE:
		cout << hero.nGetter() << " �� " << enemy.nGetter() << " �ɕ������B";
		break;

	default:
		break;
	}
}