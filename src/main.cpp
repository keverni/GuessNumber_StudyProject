#include <iostream>
#include "Game.h"

int main() noexcept
{
	std::cout << "Hello, its game 'Guess Number' " << std::endl;

	BigInt leftRange{ 0 }, rightRange{ 0 }, number{ 0 };
	
	std::cout << "Enter range of generate number: ";
	std::cin >> leftRange >> rightRange;
	
	Game game{ leftRange, rightRange };
	
	for (;;)
	{
		std::cout << "Enter number: ";
		std::cin >> number;

		auto ResultGame{ game.Start(number) };
		if (ResultGame == State::Correct)
		{
			std::cout << "You win! Congratulations!" << std::endl;
			break;
		}
		else if (ResultGame == State::Bigger)
		{
			std::cout << "My number is higher!" << std::endl;
		}
		else if (ResultGame == State::Smaller)
		{
			std::cout << "My number is smaller!" << std::endl;
		}
	}

	return 0;
}