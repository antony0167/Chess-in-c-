# Chess in C++

A two-player chess game in C++ with an SFML window. I wrote it for my C++ project course at the University of Wrocław (October 2023 to January 2024). It doesn't use a chess library: the board, the move rules and check detection are all written from scratch.

## What works

- Click a piece, then click a square to move it. Clicking another of your own pieces switches the selection.
- Move rules for every piece, including blocked paths for sliding pieces.
- Check detection: you can't make a move that leaves your own king in check, and the game prints a message when the opponent is in check.
- En passant.
- Promotion (the piece is chosen in the terminal: `Q`, `R`, `B`, `N`).

Castling, checkmate and draw by insufficient material are started in the code (`check_valid_castle`, `is_sufficient`) but not connected to the game loop yet. That's the next thing to finish.

## Building

You need CMake 3.16+ and a C++17 compiler. If SFML 2.5/2.6 is installed, CMake uses it. Otherwise it downloads and builds SFML 2.6.1 automatically.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/chess          # Windows: build\Release\chess.exe
```

On Linux, building SFML from source needs the usual system packages (`libx11-dev libxrandr-dev libxcursor-dev libudev-dev libgl1-mesa-dev libfreetype-dev`). Installing `libsfml-dev` from your package manager is quicker.

## How it's organised

Everything is in `main.cpp`:

| part | what it does |
|------|--------------|
| `pieces` | the 8x8 board, one integer per square (`Piece` enum) |
| `check_valid_move` | movement rules per piece type |
| `is_white_checked` / `is_black_checked` | looks along lines, diagonals and knight jumps from the king for attackers |
| `is_en_passant`, `is_promoting` | special pawn moves |
| `displayPieces`, `draw` | SFML rendering; textures are loaded once at startup |

## Changes since the course

- The build referenced files that weren't in the repository and a hard-coded `C:/SFML` path. CMake now finds or downloads SFML, so it builds on any OS.
- Piece images were loaded from an absolute Windows path, and from disk on every frame. They're now loaded once, from the `images/` folder next to the executable.
- Fixed black queenside castling checking White's rook square.
- Fixed the bounds check in `move_piece`.
- Source converted from Windows-1250 to UTF-8 so the Polish comments display correctly.
