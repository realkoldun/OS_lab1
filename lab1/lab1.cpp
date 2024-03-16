#include <iostream>
#include <Windows.h>


int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    LPCWSTR lpszAppName = L"C:\\Windows\\notepad.exe";
    if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {

        int error = GetLastError();

        std::cerr << "Create process failed with code: " << error <<std:: endl;

        return -1;

    }
    return 0;
}

