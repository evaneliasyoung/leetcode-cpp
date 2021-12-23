/**
 *  @file      p1.h
 *  @brief     Mockup header for 1. Two Sum.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <tuple>
#include <vector>

using namespace std;

namespace Problem1
{
  using input_t = tuple<vector<int>, int>;
  using output_t = vector<int>;

  class Solution
  {
    public:
    output_t twoSum(vector<int> &nums, int target);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem1
