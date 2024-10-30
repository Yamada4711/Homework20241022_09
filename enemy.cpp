#define _CRT_SECURE_NO_WARNINGS
#include "enemy.h";
#include "hero.h";
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

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

void Enemy::dSetter(int damage) // ダメージセッター
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Enemy::dGetter() // ディフェンスゲッター
{
	return def;
}

int Enemy::hGetter() // HPゲッター
{
	return hp;
}

char* Enemy::nGetter() // 名前ゲッター
{
	return name;
}

void Enemy::attack(Hero* hero)
{
	int hDef = hero->dGetter();
	int damage = atk - hDef;
	if (atk > hDef) hero->dSetter(damage);
	cout << name << "の攻撃で" << damage << "のダメージを受け、" << endl
		<< hero->nGetter() << "のHPが" << hero->hGetter() << "に減少した。" << endl;
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