// BasicPieceFactory.cc

#include <memory>
#include <cassert>

#include "BasicPieceFactory.h"
#include "Piece.h"
#include "Constants.h"

#include "BasicKing.h"
#include "BasicQueen.h"
#include "BasicRook.h"
#include "BasicBishop.h"
#include "BasicKnight.h"
#include "BasicPawn.h"

// Static
std::unique_ptr<Piece> BasicPieceFactory::createPiece(PieceData const &pieceData) {
    switch (pieceData.pieceType) {
        case PieceType::KING:
            return std::make_unique<BasicKing>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        case PieceType::QUEEN:
            return std::make_unique<BasicQueen>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        case PieceType::ROOK:
            return std::make_unique<BasicRook>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        case PieceType::BISHOP:
            return std::make_unique<BasicBishop>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        case PieceType::KNIGHT:
            return std::make_unique<BasicKnight>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        case PieceType::PAWN:
            return std::make_unique<BasicPawn>(pieceData.team, pieceData.pieceDirection, pieceData.hasMoved);
        default:
            assert(false);
    }
}
