template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) &&
         SemigroupOperation(Op) && Domain<T, Op>)
T power_accumulate(T x, N n, T r, Op op) {
  while(true) {
    if (odd(n)) {
      r = op(r, x);
      if (n == 1) return r;
    }
    x = op(x, x);
    n = half(n);
  }
}
