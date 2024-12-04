#include "Game.h"
#include <random>

Game::Game(BigInt leftRange, BigInt rightRange)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(leftRange,rightRange);
	
	m_Number = dist(gen);
}

State Game::Start(BigInt UserNumber) const noexcept
{
	if (m_Number == UserNumber)
	{
		return State::Correct;
	}
	if (m_Number > UserNumber)
	{
		return State::Bigger;
	}
	if (m_Number < UserNumber)
	{
		return State::Smaller;
	}
}
