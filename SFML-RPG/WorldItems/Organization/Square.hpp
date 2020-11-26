////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_SQUARE
#define SFML_RPG_SQUARE

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>

#include "WorldItems/Observables/Displayable.hpp"

namespace rpg {

	class Square
	{
	public:

		Square(int x, int y);

		Square(int x, int y, std::vector<Displayable> contains);

		int get_x() { return x; }

		int get_y() { return y; }

		std::vector<Displayable> get_contains() { return contains; }

	private:
		const int					x;
		const int					y;
		std::vector<Displayable>	contains;
	};

}

#endif // SFML_RPG_SQUARE
