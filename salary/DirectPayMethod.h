#pragma once
#include "PayMethod.h"
#include <string>

class DirectPayMethod :
	public PayMethod
{
public:
	DirectPayMethod(const std::string &bank, const std::string &account);
	virtual ~DirectPayMethod();

	std::string getBank() const;
	std::string getAccount() const;

	// Inherited via PayMethod
	virtual void pay(const PayCheck & payCheck) override;

private:
	std::string m_bank;
	std::string m_account;
};

