#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ScavTrap s(\"Sentinel\") ===\n";
    ScavTrap s("Sentinel");
    std::cout << "\n=== Display initial points ===\n";
    s.displayPoints();

    std::cout << "\n=== Attack sequence ===\n";
    s.attack("Intruder");
    s.displayPoints();

    std::cout << "\n=== Guard gate mode ===\n";
    s.guardGate();

    std::cout << "\n=== Copy & assignment tests ===\n";
    ScavTrap t(s);
    t.displayPoints();
    ScavTrap u;
    u = s;
    u.displayPoints();

    std::cout << "\n=== Done; leaving scope (check destruction order) ===\n";
    return 0;
}
