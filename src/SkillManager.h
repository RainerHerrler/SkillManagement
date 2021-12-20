#ifndef SKILLMANAGER_H_
#define SKILLMANAGER_H_

#include <vector>
#include "Employee.h"
#include "Skill.h"
#include "SkillAssociation.h"
using namespace std;

class SkillManager {
private:
	vector<Employee*> employeeList_;
	vector<Skill*> skillList_;
	vector<SkillAssociation*> skillAssociationList_;

	Employee* findEmployee(const std::string &employeeID);
	Skill* findSkill(const std::string &skillName);

public:
	// Use cases from the original description
	void addEmployee(string employeeID, string name, string department);
	void addSkill(string germanName, string englishName, SkillCategory category);
	void enterSkillAssociation(string employeeID, string skillName, int skillLevel); // may throw errors
	const vector<Employee*> getListOfEmployees();
	const vector<Skill*> getListOfSkills();
	const vector<SkillAssociation*> getListOfSkillAssociations();
};

#endif /* SKILLMANAGER_H_ */
