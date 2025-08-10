#pragma once

using BigInt = long int;

enum class State
{
	Smaller = -1,
	Correct,
	Bigger
};

class Game final
{
public:
	Game(const BigInt leftRange, const BigInt rightRange) noexcept;

	State Start(const BigInt UserNumber) const noexcept;

private:
	BigInt m_Number;
};

