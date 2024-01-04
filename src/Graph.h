
#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H

#include "AbstractGraph.h"
#include "Edge.h"
#include <string>
#include <vector>

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
        std::vector<std::string> words;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addWord(const std::string& word);
        std::vector<std::string> BFS(const std::string &startWord, const std::string &endWord);
        void addEdge(int from, int to);
        int getIndex(const std::string &startWord);
        void addEdge(int from, int to, int weight);
      //  Path* dijkstra(int source);
        Edge* edgeList(int& edgeCount);
        void depthFirstSearch(bool* visited, int fromNode) override;
        std::vector<std::string> Dijkstra(const std::string &startWord, const std::string &endWord);

    protected:
     //   void breadthFirstSearch(bool* visited, int startNode) override;

    };
}

#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H
