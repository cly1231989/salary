#pragma once
#include <memory>
#include <string>

class PayMethod;
class PaySchedule;
class PayClassification;
class Affiliation;

class Employee
{
public:
	Employee(int employeeID, std::string name, std::string address);
	~Employee();

	int getID();
	std::string getName() const;
	std::string getAddress() const;

	void setName(const std::string &name);
	void setAddress(const std::string &address);

	void setAffiliation(std::unique_ptr<Affiliation>);
	void setPayMethod(std::unique_ptr<PayMethod> );
	void setPaySchedule(std::unique_ptr<PaySchedule>);
	void setPayClassification(std::unique_ptr<PayClassification>);

	std::unique_ptr<Affiliation>& getAffiliation();
	std::unique_ptr<PayMethod>& getPayMethod();
	std::unique_ptr<PaySchedule>& getPaySchedule();
	std::unique_ptr<PayClassification>& getPayClassification();

private:
	int m_employeeID;
	std::string m_name;
	std::string m_address;

	std::unique_ptr<Affiliation> m_affiliation;
	std::unique_ptr<PayMethod> m_payMethod;
	std::unique_ptr<PaySchedule> m_paySchedule;
	std::unique_ptr<PayClassification> m_payClassification;
};

