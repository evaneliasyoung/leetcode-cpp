"""
@file      prep.py
@brief     Prepares a new problem.

@author    Evan Elias Young
@date      2021-12-23
@date      2021-12-27
@copyright Copyright 2021 Evan Elias Young. All rights reserved.
"""

from enum import IntEnum
import re
from typing import List, Optional
from dataclasses import dataclass
import bs4
import os
from datetime import datetime as dt
from bs4.element import Tag
from colorama import Fore
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from msedge.selenium_tools import Edge, EdgeOptions

OPTIONS = EdgeOptions()
OPTIONS.use_chromium = True
OPTIONS.add_argument("headless")
OPTIONS.add_argument("--log-level=3")
DRIVER = Edge(options=OPTIONS)
LEETCODE = "https://leetcode.com/problems"
YEAR: str = dt.now().strftime("%Y")
NOW: str = YEAR + dt.now().strftime("-%m-%d")


class Difficulty(IntEnum):
    EASY = 0
    MEDIUM = 1
    HARD = 2


@dataclass
class Votes:
    up: int
    down: int


@dataclass
class Problem:
    number: int
    name: str
    difficulty: Difficulty
    votes: Votes


def log(msg: str):
    def decorator(fn):
        def wrapper(*args, **kwargs):
            print(msg)
            return fn(*args, **kwargs)

        return wrapper

    return decorator


@log(Fore.MAGENTA + "selenium> connecting to page..." + Fore.RESET)
def nav_to_page(codename: str) -> None:
    DRIVER.get(f"{LEETCODE}/{codename}")


@log(Fore.MAGENTA + "selenium> loading contents and data..." + Fore.RESET)
def wait_for_data() -> None:
    WebDriverWait(DRIVER, 20).until(
        EC.invisibility_of_element_located((By.ID, "initial-loading"))
    )


@log(Fore.GREEN + "soup> parsing HTML..." + Fore.RESET)
def parse_html(markup: str) -> bs4.BeautifulSoup:
    return bs4.BeautifulSoup(markup, "html.parser")


@log(Fore.GREEN + "soup> dissecting contents..." + Fore.RESET)
def dissect_contents(soup: bs4.BeautifulSoup) -> Problem:
    ret = Problem(0, "", Difficulty.EASY, Votes(0, 0))

    el = soup.select_one('[data-cy="question-title"]')
    if el is not None:
        mt = re.match("(\d+)\. (.+)", el.text)
        if mt is not None:
            number, name = mt.groups()
            ret.number = int(number)
            ret.name = name

    el = soup.select_one(".css-10o4wqw")
    if el is not None:
        subel = el.select("button")
        if subel is not None:
            ret.votes.up = int(subel[0].text)
            ret.votes.down = int(subel[1].text)

    el = soup.select_one("div[diff]")
    if el is not None:
        rating: str = el.attrs.get("diff")
        if rating == "hard":
            ret.difficulty = Difficulty.HARD
        elif rating == "medium":
            ret.difficulty = Difficulty.MEDIUM
        else:
            ret.difficulty = Difficulty.EASY

    return ret


@log(Fore.CYAN + "main> deriving codename from url..." + Fore.RESET)
def derive_codename(url: str) -> Optional[str]:
    mt = re.match("(?:https?://)?leetcode.com/problems/([A-z0-9-]+)/?", url)
    if mt is not None:
        return mt.groups()[0]


def nav_and_wait(codename: str) -> str:
    nav_to_page(codename)
    wait_for_data()
    return DRIVER.page_source


def parse_and_dissect(markup: str) -> Problem:
    soup = parse_html(markup)
    return dissect_contents(soup)


@log(Fore.CYAN + "main> fetching problem..." + Fore.RESET)
def download(codename: str) -> Optional[Problem]:
    try:
        return parse_and_dissect(nav_and_wait(codename))
    except Exception as e:
        print(Fore.RED + f"Error! {e}" + Fore.RESET)
        DRIVER.quit()


@log(Fore.YELLOW + "builder> creating readme..." + Fore.RESET)
def make_readme(prob: Problem) -> None:
    with open(f"p{prob.number}/README.md", "w") as f:
        f.write(f"# {prob.number}. {prob.name}\n")


@log(Fore.YELLOW + "builder> creating namespace..." + Fore.RESET)
def make_namespace(prob: Problem) -> None:
    with open(f"p{prob.number}/ns.h", "w") as f:
        f.writelines(
            [
                "/**\n",
                " *  @file      ns.h\n",
                f" *  @brief     Mockup header for {prob.number}. {prob.name}.\n",
                " *\n",
                " *  @author    Evan Elias Young\n",
                f" *  @date      {NOW}\n",
                f" *  @date      {NOW}\n",
                f" *  @copyright Copyright {YEAR} Evan Elias Young. All rights reserved.\n",
                " */\n",
                "\n",
                "#pragma once\n",
                "\n",
                '#include "../stream.h"\n',
                '#include "../test.h"\n',
                "\n",
                "using namespace std;\n",
                "\n",
                f"namespace Problem{prob.number}\n",
                "{\n",
                "  using input_t = tuple<vector<int>, int>;\n",
                "  using output_t = vector<int>;\n",
                "\n",
                "  class Solution\n",
                "  {\n",
                "    public:\n",
                "    output_t twoSum(vector<int> &nums, int target);\n",
                "  };\n",
                "\n",
                "  tests_t<input_t, output_t> get_tests();\n",
                "  bool run_test(const input_t &inp, const output_t &out);\n",
                "  void test();\n",
                f"}} // namespace Problem{prob.number}\n",
            ]
        )


@log(Fore.YELLOW + "builder> creating test..." + Fore.RESET)
def make_test(prob: Problem) -> None:
    with open(f"p{prob.number}/test.cpp", "w") as f:
        f.writelines(
            [
                "/**\n",
                " *  @file      test.cpp\n",
                f" *  @brief     Handles testing for {prob.number}. {prob.name}.\n",
                " *\n",
                " *  @author    Evan Elias Young\n",
                f" *  @date      {NOW}\n",
                f" *  @date      {NOW}\n",
                f" *  @copyright Copyright {YEAR} Evan Elias Young. All rights reserved.\n",
                " */\n",
                "\n",
                '#include "ns.h"\n',
                "\n",
                f"using namespace Problem{prob.number};\n",
                "\n",
                f"tests_t<input_t, output_t> Problem{prob.number}::get_tests()\n",
                "{\n",
                "  return tests_t<input_t, output_t>{};\n",
                "}\n",
                "\n",
                f"bool Problem{prob.number}::run_test(const input_t &inp, const output_t &out)\n",
                "{\n",
                "  Solution sol{};\n",
                "\n",
                "  return false;\n",
                "}\n",
                "\n",
                f"void Problem{prob.number}::test()\n",
                "{\n",
                '  run_tests<input_t, output_t>(get_tests(), "twoSum", run_test);\n',
                "}\n",
            ]
        )


@log(Fore.YELLOW + "builder> creating source..." + Fore.RESET)
def make_source(prob: Problem) -> None:
    with open(f"p{prob.number}/source.cpp", "w") as f:
        f.writelines(
            [
                "/**\n",
                " *  @file      source.cpp\n",
                f" *  @brief     Solution for {prob.number}. {prob.name}.\n",
                " *\n",
                " *  @author    Evan Elias Young\n",
                f" *  @date      {NOW}\n",
                f" *  @date      {NOW}\n",
                f" *  @copyright Copyright {YEAR} Evan Elias Young. All rights reserved.\n",
                " */\n",
                "\n",
                '#include "ns.h"\n',
            ]
        )


if __name__ == "__main__":
    # url: str = input('Problem URL: ')
    url: str = "https://leetcode.com/problems/median-of-two-sorted-arrays/"
    codename: Optional[str] = derive_codename(url)
    if codename is not None:
        prob = download(codename)
        DRIVER.quit()
        if prob is not None:
            os.mkdir(f"p{prob.number}")
            for fn in [make_readme, make_namespace, make_test, make_source]:
                fn(prob)
