#ifndef LINDEBUGGER_SRC_MAIN_DEBUGGER_H_
#define LINDEBUGGER_SRC_MAIN_DEBUGGER_H_

class Debugger {
public:
  Debugger(const std::string programName, const pid_t pid);

  void Run();

  void HandleCommand(const std::string& line);

  void ContinueExecution();

private:
  std::string programName;
  pid_t pid;
};

#endif // LINDEBUGGER_SRC_MAIN_DEBUGGER_H_