#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

#include <experimental/optional>

auto generatePrimes(std::size_t upperLimit) -> std::vector<bool> {
  std::vector<bool> bits(upperLimit, true);
  bits[0] = false;
  bits[1] = false;
  for (auto p = 2u; p < upperLimit; ++p) {
    if (bits[p]) {
      for (auto i = p * p; i < upperLimit; i += p) {
        bits[i] = false;
      }
    }
  }
  return bits;
}

int main() {
  using std::experimental::optional;
  using std::experimental::make_optional;
  using MaybeFactors = optional<std::unordered_set<unsigned>>;

  const std::size_t upperLimit = 150000;
  std::vector<bool> isPrime = generatePrimes(upperLimit);
  auto factors = std::array<MaybeFactors, upperLimit>{};
  auto good = MaybeFactors{};

  const auto target = 4u;
  for (auto n = 2u; n < upperLimit; ++n) {
    if (good && good->size() == target * target) {
      std::cout << n - target << '\n';
      break;
    }
    if (isPrime[n]) {
      factors[n] = make_optional(std::unordered_set<unsigned>{n});
      for (auto i = n * n; i < upperLimit; i *= n) {  // write out powers
        factors[i] = make_optional<std::unordered_set<unsigned>>({i});
      }
      good = MaybeFactors{};
    } else if(!factors[n]) {  // has not been initialised - not a power
      unsigned k = std::sqrt(n) + 1;
      for (; k >= 2; --k) {
        if (factors[k] && factors[k]->size() == 1 && n % k == 0) {
          break; // found largest prime factor
        }
      }
      auto fs = factors[n / k];
      if (!fs || fs->size() == target) {
        factors[n] = MaybeFactors{};
        good = MaybeFactors{};
      } else {
        factors[n] = MaybeFactors{*fs};
        factors[n]->emplace(k);
        if (factors[n]->size() == target) {
          if (!good) {
            good = MaybeFactors{*factors[n]};
          } else {
            bool intersect = false;
            const auto gend = good->end();
            for (const auto& f : *factors[n]) {
              if (good->find(f) != gend) {
                intersect = true;
                break;
              }
            }
            if (!intersect) {
              good->insert(std::begin(*factors[n]), std::end(*factors[n]));
            } else {
              good = MaybeFactors{};
            }
          }
        } else {
          good = MaybeFactors{};
        }
      }
    }
  }
}
