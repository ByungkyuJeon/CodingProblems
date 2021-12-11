#pragma once


#include <chrono>
#include <functional>


class TimeChecker
{
public:

	/// STATIC TIME CHECKER
	/// 
	/// wroted as higher-order function
	static double CheckTime(const std::function<void()> InFunction)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		InFunction();

		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> timeSpan = endTime - startTime;

		return timeSpan.count();
	}
};