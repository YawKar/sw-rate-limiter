#pragma once
#include <ctime>

class TimeProvider {
public:
  virtual std::time_t Now();
};
