#pragma once
#include "time_provider.hpp"

class MockTimeProvider : public TimeProvider {
public:
  MockTimeProvider(std::time_t initial);

  void Advance(std::time_t seconds);

  std::time_t Now();

private:
  std::time_t MockTime_;
};
