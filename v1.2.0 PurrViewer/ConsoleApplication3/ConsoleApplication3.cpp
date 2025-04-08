#include <iostream>
#include <string>
#include <windows.h>
#include <winhttp.h>
#include <fstream>
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "shell32.lib") // ��� ShellExecuteA

// ������������ ��� ������
enum class Language {
    Russian,
    English
};

// ���������� ���������� ��� �������� �����
Language currentLanguage = Language::Russian;

// ������� ��� ��������� ������ �� ������ �����
std::string GetLocalizedString(const std::string& russian, const std::string& english) {
    return (currentLanguage == Language::Russian) ? russian : english;
}

// ������� ��� ����������� ���������
void DisplayTitle() {
    const char* title[5] = {
        "-...- -.... ....- -...- -...- -.... -.... -...- -...- ..-.. -...- -.... ....- -...- -...-",
        ".   . .    . ..-.. .   . .   . .     .    . .   . .   . ..-.. .   . .    . ..-.. .   . .   .",
        "-...- -.... ..-.. -...- -...- -.... -.... -...- -...- ..-.. -...- -.... ..-.. -...- -...-",
        ".   . .    . ..-.. .   . .   . .   . .    . .   . .   . ..-.. .   . .    . ..-.. .   . .   .",
        "-...- -.... ....- -...- -...- -.... -.... -...- -...- ..-.. -...- -.... ....- -...- -...-"
    };

    std::cout << "---------------------------------------------------" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << title[i] << std::endl;
    }
    std::cout << "C A T S P L A S H I N A T O R" << std::endl;
    std::cout << "v1.2.0 - PurrViewer" << std::endl;
    std::cout << "Created by KDG 2nd Year Student" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}

bool DownloadCatImage(const std::string& url, const std::string& filename) {
    struct WinHttpHandle {
        HINTERNET handle;
        WinHttpHandle(HINTERNET h) : handle(h) {}
        ~WinHttpHandle() { if (handle) WinHttpCloseHandle(handle); }
        operator HINTERNET() const { return handle; }
    };

    WinHttpHandle hSession = WinHttpOpen(L"Cat Downloader/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);
    if (!hSession) return false;

    WinHttpHandle hConnect = WinHttpConnect(hSession, L"cataas.com",
        INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!hConnect) return false;

    WinHttpHandle hRequest = WinHttpOpenRequest(hConnect, L"GET", L"/cat",
        NULL, WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);
    if (!hRequest) return false;

    if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0,
        WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) return false;

    if (!WinHttpReceiveResponse(hRequest, NULL)) return false;

    FILE* file = nullptr;
    errno_t err = fopen_s(&file, filename.c_str(), "wb");
    if (err != 0 || file == nullptr) return false;

    struct FileCloser {
        FILE* f;
        FileCloser(FILE* file) : f(file) {}
        ~FileCloser() { if (f) fclose(f); }
    } fileCloser(file);

    DWORD bytesRead;
    BYTE buffer[4096];
    while (WinHttpReadData(hRequest, buffer, sizeof(buffer), &bytesRead)) {
        if (bytesRead == 0) break;
        fwrite(buffer, 1, bytesRead, file);
    }

    return true;
}

// ������ ���������� ������ �� �����
int LoadLastCatNumber() {
    int number = 0;
    std::ifstream file("last_cat_number.txt");
    if (file.is_open()) {
        file >> number;
        file.close();
    }
    return number;
}

// ���������� ���������� ������ � ����
void SaveLastCatNumber(int number) {
    FILE* file = nullptr;
    errno_t err = fopen_s(&file, "last_cat_number.txt", "w");
    if (err == 0 && file != nullptr) {
        fprintf(file, "%d", number);
        fclose(file);
    }
}

// �������� ������������� �����
bool FileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// �������� ����� � ��������� ������������
void OpenImageInViewer(const std::string& filename) {
    ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

int main() {
    system("chcp 1251 > nul");

    // ����������� ���������
    DisplayTitle();

    // ����� ����� � �������� �����������
    std::cout << GetLocalizedString(
        "�������� ���� / Select Language:\n",
        "Select Language / �������� ����:\n"
    );
    std::cout << "1. English / ����������\n";
    std::cout << "2. ������� / Russian\n";
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << GetLocalizedString(
        "����� / Choice: ",
        "Choice / �����: "
    );

    std::string langInput;
    std::getline(std::cin, langInput);
    if (langInput == "1") {
        currentLanguage = Language::English;
    }
    else {
        currentLanguage = Language::Russian;
    }

    // ������� ������ ����� ������ �����
    system("cls");

    // ��������� ����� ���������
    DisplayTitle();

    std::string url = "https://cataas.com/cat";
    int catNumber = LoadLastCatNumber() + 1; // �������� � ���������� ������

    std::cout << GetLocalizedString(
        "������� Enter ��� ���������� ������ (��� 'q' ��� ������):\n",
        "Press Enter to download a cat (or 'q' to exit):\n"
    );
    std::cout << GetLocalizedString(
        "�������� ����� ����������� ��� cat1.jpg, cat2.jpg � �.�.\n",
        "Images will be saved as cat1.jpg, cat2.jpg, etc.\n"
    );
    std::cout << GetLocalizedString(
        "������� ����� ������: ",
        "Current cat number: "
    ) << catNumber << "\n";
    std::cout << "---------------------------------------------------" << std::endl;

    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        std::string filename = "cat" + std::to_string(catNumber) + ".jpg";

        // ��������, ���������� �� ����
        if (FileExists(filename)) {
            std::cout << GetLocalizedString(
                "����� #" + std::to_string(catNumber) + " ��� ����������! ����������...\n",
                "Cat #" + std::to_string(catNumber) + " already exists! Skipping...\n"
            );
            catNumber++;
            filename = "cat" + std::to_string(catNumber) + ".jpg";
        }

        if (DownloadCatImage(url, filename)) {
            std::cout << GetLocalizedString(
                "����� #" + std::to_string(catNumber) + " ������� �������� ��� " + filename + "\n",
                "Cat #" + std::to_string(catNumber) + " successfully saved as " + filename + "\n"
            );
            SaveLastCatNumber(catNumber); // ��������� ��������� �����

            // ��������� ������ � ��������� ������������
            OpenImageInViewer(filename);
            std::cout << GetLocalizedString(
                "����� #" + std::to_string(catNumber) + " ������ � ��������� ������������!\n",
                "Cat #" + std::to_string(catNumber) + " opened in the system viewer!\n"
            );

            catNumber++;
        }
        else {
            std::cout << GetLocalizedString(
                "������ ��� ���������� ������\n",
                "Error downloading the cat\n"
            );
        }

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << GetLocalizedString(
            "������� Enter ��� ���������� ������ (��� 'q' ��� ������):\n",
            "Press Enter for the next cat (or 'q' to exit):\n"
        );
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << GetLocalizedString(
        "��������� ���������\n",
        "Program finished\n"
    );
    std::cout << "---------------------------------------------------" << std::endl;
    return 0;
}