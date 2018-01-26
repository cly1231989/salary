#include "stdafx.h"
#include "CppUnitTest.h"
#include "EmployeeDatabase.h"
#include "AddHourlyEmployeeTrans.h"
#include "HourlyPayClassification.h"
#include "HourlyPaySchedule.h"
#include "MailPayMethod.h"
#include "Employee.h"
#include "AddSalaryEmployeeTrans.h"
#include "SalaryPayClassification.h"
#include "MonthlyPaySchedule.h"
#include "AddCommissionEmployeeTrans.h"
#include "CommissionPayClassification.h"
#include "CommissionPaySchedule.h"
#include "DelEmployeeTrans.h"
#include "ModifyEmployeeNameTrans.h"
#include "ModifyEmployeeAddressTrans.h"
#include "ModifyEmployeeHourlyRateTrans.h"
#include "ModifyEmployeeSalarylyRateTrans.h"
#include "ModifyEmployeeCommissionlyRateTrans.h"
#include "MailPayMethod.h"
#include "DirectPayMethod.h"
#include "HoldPayMethod.h"
#include "ModifyMailCheckTrans.h"
#include "ModifyHoldCheckTrans.h"
#include "ModifyDirectPayTrans.h"
#include "Affiliation.h"
#include "UnionAffiliation.h"
#include "NoAffiliation.h"
#include "ModifyEmployeeMemberTrans.h"
#include "ModifyEmployeeUnmemberTrans.h"
#include "AddTimeCardTrans.h"
#include "Date.h"
#include "AddSalesReceiptTrans.h"
#include "AddServiceChargeTrans.h"
#include <string>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern EmployeeDatabase gEmployeeDatabase;

namespace test
{	
	int employeeID = 1;
	int salary = 4000;
	float hourlyRate = 40.0;
	float commissionRate = 30.0;
	std::string name = "bob";
	std::string address = "chongqing";

	TEST_CLASS(UnitTest1)
	{
	public:
		void static testEmployee(const Employee &employee, const std::string &name, const std::string &address)
		{
			Assert::AreEqual(employee.getName(), name);
			Assert::AreEqual(employee.getAddress(), address);
		}

		void static testHourlyEmployee(int employeeID, float hourlyRate, const std::string &name, const std::string &address)
		{
			auto em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, address);

			auto &payClassification = em->getPayClassification();
			auto hourlyPayClassification = dynamic_cast<HourlyPayClassification*>(payClassification.get());
			Assert::IsNotNull(hourlyPayClassification);

			Assert::AreEqual(hourlyPayClassification->getHourlyRate(), hourlyRate);

			auto &paySchedule = em->getPaySchedule();
			Assert::IsNotNull(dynamic_cast<HourlyPaySchedule*>(paySchedule.get()));

			auto &payMethod = em->getPayMethod();
			Assert::IsNotNull(dynamic_cast<MailPayMethod*>(payMethod.get()));
		}

		void static testSalaryEmployee(int employeeID, int salary, const std::string &name, const std::string &address)
		{
			auto em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, address);

			auto &payClassification = em->getPayClassification();
			auto salaryPayClassification = dynamic_cast<SalaryPayClassification*>(payClassification.get());
			Assert::IsNotNull(salaryPayClassification);

			Assert::AreEqual(salaryPayClassification->getSalary(), salary);

			auto &paySchedule = em->getPaySchedule();
			Assert::IsNotNull(dynamic_cast<MonthlyPaySchedule*>(paySchedule.get()));

			auto &payMethod = em->getPayMethod();
			Assert::IsNotNull(dynamic_cast<MailPayMethod*>(payMethod.get()));
		}

		void static testCommissionEmployee(int employeeID, int salary, float commissionRate, const std::string &name, const std::string &address)
		{
			auto em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, address);

			auto &payClassification = em->getPayClassification();
			auto commissionPayClassification = dynamic_cast<CommissionPayClassification*>(payClassification.get());
			Assert::IsNotNull(commissionPayClassification);

			Assert::AreEqual(commissionPayClassification->getSalary(), salary);
			Assert::AreEqual(commissionPayClassification->getCommissionRate(), commissionRate);

			auto &paySchedule = em->getPaySchedule();
			Assert::IsNotNull(dynamic_cast<CommissionPaySchedule*>(paySchedule.get()));

			auto &payMethod = em->getPayMethod();
			Assert::IsNotNull(dynamic_cast<MailPayMethod*>(payMethod.get()));
		}

		
		
		TEST_METHOD(TestAddHourlyEmployeeTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);
		}

		TEST_METHOD(TestAddSalaryEmployeeTrans)
		{
			AddSalaryEmployeeTrans addSalaryEmployeeTrans(employeeID, name, address, salary);
			addSalaryEmployeeTrans.excute();

			testSalaryEmployee(employeeID, salary, name, address);
		}

		TEST_METHOD(TestAddCommissionEmployeeTrans)
		{
			AddCommissionEmployeeTrans addCommissionEmployeeTrans(employeeID, name, address, salary, commissionRate);
			addCommissionEmployeeTrans.excute();

			testCommissionEmployee(employeeID, salary, commissionRate, name, address);
		}

		TEST_METHOD(TestDelEmployeeTrans)
		{
			AddCommissionEmployeeTrans addCommissionEmployeeTrans(employeeID, name, address, salary, commissionRate);
			addCommissionEmployeeTrans.excute();

			auto em = gEmployeeDatabase.getEmployee(employeeID);
			Assert::IsTrue(em.get() != nullptr);

			DelEmployeeTrans delEmployeeTrans(employeeID);
			delEmployeeTrans.excute();

			em = gEmployeeDatabase.getEmployee(employeeID);
			Assert::IsTrue(em.get() == nullptr);
		}

		TEST_METHOD(TestModifyEmployeeNameTrans)
		{
			AddCommissionEmployeeTrans addCommissionEmployeeTrans(employeeID, name, address, salary, commissionRate);
			addCommissionEmployeeTrans.excute();

			auto em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, address);

			std::string newName = "john";
			ModifyEmployeeNameTrans modifyEmployeeNameTrans(employeeID, newName);
			modifyEmployeeNameTrans.excute();

			em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, newName, address);
		}

		TEST_METHOD(TestModifyEmployeeAddressTrans)
		{
			AddCommissionEmployeeTrans addCommissionEmployeeTrans(employeeID, name, address, salary, commissionRate);
			addCommissionEmployeeTrans.excute();

			auto em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, address);

			std::string newAddress = "shanghai";
			ModifyEmployeeAddressTrans modifyEmployeeAddressTrans(employeeID, newAddress);
			modifyEmployeeAddressTrans.excute();

			em = gEmployeeDatabase.getEmployee(employeeID);
			testEmployee(*em, name, newAddress);
		}

		TEST_METHOD(TestModifyEmployeeHourlyRateTrans)
		{
			AddSalaryEmployeeTrans addSalaryEmployeeTrans(employeeID, name, address, salary);
			addSalaryEmployeeTrans.excute();

			testSalaryEmployee(employeeID, salary, name, address);

			ModifyEmployeeHourlyRateTrans modifyEmployeeHourlyRateTrans(employeeID, hourlyRate);
			modifyEmployeeHourlyRateTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);
		}

		TEST_METHOD(TestModifyEmployeeSalarylyRateTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);

			ModifyEmployeeSalarylyRateTrans modifyEmployeeSalarylyRateTrans(employeeID, salary);
			modifyEmployeeSalarylyRateTrans.excute();

			testSalaryEmployee(employeeID, salary, name, address);
		}

		TEST_METHOD(TestModifyEmployeeCommissionlyRateTrans)
		{		
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);

			ModifyEmployeeCommissionlyRateTrans modifyEmployeeCommissionlyRateTrans(employeeID, salary, commissionRate);
			modifyEmployeeCommissionlyRateTrans.excute();

			testCommissionEmployee(employeeID, salary, commissionRate, name, address);
		}

		TEST_METHOD(TestModifyMailCheckTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);


			std::string mailAddress = "da.com";
			ModifyMailCheckTrans modifyMailCheckTrans(employeeID, mailAddress);
			modifyMailCheckTrans.excute();

			auto &payMethod = gEmployeeDatabase.getEmployee(employeeID)->getPayMethod();
			MailPayMethod *mailPayMethod = dynamic_cast<MailPayMethod*>(payMethod.get());
			Assert::AreEqual(mailPayMethod->getMailAddress(), mailAddress);
		}

		TEST_METHOD(TestModifyHoldCheckTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);

			ModifyHoldCheckTrans modifyMailCheckTrans(employeeID);
			modifyMailCheckTrans.excute();

			auto &payMethod = gEmployeeDatabase.getEmployee(employeeID)->getPayMethod();
			Assert::IsNotNull(dynamic_cast<HoldPayMethod*>(payMethod.get()));
		}

		TEST_METHOD(TestModifyDirectPayTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);


			std::string bank = "789";
			std::string account = "2asdfa";
			ModifyDirectPayTrans modifyMailCheckTrans(employeeID, bank, account);
			modifyMailCheckTrans.excute();

			auto &payMethod = gEmployeeDatabase.getEmployee(employeeID)->getPayMethod();
			DirectPayMethod *directPayMethod = dynamic_cast<DirectPayMethod*>(payMethod.get());
			Assert::AreEqual(directPayMethod->getBank(), bank);
			Assert::AreEqual(directPayMethod->getAccount(), account);
		}

		TEST_METHOD(TestModifyEmployeeMemberTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);


			int memberID = 5;
			float memberRate = 30.0;
			ModifyEmployeeMemberTrans modifyEmployeeMemberTrans(employeeID, memberID, memberRate);
			modifyEmployeeMemberTrans.excute();

			auto employee = gEmployeeDatabase.getEmployee(employeeID);
			auto &affiliation = employee->getAffiliation();
			auto unionAffiliation = dynamic_cast<UnionAffiliation*>(affiliation.get());
			Assert::AreEqual(unionAffiliation->getMemberRate(), memberRate);
			Assert::AreEqual(unionAffiliation->getMemberID(), memberID);
		}

		TEST_METHOD(TestModifyUnmemberTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);


			int memberID = 5;
			float memberRate = 30.0;
			ModifyEmployeeMemberTrans modifyEmployeeMemberTrans(employeeID, memberID, memberRate);
			modifyEmployeeMemberTrans.excute();

			auto employee = gEmployeeDatabase.getEmployee(employeeID);
			auto &affiliation = employee->getAffiliation();
			auto unionAffiliation = dynamic_cast<UnionAffiliation*>(affiliation.get());
			Assert::AreEqual(unionAffiliation->getMemberRate(), memberRate);
			Assert::AreEqual(unionAffiliation->getMemberID(), memberID);

			ModifyEmployeeUnmemberTrans modifyEmployeeUnmemberTrans(employeeID);
			modifyEmployeeUnmemberTrans.excute();

			employee = gEmployeeDatabase.getEmployee(employeeID);
			auto &affiliation1 = employee->getAffiliation();
			Assert::IsNotNull( dynamic_cast<NoAffiliation*>(affiliation1.get()) );
		}

		TEST_METHOD(TestAddTimeCardTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);

			float hours = 5;
			Date date(2018, 1, 26);
			AddTimeCardTrans addTimeCardTrans(employeeID, date, hours);
			addTimeCardTrans.excute();

			auto employee = gEmployeeDatabase.getEmployee(employeeID);
			HourlyPayClassification *hourlyPayClassification = dynamic_cast<HourlyPayClassification *>(employee->getPayClassification().get());
			Assert::AreEqual(hourlyPayClassification->getTimeCardHours(date), hours);
		}

		TEST_METHOD(TestAddSalesReceiptTrans)
		{
			AddCommissionEmployeeTrans addCommissionEmployeeTrans(employeeID, name, address, salary, commissionRate);
			addCommissionEmployeeTrans.excute();

			testCommissionEmployee(employeeID, salary, commissionRate, name, address);

			int amount = 25;
			Date date(2018, 1, 26);
			AddSalesReceiptTrans addSalesReceiptTrans(employeeID, date, amount);
			addSalesReceiptTrans.excute();

			auto employee = gEmployeeDatabase.getEmployee(employeeID);
			CommissionPayClassification *commissionPayClassification = dynamic_cast<CommissionPayClassification*>(employee->getPayClassification().get());
			Assert::AreEqual(commissionPayClassification->getSalesReceiptAmount(date), amount);
		}

		TEST_METHOD(TestAddServiceChargeTrans)
		{
			AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
			addHourlyEmployeeTrans.excute();

			testHourlyEmployee(employeeID, hourlyRate, name, address);


			int memberID = 5;
			float memberRate = 30.0;
			ModifyEmployeeMemberTrans modifyEmployeeMemberTrans(employeeID, memberID, memberRate);
			modifyEmployeeMemberTrans.excute();

			auto employee = gEmployeeDatabase.getEmployee(employeeID);
			auto &affiliation = employee->getAffiliation();
			auto unionAffiliation = dynamic_cast<UnionAffiliation*>(affiliation.get());
			Assert::AreEqual(unionAffiliation->getMemberRate(), memberRate);
			Assert::AreEqual(unionAffiliation->getMemberID(), memberID);
			Assert::AreEqual(unionAffiliation->getAllFees(), memberRate);

			float amount = 25;
			Date date(2018, 1, 26);
			AddServiceChargeTrans addServiceChargeTrans(memberID, amount, date);
			addServiceChargeTrans.excute();

			auto employee1 = gEmployeeDatabase.getEmployee(employeeID);
			auto &affiliation1 = employee1->getAffiliation();
			auto unionAffiliation1 = dynamic_cast<UnionAffiliation*>(affiliation1.get());
			Assert::AreEqual(unionAffiliation1->getMemberRate(), memberRate);
			Assert::AreEqual(unionAffiliation1->getMemberID(), memberID);
			Assert::AreEqual(unionAffiliation1->getAllFees(), memberRate + amount);
		}

		TEST_METHOD(TestPayDay)
		{
			Date date(2018, 1, 26);
			PayDayTrans payDayTrans(date);

			payDayTrans.excute();
		}
	};
}