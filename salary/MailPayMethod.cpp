#include "stdafx.h"
#include "MailPayMethod.h"


MailPayMethod::MailPayMethod(std::string mailAddress)
{
	m_mailAddress = mailAddress;
}


MailPayMethod::~MailPayMethod()
{
}

std::string MailPayMethod::getMailAddress()  const
{
	return m_mailAddress;
}