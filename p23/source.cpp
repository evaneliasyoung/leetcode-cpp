/**
 *  @file      source.cpp
 *  @brief     Solution for 23. Merge k Sorted Lists.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

Problem23::ListNode *Problem23::Solution::mergeKLists(vector<Problem23::ListNode *> &lists)
{
  const auto get_min_idx = [&lists]() -> int
  {
    int min = 2147483647;
    size_t idx = -1;
    for (size_t i = 0; i < lists.size(); ++i)
    {
      if (lists[i] != nullptr && lists[i]->val < min)
      {
        min = lists[i]->val;
        idx = i;
        cout << "found min = " << min << " @ " << idx;
      };
    }
    return idx;
  };
  const auto all_null = [&lists]() -> bool
  {
    for (const ListNode *list: lists)
    {
      if (list != nullptr)
      {
        return false;
      }
    }
    return true;
  };

  if (all_null())
  {
    return nullptr;
  }
  ListNode *merge = new ListNode();

  while (!all_null())
  {
    const size_t idx = get_min_idx();
    ListNode *iter = merge;
    while (iter->next != nullptr)
    {
      iter = iter->next;
    }
    iter->val = lists[idx]->val;
    lists[idx] = lists[idx]->next;

    if (!all_null())
    {
      ListNode *next = new ListNode();
      iter->next = next;
    }
  }

  return merge;
}
