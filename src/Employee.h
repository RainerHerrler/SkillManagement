#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using namespace std;

class Employee {
private:
	string employeeId_;
	string name_;
	string department_;
public:
	Employee(const string& employeeID, const string& name, const string& department);
	string getEmployeeID() const;
	string getName() const;
	string getDepartment() const;
	void setDepartment(const string &department);
	void setName(const string &name);
};

#endif /* EMPLOYEE_H_ */
