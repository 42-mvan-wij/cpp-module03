#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Unnamed FragTrap") {
	std::cout << "Default FragTrap constructor called" << std::endl;
	hp = 100;
	energy = 100;
	attackDmg = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap(std::string) costructor called" << std::endl;
	hp = 100;
	energy = 100;
	attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.name;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " wants to see some high fives going around" << std::endl;
}
