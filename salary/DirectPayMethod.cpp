#include "stdafx.h"
#include "DirectPayMethod.h"


DirectPayMethod::DirectPayMethod(const std::string &bank, const std::string &account)
{
	m_bank = bank;
	m_account = account;
}


DirectPayMethod::~DirectPayMethod()
{
}

std::string DirectPayMethod::getBank() const
{
	return m_bank;
}

std::string DirectPayMethod::getAccount() const
{
	return m_account;
}
