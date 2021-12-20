#ifndef EXAMPLE1_H_
#define EXAMPLE1_H_

#include "ExampleInterface.h"
#include "SkillManager.h"

class Example1 : public ExampleInterface {
private:
	virtual void addExampleEmployees(SkillManager &skillManager);
	virtual void addExampleSkills(SkillManager &skillManager);
	virtual void addExampleAssociations(SkillManager &skillManager);
public:
	virtual void addExampleTo(SkillManager& skillManager);
};

#endif /* EXAMPLE1_H_ */
