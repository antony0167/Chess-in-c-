#include <SFML/Graphics.hpp>
#include "./headers/Chessboard.h"
#include "iostream"

const int cell_size = 100;

sf::Vector2i selectCell(sf::RenderWindow& window) {
    sf::Vector2i selectedCell(-1, -1);

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            // Getting the mouse position
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // Calculating the cell coordinates
            int cellX = mousePosition.x / cell_size;
            int cellY = mousePosition.y / cell_size;
            std::cout << cellX << cellY << std::endl;
            if (cellX >= 0 && cellX < 8 && cellY >= 0 && cellY < 8) {
                selectedCell.x = cellX;
                selectedCell.y = cellY;
            }
        }
    }

    return selectedCell;
}

int main()
{
    sf:: RenderWindow window(sf::VideoMode(800, 800), "My window", sf::Style::Close | sf::Style::Resize);

    while (window.isOpen())
    {
        sf::Vector2i selectedCell = selectCell(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::Key::Escape) {
                window.close();
            }
        }
        /*
        sf::RectangleShape white_cell;
        sf::RectangleShape black_cell;
        sf::RectangleShape green_cell;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0 && (selectedCell.x != i || selectedCell.y != j)) {
                    white_cell.setSize(sf::Vector2f(cell_size, cell_size));
                    white_cell.setPosition(i * cell_size, j * cell_size);
                    white_cell.setFillColor(sf::Color(237, 214, 176));
                    window.draw(white_cell);
                } else if((i + j) % 2 == 1 && (selectedCell.x != i || selectedCell.y != j)) {
                    black_cell.setSize(sf::Vector2f(cell_size, cell_size));
                    black_cell.setPosition(i * cell_size, j * cell_size);
                    black_cell.setFillColor(sf::Color(184, 135, 98));
                    window.draw(black_cell);
                } else {
                    green_cell.setSize(sf::Vector2f(cell_size, cell_size));
                    green_cell.setPosition(i * cell_size, j * cell_size);
                    green_cell.setFillColor(sf::Color(0, 255, 0));
                    window.draw(green_cell);
                }
            }
        }
        */

        window.clear(sf::Color::Black);
        Chessboard::initialize(window);
        window.display();
    }

    return 0;
}
