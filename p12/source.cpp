/**
 *  @file      source.cpp
 *  @brief     Solution for 12. Integer to Roman.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

string Problem12::Solution::intToRoman(int num)
{
  if (num < 1 || num > 3999)
  {
    return "BAD RANGE";
  }

  string ret = "";
  tuple<int, string> numerals[13] = {{1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
                                     {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
                                     {500, "D"}, {900, "CM"}, {1000, "M"}};
  int i = 12;

  while (num > 0)
  {
    const auto val = get<0>(numerals[i]);
    const auto sym = get<1>(numerals[i]);

    auto div = num / val;
    num = num % val;
    while (div--)
    {
      ret += sym;
    }
    --i;
  }

  return ret;
}
