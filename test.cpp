#include "boost/type_index.hpp"
#include <Eigen/Dense>
#include <functional>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

struct DataTest {
  int a;
  int b;
  bool operator==(const DataTest &t) const { return a == t.a && b == t.b; }
  DataTest(int x, int y) : a(x), b(y) {}
};
struct HashStruct {
  std::size_t operator()(const DataTest &data) const {
    return std::hash<int>()(data.a) ^ std::hash<int>()(data.b);
  }
};

std::size_t hash_func(const DataTest &data) {
  return std::hash<int>()(data.a) ^ std::hash<int>()(data.b);
}

namespace std {
template <> struct hash<DataTest> {
  std::size_t operator()(const DataTest &data) const {
    return std::hash<int>()(data.a) ^ std::hash<int>()(data.b);
  };
};
} // namespace std

int main(int argc, char **argv) {
  Eigen::Quaterniond q1(Eigen::AngleAxisd(M_PI_2, Eigen::Vector3d::UnitZ()));
  std::cout << q1.coeffs() << std::endl;
  Eigen::Matrix3d r1;
  r1 = q1.matrix();
  std::cout << r1 << std::endl;
  Eigen::Vector3d Px(Eigen::Vector3d::UnitX());
  auto test1 = r1 * Px;
  auto test2 = q1 * Px;
  std::cout << "test1 " << test1 << std::endl;
  std::cout << "test2 " << test2 << std::endl;

      return 0;
}
