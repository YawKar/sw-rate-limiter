#include "time_provider.hpp"

std::time_t TimeProvider::Now() { return std::time(0); }
