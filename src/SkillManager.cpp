#include "SkillManager.h"

#include <vector>
#include <algorithm>
using namespace std;

SkillManager::~SkillManager() {
	for (SkillAssociation *association : skillAssociationList_) {
		delete association;
	}
	for (Employee *emp : employeeList_) {
		delete emp;
	}
	for (Skill *skill : skillList_) {
		delete skill;
	}
}

//
// Adding and listing Employees
//

Employee* SkillManager::findEmployee(const string &employeeID) {
	for (Employee *emp : employeeList_) {
		if (emp->getEmployeeID() == employeeID) {
			return emp;
		}
	}
	return nullptr;
}

void SkillManager::addEmployee(string employeeID, string name,
		string department) {
	Employee *employeeId = new Employee(employeeID, name, department);
	employeeList_.push_back(employeeId);
}

void SkillManager::removeEmployee(const Employee *employee) {
	auto iter = std::remove(employeeList_.begin(), employeeList_.end(),
			employee);
	employeeList_.erase(iter, employeeList_.end());

	vector<SkillAssociation*> markedForDeletion;
	for (SkillAssociation *skill : skillAssociationList_)
		if (skill->getEmployee() == employee)
			markedForDeletion.push_back(skill);

	for (SkillAssociation *skill : markedForDeletion) {
		auto iter = std::remove(skillAssociationList_.begin(),
				skillAssociationList_.end(), skill);
		skillAssociationList_.erase(iter, skillAssociationList_.end());
		delete skill;
	}
}

//
// Adding and listing Skills
//

void SkillManager::addSkill(string germanName, string englishName,
		SkillCategory category) {
	skillList_.push_back(new Skill(germanName, englishName, category));
}

Skill* SkillManager::findSkill(const string &skillID) {
	for (Skill *emp : skillList_) {
		if (emp->getGermanName() == skillID) {
			return emp;
		}
		if (emp->getEnglishName() == skillID) {
			return emp;
		}
	}

	return nullptr;
}

void SkillManager::enterSkillAssociation(string employeeId, string skillName,
		int skillLevel) {
	Employee *employee = findEmployee(employeeId);
	if (employee == nullptr)
		throw "Employee " + employeeId + " not found!";
	Skill *skill = findSkill(skillName);
	if (skill == nullptr)
		throw "Skill " + skillName + " not found!";
	skillAssociationList_.push_back(
			new SkillAssociation(employee, skill, skillLevel));
}

bool SkillManager::removeEmployee(const string &employeeID) {
	Employee *employee = findEmployee(employeeID);
	if (employee != nullptr) {
		removeEmployee(employee);
		delete employee;
	}
	return employee != nullptr;
}

const vector<Employee*>& SkillManager::getListOfEmployees() {
	return employeeList_;
}
const vector<Skill*>& SkillManager::getListOfSkills() {
	return skillList_;
}

const vector<SkillAssociation*> SkillManager::getListOfSkillAssociations() {
	return skillAssociationList_;
}


vector<Employee*> SkillManager::getListOfEmployees(string skillName) {
	vector<Employee*> found;
	for (SkillAssociation *association : skillAssociationList_) {
		if (association->getSkill()->getEnglishName() == skillName)
			found.push_back(association->getEmployee());
		else if (association->getSkill()->getGermanName() == skillName)
			found.push_back(association->getEmployee());
	}
	return found;
}

vector<Skill*> SkillManager::getListOfSkills(string employeeID) {
	vector<Skill*> found;
	for (SkillAssociation *association : skillAssociationList_) {
		if (association->getEmployee()->getEmployeeID()==employeeID)
			found.push_back(association->getSkill());
	}
	return found;
}

