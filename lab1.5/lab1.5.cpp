#include <iostream>
#include <Windows.h>

std::string stopProcess(int PID) {
    UINT lpExitCode = 0;
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 1, PID);
    return TerminateProcess(hProcess, lpExitCode) ? 
        "Stopped" :
        "Error";
}

int main()
{
    int PID = 0;
    std::cout << "Enter process id to stop: ";
    std::cin >> PID;

    std::cout << stopProcess(PID);

    return 0;
}
