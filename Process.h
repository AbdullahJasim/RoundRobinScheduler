#pragma once

#include <string>

class Process {
public:
	Process(const std::string& name) : m_Name(name) {};
	virtual ~Process() {};

	void DoWorkDuringTimeSlice();
	bool operator==(const Process& rhs);

private:
	std::string m_Name;
};