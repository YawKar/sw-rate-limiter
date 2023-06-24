#include "rate_limiter.hpp"

RateLimiter::RateLimiter(unsigned int maxRequests, unsigned int windowSize,
                         TimeProvider &timeProvider)
    : MaxRequests_(maxRequests), WindowSize_(windowSize),
      TimeProvider_(timeProvider) {}

bool RateLimiter::ShouldAllow(std::string clientId) {
  auto clientData = Clients_[clientId];

  while (!clientData.TimeStamps.empty() &&
         (TimeProvider_.Now() - clientData.TimeStamps.front() > WindowSize_)) {
    clientData.TimeStamps.pop();
  }

  if (clientData.TimeStamps.size() < MaxRequests_) {
    clientData.TimeStamps.push(TimeProvider_.Now());
    return true;
  } else {
    return false;
  }
}
