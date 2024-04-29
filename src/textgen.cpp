// Copyright 2024 Mikhas3009
#include "textgen.h"

std::map<prefix, std::vector<std::string>> ReadFile(int NPREF, const std::string& path) {
    prefix pref;
    std::map<prefix, std::vector<std::string>> statetab;
    std::string word;
    std::ifstream in(path);
    if (in.is_open()) {
        while (in >> word) {
            if (pref.size() < NPREF) {
                pref.push_back(word);
            } else {
                statetab[pref].push_back(word);
                pref.push_back(word);
                pref.pop_front();
            }
        }
        in.close();
    } else {
        std::cerr << "Ошибка открытия файла" << std::endl;
    }
    return statetab;
}

std::string GenWord(std::deque<std::string>& start,
                    std::map<std::deque<std::string>, std::vector<std::string>>& statetab,
                    std::string& text) {
    std::vector<std::string> variable = statetab[start];
    int index = 0;
    if (variable.size() > 0) {
        index = std::rand() % variable.size();
        text += variable[index] + " ";
        start.pop_front();
        start.push_back(variable[index]);
    }
    return variable[index];
}

std::string GenerateText(int NPREF, int MAXGEN,
                         std::deque<std::string>& start,
                         std::map<std::deque<std::string>, std::vector<std::string>>& statetab) {
    std::string text;
    for (int i = 0; i < MAXGEN; i++) {
        GenWord(start, statetab, text);
    }
    return text;
}
