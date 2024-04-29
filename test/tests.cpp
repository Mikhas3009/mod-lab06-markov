// Copyright 2024 Mikhas3009
#include <gtest/gtest.h>
#include "../include/textgen.h"

#define path "test/test-test.txt"

TEST(TestCaseName, TestName1) {
    // Jaga Boyaga, run away from me!
    std::map<prefix, std::vector<std::string>> statetab;
    statetab = ReadFile(2, path);
    std::map<prefix, std::vector<std::string>> exp = {
        {{"Jaga", "Boyaga,"}, {"run"}},
        {{"Boyaga,", "run"}, {"away"}},
        {{"run", "away"}, {"from"}},
        {{"away", "from"}, {"me!"}}
    };
    EXPECT_EQ(statetab, exp);
}

TEST(TestCaseName, TestName2) {
    std::map<prefix, std::vector<std::string>> statetab = {
        {{"Jaga", "Boyaga,"}, {"run"}},
        {{"Boyaga,", "run"}, {"away"}},
        {{"run", "away"}, {"from"}},
        {{"away", "from"}, {"me!"}}
    };
    std::string text = "";
    prefix start = { "Boyaga,", "run" };
    std::string chooseSuffix = genWord(start, statetab, text);
    EXPECT_EQ(chooseSuffix, "away");
}

TEST(TestCaseName, TestName9) {
    std::map<prefix, std::vector<std::string>> statetab = {
        {{"Jaga", "Boyaga,"}, {"run"}},
        {{"Boyaga,", "run"}, {"away"}},
        {{"run", "away"}, {"from"}},
        {{"away", "from"}, {"me!"}}
    };
    std::string text = "";
    prefix start = { "Jaga", "Boyaga," };
    std::string chooseSuffix = genWord(start, statetab, text);
    EXPECT_EQ(chooseSuffix, "run");
}

TEST(TestCaseName, TestName10) {
    std::map<prefix, std::vector<std::string>> statetab = {
        {{"Jaga", "Boyaga,"}, {"run"}},
        {{"Boyaga,", "run"}, {"away"}},
        {{"run", "away"}, {"from"}},
        {{"away", "from"}, {"me!"}}
    };
    std::string text = "Jaga Boyaga, run away from me! ";
    prefix start = { "run", "away" };
    EXPECT_EQ(generateText(2, 5, start, statetab), text);
}
