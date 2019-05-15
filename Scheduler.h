#pragma once

#include <iostream>
#include "RoundRobin.h"
#include "Process.h"

class Scheduler {
public:
	Scheduler(const std::vector<Process>& processes);
	virtual ~Scheduler() {};

	void ScheduleTimeSlice();
	void RemoveProcess(const Process& process);

private:
	RoundRobin<Process> m_RR;
};