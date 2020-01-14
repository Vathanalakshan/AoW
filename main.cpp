#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Battlefield b;
    Player P;
    Fantassin f1(52,5,true,6,2,4,5,b,P);
    std::cout << f1.getPos() << std::endl;

    return 0;
}
