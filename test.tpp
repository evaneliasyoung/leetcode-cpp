/**
 *  @file      test.tpp
 *  @brief     Functions for testing.
 *
 *  @author    Evan Elias Young
 *  @date      2021-12-23
 *  @date      2022-01-10
 *  @copyright Copyright 2021 Evan Elias Young. All rights reserved.
 */

#pragma once

template<typename Input, typename Output>
void run_tests(const tests_t<Input, Output> &tests, const string &method, const function<bool(Input, Output)> &func)
{
  cout << "Solution::" << method << '\n';
  bool pass_all = true;
  for (const auto &test: tests)
  {
    const bool pass = func(get<0>(test), get<1>(test));
    pass_all = pass_all && pass;
    cout << (pass ? "Passed" : "Failed") << " test!" << '\n' << '\n';
  }

  cout << "Solution::" << method << " tests " << (pass_all ? "passed" : "failed") << '!' << '\n';
}
