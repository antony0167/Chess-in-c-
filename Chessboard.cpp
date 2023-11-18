#include <SFML/Graphics.hpp>
#include "headers/Chessboard.h"
#include <vector>
#include <iostream>


Chessboard::Chessboard(float tileSize) : tileSize(tileSize) {
    initialize();
}

void Chessboard::initialize() {
    chessboard.resize(8, std::vector<sf::RectangleShape>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessboard[j][i].setSize(sf::Vector2f(tileSize, tileSize));
            chessboard[j][i].setPosition(i * tileSize, j * tileSize);
            if ((i + j) % 2 == 0) {
                chessboard[j][i].setFillColor(sf::Color(233, 237, 204));
            } else {
                chessboard[j][i].setFillColor(sf::Color(119, 153, 84));
            }
        }
    }
}

std::vector<int> Chessboard::select(int mouseX, int mouseY) {
    std::vector<int> index;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessboard[j][i].getGlobalBounds().contains(static_cast<float>(mouseX), static_cast<float>(mouseY))) {
                index = {j, i};
                std::cout << index[0] << index[1];
            }
        }
    }
    return index;
}

void Chessboard::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(chessboard[j][i]);
        }
    }
    displayPieces(window);
}

void Chessboard::displayPieces(sf::RenderWindow& window) {
    sf::CircleShape whitePiece(tileSize / 2);
    whitePiece.setFillColor(sf::Color::White);

    sf::RectangleShape blackPiece(sf::Vector2f(tileSize, tileSize));
    blackPiece.setFillColor(sf::Color::Black);

    float textureSize = 60.0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieces[j][i] == 1) {
                sf::Texture blackPawnTxt;
                blackPawnTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bp.png");
                sf::RectangleShape blackPawn(sf::Vector2f(textureSize, textureSize));
                blackPawn.setTexture(&blackPawnTxt);
                blackPawn.setPosition(i * tileSize, j * tileSize);
                blackPawn.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackPawn);
            } else if (pieces[j][i] == 2) {
                sf::Texture blackRookTxt;
                blackRookTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/br.png");
                sf::RectangleShape blackRook(sf::Vector2f(textureSize, textureSize));
                blackRook.setTexture(&blackRookTxt);
                blackRook.setPosition(i * tileSize, j * tileSize);
                blackRook.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackRook);
            } else if (pieces[j][i] == 3) {
                sf::Texture blackKnightTxt;
                blackKnightTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bh.png");
                sf::RectangleShape blackKnight(sf::Vector2f(textureSize, textureSize));
                blackKnight.setTexture(&blackKnightTxt);
                blackKnight.setPosition(i * tileSize, j * tileSize);
                blackKnight.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackKnight);
            } else if (pieces[j][i] == 4) {
                sf::Texture blackBishopTxt;
                blackBishopTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bb.png");
                sf::RectangleShape blackBishop(sf::Vector2f(textureSize, textureSize));
                blackBishop.setTexture(&blackBishopTxt);
                blackBishop.setPosition(i * tileSize, j * tileSize);
                blackBishop.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackBishop);
            } else if (pieces[j][i] == 5) {
                sf::Texture blackQueenTxt;
                blackQueenTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bq.png");
                sf::RectangleShape blackQueen(sf::Vector2f(textureSize, textureSize));
                blackQueen.setTexture(&blackQueenTxt);
                blackQueen.setPosition(i * tileSize, j * tileSize);
                blackQueen.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackQueen);
            } else if (pieces[j][i] == 6) {
                sf::Texture blackKingTxt;
                blackKingTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bk.png");
                sf::RectangleShape blackKing(sf::Vector2f(textureSize, textureSize));
                blackKing.setTexture(&blackKingTxt);
                blackKing.setPosition(i * tileSize, j * tileSize);
                blackKing.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(blackKing);
            } else if (pieces[j][i] == -1) {
                sf::Texture whitePawnTxt;
                whitePawnTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wp.png");
                sf::RectangleShape whitePawn(sf::Vector2f(textureSize, textureSize));
                whitePawn.setTexture(&whitePawnTxt);
                whitePawn.setPosition(i * tileSize, j * tileSize);
                whitePawn.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whitePawn);
            } else if (pieces[j][i] == -2) {
                sf::Texture whiteRookTxt;
                whiteRookTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wr.png");
                sf::RectangleShape whiteRook(sf::Vector2f(textureSize, textureSize));
                whiteRook.setTexture(&whiteRookTxt);
                whiteRook.setPosition(i * tileSize, j * tileSize);
                whiteRook.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whiteRook);
            } else if (pieces[j][i] == -3) {
                sf::Texture whiteKnightTxt;
                whiteKnightTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wh.png");
                sf::RectangleShape whiteKnight(sf::Vector2f(textureSize, textureSize));
                whiteKnight.setTexture(&whiteKnightTxt);
                whiteKnight.setPosition(i * tileSize, j * tileSize);
                whiteKnight.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whiteKnight);
            } else if (pieces[j][i] == -4) {
                sf::Texture whiteBishopTxt;
                whiteBishopTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wb.png");
                sf::RectangleShape whiteBishop(sf::Vector2f(textureSize, textureSize));
                whiteBishop.setTexture(&whiteBishopTxt);
                whiteBishop.setPosition(i * tileSize, j * tileSize);
                whiteBishop.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whiteBishop);
            } else if (pieces[j][i] == -5) {
                sf::Texture whiteQueenTxt;
                whiteQueenTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wq.png");
                sf::RectangleShape whiteQueen(sf::Vector2f(textureSize, textureSize));
                whiteQueen.setTexture(&whiteQueenTxt);
                whiteQueen.setPosition(i * tileSize, j * tileSize);
                whiteQueen.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whiteQueen);
            } else if (pieces[j][i] == -6) {
                sf::Texture whiteKingTxt;
                whiteKingTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wk.png");
                sf::RectangleShape whiteKing(sf::Vector2f(textureSize, textureSize));
                whiteKing.setTexture(&whiteKingTxt);
                whiteKing.setPosition(i * tileSize, j * tileSize);
                whiteKing.scale(tileSize / textureSize, tileSize / textureSize);
                window.draw(whiteKing);
            }
        }
    }
}
