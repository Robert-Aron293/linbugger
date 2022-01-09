
#include <iostream>

extern "C" {
  #include <unistd.h>
  #include <sys/ptrace.h>
}

#include "constants.h"
#include "debugger.h"

int main(int argc, char **argv)
{
  if (argc < Constants::NO_OF_ARGS) {
    std::cerr << "Program name not specified\n";
    return -1;
  }

  std::string programName = std::string(argv[1]);

  auto pid = fork();
  if (pid == 0) {
    ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
    execl(programName.c_str(), programName.c_str(), nullptr);
  } else if (pid >= 1) {
    std::cout << "Started debugging process " << pid << "\n";
    Debugger dbg{programName, pid};
    dbg.Run();
  }

  return 0;
}