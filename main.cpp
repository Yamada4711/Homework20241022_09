#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

class Hero; // 前方宣言
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

void Hero::dSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

void Enemy::dSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Hero::dGetter() // ディフェンスゲッター
{
	return def;
}

int Enemy::dGetter() // ディフェンスゲッター
{
	return def;
}

int Hero::hGetter() // HPゲッター
{
	return hp;
}

int Enemy::hGetter() // HPゲッター
{
	return hp;
}

char* Hero::nGetter() // 名前ゲッター
{
	return name;
}

char* Enemy::nGetter() // 名前ゲッター
{
	return name;
}

void Hero::attack(Enemy* enemy)
{
	int eDef = enemy->dGetter();
	int damage = atk - eDef;
	if (atk > eDef) enemy->dSetter(damage);
	cout << name << "は" << enemy->nGetter() << "に、" << damage << "のダメージを与えた。" << endl
		<< enemy->nGetter() << "のHPは残り" << enemy->hGetter() << "となった。" << endl;
}

void Enemy::attack(Hero* hero)
{
	int hDef = hero->dGetter();
	int damage = atk - hDef;
	if (atk > hDef) hero->dSetter(damage);
	cout << name << "の攻撃で" << damage << "のダメージを受け、" << endl
		<< hero->nGetter() << "のHPが" << hero->hGetter() << "に減少した。" << endl;
}

void Hero::heal()
{
	hp += 4;
	if (hp > maxHp) hp = maxHp;
	cout << name << "は回復し、HPが" << hp << "になった。" << endl;
}

void Enemy::heal()
{
	hp += 3;
	if (hp > maxHp) hp = maxHp;
	cout << name << "は回復し、HPが" << hp << "になった。" << endl;
}

void Enemy::battleAI(Hero* hero)
{
	if (hero->hGetter() <= 5 || hp > 4) attack(hero);
	else if (hp != 0) heal();
	else cout << name << "は力尽きた！" << endl;
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
	char enemyName[] = "StinkBugs";// Stink bugs = カメムシ
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
			cout << "攻撃なら a を、回復なら h を入力してください。" << endl;
			cin >> input;

			if (!(input == 'a' || input == 'A' || input == 'h' || input == 'H'))
			{
				cout << "入力した文字が間違っています。" << endl;
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
		cout << hero.nGetter() << " は " << enemy.nGetter() << " に勝った。";
		break;

	case DRAW:
		cout << hero.nGetter() << " と " << enemy.nGetter() << " は相打ちになった。";
		break;

	case LOSE:
		cout << hero.nGetter() << " は " << enemy.nGetter() << " に負けた。";
		break;

	default:
		break;
	}
}