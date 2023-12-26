#include "stop_watch.h"

using namespace std::chrono;

StopWatch::StopWatch() : start_(steady_clock::time_point::min()) {}

void StopWatch::Clear() { start_ = steady_clock::time_point::min(); }

void StopWatch::Start() { start_ = steady_clock::now(); }

unsigned long StopWatch::GetMs() {
  if (IsStarted()) {
    steady_clock::duration diff;
    diff = steady_clock::now() - start_;
    return (unsigned long)(duration_cast<milliseconds>(diff).count());
  }
  return 0;
}

unsigned long StopWatch::GetUs() {
  if (IsStarted()) {
    steady_clock::duration diff;
    diff = steady_clock::now() - start_;
    return (unsigned long)(duration_cast<microseconds>(diff).count());
  }
  return 0;
}

unsigned long StopWatch::GetNs() {
  if (IsStarted()) {
    steady_clock::duration diff;
    diff = steady_clock::now() - start_;
    return (unsigned long)(duration_cast<nanoseconds>(diff).count());
  }
  return 0;
}

bool StopWatch::IsStarted() const { return !(start_ == steady_clock::time_point::min()); }
