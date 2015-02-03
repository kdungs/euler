#include <array>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

auto generatePrimes(std::size_t upperLimit) -> std::vector<unsigned> {
  auto primes = std::vector<unsigned>{};
  primes.reserve(upperLimit);
  std::vector<bool> bits(upperLimit, true);
  bits[0] = false;
  bits[1] = false;
  for (auto p = 2u; p < upperLimit; ++p) {
    if (bits[p]) {
      primes.emplace_back(p);
      for (auto i = p * p; i < upperLimit; i += p) {
        bits[i] = false;
      }
    }
  }
  primes.shrink_to_fit();
  return primes;
}

auto explode(unsigned x) -> std::array<unsigned, 4> {
  assert(x > 1000 && x < 10000 && "1000 < x < 10000");
  return {{x / 1000, (x % 1000) / 100, (x % 100) / 10, x % 10}};
}

auto implode(const std::array<unsigned, 4>& arr) -> unsigned {
  return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}

int main() {
  auto primes = generatePrimes(10000);
  auto lower = std::find_if(std::begin(primes), std::end(primes),
                            [](const unsigned& p) { return p > 1000; });
  const auto end = std::end(primes);
  while (lower != end) {
    auto p = *lower;
    auto digits = explode(p);
    auto firstOccurence = 0u;
    while (std::next_permutation(std::begin(digits), std::end(digits))) {
      const auto n = implode(digits);
      if (n > p && *std::lower_bound(lower, end, n) == n) {
        if (firstOccurence == 0) {
          firstOccurence = n;
        } else {
          if (firstOccurence - p == n - firstOccurence) {
            std::cout << p << ',' << firstOccurence << ',' << n << '\n';
          }
        }
      }
    }
    ++lower;
  }
}
