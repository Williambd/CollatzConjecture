/*Collatz Conjecture:
Created by WilliamBd
to attempt to disprove the collatz conjecture.
https://en.wikipedia.org/wiki/Collatz_conjecture*/
#include <stdio.h>
#include <time.h>


int main()
{

	int testN = 2;
	int n = testN;
	time_t start;
	printf("Minutes until Collatz process should be terminated:");
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
		testN++;
	}	

}
