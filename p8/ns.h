/**
 *  @file      ns.h
 *  @brief     Mockup header for 8. String to Integer (atoi).
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-28
 *  @date      2021-12-28
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <functional>
#include <tuple>

using namespace std;

namespace Problem8
{
  using input_t = string;
  using output_t = int;

  class Solution
  {
    public:
    output_t myAtoi(string s);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem8
