#pragma once

using BigInt = long int;

enum class State
{
	Smaller = -1,
	Correct,
	Bigger
};

class Game
{
public:
	Game(BigInt leftRange, BigInt rightRange);

	State Start(BigInt UserNumber) const noexcept;

private:
	BigInt m_Number = 0;
};

