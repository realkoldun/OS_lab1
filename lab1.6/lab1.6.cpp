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
    std::cout << "Enter process id: ";
    std::cin >> PID;

    std::cout << "What do you want to do: ";
    std::cout << "1 - stop process | 2 - change priority |  0 - stop\n";

    std::cout << stopProcess(PID);

    return 0;
}
