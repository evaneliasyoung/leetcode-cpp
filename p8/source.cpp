/**
 *  @file      source.cpp
 *  @brief     Solution for 8. String to Integer (atoi).
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-28
 *  @date      2022-01-10
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "ns.h"

int Problem8::Solution::myAtoi(string s)
{
  size_t ret = 0;

  const auto clamp = [](const bool &negative) -> size_t
  {
    return negative ? 2147483648 : 2147483647;
  };

  const auto negative_and_range = [](const string &s) -> tuple<bool, tuple<size_t, size_t>>
  {
    size_t start = s.npos;
    size_t end = s.npos;
    optional<bool> negative = nullopt;
    for (size_t i = 0; i < s.size(); ++i)
    {
      const auto c = s[i];
      if ((c == '-' || c == '+') && start == s.npos)
      { // found sign character and no digits
        if (negative.has_value())
        { // already set negative flag, error oout
          break;
        }
        else
        { // set negative flag
          negative = c == '-';
        }
      }
      else if (c >= '0' && c <= '9')
      {
        if (!negative.has_value())
        { // default negative to positive
          negative = false;
        }
        if (start == s.npos)
        { // found starting index
          start = i;
        }
      }
      else if (start != s.npos)
      { // found ending index
        end = i;
        break;
      }
      else if (c == ' ')
      {
        if (negative.has_value() || start != s.npos)
        { // have found either sign or digits, stop processing
          break;
        }
        else
        { // considered leading spaces
          continue;
        }
      }
      else
      { // invalid character
        break;
      }
    }
    return {negative.value_or(false), {start, end == s.npos ? s.size() : end}};
  }(s);

  const auto pow10 = [](size_t x) -> size_t
  {
    size_t ret = 1;
    for (size_t i = 0; i < x; ++i)
    {
      ret *= 10;
    }
    return ret;
  };

  const auto negative = get<0>(negative_and_range);
  const auto range = get<1>(negative_and_range);
  const auto start = get<0>(range);
  const auto end = get<1>(range);
  cout << start << " - " << end << '\n';
  if (start != s.npos && end != s.npos)
  {
    for (size_t i = start; i < end; i++)
    {
      if (s[i] != '0')
      {
        if (end - 1 - i > 30)
        {
          ret = clamp(negative);
          break;
        }
        ret += (s[i] - '0') * pow10(end - 1 - i);
      }

      if (ret > 2147483647)
      {
        ret = clamp(negative);
        break;
      }
    }
  }

  return negative ? ret * -1 : ret;
}
