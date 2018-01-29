#pragma once
#include "PaySchedule.h"

class HourlyPaySchedule: public PaySchedule
{
public:
	HourlyPaySchedule();
	virtual ~HourlyPaySchedule();

	// Inherited via PaySchedule
	virtual bool isPayDay(const Date & date) override;
	virtual Date getBeginDate(const Date &endDate) override;
};

