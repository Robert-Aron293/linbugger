
#include <cstdint>

extern "C" {
  #include <unistd.h>
  #include <sys/ptrace.h>
}

#include "breakpoint.h"

using std::uintptr_t;

Breakpoint::Breakpoint() {}

Breakpoint::Breakpoint(const pid_t pid, const intptr_t addr)
  : pid{pid}, addr{addr}, enabled{false}, savedData{} {}

Breakpoint::Breakpoint(const Breakpoint& bp)
  : pid{bp.GetPid()}, addr{bp.GetAddress()},
  enabled{bp.IsEnabled()}, savedData{bp.GetSavedData()} {}

void Breakpoint::Enable()
{
  auto data = ptrace(PTRACE_PEEKDATA, pid, addr, nullptr);
  /* save bottom byte */
  savedData = static_cast<uint8_t>(data & 0xff);
  uint64_t int3InstructionCode = 0xcc;
  /* set bottom byte to 0xcc */
  uint64_t dataWithInt3 = ((data & ~0xff) | int3InstructionCode);

  ptrace(PTRACE_POKEDATA, pid, addr, dataWithInt3);

  enabled = true;
}

void Breakpoint::Disable()
{
  auto data = ptrace(PTRACE_PEEKDATA, pid, addr, nullptr);
  auto restoredData = ((data & ~0xff) | savedData);

  ptrace(PTRACE_POKEDATA, pid, addr, restoredData);
  enabled = false;
}

bool Breakpoint::IsEnabled() const {
  return enabled;
}

intptr_t Breakpoint::GetAddress() const {
  return addr;
}

pid_t Breakpoint::GetPid() const {
  return pid;
}

uint8_t Breakpoint::GetSavedData() const {
  return savedData;
}