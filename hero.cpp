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

void Hero::dSetter(int damage) // �_���[�W�Z�b�^�[
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Hero::dGetter() // �f�B�t�F���X�Q�b�^�[
{
	return def;
}

int Hero::hGetter() // HP�Q�b�^�[
{
	return hp;
}

char* Hero::nGetter() // ���O�Q�b�^�[
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

void Hero::heal()
{
	hp += 4;
	if (hp > maxHp) hp = maxHp;
	cout << name << "�͉񕜂��AHP��" << hp << "�ɂȂ����B" << endl;
}