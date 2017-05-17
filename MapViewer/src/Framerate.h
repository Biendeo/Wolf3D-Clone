// Framerate.h
//
// Manages a consistent framerate and manages buffer update times.

#pragma once

#include <cstdint>
#include <chrono>

class Framerate {
	public:
	Framerate(short expectedFPS);

	void SleepToNextSwapBuffer();
	void UpdateDrawTimes();
	uint64_t IncrementFrameCount();

	short ExpectedFPS();
	short ExpectedFPS(short expectedFPS);

	uint64_t FrameCount();

	float Delta();

	protected:
	short expectedFPS;
	float delta;
	std::chrono::time_point<std::chrono::steady_clock> lastDraw;
	std::chrono::time_point<std::chrono::steady_clock> nextDraw;
	uint64_t frameCount; // This must be 64-bits, a 32-bit number could overflow after a few months of constant usage.
};