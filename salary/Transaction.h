#pragma once
class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

	virtual void excute() = 0;
};

