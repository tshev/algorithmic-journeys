#include <cassert>
#include <algorithm>
#include <iostream>
#include <benchmark/benchmark.h>
#include "common.h"
// Benchmark
static void BM_baseline(benchmark::State& state) {
  while (state.KeepRunning())
    benchmark::DoNotOptimize(algo::cpp_int(algo::a1) * algo::cpp_int(algo::b1));
}
BENCHMARK(BM_baseline);

// Benchmark
static void BM_multiply0(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply0(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply0);

// Benchmark
/*
static void BM_multiply1(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply1(algo::a1, algo::b1) == algo::c1);
}
//BENCHMARK(BM_multiply1);
*/

// Benchmark
/*
static void BM_multiply2(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply2(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply2);
*/
// Benchmark
static void BM_multiply3(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply3(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply3);

// Benchmark
static void BM_multiply4(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply4(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply4);

// Benchmark
static void BM_multiply5(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply5(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply5);

// Benchmark
static void BM_multiply6(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply6(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply6);


// Benchmark
static void BM_multiply7(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply7(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply7);

// Benchmark
static void BM_multiply8(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply8(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply8);


// Benchmark
static void BM_multiply9(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply9(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply9);

// Benchmark
static void BM_multiply10(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply10(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply10);


static void BM_pow(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::power_group(3, 11, std::multiplies<int>{}) == 177147);
}
BENCHMARK(BM_pow);
static void BM_shortest_path(benchmark::State& state) {
  auto inf = std::numeric_limits<int>::max();
  size_t n = 7;
  algo::matrix<int> graph(n, n, inf);
  graph(0, 0) = 0;
  graph(1, 1) = 0;
  graph(2, 2) = 0;
  graph(3, 3) = 0;
  graph(4, 4) = 0;
  graph(5, 5) = 0;
  graph(6, 6) = 0;
  graph(0, 1) = 6;
  graph(0, 3) = 3;
  graph(1, 4) = 2;
  graph(1, 5) = 10;
  
  graph(2, 0) = 7;
  graph(3, 2) = 5;
  graph(3, 5) = 4;
  graph(4, 6) = 3;
  graph(5, 2) = 6;
  graph(5, 4) = 7;
  graph(5, 6) = 8;
  graph(6, 1) = 9;
  algo::matrix<int> result(7, 7, 0);
  while (state.KeepRunning())
    result = algo::power(graph, n - 1, algo::tropic_semiring_operation<int>{});
}
BENCHMARK(BM_shortest_path);

BENCHMARK_MAIN()

