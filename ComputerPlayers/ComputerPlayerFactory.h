// ComputerPlayerFactory.h

#ifndef ComputerPlayerFactory_h
#define ComputerPlayerFactory_h

#include <memory>

#include "ComputerPlayer.h"
#include "ChessBoard.h"
#include "Constants.h"


class ComputerPlayerFactory final {
public:
    static std::unique_ptr<ComputerPlayer> createComputerPlayer(ComputerPlayerLevel computerPlayerLevel, Team team);
};


#endif /* ComputerPlayerFactory_h */
