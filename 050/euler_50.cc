#include <cassert>
#include <iostream>
#include <vector>

template <std::size_t N>
class PrimeSieve {
 public:
  PrimeSieve() : bits_(N, true) {
    primes_.reserve(N);
    bits_[0] = false;
    bits_[1] = false;
    for (auto p = 2u; p < N; ++p) {
      if (bits_[p]) {
        primes_.emplace_back(p);
        for (auto i = p * p; i < N; i += p) {
          bits_[i] = 0;
        }
      }
    }
    primes_.shrink_to_fit();
  }
  auto IsPrime(size_t x) const -> bool {
    assert(x < N);
    return static_cast<bool>(bits_[x]);
  }
  auto primes() const -> const std::vector<unsigned>& {
    return primes_;
  }

 private:
  std::vector<bool> bits_;
  std::vector<unsigned> primes_;
};

int main() {
  const auto N = 1000000u;
  auto ps = PrimeSieve<N>{};
  auto maxN = 0u,
       maxP = 0u;
  auto outer = std::begin(ps.primes());
  const auto end = std::end(ps.primes());

  for (; outer != end; ++outer) {
    auto sum = *outer;
    auto n = 1u;
    auto inner = outer;
    ++inner;
    while (inner != end && sum + *inner < N) {
      sum += *inner;
      ++n;
      ++inner;
      if (n > maxN && ps.IsPrime(sum)) {
        maxN = n;
        maxP = sum;
      }
    }
  }
  std::cout << maxN << ',' << maxP << '\n';
}
