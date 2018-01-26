#include "stdafx.h"
#include "ModifyEmployeeUnmemberTrans.h"
#include "NoAffiliation.h"
#include "EmployeeDatabase.h"
#include "UnionAffiliation.h"
#include <memory>

extern EmployeeDatabase gEmployeeDatabase;

ModifyEmployeeUnmemberTrans::ModifyEmployeeUnmemberTrans(int employeeID)
	:ModifyEmployeeTransaction(employeeID)
{
}


ModifyEmployeeUnmemberTrans::~ModifyEmployeeUnmemberTrans()
{
}

void ModifyEmployeeUnmemberTrans::changeEmployee(Employee & employee)
{
	auto affiliation = dynamic_cast<UnionAffiliation*>(employee.getAffiliation().get());
	if (affiliation != nullptr)
		gEmployeeDatabase.delMember(affiliation->getMemberID());

	employee.setAffiliation(std::make_unique<NoAffiliation>());
}
