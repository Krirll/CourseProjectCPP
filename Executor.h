#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Commands.h"
#include "ConsoleHelper.h"
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include "Student.h"
#include <Windows.h>
#include <limits>
#include <codecvt>
#undef max
#define NO_EXIT true

class Executor
{
private:
	ConsoleHelper helper;
	std::list<Student> students;

	void init() {
		Student st = Student(L"Пупкин", L"Васька", L"Иванович", new int[4] { 3, 2, 3, 5 });
		students.push_back(st);
		st = Student(L"Есенин", L"Сергей", L"Александрович", new int[4] { 3, 3, 3, 5 });
		students.push_back(st);
		st = Student(L"Петров", L"Василий", L"Иосифович", new int[4] { 3, 3, 3, 5 });
		students.push_back(st);
		st = Student(L"Иванова", L"Мария", L"Сергеевна", new int[4] { 3, 3, 3, 5 });
		students.push_back(st);
	}

	int getNumber() {
		std::string str;
		std::getline(std::cin, str);
		if (str.length() > 1 || str.length() == 0) {
			return -1;
		}
		else {
			return (int)str[0] - 48;
		}
	}

	std::wstring enterStringParameter(std::string description, int limit) {
		std::wstring result;
		while (NO_EXIT) {
			std::cout << description;
			std::wcin >> result;								   
			std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (result.length() > 1 && result.length() < limit && result.find_first_of(L"0123456789 !?-=+@#$%^&*(){}[],.;:'\\/\"№") == std::wstring::npos) {
				return result;
			}
			else
				helper.showAppendError();
		}
	}

	int enterIntParameter(std::string description) {
		while (NO_EXIT) {
			std::cout << description;
			std::string str;
			std::getline(std::cin, str);
			if (str.length() == 1 && str[0] >= '2' && str[0] <= '5') {
				return (int)str[0] - 48;
			}
			else
				helper.showMarkError();
		}
	}

public:
	void startProgramm() {
		init();
		char symbol;
		helper.start();
		while (NO_EXIT) {
			helper.showCommands();
			symbol = getNumber();
			if (symbol != -1) {
				switch (static_cast<int>(symbol))
				{
					case static_cast<int>(Commands::ADD_STUDENT): {
						std::wstring lastName = enterStringParameter("\nВведите фамилию -> ", 25);
						std::wstring name = enterStringParameter("\nВведите имя -> ", 25);
						std::wstring middleName = enterStringParameter("\nВведите отчество -> ", 30);
						int marks[ARRAY_SIZE];
						marks[0] = enterIntParameter("\nВведите первую оценку -> ");
						marks[1] = enterIntParameter("\nВведите вторую оценку -> ");
						marks[2] = enterIntParameter("\nВведите третью оценку -> ");
						marks[3] = enterIntParameter("\nВведите четвертую оценку -> ");
						students.push_back(Student(lastName, name, middleName, marks));
						helper.showStudents(students);
						break;
					}
					case static_cast<int>(Commands::SHOW_ALL): {
						//вывод всех студентов в виде таблицы
						helper.showStudents(students);
						break;
					}
					case static_cast<int>(Commands::GET_EXCELLENT_STUDENTS): {
						//вывод студентов без двоек в виде таблицы
						std::list<Student> excellentStudents;
						std::copy_if(
							students.begin(),
							students.end(),
							std::back_inserter(excellentStudents),
							[](Student s) { return s.isExcellentStudent(); }
						);
						helper.showStudents(excellentStudents);
						break;
					}
					case static_cast<int>(Commands::CALCULATE_AVERAGES): {
						//вывести всех студентов вместе со средним арифметическим
						std::list<Student> newList;
						std::copy_if(
							students.begin(),
							students.end(),
							std::back_inserter(newList),
							[](Student s) { return s.getAverage(); }
						);
						helper.showStudentsWithAverage(newList);
						break;
					}
					case static_cast<int>(Commands::READ_FILE): {
						//чтение студентов из файла и вывод студентов
						OPENFILENAMEA dialog;
						char filename[MAX_PATH];
						ZeroMemory(&filename, sizeof(filename));
						ZeroMemory(&dialog, sizeof(dialog));
						dialog.lStructSize = sizeof(dialog);
						dialog.hwndOwner = NULL;
						dialog.lpstrFilter = "Текстовые документы\0*.txt\0";
						dialog.lpstrFile = filename;
						dialog.nMaxFile = MAX_PATH;
						dialog.lpstrTitle = "Select a File";
						dialog.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
						if (GetOpenFileNameA(&dialog)) {
							std::wifstream in(filename);
							if (in.is_open()) {
								std::wstring word;
								const std::locale empty_locale = std::locale::empty();
								typedef std::codecvt_utf8<wchar_t> converter_type;
								const converter_type* converter = new converter_type;
								const std::locale utf8_locale = std::locale(empty_locale, converter);
								in.imbue(utf8_locale);
								int counterOfReadData = 0;
								std::wstring lastName;
								std::wstring name;
								std::wstring middleName;
								int marks[ARRAY_SIZE];
								std::list<Student> fromFile;
								while (in.good()) {
									wchar_t sym = in.get();
									if (sym != ' ' && sym != '\n' && sym != 65535)
										word += sym;
									else {
										switch (counterOfReadData++)
										{
											case 0:
												lastName = word;
												break;
											case 1:
												name = word;
												break;
											case 2:
												middleName = word;
												break;
											case 3:
												marks[0] = word[0] - 48;
												break;
											case 4:
												marks[1] = word[0] - 48;
												break;
											case 5:
												marks[2] = word[0] - 48;
												break;
											case 6:
												marks[3] = word[0] - 48;
												fromFile.push_back(
													Student(lastName, name, middleName, marks)
												);
												counterOfReadData = 0;
												break;
										}
										word = L"";
									}
								}
								if (fromFile.size() == 0)
									helper.showFileIsEmpty();
								else {
									std::copy(fromFile.begin(), fromFile.end(), std::back_inserter(students));
									helper.showStudents(students);
								}
									
							}
							else 
								helper.showFileCantBeOpened();
							in.close();
						}
						break;
					}
					case static_cast<int>(Commands::EXIT): {
						//выход из программы
						helper.showExit();
						exit(0);
						break;
					}
					default: {
						//вывод об ошибке, несуществующая команда;
						helper.showCommandError();
						break;
					}
				}
			}
			else {
				helper.showCommandError();
			}
		}
	}
};

