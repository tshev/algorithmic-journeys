
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

