// Player.h

#ifndef Player_h
#define Player_h

#include <memory>


#include "Constants.h"
#include "ComputerPlayer.h"


struct Player final {
private:
    Team team;
    std::unique_ptr<ComputerPlayer> computerPlayer;
public:
    Player(Team team, std::unique_ptr<ComputerPlayer> const &computerPlayer);
    Player(Player const &other);
    Player(Player &&other) noexcept;
    Player& operator=(Player &other);
    Player& operator=(Player &&other) noexcept;
    virtual ~Player() = default;

    Team getTeam() const;
    std::unique_ptr<ComputerPlayer> const& getComputerPlayer() const;
    void setComputerPlayer(std::unique_ptr<ComputerPlayer> const &computerPlayer);
};


#endif /* Player_h */