#include "../include/square.hpp"

square::square(unsigned int size)
{
    for (size_t i = 0; intern_square.size() < size; i++) {
        std::vector<char> temp;
        char value = 'o';

        for (size_t a = 0; temp.size() < size; a++) {
            temp.push_back(value);
        }
        intern_square.push_back(temp);
    }
}

void square::display()
{
    for (size_t i = 0; i < intern_square.size(); i++) {
        for (size_t a = 0; a < intern_square[i].size(); a++) {
            std::cout << intern_square[i][a];
        }
        std::cout << std::endl;
    }
}

void square::draw_line()
{
    unsigned int middle;

    if (intern_square.size()%2 == 0)
        middle = 0;
    else
        middle = intern_square.size()/2;

    for (size_t a = 0; a < intern_square[middle].size(); a++) {
        intern_square[middle][a] = 'x';
    }
}

void square::draw_center_square()
{
    unsigned int a, b, c, d= 1;
    b = d = intern_square.size()-1;

    for (a = 1; a < b; a++) {
        std::cout << "a" << '\n';
        for (c = 1; c < d; c++) {
            intern_square[a][c] = ':';
        }
    }
}

void square::draw_middlepoint()
{
    intern_square[intern_square.size()/2][intern_square.size()/2] = 'x';
}

void square::draw_sponge(int size, int level, int x, int y)
{
    if (size < level * level * level) {
        std::cout << "size not valid in order to create sponge" << '\n';
        return;
    }
    int sub_square = size/3;

    draw_square(x+sub_square, y+sub_square, sub_square);
    // intern_square[x+sub_square][y+sub_square] = '?';

    if (level > 1) {
        draw_sponge(sub_square, level-1, x, y);
        draw_sponge(sub_square, level-1, x, y+sub_square);
        draw_sponge(sub_square, level-1, x, y+sub_square*2);

        draw_sponge(sub_square, level-1, x+sub_square*1, y);
        draw_sponge(sub_square, level-1, x+sub_square*1, y+sub_square*2);

        draw_sponge(sub_square, level-1, x+sub_square*2, y);
        draw_sponge(sub_square, level-1, x+sub_square*2, y+sub_square);
        draw_sponge(sub_square, level-1, x+sub_square*2, y+sub_square*2);
    }
}

void square::draw_square(int origin_x, int origin_y, int size)
{
    for (int y = origin_y; y < origin_y+size; y++) {
        for (int x = origin_x; x < origin_x+size; x++) {
            intern_square[x][y] = 'x';
        }
    }
}
