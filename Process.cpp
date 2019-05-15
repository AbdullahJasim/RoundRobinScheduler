#include <iostream>
#include "Process.h"

using namespace std;

void Process::DoWorkDuringTimeSlice() {
	cout << "Process " << m_Name << " is running..." << endl;
}

bool Process::operator==(const Process& rhs) {
	return m_Name == rhs.m_Name;
}