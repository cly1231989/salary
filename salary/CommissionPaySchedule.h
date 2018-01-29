#pragma once
#include "PaySchedule.h"
class CommissionPaySchedule :
	public PaySchedule
{
public:
	CommissionPaySchedule();
	virtual ~CommissionPaySchedule();

	// Inherited via PaySchedule
	virtual bool isPayDay(const Date & date) override;

	// Inherited via PaySchedule
	virtual Date getBeginDate(const Date & endDate) override;
};

