/**
 *  @file      test.cpp
 *  @brief     Handles testing for 1. Two Sum.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "p1.h"

using namespace Problem1;

tests_t<input_t, output_t> Problem1::get_tests()
{
  return tests_t<input_t, output_t>{{{{2, 7, 11, 15}, 9}, {0, 1}}, {{{3, 2, 4}, 6}, {1, 2}}, {{{3, 3}, 6}, {0, 1}}};
}

bool Problem1::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  auto nums = get<0>(inp);
  auto target = get<1>(inp);
  const auto res = sol.twoSum(nums, target);

  cout << "Input: nums = " << nums << ", target = " << target << '\n'
       << "Output: " << res << '\n'
       << "Expected: " << out << '\n';

  if (out == res)
    return true;

  return false;
}

void Problem1::test()
{
  run_tests<input_t, output_t>(get_tests(), "twoSum", run_test);
}
