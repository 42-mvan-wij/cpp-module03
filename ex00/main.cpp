#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q claptrap");
}

int main() {
	std::atexit(&check_leaks);

	ClapTrap defaultClapTrap;
	ClapTrap trapClap("trapClap");
	ClapTrap trapClap2(trapClap);

	std::cout << std::endl;

	defaultClapTrap.attack("an innocent leaf");
	defaultClapTrap.attack("an innocent leaf");
	defaultClapTrap.attack("an innocent leaf");
	defaultClapTrap.attack("an innocent leaf");
	defaultClapTrap = trapClap2;

	std::cout << std::endl;

	trapClap.takeDamage(1);
	trapClap.beRepaired(200);
	trapClap.takeDamage(11241241);
	trapClap.beRepaired(1);
	trapClap.attack("a lifeless object");

	std::cout << std::endl;

	trapClap2.takeDamage(1);
	trapClap2.beRepaired(200);
	trapClap2.takeDamage(11241241);
	trapClap2.beRepaired(1);
	trapClap2.attack("a lifeless object");

	std::cout << std::endl;

	defaultClapTrap.takeDamage(1);
	defaultClapTrap.beRepaired(200);
	defaultClapTrap.takeDamage(11241241);
	defaultClapTrap.beRepaired(1);
	defaultClapTrap.attack("a lifeless object");

	return (0);
}
