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