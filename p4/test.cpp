/**
 *  @file      test.cpp
 *  @brief     Handles testing for 4. Median of Two Sorted Arrays.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-27
 *  @date      2021-12-27
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

using namespace Problem4;

tests_t<input_t, output_t> Problem4::get_tests()
{
  return tests_t<input_t, output_t>{
    {{{1, 3}, {2}}, 2},
    {{{1, 2}, {3, 4}}, 2.5},
  };
}

bool Problem4::run_test(const input_t &inp, const output_t &out)
{
  Solution sol{};

  auto nums1 = get<0>(inp);
  auto nums2 = get<1>(inp);
  const auto res = sol.findMedianSortedArrays(nums1, nums2);

  cout << "Input: nums1 = " << nums1 << ", nums2 = " << nums2 << '\n'
       << "Output: " << res << '\n'
       << "Expected: " << out << '\n';

  return false;
}

void Problem4::test()
{
  run_tests<input_t, output_t>(get_tests(), "findMedianSortedArrays", run_test);
}
