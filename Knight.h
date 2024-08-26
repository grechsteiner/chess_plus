// Knight.h

#ifndef Knight_h
#define Knight_h

#include <vector>

#include "Constants.h"
#include "Piece.h"
#include "Move.h"

class BoardPieceInterface;

class Knight : public Piece {
private:
    std::vector<Move> getMovesImplementation(BoardPieceInterface const &board, int pieceRow, int pieceCol, bool attackingMoves) const override;
    static std::vector<std::pair<int, int>> const knightDirections;
public:
    Knight(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore = 3);
};


#endif /* Knight_h */
