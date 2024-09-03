// LevelThreeComputer.cc

#include <vector>
#include <cassert>
#include <algorithm>

#include "LevelThreeComputer.h"
#include "Constants.h"

#include "Board.h"

LevelThreeComputer::LevelThreeComputer() : BasicComputerPlayer() {}

std::vector<BoardMove> LevelThreeComputer::getPossibleMoves(ChessBoard &board, Team team) const {

    std::vector<BoardMove> captureAvoidingMoves = board.generateCaptureAvoidingMoves(team);
    if (!captureAvoidingMoves.empty()) {
        std::vector<BoardMove> capturingMoves = board.generateCapturingMoves(team);
        std::vector<BoardMove> checkApplyMoves = board.generateCheckApplyingMoves(team);

        std::vector<BoardMove> topMoves;
        for (BoardMove const & move : captureAvoidingMoves) {
            if (std::find(capturingMoves.begin(), capturingMoves.end(), move) != capturingMoves.end()) {
                topMoves.push_back(move);
            }
        }

        for (BoardMove const & move : captureAvoidingMoves) {
            if (std::find(checkApplyMoves.begin(), checkApplyMoves.end(), move) != checkApplyMoves.end()) {
                if (std::find(topMoves.begin(), topMoves.end(), move) == topMoves.end()) {
                    topMoves.push_back(move);
                }
            }
        }

        return !topMoves.empty() ? topMoves : captureAvoidingMoves;
    }

    std::vector<BoardMove> moves = board.generateCapturingMoves(team);
    std::vector<BoardMove> checkApplyMoves = board.generateCheckApplyingMoves(team);
    moves.insert(moves.end(), checkApplyMoves.begin(), checkApplyMoves.end());
    return moves.empty() ? board.generateAllLegalMoves(team) : moves;
}
