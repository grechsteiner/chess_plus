// TextObserver.cc

#include <iostream>

#include "TextObserver.h"
#include "Game.h"

TextObserver::TextObserver(std::ostream &out, Game *game) : out(out), game(game) {
    game->attach(this);
}

TextObserver::~TextObserver() {
    game->detach(this);
}

void TextObserver::notifyImplementation() {

    GameState gameState = game->getGameState();

    if (gameState == GameState::MAIN_MENU) {
        out << "+---------+" << std::endl;
        out << "|Main Menu|" << std::endl;
        out << "+---------+" << std::endl;
    } else if (gameState == GameState::SETUP) {
        std::tuple<const Board&, const std::tuple<PlayerTuple, PlayerTuple>&, int> state = game->getSetupState();

        const Board& board = std::get<0>(state);


        out << "+";
        for (int col = 0; col < board.getNumCols(); ++col) {
            out << "-";
        }
        out << "-----+" << std::endl;

        out << "|  Setup";

        for (int i = 0; i < board.getNumCols() - 3; ++i) {
            out << " ";
        }
        out << " |" << std::endl;
        
        printBoard(std::get<0>(state), std::get<2>(state));

        out << "+";
        for (int col = 0; col < board.getNumCols(); ++col) {
            out << "-";
        }
        out << "-----+" << std::endl;

    } else {
        std::tuple<const Board&, const std::tuple<PlayerTuple, PlayerTuple>&, int, bool> state = game->getActiveGameState();
        

        const Board& board = std::get<0>(state);

        out << "+";
        for (int col = 0; col < board.getNumCols(); ++col) {
            out << "-";
        }
        out << "-----+" << std::endl;

        out << "|  Active Game";

        for (int i = 0; i < board.getNumCols() - 8; ++i) {
            out << " ";
        }
        out << "|" << std::endl;
        
        printBoard(std::get<0>(state), std::get<2>(state));

        if (std::get<2>(state) == 0) { 
            if (board.isInCheckMate(Color::WHITE)) {
                out << "Checkmate! Black wins!" << std::endl;
            } else if (board.isInCheck(Color::WHITE)) {
                out << "White is in check" << std::endl;
            } else if (board.isInStaleMate(Color::WHITE)) {
                out << "Stalemate!" << std::endl;
            }

        } else {
            if (board.isInCheckMate(Color::BLACK)) {
                out << "Checkmate! White wins!" << std::endl;
            } else if (board.isInCheck(Color::BLACK)) {
                out << "Black is in check" << std::endl;
            } else if (board.isInStaleMate(Color::BLACK)) {
                out << "Stalemate!" << std::endl;
            }
        }

        out << "+";
        for (int col = 0; col < board.getNumCols(); ++col) {
            out << "-";
        }
        out << "-----+" << std::endl;


        if (std::get<3>(state) == true) {
            std::vector<std::pair<std::string, std::string>> openings = board.getMatchingOpenings();
            for (size_t i = 0; i < openings.size(); ++i) {
                std::cout << "Name: " << openings[i].first << std::endl;
            }
        }
    }
}

void TextObserver::printPiece(const std::string& str, Color color) {
    if (str == " ") {
        out << " ";
    } else if (color == Color::BLACK) {
        out << "\033[30m" << str << "\033[0m";
    } else {
        out << "\033[90m" << str << "\033[0m";
    }
}

void TextObserver::printBoard(Board const& board, int turn) {
    // Top line
    out << "|  ╔";
    for (int col = 0; col < board.getNumCols(); ++col) {
        out << "═";
    }
    out << "╗ |" << std::endl;

    for (int row = 0; row < board.getNumRows(); ++row) {
        out << "|" << board.getNumRows() - row;
        if (board.getNumRows() - row < 10) {
            out << " ";
        }
        out << "║";
        for (int col = 0; col < board.getNumCols(); ++col) {
            printPiece(board.BoardPieceInterface::getPieceAt(row, col).getImage(), board.BoardPieceInterface::getPieceAt(row, col).getPieceColor());
        }
        out << "║ |" << std::endl;
    }

    // Bottom line
    out << "|  ╚";
    for (int col = 0; col < board.getNumCols(); ++col) {
        out << "═";
    }
    out << "╝ |" << std::endl;

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    out << "|   ";
    for (int col = 0; col < board.getNumCols(); ++col) {
        out << alphabet[col];
    }
    out << "  |" << std::endl;

    if (turn == 0) {
        out << "|Turn: White";

    } else {
        out << "|Turn: Black";
    }

    for (int i = 0; i < (board.getNumCols() - 7); ++i) {
        out << " ";
    }
    out << " |" << std::endl;
}
