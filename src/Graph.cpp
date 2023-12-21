#include "Graph.h"
#include "Queue.h"
#include "Heap.h"
#include "Path.h"
#include "MinHeap.h"


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>


Graph::Graph(int vertexCount) : AbstractGraph(vertexCount) {
    std::vector<std::string> words;
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

void Graph::addEdge(int from, int to) {
    edges[from][to] = 1;
    edges[to][from] = 1;
}

void Graph::addEdge(int from, int to, int weight) {
    edges[from][to] = weight;
    edges[to][from] = weight;

}

/* int Graph::getIndex(const std::string &word) {
    auto it = std::find(words.begin(), words.end(), word);
    if (it != words.end()) {
        return std::distance(words.begin(), it);
    }
    return -1;
}
 */


void Graph::addWord(const std::string &word) {
    words.push_back(word);
    int newWordIndex = words.size() - 1;

    for (int i = 0; i < newWordIndex; ++i) {
        const std::string &existingWord = words[i];
        if (existingWord.size() != word.size()) {
            continue;
        }

        int diffCount = 0;

        for (int j = 0; j < word.size(); ++j) {
            if (word[j] != existingWord[j]) {
                ++diffCount;
            }
        }

        if (diffCount == 1) {
            addEdge(i, newWordIndex);
        }
    }
}


    void Graph::breadthFirstSearch(bool *visited, int startNode) {
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

    Path *Graph::bellmanFord(int source) {
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                for (int toNode = 0; toNode < vertexCount; toNode++){
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        return shortestPaths;
    }
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
Path *Graph::dijkstra(int source) {
    Path* shortestPaths = initializePaths(source);
    MinHeap heap = MinHeap(vertexCount);
    for (int i = 0; i < vertexCount; i++){
        heap.insert( HeapNode(shortestPaths[i].getDistance(), i));
    }
    while (!heap.isEmpty()){
        HeapNode node = heap.deleteTop();
        int fromNode = node.getName();
        for (int toNode = 0; toNode < vertexCount; toNode++){
            int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
            if (newDistance < shortestPaths[toNode].getDistance()){
                int position = heap.search(toNode);
                heap.update(position, newDistance);
                shortestPaths[toNode].setDistance(newDistance);
                shortestPaths[toNode].setPrevious(fromNode);
            }
        }
    }
    return shortestPaths;
}



















    /* Path Graph::shortestPath(const std::string& start, const std::string& end) {
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);

    if (startIndex == -1 || endIndex == -1) {
        // Handle invalid words
        return Path(); // Return an empty path for simplicity
    }

    return performBFS(startIndex, endIndex);
}
 */

/* Path Graph::performBFS(int startIdx, int endIdx) {
    std::queue<int> bfsQueue;
    std::vector<bool> visited(vertexCount, false);
    std::vector<int> parent(vertexCount, -1);

    bfsQueue.push(startIdx);
    visited[startIdx] = true;

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();

        for (int neighbor = 0; neighbor < vertexCount; ++neighbor) {
            if (edges[current][neighbor] == 1 && !visited[neighbor]) {
                bfsQueue.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;

                if (neighbor == endIdx) {
                    // Found the destination, construct the path
                    Path shortestPath;
                    while (neighbor != -1) {
                        shortestPath.prepend(words[neighbor]);
                        neighbor = parent[neighbor];
                    }
                    return shortestPath;
                }
            }
        }
    }

    // If the loop completes without finding the destination, return an empty path
    return Path();
}
 */
