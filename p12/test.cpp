/**
 *  @file      test.cpp
 *  @brief     Handles testing for 12. Integer to Roman.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

using namespace Problem12;

tests_t<input_t, output_t> Problem12::get_tests()
{
  return tests_t<input_t, output_t>{{3, "III"}, {58, "LVIII"}, {1994, "MCMXCIV"}};
}

bool Problem12::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  const auto res = sol.intToRoman(inp);

  cout << "Input: num = " << inp << '\n' << "Output: \"" << res << '"' << '\n' << "Expected: " << out << '\n';

  return out == res;
}

void Problem12::test()
{
  run_tests<input_t, output_t>(get_tests(), "twoSum", run_test);
}
