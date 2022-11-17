#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Unnamed ClapTrap"), hp(10), energy(10), attackDmg(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), energy(10), attackDmg(0) {
	std::cout << "ClapTrap(std::string) costructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hp(src.hp), energy(src.energy), attackDmg(src.attackDmg) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (energy == 0)
	{
		std::cout << "ClapTrap " << name << " tries to attack " << target << ", but has no energy left." << std::endl;
		return ;
	}
	energy--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage! " << name << " has " << energy << " energy left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp == 0) {
		std::cout << "ClapTrap " << name << " is being kicked while they are down for " << amount << " points of damage." << std::endl;
		return ;
	}
	if (hp <= amount) {
		hp = 0;
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage, " << name << " died." << std::endl;
	} else {
		hp -= amount;
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage, now at " << hp << " hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hp == 0) {
		std::cout << "ClapTrap " << name << " tried to revive itself from beyond the grave for " << amount << " hit points, but sadly this isn't possible." << std::endl;
		return ;
	}
	if (energy == 0) {
		std::cout << "ClapTrap " << name << " tried to repair itself for " << amount << " hit points, but has no energy left." << std::endl;
		return ;
	}
	energy--;
	hp += amount;
	std::cout << "ClapTrap " << name << " repaired itself for " << amount << " hit points, now at " << hp << " hit points. " << name << " has " << energy << " energy left." << std::endl;
}
