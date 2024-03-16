#include <iostream>
#include <Windows.h>

int openFloder(LPCWSTR lpszAppName, LPWSTR lpczFloderName) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    if (!CreateProcess(lpszAppName, lpczFloderName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        int error = GetLastError();
        std::cerr << "Create process failed with code: " << error << std::endl;
        return -1;
    }
    return 0;
}

int openText(LPCWSTR textFile) {
    HWND explorer = (HWND)OpenProcess(PROCESS_ALL_ACCESS, NULL, 15148);
    if (!ShellExecuteW(explorer, NULL, NULL, NULL, textFile, true)) {
        int error = GetLastError();
        std::cerr << "Create process failed with code: " << error << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    LPCWSTR lpszAppName = L"C:\\Windows\\explorer.exe";
    LPWSTR lpFloderName =(LPWSTR) L"cd C:\\TEMP";
    LPCWSTR lpszFloderName = L"C:\\TEMP";

    openFloder(lpszAppName, lpFloderName);
   // openText(lpszFloderName);

    return 0;
}