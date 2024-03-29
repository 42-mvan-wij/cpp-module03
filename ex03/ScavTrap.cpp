#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Unnamed ScavTrap"), gatekeeperMode(false) {
	std::cout << "Default ScavTrap constructor called" << std::endl;
	hp = 100;
	energy = 50;
	attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), gatekeeperMode(false) {
	std::cout << "ScavTrap(std::string) costructor called" << std::endl;
	hp = 100;
	energy = 50;
	attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src), gatekeeperMode(src.gatekeeperMode) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.name;
	gatekeeperMode = rhs.gatekeeperMode;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (energy == 0)
	{
		std::cout << "ScavTrap " << name << " tries to attack " << target << ", but has no energy left." << std::endl;
		return ;
	}
	energy--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage! " << name << " has " << energy << " energy left." << std::endl;
}

void ScavTrap::guardGate() {
	if (gatekeeperMode) {
		std::cout << "ScavTrap " << name << " is staying in gate keeper mode" << std::endl;
		return ;
	}
	gatekeeperMode = true;
	std::cout << "ScavTrap " << name << " has entered gate keeper mode" << std::endl;
}
