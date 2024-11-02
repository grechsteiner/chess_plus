// BasicKing.h

#ifndef BasicKing_h
#define BasicKing_h

#include <vector>
#include <utility>
#include <set>

#include "Constants.h"
#include "Piece.h"
#include "Cloneable.h"
#include "ComplicatedCloneable.h"
#include "PieceData.h"
#include "King.h"

class IChessBoard;
class BoardSquare;
class BoardMove;


/**
 * Basic King Piece Class
 */
class BasicKing final : public ComplicatedCloneable<Piece, King, BasicKing> {
private:
    std::vector<BoardMove> getMovesImpl(IChessBoard const &chessBoard, BoardSquare const &fromSquare, bool onlyAttackingMoves) const override;
public:
    explicit BasicKing(Team team, PieceDirection pieceDirection, bool hasMoved);
    BasicKing(BasicKing const &other);
    BasicKing(BasicKing &&other) noexcept;
    BasicKing& operator=(BasicKing const &other);
    BasicKing& operator=(BasicKing &&other) noexcept;
    virtual ~BasicKing() = default;
};

#endif /* BasicKing_h */