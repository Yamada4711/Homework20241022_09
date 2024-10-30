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

void showStatus(const Hero hero, const Enemy enemy);

int main()
{
	char heroName[] = "Yamada";
	char enemyName[] = "StinkBugs";// Stink bugs = カメムシ
	int heroHp = 30;
	int enemyHp = 25;
	State state = OTHERS;
	Hero hero(heroName, heroHp);
	Enemy enemy(enemyName, enemyHp); 
	
	showStatus(hero, enemy);

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

		if (hero.hpGetter() <= 0 && enemy.hpGetter() <= 0)
		{
			state = DRAW;
			break;
		}
		else if (enemy.hpGetter() <= 0)
		{
			state = WIN; 
			break;
		}
		else if (hero.hpGetter() <= 0)
		{
			state = LOSE; 
			break;
		}

	} while (true);

	switch (state)
	{
	case WIN:
		cout << hero.nameGetter() << " は " << enemy.nameGetter() << " に勝った。";
		break;

	case DRAW:
		cout << hero.nameGetter() << " と " << enemy.nameGetter() << " は相打ちになった。";
		break;

	case LOSE:
		cout << hero.nameGetter() << " は " << enemy.nameGetter() << " に負けた。";
		break;

	default:
		break;
	}
}

void showStatus(Hero hero, Enemy enemy)
{
	cout << "自分の名前 > " << hero.nameGetter() << endl
		<< "HP > " << hero.hpGetter() << endl
		<< "ATK > " << hero.atkGetter() << endl
		<< "DEF > " << hero.defGetter() << endl
		<< endl
		<< "敵の名前 > " << enemy.nameGetter() << endl
		<< "HP > " << enemy.hpGetter() << endl
		<< "ATK > " << enemy.atkGetter() << endl
		<< "DEF > " << enemy.defGetter() << endl
		<< endl;
}