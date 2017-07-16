template<typename T, typename N>
T multiply10(T x, N n) {
  while(!odd(n)) {
    x += x;
    n = half(n);
  }
  if (n == 1) return x;
  --n;
  return multiply_accum8(x, n, x);
}


