#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "TA.h"

int main()
{
	std::vector<TA> t;

	std::ifstream information("TAs.txt");

	if (!information) {
		std::cout << "File cant be opened";
		return 1;
	}

	std::vector<std::string> text;
	std::string lines;

	std::string Status, department;
	int Student_Id, Working_Hours;

	std::getline(information, lines);

	//extracts values from the tas.txt file using information>> and so forth. After checking if alum or nah, it stores the non alum values in t
	while (std::getline(information, lines))
	{
	
		information >> Working_Hours >> department >> Student_Id >> Status;

		if (Status != "Alum")
		{
			t.push_back(TA(Working_Hours, department, Student_Id, Status));
		}
	}

	information.close();

	information.open("TAs.txt");
	if (!information) {
		std::cout << "File cant be opened";
		return 1;
	}

	std::ofstream out("TAs.txt", std::ios::app| std::ios::ate);

	if (!out) {
		std::cout << "Error opening file";
		return 1;
	}

	//extracting data and modifying the file.
	out << std::endl;
	out << "Initial Student File After Correction:" << std::endl;
	out << t.size() << std::endl; //new size
	for (int i = 0; i < t.size(); ++i) {
		out << t[i].getWorkingHours() << " " << t[i].getDepartment() << " " << t[i].getStudentId() << " " << t[i].getStatus() << std::endl;
			
	}

	information.close();

	information.open("TAs.txt");
	if (!information) {
		std::cout << "File cant be opened";
		return 1;
	}
	std::cout << "Original file has been updated" << std::endl;
	int option;
	std::cout << "Options to proceed: ";
	std::cout << "1. Enter New TA information, 2. Sort by Column  3. Exit" << std::endl;
	std::cin >> option;

	TA ta;

	if (option == 1)
	{
		ta.addNewTA();
		while (std::getline(information, lines)) {
			std::cout << lines << std::endl;
		}
		
	}
	else if (option == 2)
	{
		int choice;
		std::cout << "Choose a column to order by:" << std::endl;
		std::cout << "1. Working Hours, 2. Department, 3. Student ID, 4. Status" << std::endl;
		std::cin >> choice;

		int orderChoice;
		std::cout << "Choose the order: 1. Ascending, 2. Descending" << std::endl;
		std::cin >> orderChoice;

		if (choice ==1 || choice==2 || choice==3 || choice==4) {
			if (orderChoice == 1) {
				std::sort(t.begin(), t.end(), [choice](const TA& a, const TA& b) {
					switch (choice) {
					case 1: 
						return a.getWorkingHours() < b.getWorkingHours();
					case 2: 
						return a.getDepartment() < b.getDepartment();
					case 3:
						return a.getStudentId() < b.getStudentId();
					case 4: 
						return a.getStatus() < b.getStatus();
					default: 
						return false; 
					}
					});
			}
			else if (orderChoice == 2) {
				std::sort(t.begin(), t.end(), [choice](const TA& a, const TA& b) {
					switch (choice) {
					case 1:
						return a.getWorkingHours() > b.getWorkingHours();
					case 2:
						return a.getDepartment() > b.getDepartment();
					case 3: 
						return a.getStudentId() > b.getStudentId();
					case 4:
						return a.getStatus() > b.getStatus();
					default:
						return false; 
					}
					});
			}
			else {
				std::cout << "Invalid choice" << std::endl;
				return 1;
			}

		
			out << std::endl;
			out << "Sorted Student File:" << std::endl;
			out << t.size() << std::endl; // new size
			for (int i = 0; i < t.size(); ++i) {
				out << t[i].getWorkingHours() << " " << t[i].getDepartment() << " " << t[i].getStudentId() << " " << t[i].getStatus() << std::endl;

			}

			while (std::getline(information, lines)) {
				std::cout << lines << std::endl;
			}
		}
		else {
			std::cout << "Invalid choice for column." << std::endl;
			return 1;
		}

	}
	else if (option == 3) 
	{
		return 0;

	}
	else {
		std::cout << "invalid input. closing system";
		exit(0);
	}


	return 0;
}

