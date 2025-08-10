#pragma once

#include <Game.h>
#include <gtest/gtest.h>

TEST(TestGuessNumber, CurrentNumber)
{
	// Arrange
	BigInt num{ 42 };

	Game game{ num, num };

	// Act
	auto res{ game.Start(num) };

	// Assert
	ASSERT_EQ(res, State::Correct);
}

TEST(TestGuessNumber, SmallerNumber)
{
	// Arrange
	BigInt num{ 42 };

	Game game{ 0, num - 1 };

	// Act
	auto res{ game.Start(num) };

	// Assert
	ASSERT_EQ(res, State::Smaller);
}

TEST(TestGuessNumber, BiggerNumber)
{
	// Arrange
	BigInt num{ 42 };

	Game game{ num + 1, 1000 }; // second number is random number

	// Act
	auto res{ game.Start(num) };

	// Assert
	ASSERT_EQ(res, State::Bigger);
}