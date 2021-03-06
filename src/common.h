#include <cstdint>
#include <algorithm>
#include <limits>
#include <boost/multiprecision/cpp_int.hpp> 
#include <boost/math/special_functions/gamma.hpp>

#define Integer typename
#define SemiGroupOperation typename
#define Regular typename
#define requires(...)


namespace std {
template<typename T>
struct reciprocal {
  T operator()(const T &x) {
    return T(1) / x;
  }
};

template<typename T>
struct and_op {
  T operator()(const T &x, const T &y) {
    return x & y;
  }
};

template<typename T>
struct or_op {
  T operator()(const T &x, const T &y) {
    return x | y;
  }
};
}
namespace algo {
template<typename T>
class matrix {
public:
  typedef T value_type;
  typedef size_t size_type;

private:
  size_type m;
  size_type n;
  std::vector<T> content;
public:
  matrix(size_type m, size_type n, const value_type &value) : m{m}, n{n}, content(m * n, value) {}
  matrix(const matrix &) = default;
  matrix(matrix &&) = default;
  
  matrix& operator=(const matrix &x) {
    m = x.m;
    n = x.n;
    content = x.content;
    return *this;
  }

  matrix& operator=(matrix &&x) {
    m = x.m;
    n = x.n;
    content = std::move(x.content);
    return *this;
  }


  value_type& operator()(size_type i, size_type j) {
    return content[i * m + j];
  }

  const value_type& operator()(size_type i, size_type j) const {
    return content[i * m + j];
  }

  size_type cols() const {
    return n;
  }

  size_type rows() const {
    return m;
  }

  auto begin() {
    return std::begin(content);
  }

  auto end() {
    return std::end(content);
  }

  auto begin() const {
    return std::begin(content);
  }

  auto end() const {
    return std::end(content);
  }

  auto data() {
    return content.data();
  }
};
}

std::ostream& operator<<(std::ostream  &out, const algo::matrix<int> &x) {
  for (size_t i = 0; i < x.rows(); ++i) {
    for (size_t j = 0; j < x.cols(); ++j) {
       if (x(i, j) == std::numeric_limits<int>::max()) {
        out << "inf";
       } else {
        out << x(i, j);
       }
       out  << "\t\t";
    }
    out << std::endl;
  }
  return out;
}

namespace algo {


using namespace boost::multiprecision;
const cpp_int a1 = (1 << 20);
const cpp_int b1 = (1 << 20);
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
  return (x % 2) == 1;
}


template<typename T>
inline
T half(T x) {
  return x >> 1;
}

inline
cpp_int half(cpp_int x) {
  return x / 2;
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
  T r = multiply4<T, N>(x + x, half(n));
  if (odd(n)) r = r + x;
  return r;
}

template<typename T, typename N>
T multiply_accum5(T x, N n, T r) {
  if (n == 1) return r + x;
  if (odd(n)) {
    return multiply_accum5<T, N>(x + x, half(n), r + x);
  } else {
    return multiply_accum5<T, N>(x + x, half(n), r);
  }
}

template<typename T, typename N>
T multiply5(T x, N n) {
  return multiply_accum5<T, N>(x, n, T{0});
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
T multiply8(T x, N n) {
  return multiply_accum8(x, n, T{0});
}

template<typename T, typename N>
inline
T multiply9(T x, N n) {
  if (n == 1) return x;
  --n;
  return multiply_accum8(x, n, x);
}

template<typename T, typename N>
inline
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
requires(Regular(T) && Integer(N) &&
         SemigroupOperation(Op) && Domain<T, Op>)
inline
T power_accumulate(T x, N n, T r, Op op) {
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
requires(Regular(T) && Integer(N) &&
        SemigroupOperation(Op) && Domain<T, Op>)
inline
T power(T x, N n, Op op) {
  while(!odd(n)) {
    x = op(x, x);
    n = half(n);
  }
  if (n == 1) return x;
  return power_accumulate(op(x, x), half(n - 1), x, op);
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
T power_monoid(T x, N n, Op op) {
  if (n == 0) return identify_element(op);
  return power(x, n, op);
}


template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) && Domain<T, Op>)
inline
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
    typedef typename std::iterator_traits<It>::value_type T;
    auto max = std::numeric_limits<T>::max();
    auto a = *(it + i * m + k);
    auto b = *(it + k * m + j);
    if (a == max || b == max) { return max; }
    return  a + b;
  }

  friend inline bool operator==(const path_iterator &x, const path_iterator &y) {
    return x.k == y.k && x.m == y.m && x.n == y.n && x.i == y.i && x.j == y.j && x.it == y.it;
  }

  friend inline bool operator!=(const path_iterator &x, const path_iterator &y) {
    return !(x == y);
  }

};

template<typename It>
auto make_path_iterator(It it, size_t m, size_t n, size_t i, size_t j, size_t k) {
  return path_iterator<It>(it, m, n, i, j, k);
}


template<typename T>
struct semigroup_closure {
  matrix<T> operator()(const matrix<T> &a, const matrix<T>&) {
    auto b = a;
    auto n = a.rows();
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        T result = 0;
        for (size_t k = 0; k < n; ++k) {
          result = result | (a(i, k) & a(k, j));
        }
        b(i, j) = result;
      }
    }
    return b;
  }
};


template<typename T>
struct tropic_semiring_operation {
  matrix<T> operator()(const matrix<T> &a, const matrix<T>&) {
    auto b = a;
    for (size_t i = 0; i < a.rows(); ++i) {
      for (size_t j = 0; j < a.cols(); ++j) {
        auto first = std::begin(a);
        auto f = make_path_iterator(first, a.rows(), a.cols(), i, j, 0);
        auto l = make_path_iterator(first, a.rows(), a.cols(), i, j, a.rows());
        auto pos = std::min_element(f, l);
        b(i, j) = *pos;
      }
    }
    return b;
  }
};


void closure_example() {
  matrix<int> graph(3, 3, 0);
  graph(0, 0) = 1;
  graph(1, 1) = 1;
  graph(2, 2) = 1;
  graph(0, 1) = 1;
  graph(1, 0) = 1;
  graph(1, 2) = 1;
  graph(2, 1) = 1;

  auto n = graph.rows() - 1;
  std::cout << graph;
  auto paths = power(graph, n, semigroup_closure<int>{});
  std::cout << paths;
}
}
