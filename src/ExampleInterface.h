#ifndef EXAMPLEINTERFACE_H_
#define EXAMPLEINTERFACE_H_

#include "SkillManager.h"

class ExampleInterface {
private:
	virtual void addExampleEmployees(SkillManager &skillManager)=0;
	virtual void addExampleSkills(SkillManager &skillManager)=0;
	virtual void addExampleAssociations(SkillManager &skillManager)=0;
public:
	virtual void addExampleTo(SkillManager& skillManager) =0;
};

#endif /* EXAMPLEINTERFACE_H_ */
