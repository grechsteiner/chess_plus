// Bishop.cc

#include <vector>
#include <cassert>

#include "Constants.h"
#include "Bishop.h"
#include "BoardPieceInterface.h"
#include "Piece.h"
#include "Move.h"

std::vector<std::pair<int, int>> const Bishop::bishopDirections = { 
    {-1, -1},  
    {-1, 1}, 
    {1, -1}, 
    {1, 1} 
};

Bishop::Bishop(Color pieceColor, PieceDirection pieceDirection, bool hasMoved, int pieceScore) :
    Piece(pieceColor, PieceType::BISHOP, pieceDirection, hasMoved, "♝", "B", pieceScore) {}

std::vector<Move> Bishop::getMovesImplementation(BoardPieceInterface const &board, int pieceRow, int pieceCol, bool attackingMoves) const {
    std::vector<Move> moves;
    for (std::pair<int, int> const &bishopDirection : bishopDirections) {
        int newRow = pieceRow + bishopDirection.first;
        int newCol = pieceCol + bishopDirection.second;
        while (board.isEmptySquareOrOpposingColorOnBoard(newRow, newCol, pieceColor)) {
            moves.emplace_back(Move(board.getNumRows(), pieceRow, pieceCol, newRow, newCol));

            // If we ran into a piece of the opposite color, don't look past it
            if (board.isOpposingColorOnBoard(newRow, newCol, pieceColor)) {
                break;
            }
            
            // Keep incrementing
            newRow += bishopDirection.first;
            newCol += bishopDirection.second;
        }
    }
    return moves;
}
