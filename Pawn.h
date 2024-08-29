// Pawn.h

#ifndef Pawn_h
#define Pawn_h

#include <vector>

#include "Constants.h"
#include "Piece.h"
#include "FullMove.h"

class ChessBoard;

class Pawn : public Piece {
private:
    std::vector<FullMove> getMovesImplementation(ChessBoard const &board, int pieceRow, int pieceCol, bool attackingMoves) const override;
    std::vector<FullMove> getPromotionMoves(ChessBoard const &board, FullMove const &move) const;
public:
    Pawn(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore = 1);
};


#endif /* Pawn */
