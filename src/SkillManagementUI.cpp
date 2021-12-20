#include "SkillManagementUI.h"

#include <iostream>
#include <iomanip>
#include "Mytools.h"

using namespace std;
using namespace Mytools;

SkillManagementUI::SkillManagementUI(SkillManager *management) :
		skillManager_(management) { }

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

void SkillManagementUI::printEmployeeList(const string& headLine,
		const vector<Employee*> &employeeList) {
	cout << headLine << endl;
	for (Employee *employee : employeeList) {
		cout << " - " << setw(6) << left
				<< employee->getEmployeeID()
				<< setw(20) << employee->getName()
				<< employee->getDepartment() << endl;
	}
}

void SkillManagementUI::printSkillList(const string& headLine,
		const vector<Skill*> &skillList) {
	cout << headLine << endl;
	for (Skill *skill : skillList) {
		cout << " - " << skill->getName() << " " << skill->getSkillCategory() << endl;
	}
}

void SkillManagementUI::printAssociations(const string& headLine, const vector<SkillAssociation*> &associationsList) {
	cout << headLine << endl;
	for (SkillAssociation *skill : associationsList) {
		cout << " - " << skill->getEmployee()->getName() << " " << skill->getSkill()->getName() << " " << skill->getSkillLevel() << endl;
	}
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

void SkillManagementUI::enterEmployee() {
	string id = query("Enter employee ID: ");
	string name = query("Enter employee name: ");
	string department = query("Enter department name: ");

	skillManager_->addEmployee(id, name, department);
	cout << "Employee " << id << " entered!" << endl;
}

void SkillManagementUI::enterSkill() {
	string germanName = query("Enter skills German name: ");
	string englishName = query("Enter skills English name: ");
	string skillCategory = query("Enter skills type: ");

	skillManager_->addSkill(germanName, englishName,
			getCategory(skillCategory));
	cout << "Skill " << englishName << " entered!" << endl;
}

void SkillManagementUI::listEmployees() {
	printEmployeeList("***All Employees", skillManager_->getListOfEmployees());
}

void SkillManagementUI::listSkills() {
	printSkillList("***All Skills", skillManager_->getListOfSkills());
}

void SkillManagementUI::removeEmployee(const string &employeeID) {
	bool removed = skillManager_->removeEmployee(employeeID);
	if (removed)
		cout << "Successfully removed." <<endl;
	else
		cout << "Did not find the object to remove." <<endl;
}

bool SkillManagementUI::startsWith(const string &input, const char *startStr){
	return input.rfind(startStr, 0) == 0;
}

void SkillManagementUI::enterAssociation() {
	string employeeID = query("Enter employee-id: ");
	string skillName = query("Enter skill-name: ");
	string skilllevelstring = query("Enter skill-level: ");
	int skillLevel = 0;
	try {
	    skillLevel = std::stoi(skilllevelstring);
	} catch (...) {
		// be ok
	}
	try {
	    skillManager_->enterSkillAssociation(employeeID, skillName, skillLevel);
	} catch (string& s) {
		cerr << "\nAn error occurred!" << endl << s << endl;
	}
}

void SkillManagementUI::listSkills(const string& employeeID) {
	printSkillList("***Skills of " + employeeID,
			skillManager_->getListOfSkills(employeeID));
}

void SkillManagementUI::listEmployees(const string &skillName) {
	printEmployeeList("***All employees with skill " + skillName,
			skillManager_->getListOfEmployees(skillName));
}

// TODO make this look more pretty
int SkillManagementUI::startMenu() {
	string input;
	showMenu();
	do {
		cout << "Enter a command: ";
		std::getline(std::cin, input);
		trim(input);
		cout << "You entered " << input << endl;
		if (input == "e") { // enter employee
			enterEmployee();
		} else if (input == "s") {// enter skill
			enterSkill();
		} else if (input == "a") {// enter association
			enterAssociation();
		} else if (input == "le") {// listEmployees
			listEmployees();
		} else if (input == "ls") {// listEmployees
			listSkills();
		} else if (startsWith(input, "ls ")) {//list skills of employee
			listSkills(input.substr(3));
		} else if (startsWith(input, "le ")) {//list employees with skill
			listEmployees(input.substr(3));
		} else if (startsWith(input, "rme ")) {
			removeEmployee(input.substr(4));
		} else if (input == "help"){
			showMenu();
		} else if (input != "exit"){
			cout << "Command not understood, type help to get info!" << endl;
		}
	} while (input != "exit");
	return 0;
}
