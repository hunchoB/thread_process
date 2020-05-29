 #include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>
#include <ctime>
#include "Action.h"

using namespace std;


mutex mtx;

int playersTeam1 = 20;
int playersTeam2 = 20;
int killing=0;
Action action;

/*
void actionOfTeam(int& playersFirst, int& playersSecond, int i)
{
	srand(time(NULL));
	this_thread::sleep_for(chrono::milliseconds(2000));
	mtx.lock();
	killing = 0;
	cout << "ID of thread = " << this_thread::get_id() << endl << endl;

	cout << i << " Team now into:\t" << playersFirst << endl;
	playersFirst += 2 + rand() % 7;
	cout << i << " Team after ADDED:\t" << playersFirst << endl;
	killing += 5 + rand() % 10;
	playersSecond -= killing;
	cout << i << " Team is killing:\t" << killing << endl << endl;
	mtx.unlock();
	this_thread::sleep_for(chrono::milliseconds(1000));
	if (playersSecond <= 0 || playersFirst <= 0) {
		cout << "GAME OVER" << endl;
		exit(0);
	}
	
}*/

/*
int main()
{
	//srand(time(0));
	
	cout << "Before starting into 1 team is =  " << playersTeam1 << "  and  " << "Before starting into 2 team is =  " << playersTeam2 << endl;

	while (playersTeam1 !=0 || playersTeam2 !=0)
	{
		thread team1(actionOfTeam, ref(playersTeam1), ref(playersTeam2), 1);
		this_thread::sleep_for(chrono::milliseconds(1000));
		thread team2(actionOfTeam, ref(playersTeam2), ref(playersTeam1), 2);

		team1.join();
		team2.join();
	}



	return 0;
}
*/
int main()
{
	//srand(time(0));

	cout << "Before starting into 1 team is =  " << playersTeam1 << "  and  " << "Before starting into 2 team is =  " << playersTeam2 << endl;

	while (playersTeam1 != 0 || playersTeam2 != 0)
	{
		thread team1(&Action::actionOfTeam, action, ref(playersTeam1), ref(playersTeam2), 1 , ref(mtx), ref(killing));
		this_thread::sleep_for(chrono::milliseconds(1000));
		thread team2(&Action::actionOfTeam, action, ref(playersTeam2), ref(playersTeam1), 2, ref(mtx), ref(killing));

		team1.join();
		team2.join();
	}



	return 0;
}
