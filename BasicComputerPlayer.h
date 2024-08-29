// BasicComputerPlayer.h

#ifndef BasicComputerPlayer_h
#define BasicComputerPlayer_h

#include <vector>

#include "Constants.h"
#include "Board.h"
#include "FullMove.h"
#include "ComputerPlayer.h"

class BasicComputerPlayer : public ComputerPlayer {
private:
    FullMove getMoveImplementation(ChessBoard &board, Color color) const override;
    virtual std::vector<FullMove> getPossibleMoves(ChessBoard &board, Color color) const = 0;
public:
    BasicComputerPlayer();
    virtual ~BasicComputerPlayer() = default;
};


#endif /* BasicComputerPlayer_h */
