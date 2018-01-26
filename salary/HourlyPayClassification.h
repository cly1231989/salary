#pragma once
#include "PayClassification.h"
#include "Date.h"
#include <map>
class HourlyPayClassification :
	public PayClassification
{
public:
	HourlyPayClassification(float hourlyRate);
	virtual ~HourlyPayClassification();

	float getHourlyRate();
	void addTimeCard(const Date &date, float hours);
	float getTimeCardHours(const Date &date);

private:
	struct TimeCard
	{
		Date date;
		float hours;
	};

	float m_hourlyRate;
	std::map<Date, TimeCard> m_timeCards;
};

