#ifndef SKILLMANAGEMENTUI_H_
#define SKILLMANAGEMENTUI_H_

#include <vector>
#include <string>
#include "Employee.h"
#include "Skill.h"
#include "SkillManager.h"

class SkillManagementUI {
private:
	//converts a string to the skill category enumeration
	static SkillCategory getCategory(const string& categoryName);
	// prints the menu options on the terminal
	void showMenu();
public:
	SkillManagementUI(SkillManager*);
	// start the user menu in a loop until the user enters "exit"
	void startMenu();
};

#endif /* SKILLMANAGEMENTUI_H_ */
