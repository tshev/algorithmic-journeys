template<typename T, typename N>
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
T multiply8(T x, N n) {
  return multiply_accum8(x, n, T{0});
}


