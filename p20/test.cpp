/**
 *  @file      test.cpp
 *  @brief     Handles testing for 20. Valid Parentheses.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

using namespace Problem20;

tests_t<input_t, output_t> Problem20::get_tests()
{
  return tests_t<input_t, output_t>{{"()", true}, {"()[]{}", true}, {"(]", false}};
}

bool Problem20::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  const auto res = sol.isValid(inp);

  cout << "Input: s = \"" << inp << '"' << '\n' << "Output: " << res << '\n' << "Expected: " << out << '\n';

  return res == out;
}

void Problem20::test()
{
  run_tests<input_t, output_t>(get_tests(), "isValid", run_test);
}
