#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int v = 1;
    for (;;) {
        ++v;
        std::cout << v << '\n';
    }
}