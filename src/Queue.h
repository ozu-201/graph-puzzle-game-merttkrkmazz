//
//
//

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_QUEUE_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_QUEUE_H

#include "Element.h"

class Queue {
private:
    Element *array;
    int first;
    int last;
    int N;
public:
    explicit Queue(int N);

    ~Queue();

    bool isFull() const;

    bool isEmpty() const;

    void enqueue(Element element);

    Element dequeue();
};


#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_QUEUE_H
