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

void Enemy::dSetter(int damage) // �_���[�W�Z�b�^�[
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Enemy::dGetter() // �f�B�t�F���X�Q�b�^�[
{
	return def;
}

int Enemy::hGetter() // HP�Q�b�^�[
{
	return hp;
}

char* Enemy::nGetter() // ���O�Q�b�^�[
{
	return name;
}

void Enemy::attack(Hero* hero)
{
	int hDef = hero->dGetter();
	int damage = atk - hDef;
	if (atk > hDef) hero->dSetter(damage);
	cout << name << "�̍U����" << damage << "�̃_���[�W���󂯁A" << endl
		<< hero->nGetter() << "��HP��" << hero->hGetter() << "�Ɍ��������B" << endl;
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