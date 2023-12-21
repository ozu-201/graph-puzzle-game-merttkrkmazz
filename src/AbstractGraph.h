//
//
//

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_ABSTRACTGRAPH_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_ABSTRACTGRAPH_H

#include "Path.h"

class AbstractGraph {
protected:
    int vertexCount;
public:
    explicit AbstractGraph(int vertexCount);
    Path*  initializePaths(int source) const;

};



#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_ABSTRACTGRAPH_H
