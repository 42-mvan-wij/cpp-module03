#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q diamondtrap");
}

int main() {
	atexit(&check_leaks);
	{
		ClapTrap claptrap("MGMT");
		claptrap.attack("an innocent leaf");
		claptrap.takeDamage(3);
		claptrap.beRepaired(2);
	}
	std::cout << std::endl;
	{
		ScavTrap scavtrap("TWRP");
		scavtrap.attack("a lifeless object");
		scavtrap.takeDamage(3);
		scavtrap.beRepaired(2);
		scavtrap.guardGate();
	}
	std::cout << std::endl;
	{
		FragTrap fragtrap("AUORA");
		fragtrap.attack("a medieval castle");
		fragtrap.takeDamage(3);
		fragtrap.beRepaired(2);
		fragtrap.highFivesGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap diamondtrap("Sweet");
		diamondtrap.attack("itself");
		diamondtrap.takeDamage(3);
		diamondtrap.beRepaired(2);
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	std::cout << std::endl;
	{
		DiamondTrap diamondtrap;
		diamondtrap.attack("itself");
		diamondtrap.takeDamage(3);
		diamondtrap.beRepaired(2);
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	return (0);
}
