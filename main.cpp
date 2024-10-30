#include "hero.h";
#include "enemy.h";
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

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