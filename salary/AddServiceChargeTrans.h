#pragma once
#include "Transaction.h"
#include "Date.h"

class AddServiceChargeTrans :
	public Transaction
{
public:
	AddServiceChargeTrans(int memberID, float amount, const Date &date);
	virtual ~AddServiceChargeTrans();

	// Inherited via Transaction
	virtual void excute() override;

private:
	int m_memberID;
	float m_amount;
	Date m_date;
};

