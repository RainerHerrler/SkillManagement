#include "SkillManagementUI.h"

#include <iostream>
#include <iomanip>

using namespace std;

void SkillManagementUI::showMenu(){
	cout << "------Skillmanagement-------" << endl;
	cout << "Use 's' to add a new skill." << endl;
	cout << "Use 'e' to add a new employee." << endl;
	cout << "Use 'a' to add a new association." << endl;
	cout << "Use 'ls [employeeID]' to list all skills." << endl;
	cout << "Use 'le [skillName]' to list all employees." << endl;
	cout << "Use 'rme <no>' remove an employee." << endl;
	cout << "Use 'help' to show this text." << endl;
	cout << "Type 'exit' to stop the program." << endl;
}

SkillCategory SkillManagementUI::getCategory(const string& categoryName) {
	if (categoryName == "softSkill")
		return softSkill;
	if (categoryName == "hardware")
		return hardware;
	if (categoryName == "software")
		return software;
	if (categoryName == "management")
		return management;
	return other;
}

void SkillManagementUI::startMenu() {

}
