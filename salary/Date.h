#pragma once
#include <ctime>

class Date
{
public:
	enum WeekDay{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

	Date();
	Date(int year, int month, int day);
	~Date();

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	Date::WeekDay getWeekDay() const;

	bool operator == (const Date& d) const;
	
	bool operator < (const Date& d) const;
	bool operator <= (const Date& d) const;
	
	bool operator > (const Date& d) const;
	bool operator >= (const Date& d) const;

	Date operator + (int day) const;
	Date operator - (int day) const;

	bool isLastDayOfMonth() const;
	static bool isInBetween(const Date &date, const Date &beginDate, const Date &endDate);

private:
	std::tm m_day;
};

