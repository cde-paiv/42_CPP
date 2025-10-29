#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap("Default-Frag")
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap [" << _name << "] default-constructed\n";
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap [" << _name << "] constructed\n";
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap [" << _name << "] copy-constructed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap [" << _name << "] destroyed\n";
}

void FragTrap::attack(const std::string& target)
{
    if (!canAct("attack")) return;

    --_energyPoints;
    std::cout << "FragTrap [" << _name << "] launches a powerful strike at ["
              << target << "] for " << _attackDamage << " damage! "
              << "(HP=" << _hitPoints << ", EP=" << _energyPoints << ")\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap [" << _name << "] requests a positive high-five!\n";
}
