#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap &operator=(ClapTrap const &rhs);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string name;
		unsigned int hp;
		unsigned int energy;
		unsigned int attackDmg;
};

#endif
