
#include <vector>
#include <string>

#include "src/main/string_util.h"

/* external dependency */
#include "gtest/gtest.h"

using std::string;
using std::vector;

TEST(StringUtilTest, SplitStringWithValidDelimiter) {
  vector<string> expectedStrings{ "This", "is", "a", "sentence." };
  vector<string> actualStrings = StringUtil::Split(
    "This is a sentence.", ' ');

  EXPECT_EQ(expectedStrings.size(), actualStrings.size());
  for (long unsigned int i = 0; i < expectedStrings.size(); ++i) {
    EXPECT_EQ(expectedStrings[i], actualStrings[i]);
  }
}

TEST(StringUtilTest, SplitStringWithInvalidDelimiter) {
  vector<string> expectedStrings{ "This is a sentence." };
  vector<string> actualStrings = StringUtil::Split(
    "This is a sentence.", ',');

  EXPECT_EQ(expectedStrings.size(), actualStrings.size());
  for (long unsigned int i = 0; i < expectedStrings.size(); ++i) {
    EXPECT_EQ(expectedStrings[i], actualStrings[i]);
  }
}

TEST(StringUtilTest, IsPrefixSameLengthValidPrefix) {
  ASSERT_TRUE(StringUtil::IsPrefix("continue", "continue"));
}

TEST(StringUtilTest, IsPrefixValidPrefixWithPrefixLengthBigger) {
  ASSERT_FALSE(StringUtil::IsPrefix("continue", "cont"));
}

TEST(StringUtilTest, IsPrefixValidPrefixWithPrefixLengthSmaller) {
  ASSERT_TRUE(StringUtil::IsPrefix("cont", "continue"));
}

TEST(StringUtilTest, IsPrefixInvalidPrefix) {
  ASSERT_FALSE(StringUtil::IsPrefix("nop", "continue"));
}