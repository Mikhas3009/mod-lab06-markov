// Copyright 2024 Mikhas3009
#include <iostream>
#include "textgen.h"

#define NUMBER_WORDS 3
#define MAX_GENERATOR 500

int main() {
    setlocale(LC_ALL, "Rus");
    std::string path = "text.txt";
    std::map<prefix, std::vector<std::string>> statetab;
    statetab = ReadFile(NUMBER_WORDS, path);
    prefix start = { "Три девицы", "девицы" };
    std::cout << generateText(NUMBER_WORDS, MAX_GENERATOR, start, statetab);
}