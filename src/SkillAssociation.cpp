#include "SkillAssociation.h"

SkillAssociation::SkillAssociation(Employee *person, Skill *skill, int skillLevel) :
		person_(person), skill_(skill), skillLevel_(skillLevel) {
}

Employee* SkillAssociation::getEmployee() const {
	return person_;
}

Skill* SkillAssociation::getSkill() const {
	return skill_;
}

int SkillAssociation::getSkillLevel() const {
	return skillLevel_;
}

