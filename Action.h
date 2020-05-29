 #define Action_H

using namespace std;


class Action
{
public:
	void actionOfTeam(int& playersFirst, int& playersSecond, int i, mutex &mtx, int &killing)
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

	}
	
	
	
private:

};
