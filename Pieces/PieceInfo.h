// PieceInfo.h

#ifndef PieceInfo_h
#define PieceInfo_h

#include <string>

#include "Constants.h"
#include "PieceData.h"


/**
 * PieceInfo Struct
 * Represents all the info pertaining to a piece
 */
struct PieceInfo final {
    PieceData pieceData;
    int pieceScore;
    std::string image;
    std::string display;

    explicit PieceInfo(PieceData const &pieceData, int pieceScore, std::string const &image, std::string const &display);
    PieceInfo(PieceInfo const &other) = default;
    PieceInfo(PieceInfo &&other) noexcept;
    PieceInfo& operator=(const PieceInfo& other) = default;
    PieceInfo& operator=(PieceInfo&& other) noexcept;
    ~PieceInfo() = default;

    bool operator==(PieceInfo const &other) const;
};


#endif /* PieceInfo_h */