#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap() called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap(std::string) called" << std::endl;
	this->name = name;
	hp = 100;
	energy = 100;
	attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.hp;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " wants to see some high fives going around" << std::endl;
}
