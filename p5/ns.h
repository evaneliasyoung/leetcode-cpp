/**
 *  @file      ns.h
 *  @brief     Mockup header for 5. Longest Palindromic Substring.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <algorithm>

using namespace std;

namespace Problem5
{
  using input_t = string;
  using output_t = string;

  class Solution
  {
    public:
    output_t longestPalindrome(string s);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem5
