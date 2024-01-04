#include <climits>
#include "AbstractGraph.h"

AbstractGraph::AbstractGraph(int vertexCount) {
    this->vertexCount = vertexCount;
}

Path *AbstractGraph::initializePaths(int source) const {
    Path* paths = new Path[vertexCount];
    for (int i = 0; i < vertexCount; i++){
        paths[i] = Path(INT_MAX, -1);
    }
    paths[source].setDistance(0);
    return paths;
}

int AbstractGraph::connectedComponentDfs() {
    int component = 0;
    bool* visited = new bool[vertexCount];
    for (int vertex = 0; vertex < vertexCount; vertex++){
        if (!visited[vertex]){
            visited[vertex] = true;
            depthFirstSearch(visited, vertex);
            component++;
        }
    }
    delete[] visited;
    return component;
}

/* int AbstractGraph::connectedComponentBfs() {
    int component = 0;
    bool* visited = new bool[vertexCount];
    for (int vertex = 0; vertex < vertexCount; vertex++){
        if (!visited[vertex]){
            visited[vertex] = true;
            breadthFirstSearchh(visited, vertex);
            component++;
        }
    }
    delete[] visited;
    return component;
}
 */
