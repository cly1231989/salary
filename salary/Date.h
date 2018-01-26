#pragma once
#include <ctime>

class Date
{
public:
	enum WeekDay{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

	Date();
	Date(int year, int month, int day);
	~Date();

	Date::WeekDay getWeekDay();

	bool operator == (const Date& d) const;
	bool operator < (const Date& d) const;

private:
	std::tm m_day;
};

