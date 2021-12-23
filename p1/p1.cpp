/**
 *  @file      p1.cpp
 *  @brief     Solution for 1. Two Sum.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "p1.h"

vector<int> Problem1::Solution::twoSum(vector<int> &nums, int target)
{
  for (int xi = 0; xi < nums.size(); ++xi)
    for (int yi = 0; yi < nums.size(); ++yi)
      if (xi == yi)
        continue;
      else if (nums[xi] + nums[yi] == target)
        return {xi, yi};
  return {};
}
