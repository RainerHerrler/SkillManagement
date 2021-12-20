#include <iostream>
#include <iomanip>
#include "Skill.h"
#include "Employee.h"
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
	SkillManager manager;

	manager.addEmployee("0001", "Max Muster", "FE");
	manager.addEmployee("0002", "Rainer Herrler", "FE");

	manager.addSkill("C++", "C++", SkillCategory::software);
	manager.addSkill("Java", "Java", SkillCategory::softSkill);
	manager.addSkill("Elektrotechnik", "Electrical Engineering",SkillCategory::hardware);

	manager.enterSkillAssociation("0001", "Elektrotechnik", 5);
    manager.enterSkillAssociation("0001", "Java", 4);
	manager.enterSkillAssociation("0002", "C++", 3);
	manager.enterSkillAssociation("0002", "Java", 5);

	printEmployeeList("**** Employee ****", manager.getListOfEmployees());
	printSkillList("**** Skills ****", manager.getListOfSkills());
	printAssociations("**** Associations ****", manager.getListOfSkillAssociations());
}

