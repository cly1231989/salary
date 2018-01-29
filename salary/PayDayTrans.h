#pragma once
#include "Transaction.h"
#include "PayCheck.h"
#include "Date.h"
#include <map>

class PayDayTrans :
	public Transaction
{
public:
	PayDayTrans(Date date);
	virtual ~PayDayTrans();

	// Inherited via Transaction
	virtual void excute() override;
	bool getPayCheck(int employeeID, PayCheck &payCheck);

private:
	Date m_date;
	std::map<int, PayCheck> m_payChecks;
};

