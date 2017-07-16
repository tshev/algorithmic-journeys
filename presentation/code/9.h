template<typename T, typename N>
T multiply9(T x, N n) {
  if (n == 1) return x;
  --n;
  return multiply_accum8(x, n, x);
}


