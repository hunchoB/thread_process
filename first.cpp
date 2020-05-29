#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
//#include "stdafx.h"
#include <sys/wait.h>
#include <algorithm>
#include <experimental/filesystem>



using namespace std;


void Timing(int x, int time, int time2)
{
    sleep(time);
    if ( x == 2)
        sleep(time2);
}



int main(int argc, char *argv[])
{
	srand(time(NULL)); 
	/*
	cout << "I am a bee and I am creating honey into my programm"<<endl;
	char buffer[50]; // created a buffer for writting into file
	

	int amountHoney; //amount honey
	int honeyOfBee = 5;

    ifstream fin("file.txt");
    fin >> buffer;
    fin.close();

    amountHoney=atoi(buffer);
    amountHoney += honeyOfBee;
    cout << "I am created honey and now it's =     "<< amountHoney<<endl;
    sprintf(buffer, "%d", amountHoney);  // put honey from number into string (our buffer)
	ofstream fout("file.txt");  // created an object and open file
    fout << buffer; // write buffer into file
    fout.close(); // closed file
    sleep(2);

*/


//
//
	int pause_time=0.6;
	int pause_time2=0.3;
	char buffer[50]; 
	int killing=0;
	int killing2=0;
    char* ch= argv[0];
    int x;
    x=atoi(ch);
    //cout<<"AFAWFF\t"<<x<<endl;
    int play1=10;
    int play2=10;
    //cout<<"aFAWFFAWF"<<ch<<endl;
  while (play1 >0 && play2 >0)
  {
  
    
    if (x == 1)
    {	//sleep(1);
    	killing=3+rand()%8;
    	ifstream fin("team1.txt");
    	fin >> buffer;
    	fin.close();

    	play1=atoi(buffer);
    	cout<<"Before step=\t"<<play1<<endl;
    	int add1=2+rand()%7;
    	cout<< "ADD 1\t"<<add1<<endl;
    	play1 += add1;
    	cout<<"Now into first team\t"<<	play1<< endl;
    	sprintf(buffer, "%d", play1);  // put honey from number into string (our buffer)
		ofstream fout("team1.txt");  // created an object and open file
    	fout << buffer; // write buffer into file
    	fout.close();	

    	ifstream fin2("team2.txt");
    	fin2 >> buffer;
    	fin2.close();

    	play2=atoi(buffer);
    	play2 -= killing;
    	cout<<"1 team killed\t"<<killing<<endl;
    	sprintf(buffer, "%d", play2);  // put honey from number into string (our buffer)
		ofstream fout2("team2.txt");  // created an object and open file
    	fout2 << buffer; // write buffer into file
    	fout2.close();
    	cout<<endl<<endl;
    	//sleep(2);
    	//exit(0);
    	sleep(1);
        Timing(x, pause_time, pause_time2);

    }
    
    else if (x == 2)
    {	
    	//sleep(1);
    	Timing(x, pause_time, pause_time2);
    	killing2=3+rand()%7;
    	ifstream fin("team2.txt");
    	fin >> buffer;
    	fin.close();

    	play2=atoi(buffer);
    	cout<<"Before step=\t"<<play2<<endl;
    	int add2=2+rand()%9;
    	cout<< "ADD 2\t"<<add2<<endl;
    	play2 += add2;
    	cout<<"Now into second team\t"<<	play2<< endl;
    	sprintf(buffer, "%d", play2);  // put honey from number into string (our buffer)
		ofstream fout("team2.txt");  // created an object and open file
    	fout << buffer; // write buffer into file
    	fout.close();	

    	ifstream fin2("team1.txt");
    	fin2 >> buffer;
    	fin2.close();

    	play1=atoi(buffer);
    	play1 -= killing2;
    	cout<<"2 team killed\t"<<killing2<<endl;
    	sprintf(buffer, "%d", play1);  // put honey from number into string (our buffer)
		ofstream fout2("team1.txt");  // created an object and open file
    	fout2 << buffer; // write buffer into file
    	fout2.close();
    	cout<<endl<<endl;
    	sleep(1);
        Timing(x, pause_time, pause_time2);
        
    }
	
  }
    cout<<"GAME OVER"<<endl;
    exit(0);
	//int killing = 0;

	/*cout << i << " Team now into:\t" << playersFirst << endl;
	playersFirst += 2 + rand() % 7;
	cout << i << " Team after ADDED:\t" << playersFirst << endl;
	killing += 5 + rand() % 10;
	playersSecond -= killing;
	cout << i << " Team is killing:\t" << killing << endl << endl;
	mtx.unlock();
	this_thread::sleep_for(chrono::milliseconds(1000));*/
//exit(0);
    sleep(1);
}	 
