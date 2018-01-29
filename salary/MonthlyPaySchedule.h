#pragma once
#include "PaySchedule.h"
class MonthlyPaySchedule :
	public PaySchedule
{
public:
	MonthlyPaySchedule();
	virtual ~MonthlyPaySchedule();

	// Inherited via PaySchedule
	virtual bool isPayDay(const Date & date) override;

	// Inherited via PaySchedule
	virtual Date getBeginDate(const Date & endDate) override;
};

