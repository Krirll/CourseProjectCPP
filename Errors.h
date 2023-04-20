#pragma once
#include <iostream>
#include <string>

static class Errors
{
public:
	static std::string NO_SUCH_COMMAND() { 
		return "\n����� ������� �� ����������! ���������� �����.\n"; 
	}

	static std::string FILE_IS_EMPTY() {
		return "\n��������� ���� ���� �������� ������.\n";
	}

	static std::string FILE_CANT_BE_OPENED() {
		return "\n���� �� ����� ���� ������ ��-�� ���� �������!\n";
	}

	static std::string ERROR_WHILE_APPEND_PARAM() {
		return "\n������! ��������� ������������ ��������� ������ � ���������� �����.";
	}

	static std::string INCORRECT_MARK() {
		return "\n������! ������ ����� ���� 2,3,4,5. ���������� ��� ���.\n";
	}

};

