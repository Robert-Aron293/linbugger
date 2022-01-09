#ifndef LINDEBUGGER_SRC_MAIN_STRING_UTIL_H_
#define LINDEBUGGER_SRC_MAIN_STRING_UTIL_H_

#include <vector>

namespace StringUtil {
  std::vector<std::string> Split(const std::string& s, const char delimiter);

  bool IsPrefix(const std::string& s, const std::string& of);
}

#endif // LINDEBUGGER_SRC_MAIN_STRING_UTIL_H_