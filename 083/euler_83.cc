#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <sstream>

template <std::size_t N>
using Matrix = std::array<std::array<unsigned, N>, N>;

template <std::size_t N>
auto dijkstraDistanceTLBR(const Matrix<N>& cost) -> unsigned {
  using Point = std::pair<std::size_t, std::size_t>;
  using PointWithCost = std::pair<unsigned, Point>;
  // Initialisation
  auto scanned = std::vector<bool>(N * N, false);
  auto prev = std::array<std::array<Point, N>, N>{};
  auto dist = Matrix<N>{};
  for (auto& row : dist) {
    for (auto& elem: row) {
      elem = std::numeric_limits<unsigned>::max();
    }
  }
  dist[0][0] = cost[0][0];
  auto pwcComp = [](const PointWithCost& lhs, const PointWithCost& rhs) {
    return lhs.first >= rhs.first;
  };
  auto pq = std::priority_queue<PointWithCost, std::vector<PointWithCost>,
                                decltype(pwcComp)>(pwcComp);
  pq.emplace(cost[0][0], std::make_pair(0, 0));
  // Run
  auto neighbours = [&](const Point& p) {
    std::vector<Point> ns;
    ns.reserve(4);
    if (p.first > 0) {
      ns.emplace_back(p.first - 1, p.second);
    }
    if (p.first < N - 1) {
      ns.emplace_back(p.first + 1, p.second);
    }
    if (p.second > 0) {
      ns.emplace_back(p.first, p.second - 1);
    }
    if (p.second < N - 1) {
      ns.emplace_back(p.first, p.second + 1);
    }
    ns.shrink_to_fit();
    return ns;
  };
  while (!pq.empty()) {
    auto u = pq.top();
    pq.pop();
    const auto& p = u.second;
    scanned[p.first * N + p.second] = true;
    auto ns = neighbours(p);
    for (const auto& n : ns) {
      if (!scanned[n.first * N + n.second]) {
        auto alt = dist[p.first][p.second] + cost[n.first][n.second];
        if (alt < dist[n.first][n.second]) {
          dist[n.first][n.second] = alt;
          prev[n.first][n.second] = p;
          pq.emplace(alt, n);
        }
      }
    }
  }
  return dist[N - 1][N - 1];
}

int main() {
  //Matrix<5> matrix{{
  //  {{131, 673, 234, 103,  18}},
  //  {{201,  96, 342, 965, 150}},
  //  {{630, 803, 746, 422, 111}},
  //  {{537, 699, 497, 121, 956}},
  //  {{805, 732, 524,  37, 331}}
  //}};
  Matrix<80> matrix;
  auto ifs = std::ifstream{"matrix.txt"};
  std::string line;
  for (auto& row : matrix) {
    std::getline(ifs, line);
    std::stringstream ss(line);
    std::string field;
    std::generate(std::begin(row), std::end(row), [&]() {
      getline(ss, field, ',');
      return std::stoul(field);
    });
  }
  ifs.close();
  std::cout << dijkstraDistanceTLBR(matrix) << '\n';
}
