/**
 *  @file      source.cpp
 *  @brief     Solution for 4. Median of Two Sorted Arrays.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-27
 *  @date      2021-12-27
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

double Problem4::Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  vector<int> vec;
  vec.reserve(nums1.size() + nums2.size());

  vec.insert(vec.end(), nums1.cbegin(), nums1.cend());
  vec.insert(vec.end(), nums2.cbegin(), nums2.cend());
  sort(vec.begin(), vec.end());

  auto mid = vec.size() / 2;
  if (vec.size() % 2 == 0)
  {
    return (vec.at(mid--) + vec.at(mid)) / 2.0;
  }
  else
  {
    return vec.at(mid);
  }
}
