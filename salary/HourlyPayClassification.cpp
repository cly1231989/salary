#include "stdafx.h"
#include "HourlyPayClassification.h"


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
