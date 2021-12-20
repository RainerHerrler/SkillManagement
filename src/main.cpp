#include <iostream>
#include "Skill.h"
#include "Employee.h"
#include "Example.h"
#include "SkillAssociation.h"
#include "SkillManagementUI.h"
#include "SkillManager.h"
#include "SkillsPersistenceCSV.h"
#include "Example.h"

using namespace std;

void print(SkillManager& skillManager) {
	const vector<Employee*> employeeList = skillManager.getListOfEmployees();
	const vector<Skill*> skillList = skillManager.getListOfSkills();
	SkillManagementUI ui(&skillManager);
	ui.printEmployeeList("*** Employee List", employeeList);
	ui.printSkillList("*** Skill List", skillList);
}

void mainCSVTest() {
	SkillManager skillManager;
	Example example;
	example.addExampleTo(skillManager);
	SkillsPersistenceCSV persistence;
	cout << persistence.toString(skillManager) << endl;
	persistence.save("skills.csv", skillManager);

	cout << "---------------"<< endl;
	SkillManager skillManager2;
	persistence.load("skills.csv", skillManager2);
	cout << persistence.toString(skillManager2) << endl;

}


int mainGui() {
	SkillManager skillManager;
	SkillManagementUI ui(&skillManager);
	ui.startMenu();
	return 0;
}

int main() {
	mainCSVTest();
	return 0;
}



