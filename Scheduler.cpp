#include "Scheduler.h"

using namespace std;

Scheduler::Scheduler(const vector<Process>& processes) {
	for (auto& process: processes) {
		m_RR.Add(process);
	}
}

void Scheduler::ScheduleTimeSlice() {
	try {
		m_RR.GetNext().DoWorkDuringTimeSlice();
	} catch (const out_of_range&) {
		cerr << "No more processes to schedule." << endl;
	}
}

void Scheduler::RemoveProcess(const Process& process) {
	m_RR.Remove(process);
}