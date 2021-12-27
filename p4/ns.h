/**
 *  @file      ns.h
 *  @brief     Mockup header for 4. Median of Two Sorted Arrays.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-27
 *  @date      2021-12-27
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

#include <algorithm>

using namespace std;

namespace Problem4
{
  using input_t = tuple<vector<int>, vector<int>>;
  using output_t = double;

  class Solution
  {
    public:
    output_t findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
  };

  tests_t<input_t, output_t> get_tests();
  bool run_test(const input_t &inp, const output_t &out);
  void test();
} // namespace Problem4
