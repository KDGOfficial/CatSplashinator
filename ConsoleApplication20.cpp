#include <iostream>
#include <string>
#include <windows.h> // Для ShellExecute

int main() {
    // Устанавливаем кодировку консоли для русского текста
    system("chcp 1251 > nul");

    std::string url = "https://cataas.com/cat";

    std::cout << "Нажмите Enter для открытия котика (или 'q' для выхода):" << std::endl;
    std::cout << "Старая вкладка не закрывается автоматически, используйте F5 в браузере для обновления." << std::endl;

    bool firstRun = true;

    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        if (firstRun) {
            // Открываем страницу в первый раз
            ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
            std::cout << "Страница открыта. Для нового котика нажмите Enter или F5 в браузере." << std::endl;
            firstRun = false;
        }
        else {
            // Пытаемся открыть новую страницу, но без гарантии закрытия старой
            ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
            std::cout << "Открыт новый котик. Старая вкладка может остаться открытой." << std::endl;
        }

        std::cout << "Нажмите Enter для следующего котика (или 'q' для выхода):" << std::endl;
    }

    std::cout << "Программа завершена" << std::endl;
    return 0;
}