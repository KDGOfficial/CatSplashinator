#include <iostream>
#include <string>
#include <windows.h>
#include <winhttp.h>
#include <fstream>
#pragma comment(lib, "winhttp.lib")

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

int main() {
    system("chcp 1251 > nul");

    std::string url = "https://cataas.com/cat";
    int catNumber = LoadLastCatNumber() + 1; // �������� � ���������� ������

    std::cout << "������� Enter ��� ���������� ������ (��� 'q' ��� ������):" << std::endl;
    std::cout << "�������� ����� ����������� ��� cat1.jpg, cat2.jpg � �.�." << std::endl;
    std::cout << "������� ����� ������: " << catNumber << std::endl;

    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        std::string filename = "cat" + std::to_string(catNumber) + ".jpg";

        // ��������, ���������� �� ����
        if (FileExists(filename)) {
            std::cout << "����� #" << catNumber << " ��� ����������! ����������..." << std::endl;
            catNumber++;
            filename = "cat" + std::to_string(catNumber) + ".jpg";
        }

        if (DownloadCatImage(url, filename)) {
            std::cout << "����� #" << catNumber << " ������� �������� ��� " << filename << std::endl;
            SaveLastCatNumber(catNumber); // ��������� ��������� �����
            catNumber++;
        }
        else {
            std::cout << "������ ��� ���������� ������" << std::endl;
        }

        std::cout << "������� Enter ��� ���������� ������ (��� 'q' ��� ������):" << std::endl;
    }

    std::cout << "��������� ���������" << std::endl;
    return 0;
}