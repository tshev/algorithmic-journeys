template<typename T, typename N>
T multiply0(T x, N n) {
  if (n == 1) return x;
  return multiply0(x, --n) + x;
}

