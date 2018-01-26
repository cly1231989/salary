#pragma once
#include "Affiliation.h"
#include "Date.h"
#include <map>

class UnionAffiliation: public Affiliation
{
public:
	UnionAffiliation(int memberID, float memberRate);
	virtual ~UnionAffiliation();

	int getMemberID() const;
	float getMemberRate() const;
	void addServiceCharge(float amount, const Date &date);

	// Inherited via Affiliation
	virtual float getAllFees() override;

private:
	struct ServiceCharge
	{
		float amount;
		Date date;
	};

	int m_memberID;
	float m_memberRate;
	std::map<Date, ServiceCharge> m_serviceCharges;
};

