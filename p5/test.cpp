/**
 *  @file      test.cpp
 *  @brief     Handles testing for 5. Longest Palindromic Substring.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "p5.h"

using namespace Problem5;

tests_t<input_t, output_t> Problem5::get_tests()
{
  return tests_t<input_t, output_t>{
    {"babad", "bab"},
    {"cbbd", "bb"},
  };
}

bool Problem5::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  const auto res = sol.longestPalindrome(inp);

  cout << "Input: s = " << inp << '\n' << "Output: " << res << '\n' << "Expected: " << out << '\n';

  if (out == res)
    return true;

  return false;
}

void Problem5::test()
{
  run_tests<input_t, output_t>(get_tests(), "longestPalindrome", run_test);
}
