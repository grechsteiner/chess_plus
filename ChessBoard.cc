// ChessBoard.cc

#include <vector>
#include <stack>
#include <optional>

#include "ChessBoard.h"
#include "Constants.h"
#include "BoardSquare.h"
#include "BoardMove.h"
#include "PieceInfo.h"


std::optional<PieceInfo> ChessBoard::getPieceInfoAt(BoardSquare const &boardSquare) const { return getPieceInfoAtImpl(boardSquare); }
std::vector<BoardSquare> ChessBoard::getAllBoardSquares() const { return getAllBoardSquaresImpl(); }

bool ChessBoard::isSquareOnBoard(BoardSquare const &boardSquare) const { return isSquareOnBoardImpl(boardSquare); }
bool ChessBoard::isSquareEmpty(BoardSquare const &boardSquare) const { return isSquareEmptyImpl(boardSquare); }
bool ChessBoard::isSquareSameTeam(BoardSquare const &boardSquare, Team ownTeam) const { return isSquareSameTeamImpl(boardSquare, ownTeam); }
bool ChessBoard::isSquareOtherTeam(BoardSquare const &boardSquare, Team ownTeam) const { return isSquareOtherTeamImpl(boardSquare, ownTeam); }
bool ChessBoard::isSquareAttacked(BoardSquare const &boardSquare, Team ownTeam) const { return isSquareAttackedImpl(boardSquare, ownTeam); }

bool ChessBoard::isInCheck(Team team) const { return isInCheckImpl(team); }
bool ChessBoard::isInCheckMate(Team team) const { return isInCheckMateImpl(team); }
bool ChessBoard::isInStaleMate(Team team) const { return isInStaleMateImpl(team); }

std::vector<BoardMove> ChessBoard::generateAllLegalMovesAtSquare(BoardSquare const &boardSquare) const { return generateAllLegalMovesAtSquareImpl(boardSquare); }
std::vector<BoardMove> ChessBoard::generateAllLegalMoves(Team team) const { return generateAllLegalMovesImpl(team); }
std::vector<BoardMove> ChessBoard::generateCapturingMoves(Team team) const { return generateCapturingMovesImpl(team); }
std::vector<BoardMove> ChessBoard::generateCheckApplyingMoves(Team team) const { return generateCheckApplyingMovesImpl(team); }
std::vector<BoardMove> ChessBoard::generateCaptureAvoidingMoves(Team team) const { return generateCaptureAvoidingMovesImpl(team); }

bool ChessBoard::setPosition(BoardSquare const &boardSquare, Team team, PieceType pieceType, PieceDirection pieceDirection, bool hasMoved, std::optional<int> pieceScore) { return setPositionImpl(boardSquare, team, pieceType, pieceDirection, hasMoved, pieceScore); }
bool ChessBoard::clearPosition(BoardSquare const &boardSquare) { return clearPositionImpl(boardSquare); }
void ChessBoard::clearBoard() { clearBoardImpl(); }

std::optional<BoardMove> ChessBoard::createBoardMove(BoardSquare const &fromSquare, BoardSquare const &toSquare, std::optional<PieceType> promotionPieceType) const { return createBoardMoveImpl(fromSquare, toSquare, promotionPieceType); }
bool ChessBoard::makeMove(BoardMove const &boardMove) { return makeMoveImpl(boardMove); }
bool ChessBoard::undoMove() { return undoMoveImpl(); }
bool ChessBoard::redoMove() { return redoMoveImpl(); }

std::optional<BoardMove> ChessBoard::getLastCompletedMove() const { return getLastCompletedMoveImpl(); }
std::stack<BoardMove> const& ChessBoard::getAllCompletedMoves() const { return getAllCompletedMovesImpl(); }

Team ChessBoard::getTeamOne() const { return getTeamOneImpl(); }
Team ChessBoard::getTeamTwo() const { return getTeamTwoImpl(); }

int ChessBoard::getNumRows() const { return getNumRowsImpl(); }
int ChessBoard::getNumCols() const { return getNumColsImpl(); }
