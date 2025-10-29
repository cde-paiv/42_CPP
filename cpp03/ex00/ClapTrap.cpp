#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
: _name(copy._name),
_hitPoints(copy._hitPoints),
_energyPoints(copy._energyPoints),
_attackDamage(copy._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

bool    ClapTrap::canAct(const char* action) const
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot " << action
                << ": no hit points left!" << std::endl;
        return false;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << "cannot " << action
                << ": no energy left!" << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string& target) {
    if (!canAct("attack")) return;

    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << "! (HP=" << _hitPoints << ", EP=" << _energyPoints << ")"
              << std::endl;
}


void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap" << _name
                  << " is already destroyed!" << std::endl;
        return;
    }

    unsigned int taken = (amount >= _hitPoints) ? _hitPoints : amount;
    _hitPoints -= taken;

    std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage! (HP= " << _hitPoints
            << ", EP=" << _energyPoints << ")" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!canAct("repair")) return;

    --_energyPoints;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name << " repairs itself for "
            << amount << " hit points! "
            << "(HP=" << _hitPoints << ", EP=" << _energyPoints << ")"
            << std::endl;
}

void    ClapTrap::setName(const std::string& name)
{
    _name = name;
}

void ClapTrap::displayPoints() const
{
    std::cout << "== " << _name
            << " | HP=" << _hitPoints
            << " | EP=" << _energyPoints
            << " | AD=" << _attackDamage
            << " ==" << std::endl;
}
