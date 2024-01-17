#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

enum Piece { EMPTY, W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING, B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING };

std::vector<std::vector<int>> pieces = { {10, 8, 9, 11, 12, 9, 8, 10},
                                         {7, 7, 7, 7, 7, 7, 7, 7},
                                         {0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1, 1, 1, 1},
                                         {4, 2, 3, 5, 6, 3, 2, 4} };

float tileSize = 100.0;

bool w_king_moved = false;
bool b_king_moved = false;

int last_src_x = -1;
int last_src_y = -1;
int last_dest_x = -1;
int last_dest_y = -1;

void initialize(std::vector<std::vector<sf::RectangleShape>>& chessboard) {
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

std::vector<int> select(std::vector<std::vector<sf::RectangleShape>>& chessboard, int mouseX, int mouseY) {
    std::vector<int> index;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessboard[j][i].getGlobalBounds().contains(static_cast<float>(mouseX), static_cast<float>(mouseY))) {
                index = {j, i};
                std::cout << index[0] << index[1] << std::endl;
            }
        }
    }
    return index;
}

void displayPieces(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieces[j][i] == 7) {
                sf::Texture blackPawnTxt;
                blackPawnTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bp.png");
                sf::RectangleShape blackPawn(sf::Vector2f(tileSize, tileSize));
                blackPawn.setTexture(&blackPawnTxt);
                blackPawn.setPosition(i * tileSize, j * tileSize);
                blackPawn.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackPawn);
            } else if (pieces[j][i] == 10) {
                sf::Texture blackRookTxt;
                blackRookTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/br.png");
                sf::RectangleShape blackRook(sf::Vector2f(tileSize, tileSize));
                blackRook.setTexture(&blackRookTxt);
                blackRook.setPosition(i * tileSize, j * tileSize);
                blackRook.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackRook);
            } else if (pieces[j][i] == 8) {
                sf::Texture blackKnightTxt;
                blackKnightTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bh.png");
                sf::RectangleShape blackKnight(sf::Vector2f(tileSize, tileSize));
                blackKnight.setTexture(&blackKnightTxt);
                blackKnight.setPosition(i * tileSize, j * tileSize);
                blackKnight.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackKnight);
            } else if (pieces[j][i] == 9) {
                sf::Texture blackBishopTxt;
                blackBishopTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bb.png");
                sf::RectangleShape blackBishop(sf::Vector2f(tileSize, tileSize));
                blackBishop.setTexture(&blackBishopTxt);
                blackBishop.setPosition(i * tileSize, j * tileSize);
                blackBishop.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackBishop);
            } else if (pieces[j][i] == 11) {
                sf::Texture blackQueenTxt;
                blackQueenTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bq.png");
                sf::RectangleShape blackQueen(sf::Vector2f(tileSize, tileSize));
                blackQueen.setTexture(&blackQueenTxt);
                blackQueen.setPosition(i * tileSize, j * tileSize);
                blackQueen.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackQueen);
            } else if (pieces[j][i] == 12) {
                sf::Texture blackKingTxt;
                blackKingTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/bk.png");
                sf::RectangleShape blackKing(sf::Vector2f(tileSize, tileSize));
                blackKing.setTexture(&blackKingTxt);
                blackKing.setPosition(i * tileSize, j * tileSize);
                blackKing.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(blackKing);
            } else if (pieces[j][i] == 1) {
                sf::Texture whitePawnTxt;
                whitePawnTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wp.png");
                sf::RectangleShape whitePawn(sf::Vector2f(tileSize, tileSize));
                whitePawn.setTexture(&whitePawnTxt);
                whitePawn.setPosition(i * tileSize, j * tileSize);
                whitePawn.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whitePawn);
            } else if (pieces[j][i] == 4) {
                sf::Texture whiteRookTxt;
                whiteRookTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wr.png");
                sf::RectangleShape whiteRook(sf::Vector2f(tileSize, tileSize));
                whiteRook.setTexture(&whiteRookTxt);
                whiteRook.setPosition(i * tileSize, j * tileSize);
                whiteRook.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whiteRook);
            } else if (pieces[j][i] == 2) {
                sf::Texture whiteKnightTxt;
                whiteKnightTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wh.png");
                sf::RectangleShape whiteKnight(sf::Vector2f(tileSize, tileSize));
                whiteKnight.setTexture(&whiteKnightTxt);
                whiteKnight.setPosition(i * tileSize, j * tileSize);
                whiteKnight.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whiteKnight);
            } else if (pieces[j][i] == 3) {
                sf::Texture whiteBishopTxt;
                whiteBishopTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wb.png");
                sf::RectangleShape whiteBishop(sf::Vector2f(tileSize, tileSize));
                whiteBishop.setTexture(&whiteBishopTxt);
                whiteBishop.setPosition(i * tileSize, j * tileSize);
                whiteBishop.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whiteBishop);
            } else if (pieces[j][i] == 5) {
                sf::Texture whiteQueenTxt;
                whiteQueenTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wq.png");
                sf::RectangleShape whiteQueen(sf::Vector2f(tileSize, tileSize));
                whiteQueen.setTexture(&whiteQueenTxt);
                whiteQueen.setPosition(i * tileSize, j * tileSize);
                whiteQueen.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whiteQueen);
            } else if (pieces[j][i] == 6) {
                sf::Texture whiteKingTxt;
                whiteKingTxt.loadFromFile("C:/Users/dluze/CLionProjects/helloSFML/images/wk.png");
                sf::RectangleShape whiteKing(sf::Vector2f(tileSize, tileSize));
                whiteKing.setTexture(&whiteKingTxt);
                whiteKing.setPosition(i * tileSize, j * tileSize);
                whiteKing.scale(tileSize / tileSize, tileSize / tileSize);
                window.draw(whiteKing);
            }
        }
    }
}

void move_piece(std::vector<std::vector<int>>& board, int src_x, int src_y, int dest_x, int dest_y) {
    if (std::abs(src_x - 3.5) > 3.5 && std::abs(src_y - 3.5) > 3.5 && std::abs(dest_x - 3.5) > 3.5 && std::abs(dest_x - 3.5) > 3.5) return;
    if (board[src_y][src_x] == 0) return;

    int moving_piece = board[src_y][src_x];
    board[src_y][src_x] = 0;
    board[dest_y][dest_x] = moving_piece;

}

bool check_valid_castle(std::vector<std::vector<int>>& board, const std::string& type, bool w_turn) {
    if (w_turn && w_king_moved) return false;
    if (!w_turn && b_king_moved) return false;

//    std::vector<std::vector<int>> curr_board = board;

    if (type == "O-O") {
        if (w_turn) {
            if (board[7][7] == 4) {
                if (board[7][5] == 0 && board[7][6] == 0) {
                    board[7][6] = 6;
                    board[7][5] = 4;
                    board[7][4] = 0;
                    board[7][7] = 0;
                    return true;
                }
            }
        } else {
            if (board[0][7] == 10) {
                if (board[0][5] == 0 && board[0][6] == 0) {
                    board[0][6] = 12;
                    board[0][5] = 10;
                    board[0][4] = 0;
                    board[0][7] = 0;
                    return true;
                }
            }
        }
    } else if (type == "O-O-O") {
        if (w_turn) {
            if (board[7][0] == 4) {
                if (board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0) {
                    board[7][2] = 6;
                    board[7][3] = 4;
                    board[7][4] = 0;
                    board[7][0] = 0;
                    return true;
                }
            }
        } else {
            if (board[7][0] == 10) {
                if (board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0) {
                    board[0][2] = 12;
                    board[0][3] = 10;
                    board[0][4] = 0;
                    board[0][0] = 0;
                    return true;
                }
            }
        }
    }
    return false;
}

bool check_valid_move(const std::vector<std::vector<int>>& board, int src_x, int src_y, int dest_x, int dest_y, bool w_turn) {
    if (w_turn && board[src_y][src_x] == 1) { //Sprawdzanie dla pionków
        if (dest_x == src_x) {
            if (dest_y == src_y - 1) {
                if (board[dest_y][dest_x] == 0) {
                    return true;
                }
            } else if (dest_y == src_y - 2 && src_y == 6) {
                if (board[dest_y][dest_x] == 0 && board[dest_y + 1][dest_x] == 0) {
                    return true;
                }
            }
        } else if ((dest_x == src_x + 1 || dest_x == src_x - 1) && dest_y == src_y - 1) {
            if (board[dest_y][dest_x] > 6) {
                return true;
            } else if (src_y == 3 && last_src_x == src_x + 1 && dest_x == src_x + 1 && last_dest_y == src_y && board[last_dest_y][last_dest_x] == 7) {
                return true;
            } else if (src_y == 3 && last_src_x == src_x - 1 && dest_x == src_x - 1 && last_dest_y == src_y && board[last_dest_y][last_dest_x] == 7) {
                return true;
            }
        }
        return false;
    } else if (!w_turn && board[src_y][src_x] == 7) {
        if (dest_x == src_x) {
            if (dest_y == src_y + 1) {
                if (board[dest_y][dest_x] == 0) {
                    return true;
                }
            } else if (dest_y == src_y + 2 && src_y == 1) {
                if (board[dest_y][dest_x] == 0 && board[dest_y - 1][dest_x] == 0) {
                    return true;
                }
            }
        } else if ((dest_x == src_x + 1 || dest_x == src_x - 1) && dest_y == src_y + 1) {
            if (board[dest_y][dest_x] < 6 && board[dest_y][dest_x] != 0) {
                return true;
            } else if (src_y == 4 && last_src_x == src_x + 1 && dest_x == src_x + 1 && last_dest_y == src_y && board[last_dest_y][last_dest_x] == 1) {
                return true;
            } else if (src_y == 4 && last_src_x == src_x - 1 && dest_x == src_x - 1 && last_dest_y == src_y && board[last_dest_y][last_dest_x] == 1) {
                return true;
            }
        }
        return false;
    } else if (w_turn && board[src_y][src_x] == 4) { //Sprawdzanie dla wie¿y
        if (dest_x == src_x) {
            if (dest_y < src_y) {
                if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                    for (int y = src_y - 1; y > dest_y; y--) {
                        if (board[y][dest_x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            } else if (dest_y > src_y) {
                if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                    for (int y = src_y + 1; y < dest_y; y++) {
                        if (board[y][dest_x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        if (dest_y == src_y) {
            if (dest_x < src_x) {
                if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                    for (int x = src_x - 1; x > dest_x; x--) {
                        if (board[dest_y][x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            } else if (dest_x > src_x) {
                if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                    for (int x = src_x + 1; x < dest_x; x++) {


                        if (board[dest_y][x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    } else if (!w_turn && board[src_y][src_x] == 10) {
        if (dest_x == src_x) {
            if (dest_y < src_y) {
                if (board[dest_y][dest_x] < 7) {
                    for (int y = src_y - 1; y > dest_y; y--) {
                        if (board[y][dest_x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            } else if (dest_y > src_y) {
                if (board[dest_y][dest_x] < 7) {
                    for (int y = src_y + 1; y < dest_y; y++) {
                        if (board[y][dest_x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        if (dest_y == src_y) {
            if (dest_x < src_x) {
                if (board[dest_y][dest_x] < 7) {
                    for (int x = src_x - 1; x > dest_x; x--) {
                        if (board[dest_y][x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            } else if (dest_x > src_x) {
                if (board[dest_y][dest_x] < 7) {
                    for (int x = src_x + 1; x < dest_x; x++) {
                        if (board[dest_y][x] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    } else if (w_turn && board[src_y][src_x] == 2) { //Sprawdzanie dla koni
        if (board[dest_y][dest_x] == 0 || board[dest_y][dest_x] > 6) {
            if (dest_x == src_x + 1 && dest_y == src_y + 2) return true;
            if (dest_x == src_x + 2 && dest_y == src_y + 1)  return true;
            if (dest_x == src_x + 2 && dest_y == src_y - 1) return true;
            if (dest_x == src_x + 1 && dest_y == src_y - 2) return true;
            if (dest_x == src_x - 1 && dest_y == src_y - 2) return true;
            if (dest_x == src_x - 2 && dest_y == src_y - 1) return true;
            if (dest_x == src_x - 2 && dest_y == src_y + 1) return true;
            if (dest_x == src_x - 1 && dest_y == src_y + 2) return true;
        }
    } else if (!w_turn && board[src_y][src_x] == 8) {
        if (board[dest_y][dest_x] < 7) {
            if (dest_x == src_x + 1 && dest_y == src_y + 2) return true;
            if (dest_x == src_x + 2 && dest_y == src_y + 1)  return true;
            if (dest_x == src_x + 2 && dest_y == src_y - 1) return true;
            if (dest_x == src_x + 1 && dest_y == src_y - 2) return true;
            if (dest_x == src_x - 1 && dest_y == src_y - 2) return true;
            if (dest_x == src_x - 2 && dest_y == src_y - 1) return true;
            if (dest_x == src_x - 2 && dest_y == src_y + 1) return true;
            if (dest_x == src_x - 1 && dest_y == src_y + 2) return true;
        }
    } else if (w_turn && board[src_y][src_x] == 3) { //Sprawdzanie dla goñców
        if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
            for (int i = 0; i < 8; i++) {
                if (dest_x == src_x + i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x + i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    } else if (!w_turn && board[src_y][src_x] == 9) {
        if (board[dest_y][dest_x] < 7) {
            for (int i = 0; i < 8; i++) {
                if (dest_x == src_x + i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x + i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    } else if (w_turn && board[src_y][src_x] == 6) { //Sprawdzanie dla królów
        if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
            if (dest_x == src_x + 1 && (dest_y == src_y + 1 || dest_y == src_y || dest_y == src_y - 1)) {
                w_king_moved = true;
                return true;
            }
            if (dest_x == src_x - 1 && (dest_y == src_y + 1 || dest_y == src_y || dest_y == src_y - 1)){
                w_king_moved = true;
                return true;
            }
            if (dest_x == src_x && (dest_y == src_y + 1 || dest_y == src_y - 1)) {
                w_king_moved = true;
                return true;
            }
            if (dest_y == src_y && (dest_y == src_y + 1 || dest_y == src_y - 1)) {
                w_king_moved = true;
                return true;
            }
            return false;
        }
    } else if (!w_turn && board[src_y][src_x] == 12) {
        if (board[dest_y][dest_x] < 7) {
            if (dest_x == src_x + 1 && (dest_y == src_y + 1 || dest_y == src_y || dest_y == src_y - 1)) {
                b_king_moved = true;
                return true;
            }
            if (dest_x == src_x - 1 && (dest_y == src_y + 1 || dest_y == src_y || dest_y == src_y - 1)) {
                b_king_moved = true;
                return true;
            }
            if (dest_x == src_x && (dest_y == src_y + 1 || dest_y == src_y - 1)){
                b_king_moved = true;
                return true;
            }
            return false;
        }
    } else if (w_turn && board[src_y][src_x] == 5) { //Sprawdzanie dla bia³ej królowej
        if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
            for (int i = 0; i < 8; i++) {
                if (dest_x == src_x + i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x + i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
            if (dest_x == src_x) {
                if (dest_y < src_y) {
                    if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                        for (int y = src_y - 1; y > dest_y; y--) {
                            if (board[y][dest_x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                } else if (dest_y > src_y) {
                    if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                        for (int y = src_y + 1; y < dest_y; y++) {
                            if (board[y][dest_x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }
            if (dest_y == src_y) {
                if (dest_x < src_x) {
                    if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                        for (int x = src_x - 1; x > dest_x; x--) {
                            if (board[dest_y][x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                } else if (dest_x > src_x) {
                    if (board[dest_y][dest_x] > 6 || board[dest_y][dest_x] == 0) {
                        for (int x = src_x + 1; x < dest_x; x++) {
                            if (board[dest_y][x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }
        }
    } else if (!w_turn && board[src_y][src_x] == 11) { //Sprawdzanie dla czarnej królowej
        if (board[dest_y][dest_x] < 7) {
            for (int i = 0; i < 8; i++) {
                if (dest_x == src_x + i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y + i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y + j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x - i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x - j] != 0) {
                            return false;
                        }
                    }
                    return true;
                } else if (dest_x == src_x + i && dest_y == src_y - i) {
                    for (int j = 1; j < std::abs(dest_x - src_x); j++) {
                        if (board[src_y - j][src_x + j] != 0) {
                            return false;
                        }
                    }
                    return true;
                }
            }
            if (dest_x == src_x) {
                if (dest_y < src_y) {
                    if (board[dest_y][dest_x] < 7) {
                        for (int y = src_y - 1; y > dest_y; y--) {
                            if (board[y][dest_x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                } else if (dest_y > src_y) {
                    if (board[dest_y][dest_x] < 7) {
                        for (int y = src_y + 1; y < dest_y; y++) {
                            if (board[y][dest_x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }
            if (dest_y == src_y) {
                if (dest_x < src_x) {
                    if (board[dest_y][dest_x] < 7) {
                        for (int x = src_x - 1; x > dest_x; x--) {
                            if (board[dest_y][x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                } else if (dest_x > src_x) {
                    if (board[dest_y][dest_x] < 7) {
                        for (int x = src_x + 1; x < dest_x; x++) {
                            if (board[dest_y][x] != 0) {
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_en_passant(std::vector<std::vector<int>>& board, int src_x, int src_y, int dest_x, int dest_y) {
    if (board[dest_y][dest_x] == 1) { //Sprawdzanie dla pionków
        if (src_y == 3 && (last_src_x == src_x + 1 || last_src_x == src_x - 1 && last_dest_y == src_y &&
                                                      board[last_dest_y][last_dest_x] == 7)) {
            std::cout << "To by³o en passant" << std::endl;
            return true;
        }
    } else if (board[dest_y][dest_x] == 7) {
        if (src_y == 4 && (last_src_x == src_x + 1 || last_src_x == src_x - 1 && last_dest_y == src_y &&
                                                      board[last_dest_y][last_dest_x] == 1)) {
            std::cout << "To by³o en passant" << std::endl;
            return true;
        }
    }
    return false;
}

bool is_white_checked(std::vector<std::vector<int>>& board) {
    int pos_x = -1;
    int pos_y = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 6) {
                pos_x = j;
                pos_y = i;
            }
        }
    }

    for (int x = 1; x < (7 - pos_x) + 1; x++) { // Sprawdzanie czy na wertykalnych liniach jest królowa lub wie¿a
        if (board[pos_y][pos_x + x] == 0){
            continue;
        } else if (board[pos_y][pos_x + x] == 10 || board[pos_y][pos_x + x] == 11) {
            return true;
        } else {
            break;
        }
    }

    for (int x = 1; x < pos_x + 1; x++) {
        if (board[pos_y][pos_x - x] == 0){
            continue;
        } else if (board[pos_y][pos_x - x] == 10 || board[pos_y][pos_x - x] == 11) {
            return true;
        } else {
            break;
        }
    }

    for (int y = 1; y < (7 - pos_y) + 1; y++) {
        if (board[pos_y + y][pos_x] == 0){
            continue;
        } else if (board[pos_y + y][pos_x] == 10 || board[pos_y + y][pos_x] == 11) {
            return true;
        } else {
            break;
        }
    }

    for (int y = 1; y < pos_y + 1; y++) {
        if (board[pos_y - y][pos_x] == 0){
            continue;
        } else if (board[pos_y - y][pos_x] == 10 || board[pos_y - y][pos_x] == 11) {
            return true;
        } else {
            break;
        }
    }

    if (7 - pos_x == std::min(7 - pos_x, pos_y)) { // Sprawdzanie czy na przek¹tnych jest królowa lub goniec
        for (int i = 1; i < (7 - pos_x) + 1; i++) {
            if (board[pos_y - i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x + i] == 9 || board[pos_y - i][pos_x + i] == 11) {
                return true;
            } else {
                break;
            }
        }
    } else if (pos_y == std::min(7 - pos_x, pos_y)) {
        for (int i = 1; i < pos_y + 1; i++) {
            if (board[pos_y - i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x + i] == 9 || board[pos_y - i][pos_x + i] == 11) {
                return true;
            } else {
                break;
            }
        }
    }

    if (pos_x == std::min(pos_x, pos_y)) {
        for (int i = 1; i < pos_x + 1; i++) {
            if (board[pos_y - i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x - i] == 9 || board[pos_y - i][pos_x - i] == 11) {
                return true;
            } else {
                break;
            }
        }
    } else if (pos_y == std::min(pos_x, pos_y)) {
        for (int i = 1; i < pos_y + 1; i++) {
            if (board[pos_y - i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x - i] == 9 || board[pos_y - i][pos_x - i] == 11) {
                return true;
            } else {
                break;
            }
        }
    }

    if (pos_x == std::min(pos_x, 7 - pos_y)) {
        for (int i = 1; i < pos_x + 1; i++) {
            if (board[pos_y + i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x - i] == 9 || board[pos_y + i][pos_x - i] == 11) {
                return true;
            } else {
                break;
            }
        }
    } else if (7 - pos_y == std::min(pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_y) + 1; i++) {
            if (board[pos_y + i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x - i] == 9 || board[pos_y + i][pos_x - i] == 11) {
                return true;
            } else {
                break;
            }
        }
    }

    if (7 - pos_x == std::min(7 - pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_x) + 1; i++) {
            if (board[pos_y + i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x + i] == 9 || board[pos_y + i][pos_x + i] == 11) {
                return true;
            } else {
                break;
            }
        }
    } else if (7 - pos_y == std::min(7 - pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_y) + 1; i++) {
            if (board[pos_y + i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x + i] == 9 || board[pos_y + i][pos_x + i] == 11) {
                return true;
            } else {
                break;
            }
        }
    }
    // Sprawdzenie czy nie ma konia na oko³o
    if ((pos_x - 2 >= 0 && pos_y + 1 < 8 && board[pos_y + 1][pos_x - 2] == 8) ||
        (pos_x - 2 >= 0 && pos_y - 1 >= 0 && board[pos_y - 1][pos_x - 2] == 8) ||
        (pos_x + 2 < 8 && pos_y + 1 < 8 && board[pos_y + 1][pos_x + 2] == 8) ||
        (pos_x + 2 < 8 && pos_y - 1 >= 0 && board[pos_y - 1][pos_x + 2] == 8) ||
        (pos_x - 1 >= 0 && pos_y + 2 < 8 && board[pos_y + 2][pos_x - 1] == 8) ||
        (pos_x - 1 >= 0 && pos_y - 2 >= 0 && board[pos_y - 2][pos_x - 1] == 8) ||
        (pos_x + 1 < 8 && pos_y + 2 < 8 && board[pos_y + 2][pos_x + 1] == 8) ||
        (pos_x + 1 < 8 && pos_y - 2 >= 0 && board[pos_y - 2][pos_x + 1] == 8)) {
        return true;
    }

    if (board[pos_y - 1][pos_x + 1] == 7) { // Sprawdzenie czy nie ma atakuj¹cego piona
        return true;
    } else if (board[pos_y - 1][pos_x - 1] == 7) {
        return true;
    }

    return false;
}

bool is_black_checked(std::vector<std::vector<int>>& board) {
    int pos_x = -1;
    int pos_y = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 12) {
                pos_x = j;
                pos_y = i;
            }
        }
    }

    for (int x = 1; x < (7 - pos_x) + 1; x++) { // Sprawdzanie czy na wertykalnych i horyzontalnych liniach jest królowa lub wie¿a
        if (board[pos_y][pos_x + x] == 0){
            continue;
        } else if (board[pos_y][pos_x + x] == 4 || board[pos_y][pos_x + x] == 5) {
            return true;
        } else {
            break;
        }
    }

    for (int x = 1; x < pos_x + 1; x++) {
        if (board[pos_y][pos_x - x] == 0){
            continue;
        } else if (board[pos_y][pos_x - x] == 4 || board[pos_y][pos_x - x] == 5) {
            return true;
        } else {
            break;
        }
    }

    for (int y = 1; y < pos_y + 1; y++) {
        if (board[pos_y - y][pos_x] == 0){
            continue;
        } else if (board[pos_y - y][pos_x] == 4 || board[pos_y - y][pos_x] == 5) {
            return true;
        } else {
            break;
        }
    }

    for (int y = 1; y < (7 - pos_y) + 1; y++) {
        if (board[pos_y + y][pos_x] == 0){
            continue;
        } else if (board[pos_y + y][pos_x] == 4 || board[pos_y + y][pos_x] == 5) {
            return true;
        } else {
            break;
        }
    }

    if (7 - pos_x == std::min(7 - pos_x, pos_y)) { // Sprawdzanie czy na przek¹tnych jest królowa lub goniec
        for (int i = 1; i < (7 - pos_x) + 1; i++) {
            if (board[pos_y - i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x + i] == 3 || board[pos_y - i][pos_x + i] == 5) {
                return true;
            } else {
                break;
            }
        }
    } else if (pos_y == std::min(7 - pos_x, pos_y)) {
        for (int i = 1; i < pos_y + 1; i++) {
            if (board[pos_y - i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x + i] == 3 || board[pos_y - i][pos_x + i] == 5) {
                return true;
            } else {
                break;
            }
        }
    }

    if (pos_x == std::min(pos_x, pos_y)) {
        for (int i = 1; i < pos_x + 1; i++) {
            if (board[pos_y - i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x - i] == 3 || board[pos_y - i][pos_x - i] == 5) {
                return true;
            } else {
                break;
            }
        }
    } else if (pos_y == std::min(pos_x, pos_y)) {
        for (int i = 1; i < pos_y + 1; i++) {
            if (board[pos_y - i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y - i][pos_x - i] == 3 || board[pos_y - i][pos_x - i] == 5) {
                return true;
            } else {
                break;
            }
        }
    }

    if (pos_x == std::min(pos_x, 7 - pos_y)) {
        for (int i = 1; i < pos_x + 1; i++) {
            if (board[pos_y + i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x - i] == 3 || board[pos_y + i][pos_x - i] == 5) {
                return true;
            } else {
                break;
            }
        }
    } else if (7 - pos_y == std::min(pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_y) + 1; i++) {
            if (board[pos_y + i][pos_x - i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x - i] == 3 || board[pos_y + i][pos_x - i] == 5) {
                return true;
            } else {
                break;
            }
        }
    }

    if (7 - pos_x == std::min(7 - pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_x) + 1; i++) {
            if (board[pos_y + i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x + i] == 3 || board[pos_y + i][pos_x + i] == 5) {
                return true;
            } else {
                break;
            }
        }
    } else if (7 - pos_y == std::min(7 - pos_x, 7 - pos_y)) {
        for (int i = 1; i < (7 - pos_y) + 1; i++) {
            if (board[pos_y + i][pos_x + i] == 0){
                continue;
            } else if (board[pos_y + i][pos_x + i] == 3 || board[pos_y + i][pos_x + i] == 5) {
                return true;
            } else {
                break;
            }
        }
    }

    if ((pos_x - 2 >= 0 && pos_y + 1 < 8 && board[pos_y + 1][pos_x - 2] == 2) ||
        (pos_x - 2 >= 0 && pos_y - 1 >= 0 && board[pos_y - 1][pos_x - 2] == 2) ||
        (pos_x + 2 < 8 && pos_y + 1 < 8 && board[pos_y + 1][pos_x + 2] == 2) ||
        (pos_x + 2 < 8 && pos_y - 1 >= 0 && board[pos_y - 1][pos_x + 2] == 2) ||
        (pos_x - 1 >= 0 && pos_y + 2 < 8 && board[pos_y + 2][pos_x - 1] == 2) ||
        (pos_x - 1 >= 0 && pos_y - 2 >= 0 && board[pos_y - 2][pos_x - 1] == 2) ||
        (pos_x + 1 < 8 && pos_y + 2 < 8 && board[pos_y + 2][pos_x + 1] == 2) ||
        (pos_x + 1 < 8 && pos_y - 2 >= 0 && board[pos_y - 2][pos_x + 1] == 2)) {
        return true;
    }

    if (board[pos_y + 1][pos_x + 1] == 1) {
        return true;
    } else if (board[pos_y + 1][pos_x - 1] == 1) {
        return true;
    }

    return false;
}

bool is_promoting(std::vector<std::vector<int>>& board) {
    for (int i = 0; i < 8; i++) {
        if (board[0][i] == 1 || board[7][i] == 7) {
            return true;
        }
    }
    return false;
}

bool is_sufficient(std::vector<std::vector<int>>& board) {
    int white_value = 0;
    int black_value = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0 || board[i][j] == 6) {
                continue;
            } else if (board[i][j] < 6 && board[i][j] != 0) {
                if (board[i][j] == 1 || board[i][j] == 4 || board[i][j] == 5) {
                    return true;
                } else if (board[i][j] == 3) {
                    white_value += 3;
                } else if (board[i][j] == 2) {
                    white_value += 2;
                }
            } else if (board[i][j] == 0 || board[i][j] == 12) {
                continue;
            } else if (board[i][j] > 6) {
                if (board[i][j] == 7 || board[i][j] == 10 || board[i][j] == 11) {
                    return true;
                } else if (board[i][j] == 9) {
                    white_value += 3;
                } else if (board[i][j] == 8) {
                    black_value += 2;
                }
            }
        }
    }

    if (white_value <= 4 || black_value <= 4) {
        return false;
    }

}

void draw(sf::RenderWindow& window, std::vector<std::vector<sf::RectangleShape>>& chessboard) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(chessboard[j][i]);
        }
    }
    displayPieces(window);
}

int main()
{
    sf:: RenderWindow window(sf::VideoMode(tileSize * 8, tileSize * 8), "Chess", sf::Style::Close | sf::Style::Resize);
    std::vector<std::vector<sf::RectangleShape>> chessboard;

    initialize(chessboard);

    int src_x = -1;
    int src_y = -1;
    int dest_x = -1;
    int dest_y = -1;

    bool w_turn = true;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (src_y == -1 && src_x == -1) {
                        src_y = select(chessboard, mousePosition.x, mousePosition.y)[0];
                        src_x = select(chessboard, mousePosition.x, mousePosition.y)[1];
                    } else {
                        dest_y = select(chessboard, mousePosition.x, mousePosition.y)[0];
                        dest_x = select(chessboard, mousePosition.x, mousePosition.y)[1];
                        if ((w_turn && pieces[dest_y][dest_x] < 7 && pieces[dest_y][dest_x] != 0) || (!w_turn && pieces[dest_y][dest_x] > 6)) {
                            src_x = dest_x;
                            src_y = dest_y;
                            dest_x = -1;
                            dest_y = -1;
                        }
                    }
                }
            }
        }
        if (src_x != -1 && src_y != -1 && dest_x != -1 && dest_y != -1) {
            std::cout << "src_x = " << src_x << "src_y = " << src_y << "dest_x = " << dest_x << "dest_y = " << dest_y << std::endl;
            if (check_valid_move(pieces, src_x, src_y, dest_x, dest_y, w_turn)) {
                int piece = pieces[dest_y][dest_x];
                move_piece(pieces, src_x, src_y, dest_x, dest_y);
                if (w_turn) {
                    if(is_white_checked(pieces)) {
                        std::cout << "You can't move that white piece" << std::endl;
                        move_piece(pieces,dest_x,dest_y,src_x,src_y);
                        pieces[dest_y][dest_x] = piece;
                        dest_x = -1;
                        dest_y = -1;
                        continue;
                    }
                    if (is_black_checked(pieces)){
                        std::cout << "Black is checked" << std::endl;
                    }
                    if (is_en_passant(pieces, src_x, src_y, dest_x, dest_y)) {
                        pieces[last_dest_y][last_dest_x] = EMPTY;
                    }
                    if (is_promoting(pieces)) {
                        std::string fig;
                        std::cout << "What figure to promote to: ";
                        std::cin >> fig;
                        if (fig == "R") {
                            pieces[dest_y][dest_x] = W_ROOK;
                        } else if (fig == "Q") {
                            pieces[dest_y][dest_x] = W_QUEEN;
                        } else if (fig == "B") {
                            pieces[dest_y][dest_x] = W_BISHOP;
                        } else if (fig == "N") {
                            pieces[dest_y][dest_x] = W_KNIGHT;
                        }
                    }
                } else {
                    if(is_black_checked(pieces)) {
                        std::cout << "You can't move that black piece" << std::endl;
                        move_piece(pieces,dest_x,dest_y,src_x,src_y);
                        pieces[dest_y][dest_x] = piece;
                        dest_x = -1;
                        dest_y = -1;
                        continue;
                    }
                    if (is_white_checked(pieces)){
                        std::cout << "White is checked" << std::endl;
                    }
                    if (is_en_passant(pieces, src_x, src_y, dest_x, dest_y)) {
                        pieces[last_dest_y][last_dest_x] = EMPTY;
                    }
                    if (is_promoting(pieces)) {
                        std::string fig;
                        std::cout << "What figure to promote to: ";
                        std::cin >> fig;
                        if (fig == "r") {
                            pieces[dest_y][dest_x] = B_ROOK;
                        } else if (fig == "q") {
                            pieces[dest_y][dest_x] = B_QUEEN;
                        } else if (fig == "b") {
                            pieces[dest_y][dest_x] = B_BISHOP;
                        } else if (fig == "n") {
                            pieces[dest_y][dest_x] = B_KNIGHT;
                        }
                    }
                }

                last_src_x = src_x;
                last_src_y = src_y;
                last_dest_x = dest_x;
                last_dest_y = dest_y;

                w_turn = !w_turn;
            }
            src_y = -1;
            src_x = -1;
            dest_y = -1;
            dest_x = -1;
        }


        window.clear();

        draw(window, chessboard);

        window.display();
    }

    return 0;
}