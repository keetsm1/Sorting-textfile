#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "TA.h"

TA::TA(int wh, std::string d, int si, std::string s)
{
	Status = s;
	Student_Id = si;
	Working_Hours = wh;
	department = d;
}

std::string TA:: getStatus() const {
	return Status;
}

int TA::getStudentId() const {
	return Student_Id;
}
int TA::getWorkingHours()const
{
	return Working_Hours;
}
std::string TA::getDepartment() const
{
	return department;
}

void TA::addNewTA() 
{
	int working_hours, student_id;
	std::string dept, status;
	char continueadd;
	std::ofstream output("TAs.txt", std::ios::app);
	std::cout << "Enter TA information" << std::endl;
	
	
	do {
		while (true) {
			try
			{
				std::cout << "Working hours: ";
				std::cin >> working_hours;
				if (std::cin.fail())
				{
					throw std::runtime_error("Invalid input, enter an integer value");
				}
				else {
					output << working_hours << " ";
					output.flush();

				}
				break;
			}
			catch (std::runtime_error& e)
			{
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
				std::cout << e.what() << std::endl;

			}
		}

		while (true) {
			try
			{
				std::cout << "Department:";
				std::cin >> dept;
				if (isDigit(dept))
				{
					throw std::runtime_error("Invalid input, enter a valid department name");
				}
				else {
					output << dept << " ";
					output.flush();

				}
				break;
			}
			catch (std::runtime_error& e)
			{
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
				std::cout << e.what() << std::endl;
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
			}
		}

		while (true) {
			try
			{
				std::cout << "student id: ";
				std::cin >> student_id;
				if (std::cin.fail())
				{
					throw std::runtime_error("Invalid input, enter an integer value");
				}
				else {
					output << student_id << " ";
					output.flush();

				}
				break;
			}
			catch (std::runtime_error& e)
			{
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
				std::cout << e.what() << std::endl;

			}
		}

		while (true) {
			try
			{

				std::cout << "Status:";
				std::cin >> status;
				if (isDigit(status))
				{
					throw std::runtime_error("Invalid input, enter a valid status name");
				}
				else {
					output << status;
					output.flush();

					output << std::endl;
				}
				break;
			}
			catch (std::runtime_error& e)
			{
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
				std::cout << e.what() << std::endl;
				std::cin.clear();  // Clear the error 
				std::cin.ignore(99999999999999, '\n'); //skip bad input
			}
		}
		std::cout << "Do you want to enter an TA (y/n)";
		std::cin >> continueadd;
	} while (continueadd == 'y' || continueadd == 'Y');
	output.close();


}


bool TA::isDigit(std::string& input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] >= '0' && input[i] <= '9') {

		}
		else {
			return false;
		}
	}
	return true;
}