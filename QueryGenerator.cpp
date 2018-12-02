//
// This code generates a random query set for test
//
// Author: Zhigang Lu

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// main() func
int main() {

	// pick up one query set randomly
	sleep(1);

	srand(time(NULL));
	int size = 9;
	int testID = 0;
	testID = rand()%size;

	//cout << testID << endl;

	//testID = 8;

	switch (testID) {
		case 0:
		cout << "UofA\tPROGRAM-ALL\tTUITIONFEE-?\tENROLMENT-ALL" << endl;
		cout << "UNIVERSITY-ALL\tPhD\tTUITIONFEE-ALL\tENROLMENT-?" << endl;
		cout << "UNIVERSITY-ALL\tPROGRAM-?\tTUITIONFEE-ALL\tENROLMENT-<10" << endl;
		cout << "UNIVERSITY-?\tPROGRAM-ALL\tTUITIONFEE-<20\tENROLMENT-ALL";
		break;
		case 1:
		cout << "UNIVERSITY-?\tPROGRAM-ALL\tTUITIONFEE-ALL\tENROLMENT-<25" << endl;
		cout << "UNIVERSITY-ALL\tMCS\tTUITIONFEE-?\tENROLMENT-?" << endl;
		cout << "UNIVERSITY-?\tMSE\tTUITIONFEE->23\tENROLMENT-ALL";
		break;
		case 2:
		cout << "Flinders\tPROGRAM-ALL\tTUITIONFEE-ALL\tENROLMENT-?" << endl;
		cout << "UNIVERSITY-ALL\tBSE\tTUITIONFEE-?\tENROLMENT-ALL" << endl;
		cout << "UniSA\tPROGRAM-ALL\tTUITIONFEE-ALL\tENROLMENT->5";
		break;
		case 3:
		cout << "UniSA\tPROGRAM-ALL\tTUITIONFEE-?\tENROLMENT-ALL" << endl;
		cout << "UNIVERSITY-ALL\tMSE\tTUITIONFEE-?\tENROLMENT-ALL";
		break;
		case 4:
		cout << "UNIVERSITY-ALL\tPhD\tTUITIONFEE-ALL\tENROLMENT-?" << endl;
		cout << "UNIVERSITY-ALL\tPROGRAM-?\tTUITIONFEE-<25\tENROLMENT-ALL";
		break;
		case 5:
		cout << "UNIVERSITY-ALL\tPROGRAM-?\tTUITIONFEE-<25\tENROLMENT-ALL";
		break;
		case 6:
		cout << "UofA\tPROGRAM-ALL\tTUITIONFEE-?\tENROLMENT-ALL" << endl;
		cout << "UNIVERSITY-ALL\tPhD\tTUITIONFEE-ALL\tENROLMENT-?" << endl;
		cout << "UNIVERSITY-ALL\tPROGRAM-?\tTUITIONFEE-ALL\tENROLMENT-<10" << endl;
		cout << "UNIVERSITY-?\tPROGRAM-ALL\tTUITIONFEE-<20\tENROLMENT-ALL" << endl;
		cout << "UNIVERSITY-?\tPROGRAM-ALL\tTUITIONFEE-<15\tENROLMENT-ALL";
		break;
		case 7:
		cout << "UofA\tBCS\tTUITIONFEE-?\tENROLMENT->=25" << endl;
		cout << "UNIVERSITY-ALL\tPhD\tTUITIONFEE->=15\tENROLMENT-?" << endl;
		cout << "UniSA\tPROGRAM-?\tTUITIONFEE-ALL\tENROLMENT-<10" << endl;
		cout << "UNIVERSITY-?\tMCS\tTUITIONFEE-<20\tENROLMENT-ALL" << endl;
		cout << "UNIVERSITY-?\tPROGRAM-ALL\tTUITIONFEE-ALL\tENROLMENT-<=5";
		break;
		case 8:
		cout << "Flinders\tPROGRAM-ALL\tTUITIONFEE-ALL\tENROLMENT-<25" << endl;
		cout << "UofA\tMCS\tTUITIONFEE-?\tENROLMENT-?" << endl;
		cout << "UniSA\tMSE\tTUITIONFEE->23\tENROLMENT-ALL";
	}

	return 0;
}
