#include "stdafx.h"
#include "HourlyPayClassification.h"
#include <algorithm>

HourlyPayClassification::HourlyPayClassification(float hourlyRate)
{
	m_hourlyRate = hourlyRate;
}


HourlyPayClassification::~HourlyPayClassification()
{
}

float HourlyPayClassification::getHourlyRate()
{
	return m_hourlyRate;
}

void HourlyPayClassification::addTimeCard(const Date & date, float hours)
{
	TimeCard timeCard = { date, hours };
	m_timeCards[date] = timeCard;
}

float HourlyPayClassification::getTimeCardHours(const Date & date)
{
	return m_timeCards[date].hours;
}

float HourlyPayClassification::payday(PayCheck & payCheck)
{
	//对于m_timeCards的每一项，需要检查是否在当期内
	float gross = 0;

	auto firstTimeCard = m_timeCards.begin();
	auto lastTimeCard = m_timeCards.end();
	for (; firstTimeCard != lastTimeCard; firstTimeCard++)
	{
		if (Date::isInBetween(firstTimeCard->second.date, payCheck.getBeginDate(), payCheck.getEndDate()))
		{
			float overTime = std::max(0.0f, firstTimeCard->second.hours - 8);
			float straitTime = firstTimeCard->second.hours - overTime;

			gross += straitTime * m_hourlyRate + overTime * 1.5f * m_hourlyRate;
		}
	}

	return gross;
}
