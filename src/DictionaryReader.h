//
//
//

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H

#include <string>
#include "Graph.h"
#include <vector>

class DictionaryReader {
public:
    DictionaryReader(const std::string filename);
    void readDictionary(const std:: string& start,const std:: string& end);
    int countLetters(const std::string& word);

private:
    std::string dictionaryFileName;
    std::vector<std::string> g3WordList;
    std::vector<std::string> g4WordList;
    std::vector<std::string> g5WordList;

};

#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_DICTIONARYREADER_H
