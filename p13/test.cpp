/**
 *  @file      test.cpp
 *  @brief     Handles testing for 13. Roman to Integer.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

using namespace Problem13;

tests_t<input_t, output_t> Problem13::get_tests()
{
  return tests_t<input_t, output_t>{{"III", 3}, {"LVIII", 58}, {"MCMXCIV", 1994}};
}

bool Problem13::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  const auto res = sol.romanToInt(inp);

  cout << "Input: s = \"" << inp << '"' << '\n' << "Output: " << res << '\n' << "Expected: " << out << '\n';

  return out == res;
}

void Problem13::test()
{
  run_tests<input_t, output_t>(get_tests(), "romanToInt", run_test);
}
