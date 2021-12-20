#include "Example2.h"
#include <iostream>

void Example::addExampleEmployees(SkillManager &skillManager) {
	skillManager.addEmployee("0001", "Max Muster", "FE");
	skillManager.addEmployee("0002", "Rainer Herrler", "FE");
}

void Example::addExampleSkills(SkillManager &skillManager) {
	skillManager.addSkill("C++", "C++", SkillCategory::software);
	skillManager.addSkill("Java", "Java", SkillCategory::softSkill);
	skillManager.addSkill("Elektrotechnik", "Electrical Engineering",
			SkillCategory::hardware);
}

void Example::addExampleAssociations(SkillManager &skillManager) {
	try {
		skillManager.enterSkillAssociation("0001", "Electrical Engineering", 5);
		skillManager.enterSkillAssociation("0001", "Java", 2);
		skillManager.enterSkillAssociation("0002", "C++", 3);
		skillManager.enterSkillAssociation("0002", "Java", 5);
	} catch (string& error) {
		cerr << error << endl;
	}
}

void Example::addExampleTo(SkillManager& skillManager) {
	addExampleEmployees(skillManager);
	addExampleSkills(skillManager);
	addExampleAssociations(skillManager);
}

