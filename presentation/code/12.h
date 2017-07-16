template<typename T, typename N, typename Op>
requires(Regular(T) && Integer(N) &&
        SemigroupOperation(Op) && Domain<T, Op>)
T power(T x, N n, Op op) {
  while(!odd(n)) {
    x = op(x, x);
    n = half(n);
  }
  if (n == 1) return x;
  return power_accumulate(op(x, x), half(n - 1), x, op);
}
