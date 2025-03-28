#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>

void printCurrentTime() {
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm *timeinfo = std::localtime(&now_time);
        std::cout << std::put_time(timeinfo, "%H:%M:%S") << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    printCurrentTime();
    return 0;
}