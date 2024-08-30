// ChessBoard.cc

#include <vector>

#include "ChessBoard.h"
#include "Constants.h"
#include "BoardMove.h"
#include "PieceInfo.h"

class UserMove;


PieceInfo ChessBoard::getPieceInfoAt(BoardSquare const &boardSquare) const { return getPieceInfoAtImpl(boardSquare); }
std::vector<BoardSquare> ChessBoard::allBoardSquares() const { return allBoardSquaresImpl(); }

bool ChessBoard::isEmptySquareOnBoard(BoardSquare const &boardSquare) const { return isEmptySquareOnBoardImpl(boardSquare); }
bool ChessBoard::isOpposingColorOnBoard(BoardSquare const &boardSquare, Color color) const { return isOpposingColorOnBoardImpl(boardSquare, color); }
bool ChessBoard::isEmptySquareOrOpposingColorOnBoard(BoardSquare const &boardSquare, Color color) const { return isEmptySquareOrOpposingColorOnBoardImpl(boardSquare, color); }
bool ChessBoard::isSquareAttacked(BoardSquare const &boardSquare, Color color) const { return isSquareAttackedImpl(boardSquare, color); }

bool ChessBoard::isSquareOnBoard(BoardSquare const &boardSquare) const { return isSquareOnBoardImpl(boardSquare); }
bool ChessBoard::isSquareOnBoard(UserSquare const &userSquare) const { return isSquareOnBoardImpl(userSquare); }
void ChessBoard::setPosition(UserSquare const &userSquare, Color pieceColor, PieceType pieceType, PieceDirection pieceDirection, bool hasMoved, int pieceScore) { 
    setPositionImpl(userSquare, pieceColor, pieceType, pieceDirection, hasMoved, pieceScore);
}
void ChessBoard::setPosition(BoardSquare const &boardSquare, Color pieceColor, PieceType pieceType, PieceDirection pieceDirection, bool hasMoved, int pieceScore) {
    setPositionImpl(boardSquare, pieceColor, pieceType, pieceDirection, hasMoved, pieceScore);
}
bool ChessBoard::clearPosition(UserSquare const &userSquare) { return clearPositionImpl(userSquare); }
bool ChessBoard::clearPosition(BoardSquare const &boardSquare) { return clearPositionImpl(boardSquare); }
void ChessBoard::clearBoard() { clearBoardImpl(); }
void ChessBoard::swapPositions(BoardSquare const &boardSquareOne, BoardSquare const &boardSquareTwo) { swapPositionsImpl(boardSquareOne, boardSquareTwo); }
void ChessBoard::setHasMoved(BoardSquare const &boardSquare, bool hasMoved) { setHasMovedImpl(boardSquare, hasMoved); }
bool ChessBoard::setBoardSize(int newNumRows, int newNumCols) { return setBoardSizeImpl(newNumRows, newNumCols); }
void ChessBoard::applyStandardSetup() { applyStandardSetupImpl(); }

std::vector<BoardMove> ChessBoard::getLegalMoves(Color color) const { return getLegalMovesImpl(color); }
std::vector<BoardMove> ChessBoard::getCapturingMoves(Color color) const { return getCapturingMovesImpl(color); }
std::vector<BoardMove> ChessBoard::getCheckApplyingMoves(Color color) const { return getCheckApplyingMovesImpl(color); }
std::vector<BoardMove> ChessBoard::getCaptureAvoidingMoves(Color color) const { return getCaptureAvoidingMovesImpl(color); }

Color ChessBoard::getColorOne() const { return getColorOneImpl(); }
Color ChessBoard::getColorTwo() const { return getColorTwoImpl(); }
Color ChessBoard::oppositeColor(Color color) const { return oppositeColorImpl(color); }

std::unique_ptr<BoardMove> ChessBoard::generateBoardMove(UserMove const &userMove) const { return generateBoardMoveImpl(userMove); }
BoardMove const& ChessBoard::getLastMadeMove() const { return getLastMadeMoveImpl(); }
std::vector<BoardMove> const& ChessBoard::getAllMadeMoves() const { return getAllMadeMovesImpl(); }
bool ChessBoard::hasMoveBeenMade() const { return hasMoveBeenMadeImpl(); }
void ChessBoard::makeMove(BoardMove const &move) { makeMoveImpl(move); }
bool ChessBoard::undoMove() { return undoMoveImpl(); }
bool ChessBoard::redoMove() { return redoMoveImpl(); }

int ChessBoard::getNumRows() const { return getNumRowsImpl(); }
int ChessBoard::getNumCols() const { return getNumColsImpl(); }

bool ChessBoard::isInCheck(Color color) const { return isInCheckImpl(color); }
bool ChessBoard::isInCheckMate(Color color) const { return isInCheckMateImpl(color); }
bool ChessBoard::isInStaleMate(Color color) const { return isInStaleMateImpl(color); }
bool ChessBoard::isInStaleMate() const { return isInStaleMateImpl(); }
bool ChessBoard::hasGameFinished() const { return hasGameFinishedImpl(); }
bool ChessBoard::isBoardInValidState() const { return isBoardInValidStateImpl(); }
