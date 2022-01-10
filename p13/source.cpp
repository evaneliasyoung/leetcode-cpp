/**
 *  @file      source.cpp
 *  @brief     Solution for 13. Roman to Integer.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

int Problem13::Solution::romanToInt(string s)
{
  int ret = 0;

  const map<string, int> sym_val = {
    {"I", 1},   {"IV", 4},  {"V", 5},    {"IX", 9},  {"X", 10},   {"XL", 40},  {"L", 50},
    {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000},
  };

  for (size_t i = 0; i < s.size(); ++i)
  {
    if (i < s.size() - 1)
    { // check compound
      const auto comp = s.substr(i, 2);
      if (sym_val.find(comp) != sym_val.end())
      {
        ret += sym_val.at(comp);
        ++i;
        continue;
      }
    }
    ret += sym_val.at(s.substr(i, 1));
  }

  return ret;
}
