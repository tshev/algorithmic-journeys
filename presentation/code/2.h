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


