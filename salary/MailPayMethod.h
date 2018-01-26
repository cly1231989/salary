#pragma once
#include "PayMethod.h"
#include <string>

class MailPayMethod :
	public PayMethod
{
public:
	MailPayMethod(std::string mailAddress);
	virtual ~MailPayMethod();

	std::string getMailAddress() const;

private:
	std::string m_mailAddress;
};

