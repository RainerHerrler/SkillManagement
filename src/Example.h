#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "SkillManager.h"

class Example {
private:
	void addExampleEmployees(SkillManager &skillManager);
	void addExampleSkills(SkillManager &skillManager);
	void addExampleAssociations(SkillManager &skillManager);
public:
	void addExampleTo(SkillManager& skillManager);
};

#endif /* EXAMPLE1_H_ */
