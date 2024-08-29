// Bishop.h

#ifndef Bishop_h
#define Bishop_h

#include <vector>

#include "Constants.h"
#include "Piece.h"
#include "FullMove.h"


class BoarePieceInterface;

class Bishop : public Piece {
private:
    std::vector<BoardMove> getMovesImplementation(ChessBoard const &board, int pieceRow, int pieceCol, bool attackingMoves) const override;
    static std::vector<std::pair<int, int>> const bishopDirections;
public:
    Bishop(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore = 3);
};


#endif /* Bishop_h */
