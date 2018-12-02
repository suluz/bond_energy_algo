//
// This code is the class record
//
// Author: Zhigang Lu

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "Record.h"

using namespace std;

string Record::getUniversity() {
	return university;
}

string Record::getProgram() {
	return program;
}

int Record::getTuitionFee() {
	return tuitionFee;
}

int Record::getEnrolment() {
	return enrolment;
}