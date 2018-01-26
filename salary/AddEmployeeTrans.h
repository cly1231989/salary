#pragma once
#include "Transaction.h"
//#include "employee.h"
#include <string>
#include <memory>

class PayClassification;
class PaySchedule;

class AddEmployeeTrans :
	public Transaction
{
public:
	AddEmployeeTrans(int employeeID, const std::string &name, const std::string &address);
	virtual ~AddEmployeeTrans();

	virtual void excute() override;

protected:
	virtual std::unique_ptr<PayClassification> getPayClassification() = 0;
	virtual std::unique_ptr<PaySchedule> getPaySchedule() = 0;

private:
	int m_employeeID;
	std::string m_name;
	std::string m_address;
};

