// BoardMove.h

#ifndef BoardMove_h
#define BoardMove_h

#include "Constants.h"
#include "UserMove.h"


class ChessBoard;


class BoardMove {

private:
    int fromRow, toRow, captureRow;     // 0: top row
    int fromCol, toCol, captureCol;     // 0: leftmost col

    // General Info
    MoveType moveType;
    bool isAttackingMove;
    PieceType promotionPieceType;

    // Moved Piece Info (needed for undoing promotion of non pawn)
    bool hasMoved;
    PieceType pieceType;
    int pieceScore;

    // Captured Piece Info
    Color capturedColor;
    PieceType capturedPieceType;
    PieceDirection capturedPieceDirection;
    bool capturedHasMoved;
    int capturedPieceScore;

    // Logic is exact same for move & undo except for setting hasMoved
    void performRookCastle(ChessBoard &board, bool isUndo) const;

public:

    BoardMove(int fromRow, int fromCol, int toRow, int toCol, int captureRow, int captureCol, 
            MoveType moveType, bool isAttackingMove, PieceType promotionPieceType,
            bool hasMoved, PieceType pieceType, int pieceScore,
            Color capturedColor, PieceType capturedPieceType, PieceDirection capturedPieceDirection, bool capturedHasMoved, int capturedPieceScore);

   static const BoardMove DEFAULT;

    BoardMove(BoardMove const &other) = default;
    BoardMove(BoardMove &&other) = default;
    BoardMove& operator=(const BoardMove& other) = default;
    BoardMove& operator=(BoardMove&& other) = default;
    ~BoardMove() = default;

    bool operator==(BoardMove const &other) const;
        
    std::string toString() const;

    // Commands
    void makeMove(ChessBoard &board) const;
    void undoMove(ChessBoard &board) const;


    /* Getters */
    // TODO: Probably don't need all of these, if any
    
    // Squares
    int getFromRow() const;
    int getToRow() const;
    int getCaptureRow() const;
    int getFromCol() const;
    int getToCol() const;
    int getCaptureCol() const;

    // General Info
    MoveType getMoveType() const;
    bool getIsAttackingMove() const;
    PieceType getPromotionPieceType() const;

    // Moved Piece Info
    bool getHasMoved() const;
    PieceType getPieceType() const;
    int getPieceScore() const;

    // Captured Piece Info
    Color getCapturedColor() const;
    PieceType getCapturedPieceType() const;
    PieceDirection getCapturedPieceDirection() const;
    bool getCapturedHasMoved() const;
    int getCapturedPieceScore() const;
};

#endif /* BoardMove */
