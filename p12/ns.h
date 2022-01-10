/**
 *  @file      ns.h
 *  @brief     Mockup header for 12. Integer to Roman.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

using namespace std;

namespace Problem12
{
  using input_t = int;
  using output_t = string;

  class Solution
  {
    public:
    output_t intToRoman(int num);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem12
