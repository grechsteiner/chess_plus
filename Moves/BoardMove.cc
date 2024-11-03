// BoardMove.cc

#include <optional>

#include "BoardMove.h"
#include "BoardSquare.h"
#include "Constants.h"
#include "PieceData.h"
#include "PieceInfo.h"

// Basic ctor
BoardMove::BoardMove(BoardSquare const &fromSquare, BoardSquare const &toSquare, BoardSquare const &captureSquare, bool doesEnableEnpassant, PieceData const &movedPieceData, std::optional<PieceData> const &capturedPieceData) :
    fromSquare(fromSquare), toSquare(toSquare), captureSquare(captureSquare), doesEnableEnpassant(doesEnableEnpassant), movedPieceData(movedPieceData), capturedPieceData(capturedPieceData) {}

// Move ctor
BoardMove::BoardMove(BoardMove &&other) noexcept :
    fromSquare(std::move(other.fromSquare)), toSquare(std::move(other.toSquare)), captureSquare(std::move(other.captureSquare)), doesEnableEnpassant(other.doesEnableEnpassant), movedPieceData(std::move(other.movedPieceData)), capturedPieceData(std::move(other.capturedPieceData)) {}

// Move assignment
BoardMove& BoardMove::operator=(BoardMove &&other) noexcept {
    if (this != &other) {
        fromSquare = std::move(other.fromSquare);
        toSquare = std::move(other.toSquare);
        captureSquare = std::move(other.captureSquare);
        doesEnableEnpassant = other.doesEnableEnpassant;
        movedPieceData = std::move(other.movedPieceData);
        capturedPieceData = std::move(other.capturedPieceData);
    }
    return *this;
}

bool BoardMove::operator==(BoardMove const &other) const {
    return typeid(*this) == typeid(other) && this->equals(other);
}

std::unique_ptr<BoardMove> BoardMove::clone() const { return cloneImpl(); }
void BoardMove::makeBoardMove(ChessBoard &chessBoard) const { return makeBoardMoveImpl(chessBoard); }
void BoardMove::undoBoardMove(ChessBoard &chessBoard) const { return undoBoardMoveImpl(chessBoard); }

BoardSquare const& BoardMove::getFromSquare() const { return fromSquare; }
BoardSquare const& BoardMove::getToSquare() const { return toSquare; }
BoardSquare const& BoardMove::getCaptureSquare() const { return captureSquare; }

bool BoardMove::getDoesEnableEnpassant() const { return doesEnableEnpassant; }
PieceData const& BoardMove::getMovedPieceData() const { return movedPieceData; }
std::optional<PieceData> BoardMove::getCapturedPieceData() const { return capturedPieceData; }
