load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [
    ":debugger"
  ]
)

cc_library(
  name = "debugger",
  srcs = ["debugger.cc"],
  hdrs = [
    "debugger.h",
    "constants.h",
    "string_util.h",
  ],
  deps = [
    ":string-util",
    "//ext:linenoise"
  ]
)

cc_library(
  name = "string-util",
  srcs = ["string_util.cc"],
  hdrs = ["string_util.h"]
)