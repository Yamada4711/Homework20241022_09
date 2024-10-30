#define _CRT_SECURE_NO_WARNINGS
#include "hero.h";
#include "enemy.h";
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

void Hero::operator=(const Hero& other)
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

Hero::Hero(const Hero& other)
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

Hero::Hero(char* m_name, int m_hp)
{
	name = new(nothrow) char[strlen(m_name) + 1];
	if (name != nullptr)
	{
		strcpy(name, m_name);
	}
	if (m_hp <= 0) m_hp = 30;
	maxHp = m_hp;
	hp = m_hp;
	atk = 11;
	def = 4;
}

Hero::~Hero()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Hero::damageSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Hero::defGetter() const // ディフェンスゲッター
{
	return def;
}

int Hero::hpGetter() const // HPゲッター
{
	return hp;
}

int Hero::atkGetter() const // アタックゲッター
{
	return atk;
}

char* Hero::nameGetter() const // 名前ゲッター
{
	return name;
}

void Hero::attack(Enemy* enemy)
{
	int eDef = enemy->defGetter();
	int damage = atk - eDef;
	if (atk > eDef) enemy->damageSetter(damage);
	cout << name << "は" << enemy->nameGetter() << "に、" << damage << "のダメージを与えた。" << endl
		<< enemy->nameGetter() << "のHPは残り" << enemy->hpGetter() << "となった。" << endl;
}

void Hero::heal()
{
	hp += 4;
	if (hp > maxHp) hp = maxHp;
	cout << name << "は回復し、HPが" << hp << "になった。" << endl;
}