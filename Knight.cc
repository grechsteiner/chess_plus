// Knight.cc

#include <vector>
#include <cassert>

#include "Constants.h"
#include "Knight.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "FullMove.h"

std::vector<std::pair<int, int>> const Knight::knightDirections = { 
    {-1, -2}, 
    {-1, 2}, 
    {1, -2}, 
    {1, 2}, 
    {-2, -1}, 
    {-2, 1}, 
    {2, -1}, 
    {2, 1} 
};

Knight::Knight(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore) :
    Piece(pieceColor, PieceType::KNIGHT, pieceDirection, hasMoved, "♞", "N", pieceScore) {}

std::vector<FullMove> Knight::getMovesImplementation(ChessBoard const &board, int pieceRow, int pieceCol, bool attackingMoves) const {
    std::vector<FullMove> moves;
    for (std::pair<int, int> const &knightDirection : knightDirections) {
        int newRow = pieceRow + knightDirection.first;
        int newCol = pieceCol + knightDirection.second;
        if (board.isEmptySquareOrOpposingColorOnBoard(newRow, newCol, pieceColor)) {
            moves.emplace_back(createFullMove(board, pieceRow, pieceCol, newRow, newCol, newRow, newCol, MoveType::STANDARD, true));
        }
    }
    return moves;
}
