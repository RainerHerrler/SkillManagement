#include <iostream>
#include <iomanip>
#include "SkillManagementUI.h"
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
	SkillManagementUI ui(&skillManager);
	ui.startMenu();
	return 0;
}

