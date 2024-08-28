// Game.h

#ifndef Game_h
#define Game_h

#include <iostream>
#include <memory>
#include <utility>
#include <tuple>

#include "Constants.h"
#include "Subject.h"
#include "Board.h"
#include "Input.h"
#include "ErrorReporter.h"
#include "ComputerPlayer.h"
#include "BoardDisplayInterface.h"
#include "BoardGameInterface.h"

// (Color, totalScore, ComputerPlayer)
using PlayerTuple = std::tuple<Color, double, std::unique_ptr<ComputerPlayer>>;

class Game : public Subject {
private:
    std::unique_ptr<Input> input;
    std::unique_ptr<ErrorReporter> errorReporter;
    std::ostream &out;

    GameState gameState = GameState::MAIN_MENU;
    BoardGameInterface &board;

    bool showingStandardOpenings = false;

    std::tuple<PlayerTuple, PlayerTuple> players = std::make_tuple(
        std::make_tuple(Color::WHITE,  0,  nullptr),
        std::make_tuple(Color::BLACK,  0,  nullptr));
    

    void outputError(std::string const &errorMessage) const;
    int currentTurn = 0;
    void incrementTurn();
    void decrementTurn();

    void resetComputerPlayers();
    void applyStalematePoints();
    void applyWinPoints(Color color);

    PlayerTuple& getPlayerWithTurn(int i);

    void setGameState(GameState newGameState);
    bool isInMainMenu() const;
    bool isInSetupMode() const;
    bool isGameActive() const;

public:
    Game(BoardGameInterface &board, std::istream &in, std::ostream &out, std::ostream &errorOut);
    void runGame();


    // Get state (observer pattern)
    GameState getGameState() const;
    const std::tuple<PlayerTuple, PlayerTuple>& getMainMenuState() const;
    std::tuple<const BoardDisplayInterface&, const std::tuple<PlayerTuple, PlayerTuple>&, int> getSetupState() const;
    std::tuple<const BoardDisplayInterface&, const std::tuple<PlayerTuple, PlayerTuple>&, int, bool> getActiveGameState() const;
};

#endif /* Game_h */
