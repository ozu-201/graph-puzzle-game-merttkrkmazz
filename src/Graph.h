//
//
//

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H

#include "AbstractGraph.h"
#include "Path.h"
#include <string>
#include <vector>
#include "Edge.h"

class Graph : public AbstractGraph {
private:
    int **edges;
    std::vector<std::string> words;

 //   Path performBFS(int startIdx, int endIdx);
public:
   // Path shortestPath(const std::string& start, const std::string& end);
    explicit Graph(int vertexCount);
    ~Graph();
    void addEdge(int from, int to);
    void addEdge(int from, int to, int weight);
    int getIndex(const std::string& word);
    void addWord(const std::string& word);

    Path* bellmanFord(int source);
    Path* dijkstra(int source);
protected:
    void depthFirstSearch(bool* visited, int fromNode);
    void breadthFirstSearch(bool* visited, int startNode);
    Edge* edgeList(int& edgeCount);
};



#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_GRAPH_H
