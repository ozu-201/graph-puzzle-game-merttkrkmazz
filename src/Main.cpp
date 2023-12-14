#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readDictionary(const std::string& filename, std::vector<std::string>& englishWords, std::vector<std::string>& turkishWords) {
    std::ifstream dictionaryFile(filename);
    if (!dictionaryFile.is_open()) {
        std::cerr << "Error opening the dictionary file.\n";
        return;
    }
    std::string line;
    while (std::getline(dictionaryFile, line)) {
        // Parse the line to extract words and language information
        // You may need to implement a more sophisticated parsing logic
        size_t pos = line.find(" ");
        std::string language = line.substr(0, pos);
        std::string word = line.substr(pos + 1);

        // Store words in appropriate vectors based on language
        if (language == "ENG") {
            englishWords.push_back(word);
        } else if (language == "TUR") {
            turkishWords.push_back(word);
        }
    }
    dictionaryFile.close();

}
int main() {

    std::vector<std::string> englishWords;

    std::cout << "Hello, World!" << std::endl;

  //  readDictionary("dictionary.txt", englishWords, turkishWords);
}
