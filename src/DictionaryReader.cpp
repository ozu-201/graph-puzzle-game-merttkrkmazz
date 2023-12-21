
#include "DictionaryReader.h"
#include "Graph.h"
#include "fstream"
#include <string>
#include "iostream"

DictionaryReader :: DictionaryReader(const std::string filename) : dictionaryFileName(filename){

}

int DictionaryReader :: countLetters(const std::string& word) {
    int count = 0;
    for (char letter : word) {
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            count++;
        }
        else if (letter >= -128 && letter <= -97){
            count++;
        }
    }
    return count;
}

void DictionaryReader :: readDictionary(const std:: string& start,const std:: string& end) {
    std::ifstream file(dictionaryFileName);
    if (file.is_open()) {
        std::string word;
        int letter3count = 0, letter4count = 0, letter5count = 0;
        while (file >> word) {
            if (countLetters(word) == 3) {
                letter3count++;
                g3WordList.push_back(word);
            }
            if (countLetters(word) == 4) {
                letter4count++;
                g4WordList.push_back(word);
            }
            if (countLetters(word) == 5) {
                letter5count++;
                g5WordList.push_back(word);
            }
        }
        file.close();
        Graph g3(letter3count);
        Graph g4(letter4count);
        Graph g5(letter5count);
        for (const std::string& word3 : g3WordList) {
            g3.addWord(word3);
        }
        for (const std::string& word4 : g4WordList) {
            g4.addWord(word4);
        }
        for (const std::string& word5 : g5WordList) {
            g5.addWord(word5);
        }
    } else {
        std::cout << "Failed to open file!" << std::endl;
    }
}
