/**
 *  @file      stream.h
 *  @brief     Streaming extensions.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v);
