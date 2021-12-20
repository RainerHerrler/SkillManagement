#ifndef SKILL_H_
#define SKILL_H_

#include <string>
using namespace std;

enum Language {german, english};
enum SkillCategory {softSkill, hardware, software, management, other};

extern Language defaultLang;

class Skill {
private:
	string skillNameGerman_;
	string skillNameEnglish_;
	SkillCategory skillCategory_;
public:
	Skill();
	Skill(string germanName, string englishName, SkillCategory skillType);
	string getName() const;
	string getEnglishName() const;
	string getGermanName() const;
	SkillCategory getSkillCategory() const;
};

#endif /* SKILL_H_ */
