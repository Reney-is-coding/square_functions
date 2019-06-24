#include <vector>
#include <fstream>
#include <iostream>

#ifndef SQUARE_HPP
#define SQUARE_HPP

class square {
private:
    std::vector<std::vector<char>> intern_square;

public:
    square(unsigned int size = 3);
    ~square() {};
    void display();
    void draw_line();
    void draw_center_square();
    void draw_middlepoint();
    void draw_sponge(int size, int level, int x, int y);
    void draw_square(int origin_x, int origin_y, int size);
};
#endif
