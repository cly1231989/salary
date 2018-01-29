#include "stdafx.h"
#include "Date.h"


Date::Date()
{
	memset(&m_day, 0, sizeof(std::tm));
}

Date::Date(int year, int month, int day)
{
	memset(&m_day, 0, sizeof(std::tm));
	m_day.tm_year = year - 1900;
	m_day.tm_mon = month - 1;
	m_day.tm_mday = day;
}


Date::~Date()
{
}

int Date::getYear() const
{
	return m_day.tm_year;
}

int Date::getMonth() const
{
	return m_day.tm_mon;
}

int Date::getDay() const
{
	return m_day.tm_mday;
}

Date::WeekDay Date::getWeekDay() const
{
	WeekDay weekDays[] = { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

	std::tm newDay = m_day;
	std::time_t timeTemp = std::mktime(&newDay);
	std::tm time = { 0 };
	localtime_s(&time, &timeTemp);
	
	return weekDays[time.tm_wday];
}

bool Date::operator==(const Date & d) const
{
	return m_day.tm_year == d.m_day.tm_year
		&& m_day.tm_mon == d.m_day.tm_mon
		&& m_day.tm_mday == d.m_day.tm_mday;
}

bool Date::operator<(const Date & d) const
{
	if (m_day.tm_year < d.m_day.tm_year)
		return true;
	else if (m_day.tm_year > d.m_day.tm_year)
		return false;
	else
	{
		if (m_day.tm_mon < d.m_day.tm_mon)
			return true;
		else if (m_day.tm_mon > d.m_day.tm_mon)
			return false;
		else
			return m_day.tm_mday < d.m_day.tm_mday;
	}
}

bool Date::operator<=(const Date & d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date & d) const
{
	return d < *this;
}

bool Date::operator>=(const Date & d) const
{
	return !(*this < d);
}

Date Date::operator+(int day) const
{
	Date newDate = *this;
	newDate.m_day.tm_mday += day;
	return newDate;
}

Date Date::operator-(int day) const
{
	Date newDate = *this;
	newDate.m_day.tm_mday -= day;
	return newDate;
}

bool Date::isLastDayOfMonth() const
{
	return m_day.tm_mon != (*this+1).m_day.tm_mon;
}

bool Date::isInBetween(const Date & date, const Date & beginDate, const Date & endDate)
{
	return date > beginDate && date <= endDate;
}
