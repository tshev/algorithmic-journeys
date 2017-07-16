template<typename T> struct tropical_semiring {
  matrix<T> operator()(const matrix<T> &a,
                       const matrix<T> &b) {
    auto closure = a;
    auto n = a.rows();
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        T result = std::numeric_limits<T>::max();
        for (size_t k = 0; k < n; ++k) {
          result = min(result, a(i, k) + b(k, j)); }
        closure(i, j) = result; }}
    return b;}};
power_monoid(10, 30, matrix_transitive_closure<int>{});
