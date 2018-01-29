#pragma once
#include "Date.h"

class PaySchedule
{
public:
	PaySchedule();
	virtual ~PaySchedule();

	virtual bool isPayDay(const Date &date) = 0;
	virtual Date getBeginDate(const Date &endDate) = 0;
};

