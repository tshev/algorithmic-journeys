
template<typename T, typename N>
T multiply4(T x, N n) {
  if (n == 1) return x;
  T r = multiply4<T, N>(x + x, half(n));
  if (odd(n)) r = r + x;
  return r;
}


