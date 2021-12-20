#ifndef EXAMPLE2_H_
#define EXAMPLE2_H_

#include "ExampleInterface.h"
#include "SkillManager.h"

class Example : public ExampleInterface {
private:
	virtual void addExampleEmployees(SkillManager &skillManager);
	virtual void addExampleSkills(SkillManager &skillManager);
	virtual void addExampleAssociations(SkillManager &skillManager);
public:
	virtual void addExampleTo(SkillManager& skillManager);
};

#endif /* EXAMPLE1_H_ */
