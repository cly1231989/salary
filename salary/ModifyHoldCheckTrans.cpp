#include "stdafx.h"
#include "ModifyHoldCheckTrans.h"
#include "HoldPayMethod.h"
#include <memory>

ModifyHoldCheckTrans::ModifyHoldCheckTrans(int employeeID)
	:ModifyEmployeeTransaction(employeeID)
{
}


ModifyHoldCheckTrans::~ModifyHoldCheckTrans()
{
}

void ModifyHoldCheckTrans::changeEmployee(Employee & employee)
{
	employee.setPayMethod(std::make_unique<HoldPayMethod>());
}
