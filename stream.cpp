/**
 *  @file      stream.cpp
 *  @brief     Streaming extensions.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#include "stream.h"

ostream &operator<<(ostream &os, const vector<int> &v)
{
  os << '[';
  for (auto it = v.cbegin(); it != v.cend(); ++it)
  {
    os << *it;
    if (next(it) != v.cend())
      os << ',';
  }
  os << ']';
  return os;
}
