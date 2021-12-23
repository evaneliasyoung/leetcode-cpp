/**
 *  @file      test.tpp
 *  @brief     Functions for testing.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2021-12-23
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

template<typename Input, typename Output>
void run_tests(const tests_t<Input, Output> &tests, const string &method, const function<bool(Input, Output)> &func)
{
  cout << "Solution::" << method << '\n';
  for (const auto &test: tests)
    if (func(get<0>(test), get<1>(test)))
      cout << "Passed test!" << '\n' << '\n';
    else
      cout << "Failed test..." << '\n' << '\n';
}
