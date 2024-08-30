// Rook.h

#ifndef Rook_h
#define Rook_h

#include <vector>

#include "Constants.h"
#include "Piece.h"
#include "BoardMove.h"

class ChessBoard;

class Rook : public Piece {
private:
    std::vector<BoardMove> getMovesImplementation(ChessBoard const &board, BoardSquare const &boardSquare, bool onlyAttackingMoves) const override;
    static std::vector<std::pair<int, int>> const rookDirections;
public:
    Rook(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore = 5);
};


#endif /* Rook_h */
