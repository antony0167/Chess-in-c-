#include <SFML/Graphics.hpp>
#include "./headers/Chessboard.h"

int main()
{
    sf:: RenderWindow window(sf::VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Resize);
    Chessboard chessboard(100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    chessboard.select(mousePosition.x, mousePosition.y);
                }
            }
        }

        window.clear();

        chessboard.draw(window);

        window.display();
    }

    return 0;
}