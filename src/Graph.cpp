#include "Graph.h"
#include "Queue.h"
#include "Heap.h"
#include "MinHeap.h"
#include "iostream"
#include "Edge.h"
#include <string>
#include <vector>
#include <algorithm>


namespace array {

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount) {
        edges = new int *[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addWord(const std::string &word) {
        words.push_back(word);
        int newWordIndex = words.size() - 1;
        for (int i = 0; i < newWordIndex; i++) {
            const std::string currentWord = words[i];
            if (word.size() != currentWord.size()) {
                continue;
            }
            int diffCount = 0;
            for (int j = 0; j < word.size(); j++) {
                if (word[j] != currentWord[j]) {
                    diffCount++;
                }
            }
            if (diffCount == 1) {
                addEdge(i, newWordIndex);
                addEdge(newWordIndex, i);
            }
        }

    }

    int Graph::getIndex(const std::string &word) {
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }


 /*  void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue(Element(startNode));
        while (!queue.isEmpty()) {
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]) {
                        visited[toNode] = true;
                        queue.enqueue(Element(toNode));
                    }
                }
            }
        }
    }
    */


    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }



    std::vector<std::string> Graph::BFS(const std::string &startWord, const std::string &endWord) {
        int source = getIndex(startWord);
        int destination = getIndex(endWord);

        Queue queue = Queue(100);
        std::vector<int> distances(vertexCount, -1);
        std::vector<int> previous(vertexCount, -1);

        queue.enqueue(Element(source));
        distances[source] = 0;

        while (!queue.isEmpty()) {
            int current = queue.dequeue().getData();
            for (int neighbor = 0; neighbor < vertexCount; ++neighbor) {
                if (edges[current][neighbor] > 0 && distances[neighbor] == -1) {
                    distances[neighbor] = distances[current] + 1;
                    previous[neighbor] = current;
                    queue.enqueue(Element(neighbor));
                }
            }
        }

        std::vector<std::string> pathWords;
        int currentVertex = destination;

        while (currentVertex != -1) {
            pathWords.push_back(words[currentVertex]);
            currentVertex = previous[currentVertex];
        }

        std::reverse(pathWords.begin(), pathWords.end());

        std::cout << "The path from " << startWord << " to " << endWord << " is: " << std::endl;
        for (const std::string &word : pathWords) {
            std::cout << word << " ";
        }
        std::cout << std::endl;

        return pathWords;
    }


  std::vector<std::string> Graph::Dijkstra(const std::string &startWord, const std::string &endWord){
        int source = getIndex(startWord);
        int destination = getIndex(endWord);
        Path *shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()) {
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if(edges[fromNode][toNode] > 0) {
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()) {
                        int position = heap.search(toNode);
                        heap.update(position, newDistance);
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        std::vector<std::string> pathWords;
        int currentVertex = destination;
        while(currentVertex != source){
            pathWords.push_back(words[currentVertex]);
            currentVertex = shortestPaths[currentVertex].getPrevious();
        }
        pathWords.push_back(words[source]);
        std::reverse(pathWords.begin(),pathWords.end());
        std::cout<<"The shortest path from " << startWord << " to " << endWord << " is: " << std::endl;
        for (const std::string &word:pathWords){
            std::cout << word << " ";
        }
        std::cout << std::endl;
        delete[] shortestPaths;
        return pathWords;
    };


   /* Path *Graph::dijkstra(int source) {
        Path *shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()) {
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()) {
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }
    */
    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }

}


















