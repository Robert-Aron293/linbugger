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
    "breakpoint.h"
  ],
  deps = [
    ":string-util",
    ":breakpoint",
    "//ext:linenoise"
  ]
)

cc_library(
  name = "string-util",
  srcs = ["string_util.cc"],
  hdrs = ["string_util.h"]
)

cc_library(
  name = "breakpoint",
  srcs = ["breakpoint.cc"],
  hdrs = ["breakpoint.h"]
)