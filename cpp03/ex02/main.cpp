#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating FragTrap f(\"Frito\") ===\n";
    FragTrap f("Frito");

    std::cout << "\n=== Display initial points ===\n";
    f.displayPoints();

    std::cout << "\n=== Attack and high-five ===\n";
    f.attack("Target Dummy");
    f.highFivesGuys();

    std::cout << "\n=== Copy & assignment ===\n";
    FragTrap g(f);
    g.displayPoints();
    FragTrap h;
    h = f;
    h.displayPoints();

    std::cout << "\n=== Done; leaving scope (check destruction order) ===\n";
    return 0;
}
