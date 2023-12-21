#include <iostream>
#include "DictionaryReader.h"
#include <string>


int main() {
    std::cout << "Hello World" << std::endl;
    std::string fileName = "/Users/mk034587/turkishDict.txt";
    DictionaryReader reader(fileName);
    std::string start = "masa";
    std::string finish = "masal";
    reader.readDictionary(start,finish);


    return 0;
}