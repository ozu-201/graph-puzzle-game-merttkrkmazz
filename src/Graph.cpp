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

int Graph::getIndex(const std::string &word) {
    auto it = std::find(words.begin(), words.end(), word);
    if (it != words.end()) {
        return std::distance(words.begin(), it);
    }
    return -1;
}

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