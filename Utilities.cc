// Utilities.cc

#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

#include "Utilities.h"
#include "Constants.h"


std::optional<ComputerPlayerLevel> Utilities::stringToComputerPlayerLevel(std::string const &str) {
    static std::unordered_map<std::string, ComputerPlayerLevel> mapping = {
        { "1", ComputerPlayerLevel::ONE },
        { "2", ComputerPlayerLevel::TWO },
        { "3", ComputerPlayerLevel::THREE },
        { "4", ComputerPlayerLevel::FOUR },
        { "5", ComputerPlayerLevel::FIVE }
    };

    return mapping.find(str) != mapping.end()
        ? std::make_optional<ComputerPlayerLevel>(mapping[str])
        : std::nullopt;
}

std::optional<PlayerType> Utilities::stringToPlayerType(std::string const &str) {
    static std::unordered_map<std::string, PlayerType> mapping = {
        { "HUMAN", PlayerType::HUMAN },
        { "COMPUTER", PlayerType::COMPUTER }
    };

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    return mapping.find(str) != mapping.end()
        ? std::make_optional<PlayerType>(mapping[str])
        : std::nullopt;
}

std::optional<PieceType> Utilities::stringToPieceType(std::string const &str) {
    static std::unordered_map<std::string, PieceType> mapping = {
        { "P", PieceType::PAWN },
        { "R", PieceType::ROOK },
        { "N", PieceType::KNIGHT },
        { "B", PieceType::BISHOP },
        { "Q", PieceType::QUEEN },
        { "K", PieceType::KING }
    };

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    return mapping.find(str) != mapping.end()
        ? std::make_optional<PieceType>(mapping[str])
        : std::nullopt;
}

std::optional<PieceLevel> Utilities::stringToPieceLevel(std::string const &str) {
    static std::unordered_map<std::string, PieceLevel> mapping = {
        { "BASIC", PieceLevel::BASIC },
        { "ADVANCED", PieceLevel::ADVANCED }
    };

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    return mapping.find(str) != mapping.end()
        ? std::make_optional<PieceLevel>(mapping[str])
        : std::nullopt;
}

std::optional<PieceDirection> Utilities::stringToPieceDirection(std::string const &str) {
    static std::unordered_map<std::string, PieceDirection> mapping = {
        { "NORTH", PieceDirection::NORTH },
        { "SOUTH", PieceDirection::SOUTH },
        { "EAST", PieceDirection::EAST },
        { "WEST", PieceDirection::WEST }
    };

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    return mapping.find(str) != mapping.end()
        ? std::make_optional<PieceDirection>(mapping[str])
        : std::nullopt;
}
