template<typename T, typename N>
T multiply_accum7(T x, N n, T r) {
  while(true) {
    if (n == 1) return r + x;
    if (odd(n)) r += x;
    x += x;
    n = half(n);
  }
}
template<typename T, typename N>
T multiply7(T x, N n) {
  return multiply_accum7(x, n, T{0});
}
