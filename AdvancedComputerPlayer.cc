// AdvancedComputerPlayer.cc

#include <random>
#include <vector>
#include <tuple>
#include <algorithm>

#include "AdvancedComputerPlayer.h"
#include "MoveShuffler.h"


FullMove AdvancedComputerPlayer::getMoveImplementation(BoardComputerInterface &board, Color color) const {
    return std::get<1>(alphaBetaSearch(board, depth, color, 1000, -1000));
}

std::tuple<int, FullMove> AdvancedComputerPlayer::alphaBetaSearch(BoardComputerInterface &board, int currentDepth, Color color, int beta, int alpha) const {

    if (currentDepth == 0) {
        if (board.isInStaleMate(color)) {
            return std::make_tuple(0, FullMove::DEFAULT);
        }
        return std::make_tuple(board.getAlphaBetaBoardScore(color), FullMove::DEFAULT);
    }

    int bestScore = (color == board.getColorOne()) ? -10000 : 10000;
    FullMove bestMove = FullMove::DEFAULT;
    std::vector<FullMove> allMoves = board.getLegalMoves(color);
    allMoves = rank_moves(board, allMoves);
    if (color == board.getColorOne()) {
        for (FullMove const &move : allMoves) {
            board.makeMove(move);
            int currentScore = std::get<0>(alphaBetaSearch(board, currentDepth - 1, board.oppositeColor(color), beta, alpha));
            board.undoMove();   
            if (currentScore > bestScore) {
                bestScore = currentScore;
                bestMove = move;
            }
            if (bestScore >= beta) {
                break;
            } else if (bestScore > alpha) {
                alpha = bestScore;
            }
        }

    } else {
        for (FullMove const &move : allMoves) {
            board.makeMove(move);
            int currentScore = std::get<0>(alphaBetaSearch(board, currentDepth - 1, board.oppositeColor(color), beta, alpha));
            board.undoMove();    
            if (currentScore < bestScore) {
                bestScore = currentScore;
                bestMove = move;
            }
            if (bestScore <= alpha) {
                break;
            } else if (bestScore < beta) {
                beta = bestScore;
            }
            
        }
    }

    if (bestScore == 10000 || bestScore == -10000) {
        if (board.isInStaleMate(color)) {
            return std::make_tuple(0, FullMove::DEFAULT);
        }
        return std::make_tuple(board.getAlphaBetaBoardScore(color), FullMove::DEFAULT);
    }

    return std::make_tuple(bestScore, bestMove);
}

struct ScoredMove {
    FullMove move;
    int score;

    ScoredMove(const FullMove& m, int s) : move(m), score(s) {}
};

std::vector<FullMove> AdvancedComputerPlayer::rank_moves(BoardComputerInterface& board, const std::vector<FullMove>& moves) const {
    std::vector<ScoredMove> scored_moves;

    // Assign values to each move
    for (const auto& move : moves) {
        int score = 0;
        score += board.getPieceAt(move.getCaptureRow(), move.getCaptureCol()).getPieceScore();
        scored_moves.emplace_back(move, score);
    }

    // Sort moves by score in descending order
    std::sort(scored_moves.begin(), scored_moves.end(), [](const ScoredMove& a, const ScoredMove& b) {
        return a.score > b.score;
    });

    // Randomize moves with the same score
    std::vector<FullMove> final_list;
    int current_value = scored_moves[0].score;
    std::vector<ScoredMove> temp_list;

    std::random_device rd;
    std::mt19937 g(rd());

    for (const auto& scored_move : scored_moves) {
        if (scored_move.score != current_value) {
            std::shuffle(temp_list.begin(), temp_list.end(), g);
            for (const auto& temp_move : temp_list) {
                final_list.push_back(temp_move.move);
            }

            current_value = scored_move.score;
            temp_list.clear();
        }
        temp_list.push_back(scored_move);
    }

    // Shuffle and add the last set of moves
    std::shuffle(temp_list.begin(), temp_list.end(), g);
    for (const auto& temp_move : temp_list) {
        final_list.push_back(temp_move.move);
    }

    return final_list;
}
