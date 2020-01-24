#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Battlefield b;
    Player p;
    b.Generer(&p);
    std::cout<<b;
    return 0;
}
