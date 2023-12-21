//
//
//

#ifndef GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_PATH_H
#define GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_PATH_H

class Path {
private:
    int distance;
    int previous;
public:
    Path(int distance, int previous);
    Path() = default;
    int getDistance() const;
    int getPrevious() const;
    void setDistance(int _distance);
    void setPrevious(int _previous);
};


#endif //GRAPH_PUZZLE_GAME_MERTTKRKMAZZ_PATH_H
