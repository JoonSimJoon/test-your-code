#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int N = std::rand() % 1000 + 1; // 1 <= N <= 1000
    std::cout << N << "\n";
    for (int i = 0; i < N; ++i) {
        int num = std::rand() % 1000 + 1; // 1 <= num <= 1000
        std::cout << num << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}