#include "stdafx.h"
#include "MonthlyPaySchedule.h"


MonthlyPaySchedule::MonthlyPaySchedule()
{
}


MonthlyPaySchedule::~MonthlyPaySchedule()
{
}

bool MonthlyPaySchedule::isPayDay(const Date & date)
{
	return date.isLastDayOfMonth();
}

Date MonthlyPaySchedule::getBeginDate(const Date & endDate)
{
	return Date(endDate.getYear(), endDate.getMonth(), 1);
}
