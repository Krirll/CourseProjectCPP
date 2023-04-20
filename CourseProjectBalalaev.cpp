#include "Executor.h"
#include <consoleapi2.h>
#include <locale>

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Executor exe;
    exe.startProgramm();
}
