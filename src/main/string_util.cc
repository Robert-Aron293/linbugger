
#include <vector>
#include <string>
#include <sstream>

#include "string_util.h"

using std::vector;
using std::string;
using std::stringstream;

namespace StringUtil
{
  vector<string> Split(const string& s, const char delimiter)
  {
    vector<string> out{};
    stringstream ss {s};
    string item;

    while (std::getline(ss, item, delimiter)) {
      out.push_back(item);
    }

    return out;
  }

  bool IsPrefix(const string& s, const string& of)
  {
    if (s.size() > of.size()) return false;
    return std::equal(s.begin(), s.end(), of.begin());
  }
} // namespace StringUtil

