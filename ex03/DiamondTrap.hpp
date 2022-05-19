#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap const &rhs);

		void whoAmI();
		using ScavTrap::attack;

	protected:
		using FragTrap::hp;
		using ScavTrap::energy;
		using FragTrap::attackDmg;

	private:
		std::string name;
};

#endif
