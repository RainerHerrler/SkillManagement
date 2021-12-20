#include "Employee.h"

/*!
  The employee is described by a unique ID a name and he is associated with a department.
  Employees can have different skills but that is handeled in the association class.
*/
Employee::Employee(const string& employeeID, const string& name, const string& department) :
	employeeId_(employeeID),
	name_(name),
	department_(department) { }

string Employee::getEmployeeID() const {
	return employeeId_;
}


string Employee::getName() const {
	return name_;
}

string Employee::getDepartment() const {
	return department_;
}

void Employee::setDepartment(const string &department) {
	department_ = department;
}

void Employee::setName(const string &name) {
	name_ = name;
}
