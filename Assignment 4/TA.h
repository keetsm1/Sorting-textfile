#pragma once
#include <iostream>
class TA
{
private:
	std::string Status, department;
	int Student_Id, Working_Hours;
public:
	TA() {};
	TA(int, std::string, int, std::string);

	std::string getStatus() const;

	int getStudentId() const;
	int getWorkingHours() const;
	std::string getDepartment() const;

	bool isDigit(std::string&);
	void addNewTA();
};


