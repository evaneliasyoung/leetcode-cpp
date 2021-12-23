/**
 *  @file      test.h
 *  @brief     Headers for tests.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

template<typename Input = int, typename Output = int> using test_t = tuple<Input, Output>;

template<typename Input = int, typename Output = int> using tests_t = vector<test_t<Input, Output>>;

template<typename Input = int, typename Output = int>
void run_tests(const tests_t<Input, Output> &tests, const string &method, const function<bool(Input, Output)> &func);

#include "test.tpp"
