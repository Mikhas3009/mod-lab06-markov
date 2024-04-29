#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>

namespace markov {
    class MarkovChain {
    public:
        using Prefix = std::deque<std::string>;
        using Suffixes = std::vector<std::string>;
        
        std::map<Prefix, Suffixes> table;
        
        void train(const std::string& filename, int npref);
        std::string generate(int len, bool randfirst);
        
    private:
        std::mt19937 mt; // Генератор случайных чисел
        
        // Инициализация генератора случайных чисел
        void initializeRandomGenerator();
    };
}

#endif  // INCLUDE_TEXTGEN_H_
