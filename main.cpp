#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Battlefield b;
    Player P,Q;
    b.Generer(P,Q);
    b.Printfile();

    return 0;
}
