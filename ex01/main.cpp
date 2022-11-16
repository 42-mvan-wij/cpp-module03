#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q scavtrap");
}

int main() {
	std::atexit(&check_leaks);

	{
		ClapTrap claptrap("CL4P-TP");
		claptrap.attack("an innocent leaf");
		claptrap.takeDamage(3);
		claptrap.beRepaired(2);
	}
	std::cout << std::endl;
	{
		ScavTrap scavtrap("SC4V-TP");
		scavtrap.attack("a lifeless object");
		scavtrap.takeDamage(3);
		scavtrap.beRepaired(2);
		scavtrap.guardGate();
	}
	std::cout << std::endl;
	{
		ScavTrap scavtrap("SC4V-TP");
		ScavTrap scavtrap2("scavtrap2");
		scavtrap2.attack("a lifeless object");
		scavtrap2.takeDamage(3);
		scavtrap2.beRepaired(2);
		scavtrap2.guardGate();
		scavtrap2 = scavtrap;
		scavtrap2.attack("a lifeless object");
		scavtrap2.takeDamage(3);
		scavtrap2.beRepaired(2);
		scavtrap2.guardGate();
	}
	return (0);
}
