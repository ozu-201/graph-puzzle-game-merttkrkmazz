cmake_minimum_required(VERSION 3.25)
project(graph-puzzle-game-merttkrkmazz)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph-puzzle-game-merttkrkmazz main.cpp Main.cpp AbstractGraph.cpp DictionaryReader.cpp Edge.cpp
        Element.cpp

        Graph.cpp

        Graph.cpp Heap.cpp HeapNode.cpp MinHeap.cpp Path.cpp Queue.cpp)