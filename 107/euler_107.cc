#include <array>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <experimental/optional>

template <typename T>
class UnionFind {
  public:
    auto Add(const T& x) -> void {
      map_[x] = x;
    }
    auto Union(const T& x, const T& y) -> void {
      map_[Find(y)] = map_[Find(x)];
    }
    auto Find(const T& x) const -> const T& {
      if (map_.at(x) == x) {
        return x;
      }
      return Find(map_.at(x));
    }

  private:
  std::unordered_map<T, T> map_;
};

struct Edge {
  unsigned v1, v2, cost;
  Edge(unsigned pv1, unsigned pv2, unsigned pcost)
      : v1{std::move(pv1)}, v2{std::move(pv2)}, cost{std::move(pcost)} {}
  auto operator<(const Edge& rhs) const -> bool {
    return cost < rhs.cost;
  }
};

template <std::size_t N>
auto loadSortedEdges(const std::string& filename)
    -> std::vector<Edge> {
  using std::experimental::optional;
  using std::experimental::make_optional;
  auto edges = std::vector<Edge>{};
  // Load adjacency matrix from file
  auto matrix = std::array<std::array<optional<unsigned>, N>, N>{};
  auto ifs = std::ifstream{filename};
  std::string line;
  for (auto& row : matrix) {
    std::getline(ifs, line);
    std::stringstream ss(line);
    std::string field;
    std::generate(std::begin(row), std::end(row), [&]() {
      getline(ss, field, ',');
      if (field != "-") {
        return make_optional<unsigned>(std::stoul(field));
      } else {
        return optional<unsigned>{};
      }
    });
  }
  ifs.close();
  // Extract edges from matrix
  for (auto row = 1u; row < N; ++row) {
    for (auto col = 0u; col < row; ++col) {  // symmetric
      if (matrix[row][col]) {
        edges.emplace_back(row, col, *matrix[row][col]);
      }
    }
  }
  std::sort(std::begin(edges), std::end(edges));
  return edges;
}

template <std::size_t N>
auto totalMSTSavingKruskal(const std::vector<Edge>& edges) -> unsigned {
  auto uf = UnionFind<unsigned>{};
  for (auto v = 0u; v < N; ++v) {
    uf.Add(v);
  }
  auto saving = 0u;
  for (const auto& edge : edges) {
    if (uf.Find(edge.v1) != uf.Find(edge.v2)) {
      uf.Union(edge.v1, edge.v2);
    } else {
      saving += edge.cost;
    }
  }
  return saving;
}

int main() {
  std::cout << totalMSTSavingKruskal<40>(loadSortedEdges<40>("network.txt")) << '\n';
}
