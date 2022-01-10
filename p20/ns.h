/**
 *  @file      ns.h
 *  @brief     Mockup header for 20. Valid Parentheses.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <stack>

using namespace std;

namespace Problem20
{
  using input_t = string;
  using output_t = bool;

  class Solution
  {
    public:
    output_t isValid(string s);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem20
