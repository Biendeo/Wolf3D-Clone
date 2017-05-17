// Framerate.cpp
//
// Manages a consistent framerate and manages buffer update times.

#include "Framerate.h"

#include <thread>
#include <chrono>

Framerate::Framerate(short expectedFPS) {
	this->expectedFPS = expectedFPS;
	this->frameCount = 0ull;
	UpdateDrawTimes();
	this->delta = 0.0f;
}

void Framerate::SleepToNextSwapBuffer() {
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto nanos = (nextDraw - currentTime);
	std::this_thread::sleep_for(nanos);
}

void Framerate::UpdateDrawTimes() {
	auto previousDraw = this->lastDraw;
	this->lastDraw = std::chrono::high_resolution_clock::now();
	this->delta = (this->lastDraw - previousDraw).count() / 1000000000.0;
	this->nextDraw = lastDraw + std::chrono::nanoseconds((int)(1000000000.0 / expectedFPS));
}

uint64_t Framerate::IncrementFrameCount() {
	return ++frameCount;
}

short Framerate::ExpectedFPS() {
	return expectedFPS;
}

short Framerate::ExpectedFPS(short expectedFPS) {
	this->expectedFPS = expectedFPS;
	return expectedFPS;
}

uint64_t Framerate::FrameCount() {
	return frameCount;
}

float Framerate::Delta() {
	return delta;
}
