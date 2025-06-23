#include <iostream>
#include <random>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::random_device rd;
    std::mt19937 gen(rd());  // 고속 난수 생성기
    std::uniform_int_distribution<> dist_n(1, 10);
    std::uniform_int_distribution<> dist_val(1, 1000);

    int N = dist_n(gen);
    std::cout << N << "\n";

    for (int i = 0; i < N; ++i) {
        std::cout << dist_val(gen) << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}