#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q diamondtrap");
}

int main() {
	DiamondTrap diamond_trap("Pink Diamond");

	diamond_trap.whoAmI();
	diamond_trap.attack("Johnny");
	diamond_trap.takeDamage(3);
	diamond_trap.beRepaired(5);
	diamond_trap.takeDamage(10);
	diamond_trap.beRepaired(5);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.beRepaired(0);
	diamond_trap.takeDamage(5);
	diamond_trap.attack("Johnny");
	diamond_trap.takeDamage(5);
	return (0);
}
