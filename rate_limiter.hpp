#pragma once

#include "utils/time_provider.hpp"
#include <queue>
#include <string>
#include <unordered_map>

class RateLimiter {
public:
  RateLimiter(unsigned int maxRequests, unsigned int windowSize,
              TimeProvider &timeProvider);

  bool ShouldAllow(std::string clientId);

private:
  struct ClientData {
    std::queue<std::time_t> TimeStamps;
  };

  std::unordered_map<std::string, ClientData> Clients_;
  unsigned int MaxRequests_;
  unsigned int WindowSize_;
  TimeProvider &TimeProvider_;
};
