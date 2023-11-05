#include "headers/Chessboard.h"

#include "SFML/Graphics.hpp"
#include "./headers/Chessboard.h"
#include "vector"

void Chessboard::initialize(sf::RenderWindow& window) {
    float cell_size = 100.0;

    sf::RectangleShape white_cell;
    sf::RectangleShape black_cell;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                white_cell.setSize(sf::Vector2f(cell_size, cell_size));
                white_cell.setPosition(i * cell_size, j * cell_size);
                white_cell.setFillColor(sf::Color(237, 214, 176));
                window.draw(white_cell);
            } else {
                black_cell.setSize(sf::Vector2f(cell_size, cell_size));
                black_cell.setPosition(i * cell_size, j * cell_size);
                black_cell.setFillColor(sf::Color(184, 135, 98));
                window.draw(black_cell);
            }
        }
    }
}
