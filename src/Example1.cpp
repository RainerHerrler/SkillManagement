#include "Example1.h"
#include <iostream>

void Example1::addExampleEmployees(SkillManager &skillManager) {
	skillManager.addEmployee("0001", "Rainer Herrler", "FE");
	skillManager.addEmployee("0002", "Bletz Siebert", "FANG");
	skillManager.addEmployee("0003", "Volker Willert", "FE");
}

void Example1::addExampleSkills(SkillManager &skillManager) {
	skillManager.addSkill("C++", "CPlusPlus", SkillCategory::software);
	skillManager.addSkill("Analysis", "Calculus", SkillCategory::other);
	skillManager.addSkill("Robotermechanik", "Robot mechanics",
			SkillCategory::hardware);
	skillManager.addSkill("Elektrotechnik", "Electrical Engineering",
			SkillCategory::hardware);
	skillManager.addSkill("Maschinelles Lernen", "Machine Learning",
			SkillCategory::software);
	skillManager.addSkill("Java", "Java", SkillCategory::software);
	skillManager.addSkill("Maschinelles Sehen", "Computer Vision",
			SkillCategory::hardware);
}

void Example1::addExampleAssociations(SkillManager &skillManager) {
	try {
		skillManager.enterSkillAssociation("0001", "C++", 3);
		skillManager.enterSkillAssociation("0001", "Java", 5);
		skillManager.enterSkillAssociation("0001", "Machine Learning", 5);
		skillManager.enterSkillAssociation("0002", "Analysis", 5);
		skillManager.enterSkillAssociation("0003", "Computer Vision", 5);
	} catch (string& error) {
		cerr << error << endl;
	}
}



void Example1::addExampleTo(SkillManager& skillManager) {
	addExampleEmployees(skillManager);
	addExampleSkills(skillManager);
	addExampleAssociations(skillManager);
}
