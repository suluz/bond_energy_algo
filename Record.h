//
// This code is the header of class record
//
// Author: Zhigang Lu

#ifndef _RECORD_H_
#define _RECORD_H_

#include <string>
#include <stdlib.h>


using namespace std;


class Record {

private:
	string SID;
	string university;
	string program;
	int tuitionFee = 0;
	int enrolment = 0;

public:
	Record() {

	};

	Record(string s, string u, string p, int t, int e) {
	SID = s;
	university = u;
	program = p;
	tuitionFee = t;
	enrolment = e;
	};

	string getUniversity();
	string getProgram();
	int getTuitionFee();
	int getEnrolment();

};

#endif