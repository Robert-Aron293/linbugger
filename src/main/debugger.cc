
#include <string>
#include <iostream>

extern "C" {
  #include <sys/wait.h>
  #include <sys/unistd.h>
  #include <sys/ptrace.h>

  /* external dependency */
  #include "ext/linenoise.h"
}


#include "debugger.h"
#include "constants.h"
#include "string_util.h"

Debugger::Debugger(const std::string programName, const pid_t pid) :
  programName(programName), pid(pid) {}

void Debugger::Run()
{
  int waitStatus;
  auto options = 0;
  waitpid(pid, &waitStatus, options);

  char* line = nullptr;
  while((line = linenoise("minidbg> ")) != nullptr) {
    HandleCommand(line);
    linenoiseHistoryAdd(line);
    linenoiseFree(line);
  }
}

void Debugger::HandleCommand(const std::string& line)
{
  auto args = StringUtil::Split(line, ' ');
  auto command = args[0];

  if (StringUtil::IsPrefix(command, Constants::CMD_CONTINUE)) {
    ContinueExecution();
  } else {
    std::cerr << "Unknown command " << command << std::endl;
  }
}

void Debugger::ContinueExecution()
{
  ptrace(PTRACE_CONT, pid, nullptr, nullptr);

  int waitStatus;
  auto options = 0;
  waitpid(pid, &waitStatus, options);
}