#include <iostream>
#include "ClapTrap.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q claptrap");
}

int main() {
	ClapTrap clap_trap("Clappy");

	clap_trap.attack("Johnny");
	clap_trap.takeDamage(3);
	clap_trap.beRepaired(5);
	clap_trap.takeDamage(10);
	clap_trap.beRepaired(5);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.beRepaired(0);
	clap_trap.takeDamage(5);
	clap_trap.attack("Johnny");
	clap_trap.takeDamage(5);
	return (0);
}
