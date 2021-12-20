#include <iostream>
#include <vector>
#include "Skill.h"
#include "Employee.h"
#include "SkillAssociation.h"

using namespace std;

// implement functions for the following prototypes
void printEmployeeList(const string& headLine, const vector<Employee*> &employeeList);
void printSkillList(const string& headLine, const vector<Skill*> &skillList);
void printAssociations(const string& headLine, const vector<SkillAssociation*> &associationsList);

int main() {
	vector<Employee*> employeeList;
	employeeList.push_back(new Employee("0001", "Max Muster", "FE"));
	employeeList.push_back(new Employee("0002", "Rainer Herrler", "FE"));

	vector<Skill*> skillList;
	skillList.push_back(new Skill("C++", "C++", SkillCategory::software));
	skillList.push_back(new Skill("Java", "Java", SkillCategory::softSkill));
	skillList.push_back(new Skill("Elektrotechnik", "Electrical Engineering",SkillCategory::hardware));

    vector<SkillAssociation*> skillAssociationList;
    // add a SkillAssoziation Employee 0001 <-> Elektrotechnik 	with SkillLevel 5
    // add a SkillAssoziation Employee 0001 <-> Java 			with SkillLevel 4
    // add a SkillAssoziation Employee 0002 <-> C++ 			with SkillLevel 3
    // add a SkillAssoziation Employee 0002 <-> Java 			with SkillLevel 5

    // print the final lists
}


