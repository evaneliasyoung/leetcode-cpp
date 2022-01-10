/**
 *  @file      test.cpp
 *  @brief     Handles testing for 8. String to Integer (atoi).
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-28
 *  @date      2022-01-10
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

using namespace Problem8;

tests_t<input_t, output_t> Problem8::get_tests()
{
  return tests_t<input_t, output_t>{{"42", 42},
                                    {"   -42", -42},
                                    {"4193 with words", 4193},
                                    {"words and 987", 0},
                                    {"+1", 1},
                                    {"+-12", 0},
                                    {"00000-42a1234", 0},
                                    {"  +  413", 0},
                                    {"  0000000000012345678", 12345678},
                                    {"100000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                     "00000000000000000000000522545459",
                                     2147483647}};
}

bool Problem8::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  const auto res = sol.myAtoi(inp);

  cout << "Input: s = \"" << inp << "\"" << '\n' << "Output: " << res << '\n' << "Expected: " << out << '\n';

  return out == res;
}

void Problem8::test()
{
  run_tests<input_t, output_t>(get_tests(), "myAtoi", run_test);
}
