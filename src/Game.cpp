#include "Game.h"
#include <random>

Game::Game(const BigInt leftRange, const BigInt rightRange) noexcept
{
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> dist{ leftRange,rightRange };
	
	m_Number = dist(gen);
}

State Game::Start(const BigInt UserNumber) const noexcept
{
	if (m_Number == UserNumber)
	{
		return State::Correct;
	}
	else if (m_Number > UserNumber)
	{
		return State::Bigger;
	}
	else
	{
		return State::Smaller;
	}
}
