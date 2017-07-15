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
/*
static void BM_multiply0(benchmark::State& state) {
  while (state.KeepRunning())
    assert(algo::multiply0(algo::a1, algo::b1) == algo::c1);
}
BENCHMARK(BM_multiply0);
*/

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
  while (state.KeepRunning())
    algo::shortest_path_example();
}
BENCHMARK(BM_shortest_path);

BENCHMARK_MAIN()
