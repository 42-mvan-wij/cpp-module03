#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q claptrap");
}

int main() {
	atexit(&check_leaks);
	ClapTrap trapClap("trapClap");
	ClapTrap trapClap2(trapClap);

	trapClap.takeDamage(1);
	trapClap.beRepaired(200);
	trapClap.takeDamage(11241241);
	trapClap.beRepaired(1);
	trapClap.attack("a lifeless object");

	trapClap2.takeDamage(1);
	trapClap2.beRepaired(200);
	trapClap2.takeDamage(11241241);
	trapClap2.beRepaired(1);
	trapClap.attack("a lifeless object");
	return (0);
}
