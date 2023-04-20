#pragma once
#include <iostream>
#include "Errors.h"
#include "Student.h"
#include <list>
#define HORIZONTAL_LINE "\n----------------------------------------------------------------------------------------------------------\n"
#define HORIZONTAL_LINE_AVERAGE "\n-------------------------------------------------------------------------------------------------------------------------\n"
#define FORMAT_STRING_MAIN L"| %-25s | %-25s | %-30s | %-13s |"
#define FORMAT_STRING_MAIN_AVERAGE L"| %-25s | %-25s | %-30s | %-13s | %-5s |"
#define FORMAT_STRING L"| %-25s | %-25s | %-30s | %d | %d | %d | %d |"
#define FORMAT_STRING_AVERAGE L"| %-25s | %-25s | %-30s | %d | %d | %d | %d |     %.2f     |"

class ConsoleHelper
{

private:
	Errors errors;

public:
	void start() {
		std::cout << "����� ����������!\n��� ������������� ��������� ���������� ������� ������ ��� �������:\n";
	}

	void showCommands() {
		std::cout 
			<< "\n1 - �������� ���� ���������\n"
			<< "2 - ������� ���������, �� ������� �����\n"
			<< "3 - �������� ������� ��������������� ���� ������� ��������\n"
			<< "4 - �������� ��������\n"
			<< "5 - ������� ��������� �� �����\n"
			<< "6 - ������� ���������\n";
	}

	void showCommandError() {
		std::cout << errors.NO_SUCH_COMMAND();
	}

	void showFileIsEmpty() {
		std::cout << errors.FILE_IS_EMPTY();
	}

	void showFileCantBeOpened() {
		std::cout << errors.FILE_CANT_BE_OPENED();
	}

	void showAppendError() {
		std::cout << errors.ERROR_WHILE_APPEND_PARAM();
	}

	void showMarkError() {
		std::cout << errors.INCORRECT_MARK();
	}

	void showExit() {
		std::cout << "\n����� �� ���������...\n";
	}

	void showStudents(std::list<Student> list) {
		//������� ������� � ��� � ��������
		printf(HORIZONTAL_LINE);
		wprintf(FORMAT_STRING_MAIN, L"�������", L"���", L"��������", L"������");
		printf(HORIZONTAL_LINE);
		for (std::list<Student>::iterator it = list.begin(); it != list.end(); ++it) {
			std::array<int, ARRAY_SIZE> marks = it->getMarks();
			wprintf(
				FORMAT_STRING,
				it->getLastName().c_str(),
				it->getName().c_str(),
				it->getMiddleName().c_str(),
				marks[0], marks[1], marks[2], marks[3]);
			printf(HORIZONTAL_LINE);
		}
	}

	void showStudentsWithAverage(std::list<Student> list) {
		//������� ������� � ���, �������� � ������� ��������������
		printf(HORIZONTAL_LINE_AVERAGE);
		wprintf(FORMAT_STRING_MAIN_AVERAGE, L"�������", L"���", L"��������", L"������", L"������� ����");
		printf(HORIZONTAL_LINE_AVERAGE);
		for (std::list<Student>::iterator it = list.begin(); it != list.end(); ++it) {
			std::array<int, ARRAY_SIZE> marks = it->getMarks();
			wprintf(
				FORMAT_STRING_AVERAGE,
				it->getLastName().c_str(),
				it->getName().c_str(),
				it->getMiddleName().c_str(),
				marks[0], marks[1], marks[2], marks[3],
				it->getAverage());
			printf(HORIZONTAL_LINE_AVERAGE);
		}
	}

	void writeLastName() {
		std::cout << "\n������� ������� -> ";
	}
};

