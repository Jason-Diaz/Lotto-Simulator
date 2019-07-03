// ExtraCredit2JasonDiaz.cpp : Defines the entry point for the console application.
//Jason Diaz

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 7;

void sort(vector <int> lotto);
bool match(vector <int> lotto, vector <int> guess);

int main()
{
	bool running = true;
	vector <int> lottoNums (SIZE);
	vector <int> lottoGuess(SIZE);

	while (running) {
		for (int i=0; i < SIZE; i++) {
			lottoNums[i] = rand() % 20 + 1; //random number generator 1-20
		}
		sort(lottoNums);

	// user promts and input
		for (int i = 0; i < SIZE; i++) {
			cout << "Enter guess " << i+1 << ":" << endl;
			cin >> lottoGuess[i];
		}
		sort(lottoGuess); //if the guesses are sorted the match function runs faster

		cout << ((match(lottoNums, lottoGuess)) ? "Winner Winner Chicken Dinner" : "Sorry You Lost") << endl;
		cout << "Play Again" << endl; //since the program should keep running
	}
	system("pause");
    return 0;
}

/*
sort - sorts the data in ascending order by base depth
implimented a bubble sort
*/
void sort(vector <int> lotto) {
	bool swapped = true;
	int j = 0;
	int temp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < SIZE - j; i++) {
			if (lotto[i] > lotto[i + 1]) {
				temp = lotto[i];
				lotto[i] = lotto[i + 1];
				lotto[i + 1] = temp;
				swapped = true;
			}
		}
	}
	return;
}

/*
match - this finds if there is a match in with the guess and the lotto numbers and returns if found or not
it starts with the guess and searches for that number in the lotto list, if found it drops out and moves to next number
if an number is not found false is returned
*/
bool match(vector <int> lotto, vector <int> guess) {
	bool match = false;
	for (int i = 0; i < SIZE; i++) { //outer loop for the guess list
		for (int j = 0; j < SIZE; j++) //inner loop for the lotto list
		{
			match = false; // always reset match to false due to it being an indecator as to if there was a match in the previous round
			if (guess[i] == lotto[j]) {
				match = true;
				j = SIZE;
			}
		}
		if (!match) { // if there is no match of a number in the list then we can drop out of the outer loop and return false
			i = SIZE;
		}
	}
	return match;
}