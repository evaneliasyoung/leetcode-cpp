/**
 *  @file      source.cpp
 *  @brief     Solution for 20. Valid Parentheses.
 *
 *  @author    Evan Elias Young
 *  @date      2022-01-10
 *  @date      2022-01-10
 *  @copyright Copyright 2022 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

bool Problem20::Solution::isValid(string s)
{
  stack<char> parens = {};

  for (const char &c: s)
  {
    if (c == '(' || c == '[' || c == '{')
    {
      parens.push(c);
    }
    else if (c == ')' || c == ']' || c == '}')
    {
      if (c == ')' && (parens.empty() || parens.top() != '('))
      {
        return false;
      }
      else if (c == ']' && (parens.empty() || parens.top() != '['))
      {
        return false;
      }
      else if (c == '}' && (parens.empty() || parens.top() != '{'))
      {
        return false;
      }
      else
      {
        parens.pop();
      }
    }
  }

  return parens.empty();
}
