#include "SkillManager.h"

void SkillManager::addEmployee(string employeeID, string name, string department) {
	employeeList_.push_back(new Employee(employeeID, name, department));
}

void SkillManager::addSkill(string germanName, string englishName, SkillCategory category) {
	skillList_.push_back(new Skill(germanName, englishName, category));
}

Employee* SkillManager::findEmployee(const string &employeeID) {
	Employee *foundEmployee = nullptr;
	for (Employee *employee : employeeList_) {
		if (employee->getEmployeeID() == employeeID)
			foundEmployee = employee;
	}
	return foundEmployee;
}

Skill* SkillManager::findSkill(const string &skillName) {
	Skill *foundSkill = nullptr;
	for (Skill *skill : skillList_) {
		if (skill->getEnglishName() == skillName)
			foundSkill = skill;

		if (skill->getGermanName() == skillName)
			foundSkill = skill;
	}
	return foundSkill;
}

// may throw errors
void SkillManager::enterSkillAssociation(string employeeID, string skillName, int skillLevel) {
	Employee* foundEmployee = findEmployee(employeeID);
	Skill *foundSkill = findSkill(skillName);

	if (foundEmployee==nullptr)
		throw "Employee not found";

    if (foundSkill==nullptr)
		throw "Skill not found";

	skillAssociationList_.push_back(new SkillAssociation(foundEmployee, foundSkill, skillLevel));
}

const vector<Employee*> SkillManager::getListOfEmployees() {
	return employeeList_;
}

const vector<Skill*> SkillManager::getListOfSkills() {
	return skillList_;
}

const vector<SkillAssociation*> SkillManager::getListOfSkillAssociations() {
	return skillAssociationList_;
}





