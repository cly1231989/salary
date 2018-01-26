#pragma once
class Affiliation
{
public:
	Affiliation();
	virtual ~Affiliation();

	virtual float getAllFees() = 0;
};

