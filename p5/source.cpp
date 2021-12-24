/**
 *  @file      p5.cpp
 *  @brief     Solution for 5. Longest Palindromic Substring.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

string Problem5::Solution::longestPalindrome(string s)
{
  if (s.size() <= 1)
    return s;

  int stt = 0;
  int len = 1;

  for (int i = 0; i < s.size();)
  {
    if (s.size() - i <= len / 2) // Too far in to be longer
      break;
    int j = i;
    int k = i;
    while (k < s.size() - 1 && s[k + 1] == s[k]) // Skip duplicant characters
      ++k;
    i = k + 1;

    while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) // Expand palindrome selection
    {
      ++k;
      --j;
    }

    int new_len = k - j + 1;
    if (new_len > len)
    {
      stt = j;
      len = new_len;
    }
  }

  return s.substr(stt, len);
}
