#include <iostream>
#include <thread>
#include <chrono>

int main() {
    for (int x = 0; x < 4; ++x) {
        std::cout << "Hi" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}