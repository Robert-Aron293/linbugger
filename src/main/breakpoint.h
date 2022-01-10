
#ifndef LINDEBUGGER_SRC_MAIN_BREAKPOINT_H_
#define LINDEBUGGER_SRC_MAIN_BREAKPOINT_H_

#include <cstdint>

extern "C" {
  #include <unistd.h>
}

class Breakpoint {
public:
  Breakpoint(const pid_t pid, std::intptr_t addr);

  Breakpoint(const Breakpoint& bp);

  Breakpoint();

  void Enable();

  void Disable();

  bool IsEnabled() const;

  std::intptr_t GetAddress() const;

  pid_t GetPid() const;

  uint8_t GetSavedData() const;

private:
  pid_t pid;
  std::intptr_t addr;
  bool enabled;
  uint8_t savedData;
};

#endif // LINDEBUGGER_SRC_MAIN_BREAKPOINT_H_