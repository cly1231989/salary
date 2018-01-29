#include "stdafx.h"
#include "CommissionPaySchedule.h"


CommissionPaySchedule::CommissionPaySchedule()
{
}


CommissionPaySchedule::~CommissionPaySchedule()
{
}

bool CommissionPaySchedule::isPayDay(const Date & date)
{
	return false;
}

Date CommissionPaySchedule::getBeginDate(const Date & endDate)
{
	return Date();
}
