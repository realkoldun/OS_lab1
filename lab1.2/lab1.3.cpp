#include <iostream>
#include <Windows.h>

int openNotepad(LPCWSTR lpszAppName, STARTUPINFO& si, PROCESS_INFORMATION& pi) {
    if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {

        int error = GetLastError();

        std::cerr << "Create process failed with code: " << error << std::endl;

        return -1;
    }
    return 0;
}

int openText(LPCWSTR lpszAppName, LPCWSTR textFile) {
    if (!ShellExecute(NULL, NULL, textFile, NULL, lpszAppName, 1)) {
        int error = GetLastError();

        std::cerr << "Create process failed with code: " << error << std::endl;

        return -1;
    }
    return 0;
}

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));

    LPCWSTR lpszAppName = L"C:\\Windows\\notepad.exe";
    LPCWSTR textFile = L"C:\\Users\\koldun\\Desktop\\text.txt";

    std::cout << "1 - open notepad | 2 - open text.txt |  0 - stop\n";

    int k; 
    std::cin >> k;
    switch (k) {
    case 1:
        return openNotepad(lpszAppName, si, pi);
    case 2:
        return openText(lpszAppName, textFile);
    case 0:
        return 0;
    default:
        std::cin >> k;
    }
    return 0;
}
