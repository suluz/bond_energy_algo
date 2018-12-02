//
// This code is the starter
//
// Author: Zhigang Lu

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <stdlib.h>

#include "Record.h"


using namespace std;



// main() func

int main (int argc, char *argv[]) {

	//read database
	std::vector<Record> records;
	ifstream fileDB;
	fileDB.open(argv[1]);
	string lineDB;
	// ignore the first line
	fileDB.ignore(256, '\n');

	while (!fileDB.eof()) {
		getline(fileDB, lineDB);
		istringstream issDB(lineDB);
		
		std::vector<string> tokensDB;
		string tokenDB;
		while (getline(issDB, tokenDB, '\t')) {
			tokensDB.push_back(tokenDB);
		}
		
		Record* rec = new Record(tokensDB[0], tokensDB[1], tokensDB[2], stoi(tokensDB[3]), stoi(tokensDB[4]));
		records.push_back(*rec);
		
	}

	fileDB.close();

//test
	// cout << records[0].getUniversity() << ", " << records[0].getProgram() << ", " << records[58].getTuitionFee() << ", " << records[58].getEnrolment() << endl;

	
	//read query
	ifstream fileQ;
	fileQ.open(argv[2]);
	string lineQ;

	std::vector<string> universityQuery;
	std::vector<string> programQuery;
	std::vector<string> tuitionFeeQuery;
	std::vector<string> enrolmentQuery;

	while (!fileQ.eof()) {
		getline(fileQ, lineQ);
		istringstream issQ(lineQ);

		std::vector<string> tokensQ;
		string tokenQ;
		while(getline(issQ, tokenQ, '\t')) {
			tokensQ.push_back(tokenQ);
		}

		if (tokensQ[0].compare("UNIVERSITY-ALL") && tokensQ[0].compare("UNIVERSITY-?")) {
			universityQuery.push_back(tokensQ[0]);
		}

		if (tokensQ[1].compare("PROGRAM-ALL") && tokensQ[1].compare("PROGRAM-?")) {
			programQuery.push_back(tokensQ[1]);
		}

		if (tokensQ[2].compare("TUITIONFEE-ALL") && tokensQ[2].compare("TUITIONFEE-?")) {
			tuitionFeeQuery.push_back(tokensQ[2].substr(11));
		}

		if (tokensQ[3].compare("ENROLMENT-ALL") && tokensQ[3].compare("ENROLMENT-?")) {
			enrolmentQuery.push_back(tokensQ[3].substr(10));
		}
	}

	fileQ.close();


	//read predicates
	ifstream fileP;
	fileP.open(argv[3]);
	string lineP;

	std::vector<string> universityPredicate;
	std::vector<string> programPredicate;
	std::vector<string> tuitionFeePredicate;
	std::vector<string> enrolmentPredicate;

	int counter = 0;

	while (!fileP.eof()) {
		getline(fileP, lineP);
		istringstream issP(lineP);

		//std::vector<string> tokensP;
		string tokenP;
		while(getline(issP, tokenP, '\t')) {
			switch (counter) {
				case 0:
					universityPredicate.push_back(tokenP);
				break;
				case 1:
					programPredicate.push_back(tokenP);
				break;
				case 2:
					tuitionFeePredicate.push_back(tokenP);
				break;
				case 3:
					enrolmentPredicate.push_back(tokenP);
			}
		}
		counter = counter + 1;
	}

	fileP.close();


	//COM_MIN
	//uni
	std::vector<string> universityP;
	for (int i = 0; i < universityPredicate.size(); i++) {
		for (int j = 0; j < universityQuery.size(); j++) {
			if (universityQuery[j].compare(universityPredicate[i].substr(11)) == 0) {
				universityP.push_back(universityPredicate[i]);
				break;
			}
		}
	}

	//put the non in
	if ((universityP.size() < 3) && (universityP.size() > 0)) {
		std::vector<string> universityPTemp;
		while (universityP.size() != 0) {
			for (int i = 0; i < universityP.size(); i++) {
				if (universityP[i].substr(11).compare("UofA") == 0) {
					universityPTemp.push_back(universityP[i]);
					universityP.erase(universityP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < universityP.size(); i++) {
				if (universityP[i].substr(11).compare("UniSA") == 0) {
					universityPTemp.push_back(universityP[i]);
					universityP.erase(universityP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < universityP.size(); i++) {
				if (universityP[i].substr(11).compare("Flinders") == 0) {
					universityPTemp.push_back(universityP[i]);
					universityP.erase(universityP.begin() + i);
					break;
				}
			}
		}
		string str;
		universityP.clear();
		for (int i = 0; i < universityPTemp.size(); i++) {
			universityP.push_back(universityPTemp[i]);
			if (i == (universityPTemp.size() - 1)) {
				str = str + universityPTemp[i].insert(10, "!");
			}
			else {
				str = str + universityPTemp[i].insert(10, "!") + "\t";
			}
		}
		universityP.push_back(str);
	}
	universityP.push_back("LU");


	//prog
	std::vector<string> programP;
	for (int i = 0; i < programPredicate.size(); i++) {
		for (int j = 0; j < programQuery.size(); j++) {
			if (programQuery[j].compare(programPredicate[i].substr(8)) == 0) {
				programP.push_back(programPredicate[i]);
				break;
			}
		}
	}

	//put the non in
	if ((programP.size() < 5) && (programP.size() > 0)) {
		std::vector<string> programPTemp;
		while (programP.size() != 0) {
			for (int i = 0; i < programP.size(); i++) {
				if (programP[i].substr(8).compare("PhD") == 0) {
					programPTemp.push_back(programP[i]);
					programP.erase(programP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < programP.size(); i++) {
				if (programP[i].substr(8).compare("MCS") == 0) {
					programPTemp.push_back(programP[i]);
					programP.erase(programP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < programP.size(); i++) {
				if (programP[i].substr(8).compare("MSE") == 0) {
					programPTemp.push_back(programP[i]);
					programP.erase(programP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < programP.size(); i++) {
				if (programP[i].substr(8).compare("BCS") == 0) {
					programPTemp.push_back(programP[i]);
					programP.erase(programP.begin() + i);
					break;
				}
			}
			for (int i = 0; i < programP.size(); i++) {
				if (programP[i].substr(8).compare("BSE") == 0) {
					programPTemp.push_back(programP[i]);
					programP.erase(programP.begin() + i);
					break;
				}
			}
		}
		string str;
		programP.clear();
		for (int i = 0; i < programPTemp.size(); i++) {
			programP.push_back(programPTemp[i]);
			if (i == (programPTemp.size() - 1)) {
				str = str + programPTemp[i].insert(7, "!");
			}
			else {
				str = str + programPTemp[i].insert(7, "!") + "\t";
			}
		}
		programP.push_back(str);
	}
	programP.push_back("LU");


	//fee
	std::vector<string> tuitionFeeP;
	for (int i = 0; i < tuitionFeePredicate.size(); i++) {
		for (int j = 0; j < tuitionFeeQuery.size(); j++) {
				if (tuitionFeeQuery[j].compare(tuitionFeePredicate[i].substr(10)) == 0) {
				tuitionFeeP.push_back(tuitionFeePredicate[i]);
				if (tuitionFeePredicate[i].substr(11, 1).compare("=") == 0) {
					tuitionFeePredicate[i].erase(11, 1);
					if (tuitionFeePredicate[i].substr(10, 1).compare(">") == 0) {
						tuitionFeePredicate[i].replace(10, 1, "<");
					}
					else {
						tuitionFeePredicate[i].replace(10, 1, ">");
					}
				}
				else {
					if (tuitionFeePredicate[i].substr(10, 1).compare(">") == 0) {
						tuitionFeePredicate[i].replace(10, 1, "<=");
					}
					else {
						tuitionFeePredicate[i].replace(10, 1, ">=");
					}
				}
				tuitionFeeP.push_back(tuitionFeePredicate[i]);
				break;
			}
		}
	}


	//remove the meaningless items of tuitionFee
	if (tuitionFeeP.size() > 2) {
		std::vector<string> tuitionFeeTempL;
		std::vector<string> tuitionFeeTempG;
		for (int i = 0; i < tuitionFeeP.size(); i++) {
			if (tuitionFeeP[i].substr(10, 1).compare("<") == 0) {
				tuitionFeeTempL.push_back(tuitionFeeP[i]);
			}
			else {
				tuitionFeeTempG.push_back(tuitionFeeP[i]);
			}
		}
		string num;
		int flag = 999999999;
		int mark = 0;
		std::vector<string> tuitionFeeLess;
		std::vector<string> tuitionFeeGreater;
		int size = tuitionFeeTempL.size();
		while (tuitionFeeLess.size() != size) {
			for (int i = 0; i < tuitionFeeTempL.size(); i++) {
				num.clear();
				for (int j = 0; j < tuitionFeeTempL[i].size(); j++) {
					if (isdigit(tuitionFeeTempL[i][j])) {
						num = num + tuitionFeeTempL[i][j];
					}
				}
				if (stoi(num) < flag) {
					flag = stoi(num);
					mark = i;
				}
			}
			tuitionFeeLess.push_back(tuitionFeeTempL[mark]);
			tuitionFeeGreater.push_back(tuitionFeeTempG[mark]);
			tuitionFeeTempL.erase(tuitionFeeTempL.begin() + mark);
			tuitionFeeTempG.erase(tuitionFeeTempG.begin() + mark);
			flag = 9999999;
			mark = 0;
		}
		std::vector<string> tuitionFeeTemp;
		for (int i = 0; i < tuitionFeeLess.size(); i++) {
			tuitionFeeTemp.push_back(tuitionFeeLess[i]);
			tuitionFeeTemp.push_back(tuitionFeeGreater[i]);
		}
		tuitionFeeP.clear();
		tuitionFeeP.push_back(tuitionFeeTemp[0]);
		int i = 1;
		while (i < tuitionFeeTemp.size()) {
			if (i == tuitionFeeTemp.size() - 1) {
				tuitionFeeP.push_back(tuitionFeeTemp[i]);
			}
			else {
				string str = tuitionFeeTemp[i] + "\t" + tuitionFeeTemp[i + 1];
				tuitionFeeP.push_back(str);
			}
			i = i + 2;
		}
	}
	tuitionFeeP.push_back("LU");


	//enrolment
	std::vector<string> enrolmentP;
	for (int i = 0; i < enrolmentPredicate.size(); i++) {
		for (int j = 0; j < enrolmentQuery.size(); j++) {
				if (enrolmentQuery[j].compare(enrolmentPredicate[i].substr(9)) == 0) {
				enrolmentP.push_back(enrolmentPredicate[i]);
				if (enrolmentPredicate[i].substr(10, 1).compare("=") == 0) {
					enrolmentPredicate[i].erase(10, 1);
					if (enrolmentPredicate[i].substr(9, 1).compare(">") == 0) {
						enrolmentPredicate[i].replace(9, 1, "<");
					}
					else {
						enrolmentPredicate[i].replace(9, 1, ">");
					}
				}
				else {
					if (enrolmentPredicate[i].substr(9, 1).compare(">") == 0) {
						enrolmentPredicate[i].replace(9, 1, "<=");
					}
					else {
						enrolmentPredicate[i].replace(9, 1, ">=");
					}
				}
				enrolmentP.push_back(enrolmentPredicate[i]);
				break;
			}
		}
	}


	//remove the meaningless items of enrolment
	if (enrolmentP.size() > 2) {
		std::vector<string> enrolmentTempL;
		std::vector<string> enrolmentTempG;
		for (int i = 0; i < enrolmentP.size(); i++) {
			if (enrolmentP[i].substr(9, 1).compare("<") == 0) {
				enrolmentTempL.push_back(enrolmentP[i]);
			}
			else {
				enrolmentTempG.push_back(enrolmentP[i]);
			}
		}
		string num;
		int flag = 999999999;
		int mark = 0;
		std::vector<string> enrolmentLess;
		std::vector<string> enrolmentGreater;
		int size = enrolmentTempL.size();
		while (enrolmentLess.size() != size) {
			for (int i = 0; i < enrolmentTempL.size(); i++) {
				num.clear();
				for (int j = 0; j < enrolmentTempL[i].size(); j++) {
					if (isdigit(enrolmentTempL[i][j])) {
						num = num + enrolmentTempL[i][j];
					}
				}
				if (stoi(num) < flag) {
					flag = stoi(num);
					mark = i;
				}
			}
			enrolmentLess.push_back(enrolmentTempL[mark]);
			enrolmentGreater.push_back(enrolmentTempG[mark]);
			enrolmentTempL.erase(enrolmentTempL.begin() + mark);
			enrolmentTempG.erase(enrolmentTempG.begin() + mark);
			flag = 9999999;
			mark = 0;
		}
		std::vector<string> enrolmentTemp;
		for (int i = 0; i < enrolmentLess.size(); i++) {
			enrolmentTemp.push_back(enrolmentLess[i]);
			enrolmentTemp.push_back(enrolmentGreater[i]);
		}
		enrolmentP.clear();
		enrolmentP.push_back(enrolmentTemp[0]);
		int i = 1;
		while (i < enrolmentTemp.size()) {
			if (i == enrolmentTemp.size() - 1) {
				enrolmentP.push_back(enrolmentTemp[i]);
			}
			else {
				string str = enrolmentTemp[i] + "\t" + enrolmentTemp[i + 1];
				enrolmentP.push_back(str);
			}
			i = i + 2;
		}
	}
	enrolmentP.push_back("LU");



	//determine the set M of minterm predicates directly
	std::vector<string> mintermPredicates;
	std::vector<std::vector<string>> mintermP;
	counter = 0;
	std::vector<int> label (4, 0);
	for (int i = 0; i < universityP.size(); i++) {
		if (universityP[i].compare("LU") != 0) {
			mintermPredicates.push_back(universityP[i]);
			label[0] = 1;
		}
		for (int j = 0; j < programP.size(); j++) {
			if (programP[j].compare("LU") != 0) {
				mintermPredicates.push_back(programP[j]);
				label[1] = 1;
			}
			for (int m = 0; m < tuitionFeeP.size(); m++) {
				if (tuitionFeeP[m].compare("LU") != 0){
					mintermPredicates.push_back(tuitionFeeP[m]);
					label[2] = 1;
				}
				for (int n = 0; n < enrolmentP.size(); n++) {
					if (enrolmentP[n].compare("LU") != 0) {
						mintermPredicates.push_back(enrolmentP[n]);
						label[3] = 1;
					}
					mintermP.push_back(mintermPredicates);
					if (label[3] == 1) {
						mintermPredicates.pop_back();
					}
					label[3] = 0;
				}
				if (label[2] == 1) {
					mintermPredicates.pop_back();
				}
				label[2] = 0;
			}
			if (label[1] == 1) {
				mintermPredicates.pop_back();
			}
			label[1] = 0;
		}
		if (label[0] == 1) {
			mintermPredicates.pop_back();
		}
		label[0] = 0;
	}

	// clean mintermP
	counter = 0;
	if (universityP.size() == 1) {
		counter = counter + 1;
	}
	if (programP.size() == 1) {
		counter = counter + 1;
	}
	if (tuitionFeeP.size() == 1) {
		counter = counter + 1;
	}
	if (enrolmentP.size() == 1) {
		counter = counter + 1;
	}
	for (int i = 0; i < mintermP.size(); i++) {
		if (mintermP[i].size() != (4 - counter)) {
			mintermP.erase(mintermP.begin() + i);
			i = i - 1;
		}
	}

//test
	//output
	// for (int i = 0; i < mintermP.size(); i++) {
	// 	for (int j = 0; j < mintermP[i].size(); j++) {
	// 		if (j != (mintermP[i].size() - 1)) {
	// 			cout << mintermP[i][j] << "\t";
	// 		}
	// 		else {
	// 			cout << mintermP[i][j];
	// 		}
	// 	}
	// 	cout << endl;
	// }
	// cout << "---------------" << endl;

	//go through the database
	std::vector<string> num;
	for (int i = 0; i < 2; i++) {
		num.push_back("");
	}

	counter = 0;
	for (int i = 0; i < mintermP.size(); i++) {
		std::vector<int> marker (4, 0);
		for (int j = 0; j < records.size(); j++) {
			//marker = 0;
			for (int m = 0; m < mintermP[i].size(); m++) {
				marker[m] = 0;
				if (mintermP[i][m].substr(0, 1).compare("U") == 0) {
					if (mintermP[i][m].substr(10, 1).compare("!") != 0) {
						if (mintermP[i][m].substr(11).compare(records[j].getUniversity()) == 0) {
							marker[m] = 1;
						}
						else {
							marker[m] = 0;
							//break;
						}
					}
					else {
						if (mintermP[i][m].find(records[j].getUniversity()) == std::string::npos) {
							marker[m] = 1;
//test
							// if ((records[j].getUniversity().compare("Flinders") == 0) && (records[j].getProgram().compare("MSE") == 0) && (records[j].getTuitionFee() == 13)) {
							// 	cout << "testU: " << mintermP[i][m] << endl;
							// }
						}
						else {
							marker[m] = 0;
							//break;
						}
					}
				}

				if (mintermP[i][m].substr(0, 1).compare("P") == 0) {
					if (mintermP[i][m].substr(7, 1).compare("!") != 0) {
						if (mintermP[i][m].substr(8).compare(records[j].getProgram()) == 0) {
							marker[m] = 1;
						}
						else {
							marker[m] = 0;
							//break;
						}
					}
					else {
						if (mintermP[i][m].find(records[j].getProgram()) == std::string::npos) {
							marker[m] = 1;
//test
							// if ((records[j].getUniversity().compare("Flinders") == 0) && (records[j].getProgram().compare("MSE") == 0) && (records[j].getTuitionFee() == 13)) {
							// 	cout << "testP: " << mintermP[i][m] << endl;
							// }
						}
						else {
							marker[m] = 0;
							//break;
						}
					}
				}
				
				if (mintermP[i][m].substr(0, 1).compare("T") == 0) {
					std::vector<string> strT;
					istringstream ss(mintermP[i][m]);
					string t;
					while (getline(ss, t, '\t')) {
						strT.push_back(t);
					}
					//marker[m] = 0;
					for (int l = 0; l < strT.size(); l++) {
						num[l].clear();
						for (int k = 0; k < strT[l].size(); k++) {
							if (isdigit(strT[l][k])) {
								num[l] = num[l] + strT[l][k];
							}
						}
						if (((strT[l].substr(10,1).compare("<") == 0) && (stoi(num[l]) > records[j].getTuitionFee())) || ((strT[l].substr(10,1).compare(">") == 0) && (stoi(num[l]) < records[j].getTuitionFee())) || ((strT[l].substr(10,2).compare("<=") == 0) && (stoi(num[l]) >= records[j].getTuitionFee())) || ((strT[l].substr(10,2).compare(">=") == 0) && (stoi(num[l]) <= records[j].getTuitionFee()))) {
							marker[m] = 1;
//test
							// if ((records[j].getUniversity().compare("Flinders") == 0) && (records[j].getProgram().compare("MSE") == 0) && (records[j].getTuitionFee() == 13)) {
							// 	cout << "testT: " << mintermP[i][m] << endl;
							// }
						}
						else {
							marker[m] = 0;
							break;
						}
					}
				}
				
				if (mintermP[i][m].substr(0, 1).compare("E") == 0) {
					std::vector<string> strTe;
					istringstream sse(mintermP[i][m]);
					string te;
					while (getline(sse, te, '\t')) {
						strTe.push_back(te);
					}
					//marker[m] = 0;
					for (int l = 0; l < strTe.size(); l++) {
						num[l].clear();
						for (int k = 0; k < strTe[l].size(); k++) {
							if (isdigit(strTe[l][k])) {
								num[l] = num[l] + strTe[l][k];
							}
						}
						if (((strTe[l].substr(9,1).compare("<") == 0) && (stoi(num[l]) > records[j].getEnrolment())) || ((strTe[l].substr(9,1).compare(">") == 0) && (stoi(num[l]) < records[j].getEnrolment())) || ((strTe[l].substr(9,2).compare("<=") == 0) && (stoi(num[l]) >= records[j].getEnrolment())) || ((strTe[l].substr(9,2).compare(">=") == 0) && (stoi(num[l]) <= records[j].getEnrolment()))) {
							marker[m] = 1;
//test
							// if ((records[j].getUniversity().compare("Flinders") == 0) && (records[j].getProgram().compare("MSE") == 0) && (records[j].getTuitionFee() == 13)) {
							// 	cout << "testE: " << mintermP[i][m] << endl;
							// }
						}
						else {
							marker[m] = 0;
							break;
						}
					}
				}
			}
			int x = 0;
//test
			// cout << "mintermP size: " << mintermP[i].size() << endl;
			for (int m = 0; m < mintermP[i].size(); m++) {
				if (marker[m] == 1) {
					x = x + 1;
				}
			}
			if (x == mintermP[i].size()) {
				records.erase(records.begin() + j);
				counter = 0;
				break;
			}
			else {
				counter = counter + 1;
			}
		}
		if (counter == records.size()) {
			mintermP.erase(mintermP.begin() + i);
			i = i - 1;
		}
		counter = 0;
	}

	//output
	for (int i = 0; i < mintermP.size(); i++) {
		for (int j = 0; j < mintermP[i].size(); j++) {
			if (j != (mintermP[i].size() - 1)) {
				cout << mintermP[i][j] << "\t";
			}
			else {
				cout << mintermP[i][j];
			}
		}
		cout << endl;
	}
	
	

	return 0;
}

