

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H

#include "Graph.h"
#include <string>
#include <vector>
#include "fstream"

class DictionaryReader {
public:
    DictionaryReader(const std::string filename);
    void readDictionaryToGraph(const std::string startWord,const std::string endWord);
private:
    std::string dictionaryFileName;
    int countLetters(const std::string word);
    std::vector<std::string> g3WordList;
    std::vector<std::string> g4WordList;
    std::vector<std::string> g5WordList;
};


#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H
