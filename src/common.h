#include <cstdint>
#include <algorithm>
#include <limits>
#include <boost/multiprecision/cpp_int.hpp> 
#include <boost/math/special_functions/gamma.hpp>
namespace std {
template<typename T>
struct reciprocal {
  T operator()(const T &x) {
    return T(1) / x;
  }
};
}

namespace algo {

#define Integer typename
#define SemiGroupOperation typename
#define Regular typename
#define requires(...)

template<typename T>
class matrix {
public:
  typedef T value_type;
  typedef size_t size_type;
//private:
  size_type m;
  size_type n;
  std::vector<T> data;
public:
  matrix(size_type m, size_type n, const value_type &value) : m{m}, n{n}, data(m * n, value) {}
  matrix(const matrix &) = default;
  matrix(matrix &&) = default;
  
  matrix& operator=(const matrix &x) {
    m = x.m;
    n = x.n;
    data = x.data;
    return *this;
  }

  matrix& operator=(matrix &&x) {
    m = x.m;
    n = x.n;
    data = std::move(x.data);
    return *this;
  }


  value_type& operator()(size_type i, size_type j) {
    return data[i * m + j];
  }

  const value_type& operator()(size_type i, size_type j) const {
    return data[i * m + j];
  }

  size_type cols() const {
    return n;
  }

  size_type rows() const {
    return m;
  }

};

using namespace boost::multiprecision;
const int64_t a1 = (1 << 20);
const int64_t b1 = (1 << 20);
const auto c1 = a1 * b1;

const int64_t a2 = (1LL << 30) + 1;
const int64_t b2 = (1LL << 30) + 1;
const int64_t c2 = a2 * b2;

template<typename T>
inline
bool odd(T x) {
  return (x & 1);
}

inline 
bool odd(cpp_int x) {
  return (x & 1) == 1;
}


template<typename T>
inline
T half(T x) {
  return x >> 1;
}

template<typename T>
bool even(T x) {
  return !odd(x);
}

template<typename T, typename N>
T multiply0(T x, N n) {
  if (n == 1) return x;
  return multiply0(x, --n) + x;
}

template<typename T, typename N>
T multiply_accum1(T x, N n, T r) {
  if (n == 1) return x + r;
  return multiply_accum1(x, n - 1, r + x);
  return x;
}

template<typename T, typename N>
T multiply1(T x, N n) {
  return multiply_accum1(x, n, T(0));
}


template<typename T, typename N>
T multiply_accum2(T x, N n, T r) {
  if (n == 1) return x + r;
  --n;
  r = r + x;
  return multiply_accum2(x, n, r);
}

template<typename T, typename N>
T multiply2(T x, N n) {
  return multiply_accum2(x, n, T{0});
}


template<typename T, typename N>
T multiply_accum3(T x, N n, T r) {
  while(true) {
    if (n == 1) return x + r;
    --n;
    r = r + x;
  }
}

template<typename T, typename N>
T multiply3(T x, N n) {
  return multiply_accum3(x, n, T{0});
}

template<typename T, typename N>
T multiply4(T x, N n) {
  if (n == 1) return x;
  T r = multiply4(x + x, half(n));
  if (odd(n)) r = r + x;
  return r;
}

template<typename T, typename N>
T multiply_accum5(T x, N n, T r) {
  if (n == 1) return r + x;
  if (odd(n)) {
    return multiply_accum5(x + x, half(n), r + x);
  } else {
    return multiply_accum5(x + x, half(n), r);
  }
}

template<typename T, typename N>
T multiply5(T x, N n) {
  return multiply_accum5(x, n, T{0});
}

template<typename T, typename N>
T multiply_accum6(T x, N n, T r) {
  if (n == 1) return r + x;
  if (odd(n)) {
    r = r + x;
  }
  n = half(n);
  x = x + x; 
  return multiply_accum6(x, n, r);
}

template<typename T, typename N>
T multiply6(T x, N n) {
  return multiply_accum6(x, n, T{0});
}


template<typename T, typename N>
inline
T multiply_accum7(T x, N n, T r) {
  while(true) {
    if (n == 1) return r + x;
    if (odd(n)) {
      r += x;
    }
    x += x;
    n = half(n);
  }
}

template<typename T, typename N>
T multiply7(T x, N n) {
  return multiply_accum7(x, n, T{0});
}

template<typename T, typename N>
inline
constexpr
T multiply_accum8(T x, N n, T r) {
  while(true) {
    if (odd(n)) {
      r += x;
      if (n == 1) return r;
    }
    x += x;
    n = half(n);
  }
}

template<typename T, typename N>
inline
constexpr
T multiply8(T x, N n) {
  return multiply_accum8(x, n, T{0});
}

template<typename T, typename N>
inline
constexpr
T multiply9(T x, N n) {
  if (n == 1) return x;
  --n;
  return multiply_accum8(x, n, x);
}

template<typename T, typename N>
inline
constexpr
T multiply10(T x, N n) {
  while(!odd(n)) {
    x += x;
    n = half(n);
  }
  if (n == 1) return x;
  --n;
  return multiply_accum8(x, n, x);
}

template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) && Domain<T, Op>)
inline
constexpr
T power_accum(T x, N n, T r, Op op) {
  while(true) {
    if (odd(n)) {
      r = op(r, x);
      if (n == 1) return r;
    }
    x = op(x, x);
    n = half(n);
  }
}

template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) && Domain<T, Op>)
inline
constexpr
T power(T x, N n, Op op) {
  while(!odd(n)) {
    x = op(x, x);
    n = half(n);
  }
  if (n == 1) return x;
  return power_accum(op(x, x), half(n - 1), x, op);
}

template<typename T>
T identify_element(std::multiplies<T>) {
  return T(1);
}

template<typename T>
T identify_element(std::plus<T>) {
  return T(0);
}

template<typename T>
std::negate<T> inverse_operation(std::plus<T>) {
  return std::negate<T>{};
}

template<typename T>
std::reciprocal<T> inverse_operation(std::multiplies<T>) {
  return std::reciprocal<T>{};
}


template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) && Domain<T, Op>)
inline
constexpr
T power_monoid(T x, N n, Op op) {
  if (n == 0) return identify_element(op);
  return power(x, n, op);
}


template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) && Domain<T, Op>)
inline
constexpr
T power_group(T x, N n, Op op) {
  if (n < 0) {
    n = -n;
    x = inverse_operation(op)(x);
  }
  return power(x, n, op);
}

template<typename It>
struct path_iterator {
  It it;
  size_t m;
  size_t n;
  size_t i;
  size_t j;
  size_t k;

  path_iterator() = default;
  path_iterator(It it, size_t m, size_t n, size_t i, size_t j, size_t k) : it(it), m(m), n(n), i(i), j(j), k(k) {}
  path_iterator(const path_iterator &) = default;
  path_iterator(path_iterator &&) = default;

  path_iterator& operator=(const path_iterator &x) {
    it = x.it;
    m = x.m;
    n = x.n;
    i = x.i;
    j = x.j;
    k = x.k;
    return *this;
  }

  auto& operator++() {
    ++k;
    return *this;
  }

  typename std::iterator_traits<It>::value_type operator*() {
    return *(it + i * m + k) + *(it + k * m + j);
  }

  friend
  inline
  bool operator==(const path_iterator &x, const path_iterator &y) {
    return x.k == y.k && x.m == y.m && x.n == y.n && x.i == y.i && x.j == y.j && x.it == y.it;
  }

  friend
  inline
  bool operator!=(const path_iterator &x, const path_iterator &y) {
    return !(x == y);
  }

};

template<typename It>
auto make_path_iterator(It it, size_t m, size_t n, size_t i, size_t j, size_t k) {
  return path_iterator<It>(it, m, n, i, j, k);
}


template<typename T>
struct tropic_semigroup_operation {
  matrix<T> operator()(const matrix<T> &a, const matrix<T>&) {
    auto b = a;
    for (size_t i = 0; i < a.rows(); ++i) {
      for (size_t j = 0; j < a.cols(); ++j) {
        auto first = std::begin(a.data);
        auto f = make_path_iterator(first, a.rows(), a.cols(), i, j, 0);
        auto l = make_path_iterator(first, a.rows(), a.cols(), i, j, a.rows());
        auto pos = std::min_element(f, l);
        b(i, j) = *pos;
      }
    }
    return b;
  }
};

template<typename Matrix>
void print(const Matrix &x) {
  for (size_t i = 0; i < x.rows(); ++i) {
    for (size_t j = 0; j < x.cols(); ++j) {
      std::cout << x(i, j) << " ";
    }
    std::cout << "\n";
  }
}

void shortest_path_example() {
  auto inf = std::numeric_limits<int>::max();
  matrix<int> graph(7, 7, inf);
  graph(0, 0) = 0;
  graph(1, 1) = 0;
  graph(2, 2) = 0;
  graph(3, 3) = 0;
  graph(4, 4) = 0;
  graph(5, 5) = 0;
  graph(6, 6) = 0;
  graph(0, 1) = 6;
  graph(0, 3) = 3;

  auto n = graph.rows() - 1;
  auto paths = power(graph, n - 1, tropic_semigroup_operation<int>{});
}

}
