#pragma once
#include <iostream>
#include <string>

static class Errors
{
public:
	static std::string NO_SUCH_COMMAND() { 
		return "\nТакой команды не существует! Попробуйте снова.\n"; 
	}

	static std::string FILE_IS_EMPTY() {
		return "\nВыбранный вами файл оказался пустым.\n";
	}

	static std::string FILE_CANT_BE_OPENED() {
		return "\nФайл не может быть открыт из-за прав доступа!\n";
	}

	static std::string ERROR_WHILE_APPEND_PARAM() {
		return "\nОшибка! Проверьте правильность введенных данных и иопробуйте снова.";
	}

	static std::string INCORRECT_MARK() {
		return "\nОшибка! Оценка может быть 2,3,4,5. Попробуйте еще раз.\n";
	}

};

