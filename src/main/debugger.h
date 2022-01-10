#ifndef LINDEBUGGER_SRC_MAIN_DEBUGGER_H_
#define LINDEBUGGER_SRC_MAIN_DEBUGGER_H_

#include <unordered_map>

#include "breakpoint.h"

class Debugger {
public:
  Debugger(const std::string programName, const pid_t pid);

  void Run();

  void HandleCommand(const std::string& line);

  void ContinueExecution();

  void SetBreakpointAtAddress(const std::intptr_t addr);

private:
  std::string programName;
  pid_t pid;
  std::unordered_map<std::intptr_t, Breakpoint> breakpoints;
};

#endif // LINDEBUGGER_SRC_MAIN_DEBUGGER_H_