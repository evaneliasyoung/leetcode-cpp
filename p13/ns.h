/**
 *  @file      ns.h
 *  @brief     Mockup header for 13. Roman to Integer.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <map>

using namespace std;

namespace Problem13
{
  using input_t = string;
  using output_t = int;

  class Solution
  {
    public:
    output_t romanToInt(string s);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem13
