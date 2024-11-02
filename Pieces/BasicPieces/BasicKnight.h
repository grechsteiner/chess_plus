// BasicKnight.h

#ifndef BasicKnight_h
#define BasicKnight_h

#include <vector>
#include <utility>
#include <set>

#include "Constants.h"
#include "Piece.h"
#include "Cloneable.h"
#include "ComplicatedCloneable.h"
#include "PieceData.h"
#include "Knight.h"

class IChessBoard;
class BoardSquare;
class BoardMove;


/**
 * BasicKnight Piece Class
 */
class BasicKnight final : public ComplicatedCloneable<Piece, Knight, BasicKnight> {
private:
    std::vector<BoardMove> getMovesImpl(IChessBoard const &chessBoard, BoardSquare const &fromSquare, bool onlyAttackingMoves) const override;
public:
    explicit BasicKnight(Team team, PieceDirection pieceDirection, bool hasMoved);
    BasicKnight(BasicKnight const &other);
    BasicKnight(BasicKnight &&other) noexcept;
    BasicKnight& operator=(BasicKnight const &other);
    BasicKnight& operator=(BasicKnight &&other) noexcept;
    virtual ~BasicKnight() = default;
};


#endif /* BasicKnight_h */