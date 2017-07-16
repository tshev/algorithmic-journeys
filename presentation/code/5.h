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

