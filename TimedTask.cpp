//Name: Shayan Chabook
//student ID: 159844208
//email:schabook@myseneca.ca
//5/28/2022
#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "TimedTask.h"
using namespace std;

namespace sdds {

	TimedTask::TimedTask()
	{
		numberOfRecords = 0;
		//start time
		//stop time
	}

	void TimedTask::startClock()
	{
		//starts the clock
		startTime = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock()
	{
		//stops the clock
		stopTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* task)
	{
		int static flag = 0;
		tasks[flag].taskName = task; //sus

		tasks[flag].unitsOfTime = "nanoseconds";

		tasks[flag].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime); 
		
		flag += 1;
	}

	ostream& operator<<(ostream& ostr, TimedTask& time)
	{
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;
		for (int i = 0; i < 7; i++)
		{
			ostr << setw(21) << left << time.tasks[i].taskName;

			ostr << time.tasks[i].duration.count();
			ostr << setw(13) << right << time.tasks[i].unitsOfTime << endl;
		}
		cout << "--------------------------\n";

		return ostr;
	}

}