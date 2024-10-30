#define _CRT_SECURE_NO_WARNINGS
#include "hero.h";
#include "enemy.h";
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

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

void Hero::dSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Hero::dGetter() // ディフェンスゲッター
{
	return def;
}

int Hero::hGetter() // HPゲッター
{
	return hp;
}

char* Hero::nGetter() // 名前ゲッター
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

void Hero::heal()
{
	hp += 4;
	if (hp > maxHp) hp = maxHp;
	cout << name << "は回復し、HPが" << hp << "になった。" << endl;
}