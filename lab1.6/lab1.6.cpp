#include <iostream>
#include <Windows.h>

std::string stopProcess(int PID) {
    UINT lpExitCode = 0;
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 1, PID);
    return TerminateProcess(hProcess, lpExitCode) ?
        "Stopped" :
        "Error";
}

std::string changeProcessPriority(int PID) {
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 1, PID);
    std::cout << "The priority of this process is: " << GetPriorityClass(hProcess) << "\nChange it to:\n";
    std::cout << "(1) NORMAL_PRIORITY_CLASS\n" <<
        "(2) BELOW_NORMAL_PRIORITY_CLASS\n" <<
        "(3) ABOVE_NORMAL_PRIORITY_CLASS\n" <<
        "(4) REALTIME_PRIORITY_CLASS\n" <<
        "(5) HIGH_PRIORITY_CLASS\n" <<
        "(6) IDLE_PRIORITY_CLASS\n" <<
        "(0) cancel\n";
    int key;
    std::cin >> key;
    switch (key) {
    case 1:
        return SetPriorityClass(hProcess, NORMAL_PRIORITY_CLASS) ? "Seccess" : "Error";
    case 2:
        return SetPriorityClass(hProcess, BELOW_NORMAL_PRIORITY_CLASS) ?  "Seccess" : "Error";
    case 3:
        return SetPriorityClass(hProcess, ABOVE_NORMAL_PRIORITY_CLASS) ? "Seccess" : "Error";
    case 4:
        return SetPriorityClass(hProcess, REALTIME_PRIORITY_CLASS) ? "Seccess" : "Error";
    case 5:
        return SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS) ? "Seccess" : "Error";
    case 6:
        return SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS) ? "Seccess" : "Error";
    case 0:
        return "Canceled";
    default:
        std::cin >> key;
    }
    return "";
}
int main()
{
    int PID = 0;
    std::cout << "Enter process id: ";
    std::cin >> PID;

    std::cout << "What do you want to do\n1 - stop process | 2 - change priority |  0 - stop\n";
    int key;
    std::cin >> key;

    switch (key) {
    case 1 :
        std::cout << stopProcess(PID);
        break;
    case 2:
        std::cout << changeProcessPriority(PID);
        break;
    default:
        std::cin >> key;
    }
    return 0;
}
