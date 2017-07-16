template<typename T, typename N>
T multiply_accum6(T x, N n, T r) {
  if (n == 1) return r + x;
  if (odd(n)) r = r + x;
  n = half(n);
  x = x + x; 
  return multiply_accum6(x, n, r);
}
template<typename T, typename N>
T multiply6(T x, N n) {
  return multiply_accum6(x, n, T{0});
}


