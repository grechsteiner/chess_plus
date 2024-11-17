// Bishop.h

#ifndef Bishop_h
#define Bishop_h

#include <memory>
#include <set>
#include <utility>
#include <vector>

#include "BoardMove.h"
#include "BoardSquare.h"
#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"


/**
 * Abstract Bishop Piece Class
 */
class Bishop : public Piece {
private:
    static std::set<std::pair<int, int>> const bishopDirections;

protected:
    explicit Bishop(PieceLevel pieceLevel, Team team, PieceDirection pieceDirection, bool hasMoved, char32_t image);
    Bishop(Bishop const &other);
    Bishop(Bishop &&other) noexcept;
    Bishop& operator=(Bishop const &other);
    Bishop& operator=(Bishop &&other) noexcept;
    virtual ~Bishop() = default;

    std::vector<std::unique_ptr<BoardMove>> getStandardMoves(std::unique_ptr<ChessBoard> const &chessBoard, BoardSquare const &fromSquare, bool onlyAttackingMoves) const override;
};


#endif /* Bishop_h */
