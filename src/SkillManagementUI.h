#ifndef SKILLMANAGEMENTUI_H_
#define SKILLMANAGEMENTUI_H_

#include <vector>
#include <string>
#include "Employee.h"
#include "Skill.h"
#include "SkillManager.h"

class SkillManagementUI {
private:
	SkillManager* skillManager_;
	void enterEmployee();
	void enterSkill() ;
	static SkillCategory getCategory(const string& categoryName);
	void listEmployees();
	void showMenu();
	void listSkills();
	void removeEmployee(const string& input);
	void enterAssociation();
	bool startsWith(const string &input, const char *startStr);
	void listSkills(const string &employeeID);
	void listEmployees(const string &skillName);

public:
	SkillManagementUI(SkillManager* skillManager);
	void printEmployeeList(const string& headLine, const vector<Employee*> &employeeList);
	void printSkillList(const string& headLine, const vector<Skill*> &skillList);
	void printAssociations(const string& headLine, const vector<SkillAssociation*> &associationsList);
	int startMenu();
};

#endif /* SKILLMANAGEMENTUI_H_ */
