#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap() called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap(std::string) called" << std::endl;
	this->name = name;
	hp = 100;
	energy = 50;
	attackDmg = 20;
	gatekeeperMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
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
		return ;
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
