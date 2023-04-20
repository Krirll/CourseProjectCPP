#pragma once
#include <iostream>;
#include <array>
#define BAD_MARK 2
#define ARRAY_SIZE 4

class Student
{

private:
	std::wstring lastName;
	std::wstring name;
	std::wstring middleName;
	std::array<int, ARRAY_SIZE> marks;
	float average = 0;

public:
	Student(std::wstring lastName, std::wstring name, std::wstring middleName, int marks[ARRAY_SIZE]) {
		this->lastName = lastName;
		this->name = name;
		this->middleName = middleName;
		for (int i = 0; i < ARRAY_SIZE; i++)
			this->marks[i] = marks[i];
	}


	std::wstring getLastName() {
		return this->lastName;
	}

	std::wstring getName() {
		return this->name;
	}

	std::wstring getMiddleName() {
		return this->middleName;
	}

	std::array<int, ARRAY_SIZE> getMarks() {
		return this->marks;
	}

	float getAverage() {
		if (this->average == 0)
			this->average = static_cast<float>(this->marks[0] + this->marks[1] + this->marks[2] + this->marks[3]) / static_cast<float>(ARRAY_SIZE);
		return this->average;
	}

	bool isExcellentStudent() {
		return (this->marks[0] > BAD_MARK) && (this->marks[1] > BAD_MARK) && (this->marks[2] > BAD_MARK) && (this->marks[3] > BAD_MARK);
	}

};

