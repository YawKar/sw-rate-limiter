#include "mock_time_provider.hpp"

MockTimeProvider::MockTimeProvider(std::time_t initial) : MockTime_(initial) {}

void MockTimeProvider::Advance(std::time_t seconds) { MockTime_ += seconds; }

std::time_t MockTimeProvider::Now() { return MockTime_; }
