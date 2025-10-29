#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap("Default-Scav")
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap [" << _name << "] default-constructed\n";
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap [" << _name << "] constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap [" << _name << "] copy-constructed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap [" << _name << "] destroyed\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!canAct("attack")) return;

    --_energyPoints;
    std::cout << "ScavTrap [" << _name << "] ferociously attacks [" << target
              << "] for " << _attackDamage << " damage! "
              << "(HP=" << _hitPoints << ", EP=" << _energyPoints << ")\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap [" << _name << "] is now in Gate keeper mode.\n";
}
