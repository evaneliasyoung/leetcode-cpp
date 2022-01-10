/**
 *  @file      ns.h
 *  @brief     Mockup header for 23. Merge k Sorted Lists.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#pragma once

#include "../stream.h"
#include "../test.h"

using namespace std;

namespace Problem23
{
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr)
    {
    }
    ListNode(int x): val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next): val(x), next(next)
    {
    }
  };

  using input_t = vector<ListNode *> &;
  using output_t = ListNode *;

  class Solution
  {
    public:
    output_t mergeKLists(vector<ListNode *> &lists);
  };
} // namespace Problem23
