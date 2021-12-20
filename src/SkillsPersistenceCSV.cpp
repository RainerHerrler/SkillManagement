#include "SkillsPersistenceCSV.h"
#include "Skill.h"
#include "Mytools.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
using namespace Mytools;

const char *EMPLOYEE_LIST = "employeeList";
const char *SKILL_LIST = "skillList";
const char *SKILL_ASSOCIATION_LIST = "skillAssociationList";
const char *EMPLOYEE_ID = "employeeID";
const char *EMPLOYEE_NAME = "name";
const char *EMPLOYEE_DEPARTMENT = "department";
const char *SKILL_GERMAN_NAME = "germanName";
const char *SKILL_ENGLISH_NAME = "englishName";
const char *SKILL_CATEGORY = "skillCategory";
const char *SKILL_LEVEL = "skillLevel";
const char *GENERATED = "generated";

string SkillsPersistenceCSV::toString(SkillManager &manager) {
	std::stringstream ss;

	ss << "#" << EMPLOYEE_LIST << endl;
	ss << "#" << EMPLOYEE_ID << "," << EMPLOYEE_NAME << "," << EMPLOYEE_DEPARTMENT << endl;
	for (const Employee *employee : manager.getListOfEmployees()) {
		ss << employee->getEmployeeID() << "," << employee->getName() << "," << employee->getDepartment() << endl;
	}

	ss << "#" << SKILL_LIST << endl;
	ss << "#" << SKILL_GERMAN_NAME << "," << SKILL_ENGLISH_NAME << "," << SKILL_CATEGORY << endl;
	for (const Skill *skill : manager.getListOfSkills()) {
		ss << skill->getGermanName() << "," << skill->getEnglishName() << "," << skill->getSkillCategory() << endl;
	}

	ss << "#" << SKILL_ASSOCIATION_LIST << endl;
	ss << "#" << SKILL_ENGLISH_NAME << "," << EMPLOYEE_ID << "," << SKILL_LEVEL << endl;
	for (const SkillAssociation *skill : manager.getListOfSkillAssociations()) {
		ss << skill->getSkill()->getEnglishName() << ",";
		ss << skill->getEmployee()->getEmployeeID() << ",";
		ss << skill->getSkillLevel() << endl;
	}

	return ss.str();
}

void SkillsPersistenceCSV::save(const string &fileName, SkillManager &manager) {
	ofstream out(fileName);
	out << toString(manager);
	out.close();
}

void SkillsPersistenceCSV::load(const string &fileName, SkillManager &manager) {
	cout << "SkillsPersistenceCSV::load" << endl;

	enum ParsingState {
		nothing, employees, skills, associations
	};
	ParsingState state = nothing;

	ifstream in(fileName);
	string readLine;
	while (std::getline(in, readLine)) {
		trim(readLine);
		if (startsWith(readLine, (string("#")).append(EMPLOYEE_LIST).c_str())) {
			state = employees;
			continue;
		}
		if (startsWith(readLine, (string("#")).append(SKILL_LIST).c_str())) {
			state = skills;
			continue;
		}
		if (startsWith(readLine, (string("#")).append(SKILL_ASSOCIATION_LIST).c_str())) {
			state = associations;
			continue;
		}
		if (startsWith(readLine, "#")) {
			continue; // jump over any other comment
		}
		if (trim(readLine) == string("")) {
			continue; // jump over empty lines
		}

		if (state == employees) {
			vector<string> tokens;
			tokenize(readLine, tokens, ",");
			if (tokens.size() == 3) {
				manager.addEmployee(tokens[0], tokens[1], tokens[2]);
				cout << "Employee " << tokens[0] << " added." << endl;
			} else {
				cerr << "Error reading employee. Line had " << tokens.size() << " tokens";
			}
		}
		if (state == skills) {
			vector<string> tokens;
			tokenize(readLine, tokens, ",");
			if (tokens.size() == 3) {
				SkillCategory category = (SkillCategory) stoi(tokens[2]);
				manager.addSkill(tokens[1], tokens[0], category);
				cout << "Skill " << tokens[0] << " added." << endl;
			} else {
				cerr << "Error reading skill. Line had " << tokens.size() << " tokens";
			}
		}
		if (state == associations) {
			vector<string> tokens;
			tokenize(readLine, tokens, ",");
			if (tokens.size() == 3) {
				int skillLevel = stoi(tokens[2]);
				try {
					manager.enterSkillAssociation(tokens[1], tokens[0], skillLevel);
				} catch (string& s) {
					cerr << s;
				}
			} else {
				cerr << "Error reading association. Line had " << tokens.size() << " tokens";
			}
		}
	}
	in.close();
}

