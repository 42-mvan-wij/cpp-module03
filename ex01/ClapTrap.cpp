#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Unnamed ClapTrap"), hp(10), energy(10), attackDmg(0) {
	std::cout << "ClapTrap() called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), energy(10), attackDmg(0) {
	std::cout << "ClapTrap(std::string) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): name(src.name), hp(src.hp), energy(src.energy), attackDmg(src.attackDmg) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (energy == 0)
		return ;
	energy--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage! " << name << " has " << energy << " energy left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp <= 0)
		return ;
	hp -= amount;
	if (hp <= 0) {
		energy = 0;
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage, " << name << " died." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage, now at " << hp << " hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy == 0)
		return ;
	energy--;
	hp += amount;
	std::cout << "ClapTrap " << name << " repaired itself for " << amount << " hit points, now at " << hp << " hit points. " << name << " has " << energy << " energy left." << std::endl;
}
