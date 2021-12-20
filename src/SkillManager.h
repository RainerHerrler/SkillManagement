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

	void removeEmployee(const Employee* employee);
	Employee* findEmployee(const string& employeeID);
	Skill* findSkill(const string& skillName);

public:
	virtual ~SkillManager();
	// Use cases
	void addEmployee(string employeeID, string name, string department);
	void addSkill(string germanName, string englishName, SkillCategory category);
	void enterSkillAssociation(string employeeID, string skillName, int skillLevel); // may throw errors
	bool removeEmployee(const string& employeeID);
	vector<Employee*> getListOfEmployees(string skillName);
	vector<Skill*> getListOfSkills(string employeeID);

	// Further Use Cases for access
	const vector<Employee*>& getListOfEmployees();
	const vector<Skill*>& getListOfSkills();
	const vector<SkillAssociation*> getListOfSkillAssociations();
};

#endif /* SKILLMANAGER_H_ */
