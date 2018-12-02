//
// This code generates a random database for test
//
// Author: Zhigang Lu

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

void generateUni();
void generateProgram();
void generateTuitionFee();
void generateEnrolment();
void generateEnrolmentLastLine();

// main() func

int main() {

	cout << "SID\tUniversity\tProgram\tTuitionFee\tEnrolment" << endl;

	// make sure there are 500 - 800 records in this database
	srand(time(NULL));
	int size = 10;
	size = rand()%size + 50;

	int count = size;
	int ID = 1;
	while(count > 0) {

		cout << "S" << ID << "\t";
		ID = ID + 1;
		generateUni();
		generateProgram();
		generateTuitionFee();
		if(count > 1) {
			generateEnrolment();
		}
		else {
			generateEnrolmentLastLine();
		}


		count = count - 1;
	}

	return 0;
}

void generateUni() {
	int size = 3;
	int i = rand()%size;

	switch(i) {
		case 0: cout << "UofA\t"; break;
		case 1: cout << "UniSA\t"; break;
		case 2: cout << "Flinders\t";
	}

}

void generateProgram() {
	int size = 5;
	int i = rand()%size;

	switch(i) {
		case 0: cout << "PhD\t"; break;
		case 1: cout << "MCS\t"; break;
		case 2: cout << "BSE\t"; break;
		case 3: cout << "MSE\t"; break;
		case 4: cout << "BCS\t";
	}
}

void generateTuitionFee() {
	int size = 30;
	int i = rand()%size + 10;

	cout << i << "\t";

}

void generateEnrolment() {
	int size = 30;
	int i = rand()%size + 1;

	cout << i << endl;
}

void generateEnrolmentLastLine() {
	int size = 30;
	int i = rand()%size + 1;

	cout << i;
}
