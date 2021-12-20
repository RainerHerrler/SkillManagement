#ifndef SKILLASSOCIATION_H_
#define SKILLASSOCIATION_H_

#include "Employee.h"
#include "Skill.h"

class SkillAssociation {
private:
	Employee* person_;
	Skill* skill_;
	int skillLevel_;
public:
	SkillAssociation(Employee* person, Skill* skill, int skillLevel);
	Employee* getEmployee() const;
	Skill* getSkill() const;
	int getSkillLevel() const;
};

#endif /* SKILLASSOCIATION_H_ */
