#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Unnamed DiamondTrap_clap_name"), name("Unnamed DiamondTrap") {
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name(name) {
	std::cout << "DiamondTrap(std::string) costructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), FragTrap(src), ScavTrap(src), name(src.name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	attackDmg = rhs.attackDmg;
	energy = rhs.energy;
	hp = rhs.hp;
	name = rhs.name;
	ClapTrap::name = rhs.ClapTrap::name;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am: \"" << ClapTrap::name << "\" a.k.a.: \"" << name << "\"" << std::endl;
}
