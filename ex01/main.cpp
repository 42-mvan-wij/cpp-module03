#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q scavtrap");
}

int main() {
	ScavTrap scav_trap("Scavvy");

	scav_trap.attack("Johnny");
	scav_trap.takeDamage(3);
	scav_trap.beRepaired(5);
	scav_trap.takeDamage(10);
	scav_trap.beRepaired(5);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.beRepaired(0);
	scav_trap.takeDamage(5);
	scav_trap.attack("Johnny");
	scav_trap.takeDamage(5);
	return (0);
}
