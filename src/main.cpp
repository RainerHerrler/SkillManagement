#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Example2.h"
#include "Skill.h"
#include "SkillAssociation.h"
#include "SkillManager.h"

using namespace std;

void printEmployeeList(const string &headLine, const vector<Employee*> &employeeList) {
	cout << headLine << endl;
	for (Employee *employee : employeeList) {
		cout << " - " << setw(6) << left << employee->getEmployeeID() << setw(20) << employee->getName() << employee->getDepartment() << endl;
	}
}

void printSkillList(const string &headLine, const vector<Skill*> &skillList) {
	cout << headLine << endl;
	for (Skill *skill : skillList) {
		cout << " - " << skill->getName() << " " << skill->getSkillCategory() << endl;
	}
}

void printAssociations(const string &headLine, const vector<SkillAssociation*> &associationsList) {
	cout << headLine << endl;
	for (SkillAssociation *skill : associationsList) {
		cout << " - " << skill->getEmployee()->getName() << " " << skill->getSkill()->getName() << " " << skill->getSkillLevel() << endl;
	}
}

int main() {
	SkillManager skillManager;

	// Example creation was outsourced
	Example example;
	example.addExampleTo(skillManager);

	// now find all employees with skill "Java"
	cout << "Finding employees with skill \"Java\"." << endl;
	vector<Employee*> javaPeople = skillManager.getListOfEmployees("Java");
	printEmployeeList("**JAVAPEOPLE***", javaPeople);

	// now find all skills of employee "Rainer Herrler" with id 0002
	cout << "Finding skills of employee \"Rainer Herrler\"." << endl;
	vector<Skill*> herrlerSkills = skillManager.getListOfSkills("0002");
	printSkillList("**HERRLERSKILLS***", herrlerSkills);

	// now remove employee "Max Muster" with id "0001"
	cout << "Removing \"Max Muster\"." << endl;
	skillManager.removeEmployee("0001");

	// Print the all SkillAssociations
	cout << "Print all SkillAssociations" << endl;
	printAssociations("After Removal", skillManager.getListOfSkillAssociations());
}

