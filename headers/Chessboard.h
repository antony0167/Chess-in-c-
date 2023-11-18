#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class Chessboard {
public:
    explicit Chessboard(float tileSize);
    void initialize();
    std::vector<int> select(int mouseX, int mouseY);
    void draw(sf::RenderWindow& window);
    void displayPieces(sf::RenderWindow& window);

private:
    float tileSize;
    std::vector<std::vector<sf::RectangleShape>> chessboard;
    std::vector<std::vector<int>> pieces = { {2, 3, 4, 5, 6, 4, 3, 2},
                                             {1, 1, 1, 1, 1, 1, 1, 1},
                                             {0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0},
                                             {-1,-1,-1,-1,-1,-1,-1,-1},
                                             {-2,-3,-4,-5,-6,-4,-3,-2} };
};

#endif // CHESSBOARD_H
