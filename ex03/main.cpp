#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q diamondtrap");
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
		FragTrap fragtrap("FR4G-TP");
		fragtrap.attack("a medieval castle");
		fragtrap.takeDamage(3);
		fragtrap.beRepaired(2);
		fragtrap.highFivesGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap diamondtrap("DI4M0ND-TP");
		diamondtrap.attack("The Earth");
		diamondtrap.takeDamage(3);
		diamondtrap.beRepaired(2);
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	std::cout << std::endl;
	{
		DiamondTrap diamondtrap;
		diamondtrap.attack("The Earth");
		diamondtrap.takeDamage(3);
		diamondtrap.beRepaired(2);
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	return (0);
}
