#define _CRT_SECURE_NO_WARNINGS
#include "enemy.h";
#include "hero.h";
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

void Enemy::operator=(const Enemy& other)
{
	char* m_name = new(nothrow) char[strlen(other.name) + 1];

	if (m_name != nullptr)
	{
		if (name != nullptr)
		{
			delete[] name;
			copy(other.name, other.name + strlen(other.name) + 1, name);
		}
	}
	hp = other.hp;
	atk = other.atk;
	def = other.def;
}

Enemy::Enemy(const Enemy& other)
{
	name = new(nothrow) char[strlen(other.name) + 1];
	maxHp = other.maxHp;
	hp = other.hp;
	atk = other.atk;
	def = other.def;
	if (name != nullptr)
	{
		copy(other.name, other.name + strlen(other.name) + 1, name);
	}
}

Enemy::Enemy(char* m_name, int m_hp)
{
	name = new(nothrow) char[strlen(m_name) + 1];
	if (name != nullptr)
	{
		strcpy(name, m_name);
	}
	if (m_hp <= 0) m_hp = 30;
	maxHp = m_hp;
	hp = m_hp;
	atk = 9;
	def = 6;
}

Enemy::~Enemy()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Enemy::damageSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Enemy::defGetter() const // ディフェンスゲッター
{
	return def;
}

int Enemy::hpGetter() const // HPゲッター
{
	return hp;
}

int Enemy::atkGetter() const // アタックゲッター
{
	return atk;
}

char* Enemy::nameGetter() const // 名前ゲッター
{
	return name;
}

void Enemy::attack(Hero* hero)
{
	int hDef = hero->defGetter();
	int damage = atk - hDef;
	if (atk > hDef) hero->damageSetter(damage);
	cout << name << "の攻撃で" << damage << "のダメージを受け、" << endl
		<< hero->nameGetter() << "のHPが" << hero->hpGetter() << "に減少した。" << endl;
}

void Enemy::heal()
{
	hp += 3;
	if (hp > maxHp) hp = maxHp;
	cout << name << "は回復し、HPが" << hp << "になった。" << endl;
}

void Enemy::battleAI(Hero* hero)
{
	if (hero->hpGetter() <= 5 || hp > 4) attack(hero);
	else if (hp != 0) heal();
	else cout << name << "は力尽きた！" << endl;
}