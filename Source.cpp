#include <time.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
using namespace std;

/**
* multithreaded_findWinner searches all the y for the given x and for where the "winner" is (which cell contains a 1)
* 
* @param arr	the 2d array to search
* @param x		the x to stay within while changing y
* @param winnerposition		 will set this value to the absolute position of the "winner" in terms of 1000*x + y, or unchanged if not found
*/
void multithreaded_findWinner(int** arr, int x, int& winnerPosition);


int main() {
	//setup two dimension array
	int** arr = new int* [2];
	arr[0] = new int[1000];
	arr[1] = new int[1000];

	srand(time(0)); 

	//populate arrays
	for (int i = 0; i < 1000; i++) {
		arr[0][i] = 0;
	}
	for (int i = 0; i < 1000; i++) {
		arr[1][i] = 0;
	}
	int winnerPos;
	for (int i = (rand() % 9)+1; i > 0; i--) { //this is just to increase randomness. I can't explain why it just does.
		winnerPos = rand() % 2000; //find a random spot to put a 1
	}

	if (winnerPos < 1000) { //theres a better way to do this for sure, but basically just convert the random spot to the two dimensional array
		arr[0][winnerPos] = 1;
	}
	else {
		arr[1][winnerPos - 1000] = 1;
	}

	winnerPos = 0;
	thread t(multithreaded_findWinner, arr, 0, ref(winnerPos));
	t.join();

	cout << winnerPos;

	//delete arrays
	delete[] arr[0];
	delete[] arr[1];
	delete[] arr;
	return 0;
}

void multithreaded_findWinner(int** arr, int x, int& winnerPosition) {
	for (int i = 0; i < 1000; i++) {
		if(arr[x][i]) winnerPosition= x*1000 + i;
	}
}

