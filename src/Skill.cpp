#include "Skill.h"

Language defaultLang = german;

Skill::Skill()
    : skillNameGerman_("undefiniert"),
	  skillNameEnglish_("undefined"),
	  skillCategory_ (SkillCategory::other) { }

Skill::Skill(string germanName, string englishName, SkillCategory skillType)
   : skillNameGerman_(germanName),
	 skillNameEnglish_(englishName),
	 skillCategory_(skillType)
	 { }

string Skill::getName() const {
	return defaultLang==english ? skillNameEnglish_ : skillNameGerman_;
}

string Skill::getEnglishName() const{
	return skillNameEnglish_;
}

string Skill::getGermanName() const {
	return skillNameGerman_;
}

SkillCategory Skill::getSkillCategory() const {
	return skillCategory_;
}

