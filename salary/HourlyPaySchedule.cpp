#include "stdafx.h"
#include "HourlyPaySchedule.h"


HourlyPaySchedule::HourlyPaySchedule()
{
}


HourlyPaySchedule::~HourlyPaySchedule()
{
}

bool HourlyPaySchedule::isPayDay(const Date & date)
{
	return date.getWeekDay() == Date::Friday;
}

Date HourlyPaySchedule::getBeginDate(const Date & endDate)
{
	return endDate-7;
}
