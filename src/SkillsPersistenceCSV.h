#ifndef SKILLSPERSISTENCECSV_H_
#define SKILLSPERSISTENCECSV_H_

#include <string>
#include "SkillManager.h"

class SkillsPersistenceCSV {
public:
	string toString(SkillManager &manager);
	void save(const string &fileName, SkillManager &manager);
	void load(const string &fileName, SkillManager &manager);
};

#endif /* SKILLSPERSISTENCECSV_H_ */
