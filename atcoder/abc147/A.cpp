#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << ((a+b+c)>=22?"bust":"win");
    return 0;
}
