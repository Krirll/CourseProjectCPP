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
		std::cout << "Добро пожаловать!\nДля использования программы необходимо выбрать нужную вам команду:\n";
	}

	void showCommands() {
		std::cout 
			<< "\n1 - Показать всех студентов\n"
			<< "2 - Вывести студентов, не имеющих двоек\n"
			<< "3 - Показать средний экзаменационный балл каждого студента\n"
			<< "4 - Добавить студента\n"
			<< "5 - Вывести студентов из файла\n"
			<< "6 - Закрыть программу\n";
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
		std::cout << "\nВыход из программы...\n";
	}

	void showStudents(std::list<Student> list) {
		//вывести таблицу с ФИО и оценками
		printf(HORIZONTAL_LINE);
		wprintf(FORMAT_STRING_MAIN, L"Фамилия", L"Имя", L"Отчество", L"Оценки");
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
		//вывести таблицу с ФИО, оценками и средним арифмитическим
		printf(HORIZONTAL_LINE_AVERAGE);
		wprintf(FORMAT_STRING_MAIN_AVERAGE, L"Фамилия", L"Имя", L"Отчество", L"Оценки", L"Средний балл");
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
		std::cout << "\nВведите фамилию -> ";
	}
};

