#include "classes/include/square.hpp"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::ifstream usage(".usage.txt", std::ios::in);
        if (usage.is_open()) {
            std::string line;
            while (std::getline(usage, line)) {
                std::cerr << line << '\n';
            }
            usage.close();
        }
        return (0);
    }
    int size = atoi(argv[1]);
    if ((size < 0 || size > 50) || size%2 == 0){
        std::cerr << "size must be comprised between 0 and 50 and be a odd number" << std::endl;
        return 84;
    }
    square carre((unsigned int)size);
    //carre.draw_line();
    // carre.draw_center_square();
    // carre.draw_middlepoint();
    carre.draw_sponge(size, 2, 0, 0);
    carre.display();
    return 0;
}
