#ifndef STOP_WATCH_H_
#define STOP_WATCH_H_

#include <chrono>

class StopWatch {
 public:
  StopWatch();
  void Clear();
  void Start();
  unsigned long GetMs();
  unsigned long GetUs();
  unsigned long GetNs();

 private:
  [[nodiscard]] bool IsStarted() const;
  std::chrono::steady_clock::time_point start_;
};

#endif  // STOP_WATCH_H_
