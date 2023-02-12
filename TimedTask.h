//Name: Shayan Chabook
//student ID: 159844208
//email:schabook@myseneca.ca
//5/28/2022
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <string>
#include <chrono>
#include <iostream>
using namespace std;
namespace sdds {

	class TimedTask {


		int numberOfRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point stopTime;


		struct Task //array of 10
		{
			string taskName;
			string unitsOfTime;
			std::chrono::steady_clock::duration duration;
		};

		Task tasks[10];

	public:

		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* task);

		friend ostream& operator<<(ostream& istr, TimedTask& time);

	};
}
#endif
