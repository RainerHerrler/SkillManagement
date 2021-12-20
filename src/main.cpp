#include <iostream>
#include <vector>
#include <iomanip>
#include "Skill.h"
#include "Employee.h"
#include "SkillAssociation.h"

using namespace std;

// implement functions for the following prototypes
void printEmployeeList(const string &headLine, const vector<Employee*> &employeeList);
void printSkillList(const string &headLine, const vector<Skill*> &skillList);
void printAssociations(const string &headLine, const vector<SkillAssociation*> &associationsList);

int main() {
	vector<Employee*> employeeList;
	employeeList.push_back(new Employee("0001", "Max Muster", "FE"));
	employeeList.push_back(new Employee("0002", "Rainer Herrler", "FE"));

	vector<Skill*> skillList;
	skillList.push_back(new Skill("C++", "C++", SkillCategory::software));
	skillList.push_back(new Skill("Java", "Java", SkillCategory::softSkill));
	skillList.push_back(new Skill("Elektrotechnik", "Electrical Engineering", SkillCategory::hardware));

	vector<SkillAssociation*> skillAssociationList;
	skillAssociationList.push_back(new SkillAssociation(employeeList[0], skillList[2], 5));
	skillAssociationList.push_back(new SkillAssociation(employeeList[0], skillList[1], 4));
	skillAssociationList.push_back(new SkillAssociation(employeeList[1], skillList[0], 3));
	skillAssociationList.push_back(new SkillAssociation(employeeList[1], skillList[1], 5));

	printEmployeeList("***Employees***", employeeList);
	printSkillList("***Skills***", skillList);
	printAssociations("***Associations***", skillAssociationList);
}

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

