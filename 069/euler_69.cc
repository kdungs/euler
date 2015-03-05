#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
auto generatePrimes(T upperLimit) {
  auto primes = std::vector<T>{};
  primes.reserve(upperLimit);
  std::vector<bool> bits(upperLimit, true);
  bits[0] = false;
  bits[1] = false;
  for (auto p = T{2}; p < upperLimit; ++p) {
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

template <typename T>
auto findDivisors(T x, const std::vector<T>& primes) {
  for (const auto& p : primes) {
    if (x % p == 0) {
      auto m = p;
      auto q = x / p;
      while (q % p == 0) {
        m *= p;
        q /= p;
      }
      return std::make_tuple(m, q);
    }
  }
  assert(false);
}

template <typename T>
auto weights(T upperLimit) {
  const auto primes = generatePrimes(upperLimit);
  auto ws = std::vector<double>(upperLimit, 0.0);
  for (const auto& p : primes) {
    for (auto pm = p; pm < upperLimit; pm *= p) {
      ws[pm] = 1.0 / (1.0 - 1.0 / p);
    }
  }
  for (auto i = T{2}; i < upperLimit; ++i) {
    if (static_cast<T>(ws[i]) == T{0}) {  // not yet calculated
      T m, q;
      std::tie(m, q) = findDivisors(i, primes);
      ws[i] = ws[m] * ws[q];
    }
  }
  return ws;
}

int main() {
  const auto N = 1'000'001ul;
  //const auto N = 11ul;
  auto ws = weights(N);

  auto n = std::distance(std::begin(ws),
                         std::max_element(std::begin(ws), std::end(ws)));
  std::cout << n << '\n';
}
