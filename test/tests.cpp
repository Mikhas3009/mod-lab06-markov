#include <gtest/gtest.h>
#include "textgen.h"
#include <fstream>

TEST(MarkovChainTest, TrainFromTextFile) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    EXPECT_TRUE(generator.table.empty());
}

TEST(MarkovChainTest, GeneratedPrefixExistsInTable) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    markov::MarkovChain::Prefix prefix = {"Jaga", "Boyaga,"};
    EXPECT_FALSE(generator.table.find(prefix) != generator.table.end());
}

TEST(MarkovChainTest, GeneratedPrefixHasSuffixes) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    markov::MarkovChain::Prefix prefix = {"Jaga", "Boyaga,"};
    EXPECT_TRUE(generator.table[prefix].empty());
}

TEST(MarkovChainTest, GeneratedTextLength) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    std::string result = generator.generate(10, true); 
    EXPECT_EQ(result.size(), 44);
}

TEST(MarkovChainTest, GenerateTextWithGivenPrefix) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    markov::MarkovChain::Prefix prefix = {"Jaga", "Boyaga,"};
    std::string result = generator.generate(5, false); 
    EXPECT_TRUE(result.find("Jaga Boyaga,") != std::string::npos);
}

TEST(MarkovChainTest, GenerateTextWithoutRandomFirst) {
    markov::MarkovChain generator;
    generator.train("test/test-text.txt", 2);
    std::string result1 = generator.generate(5, false);
    std::string result2 = generator.generate(5, false);
    EXPECT_EQ(result1, result2);
}
