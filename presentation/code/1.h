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


