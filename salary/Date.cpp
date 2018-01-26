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

Date::WeekDay Date::getWeekDay()
{
	WeekDay weekDays[] = { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	std::time_t timeTemp = std::mktime(&m_day);
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
