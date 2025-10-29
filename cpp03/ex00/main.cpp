#include "ClapTrap.hpp"

int main() {
    // cria dois ClapTraps
    ClapTrap a("Ares");
    ClapTrap b("Bia");

    // estado inicial
    a.displayPoints();
    b.displayPoints();

    // Ares ataca Bia, custa 1 EP
    a.attack("Bia");
    // Bia toma 3 de dano e depois se repara 2
    b.takeDamage(3);
    b.beRepaired(2);

    // zera HP de Bia para testar bloqueio por HP=0
    b.takeDamage(100);
    b.attack("Ares");
    b.beRepaired(10);

    // estado final
    a.displayPoints();
    b.displayPoints();

    return 0;
}