#include "stop_watch.h"

#include <gtest/gtest.h>

#include <thread>

TEST(stop_watch, not_start) {
  StopWatch sw;
  sw.Clear();

  EXPECT_EQ(0, sw.GetMs());
  EXPECT_EQ(0, sw.GetNs());
  EXPECT_EQ(0, sw.GetUs());
}

TEST(stop_watch, get_ms) {
  StopWatch sw;
  sw.Start();

  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  uint64_t cost_ms = sw.GetMs();
  EXPECT_GE(cost_ms, 1) << "cost ms: " << cost_ms << std::endl;
}

TEST(stop_watch, get_us) {
  StopWatch sw;
  sw.Start();

  std::this_thread::sleep_for(std::chrono::microseconds(100));

  uint64_t cost_us = sw.GetUs();
  EXPECT_GT(cost_us, 100) << "cost us: " << cost_us << std::endl;
}

TEST(stop_watch, get_ns) {
  StopWatch sw;
  sw.Start();

  std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
  uint64_t cost_ns = sw.GetNs();
  EXPECT_GE(cost_ns, 1000) << "cost ns: " << cost_ns << std::endl;
}
