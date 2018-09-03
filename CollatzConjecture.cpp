/*Collatz Conjecture:
Created by WilliamBd
to attempt to disprove the collatz conjecture.
https://en.wikipedia.org/wiki/Collatz_conjecture*/
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
	//gets the last calculation made by program
	ifstream myfile;
	ofstream ofs;
	int n;
	myfile.open("lastcalc.txt");
	int firstCalc;
	string firstCalcStr;
	//assigns line to string then transfers to int
	getline(myfile,firstCalcStr);
	firstCalc = stoi(firstCalcStr);
	myfile.close();

	int testN = firstCalc;
	time_t start;

	//gets the minutes until collatz process should be terminated in minutes.
	printf("Minutes of runtime until Collatz process should be terminated and file printed:");
	int killT;
	scanf("%d", &killT);
	killT = killT*60;
	
	while(true)
	{

		start = time(NULL);
		n = testN;
		while (n != 1){
			if ((n%2) == 0){
				n = n/2;
			} else{
				n = (n*3)+1;
			}
			//breaks program when given such 
			if(time(NULL)-start > killT){
				printf("%d \n",testN);
				break;
			}
		}
		ofs.open("lastcalc.txt", ofstream::out | ofstream::trunc);
		ofs << testN;
		ofs.close();
		testN++;
	}	
	return 0;

}
