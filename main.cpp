
#include "rate_limiter.hpp"
#include "utils/mock_time_provider.hpp"
#include <iostream>

int main() {
  MockTimeProvider timeProvider(0);
  RateLimiter limiter(5, 10, timeProvider);

  for (int i = 0; i < 10; ++i) {
    if (limiter.ShouldAllow("client1")) {
      std::cout << "Request " << i << " allowed.\n";
    } else {
      std::cout << "Request " << i << " denied.\n";
    }
    timeProvider.Advance(2);
  }

  return 0;
}
