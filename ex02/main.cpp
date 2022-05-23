#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q fraptrap");
}

int main() {
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
	return (0);
}
