/**
 *  @file      p1.cpp
 *  @brief     Solution for 1. Two Sum.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

vector<int> Problem1::Solution::twoSum(vector<int> &nums, int target)
{
  for (int x = 0; x < nums.size() - 1; ++x)
    for (int y = x + 1; y < nums.size(); ++y)
      if (nums[x] + nums[y] == target)
        return {x, y};
  return {};
}
