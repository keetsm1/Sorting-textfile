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
	
	while (std::getline(information, lines)) {
		std::cout << lines << std::endl;
	}
	std::cout << "Original file has been modified with the sorted TAs!";

	

	std::cout << std::endl << std::endl;
	int option;
	std::cout << "Options to proceed: ";
	std::cout << "1. Enter New TA information, 2. Sort by Column  3. Exit" << std::endl;
	std::cin >> option;
	
	TA ta;
	
		if (option == 1)
		{
			system("cls");

			out << std::endl;
			out << "New TAs Added: " << std::endl;
			ta.addNewTA();
		}
		else if(option==2)
		{
			
		}
		else if (option == 3) //when this is pressed, need to restart IDE for some reason to see output so i added this text at the bottom but then it prints 2x
		{
			out << std::endl;
			out << "Initial Student File After Correction:" << std::endl;
			out << t.size() << std::endl; //new size
			for (int i = 0; i < t.size(); ++i) {
				out << t[i].getWorkingHours() << " " << t[i].getDepartment() << " " << t[i].getStudentId() << " " << t[i].getStatus() << std::endl;

			}

			exit(0);
		}
		else {
			std::cout << "invalid input. closing system";
			exit(0);
		}

	information.close();
	out.close();
	return 0;
}

