#include <iostream>
#include "DictionaryReader.h"
#include "Graph.h"

int main() {

  std::string filename = "/User/mk034587/Dict.txt";
    DictionaryReader reader (filename);

    //My readDictionaryToGraph method is creating graphs and also giving the shortest path.
    //If it cant find your path to file it will print "a" so you can understand that you gave the wrong path to file.
    //You can use turkishDict becuase english takes too much time because of the size.

    reader.readDictionaryToGraph("kedi","masa");

  //  reader.readDictionaryToGraph("kod","dil");  You can test 3 letter if you want to test one of them comment others.
  //  reader.readDictionaryToGraph("ermek","erdem"); You can test 5 letter if you want to test one of them comment others.

    array::Graph graph3(4);
    graph3.addWord("cat");
    graph3.addWord("cot");
    graph3.addWord("cog");
    graph3.addWord("dog");
    //My addWord method is already creating an edge.

    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'cat' to 'dog' (BFS):\n";
    graph3.BFS("cat", "dog");                           //BFS
    std::cout << "Shortest Path from 'cat' to 'dog' (Dijkstra):\n";
    graph3.Dijkstra("cat", "dog");                      //Dijkstra
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (4 letter words)
    array::Graph graph4(3);
    graph4.addWord("dark");
    graph4.addWord("bark");
    graph4.addWord("barn");
    //My addWord method is already creating an edge

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'dark' to 'barn' (BFS):\n";
    graph4.BFS("dark", "barn");
    std::cout << "Shortest Path from 'dark' to 'barn' (Dijkstra):\n";
    graph4.Dijkstra("dark", "barn");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (5 letter words)
    array::Graph graph5(3);
    graph5.addWord("stone");
    graph5.addWord("store");
    graph5.addWord("score");
    //My addWord method is already creating an edge


    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'stone' to 'score' (BFS):\n";
    graph5.BFS("stone", "score");
    std::cout << "Shortest Path from 'stone' to 'score' (Dijkstra):\n";
    graph5.Dijkstra("stone", "score");
    std::cout << "------------------------------------------\n";

   // std::cout<<"Hello World";

    return 0;


}




















/*  std::string start,finish;
    //  std:: cout << "Enter starting word: " << std::endl;
    //  std::getline(std::cin,start);
    //  std:: cout << "Enter destination word: " << std::endl;
    //  std::getline(std::cin,finish);
    */
