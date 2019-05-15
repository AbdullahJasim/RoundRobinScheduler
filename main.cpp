//A simple round robin scheduling program

#include <iostream>
#include "Scheduler.h"

using namespace std;

int main() {
	vector<Process> processes =	{Process("1"), Process("2") , Process("3")};

	Scheduler s(processes);

	for (int i = 0; i < 4; ++i) s.ScheduleTimeSlice();

	s.RemoveProcess(processes[2]);
	cout << "Removed third process" << endl;

	for (int i = 0; i < 4; ++i) s.ScheduleTimeSlice();

	cin.get();

	return 0;
}