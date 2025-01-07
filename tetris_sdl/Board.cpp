// Includes

#include "Board.h"

// Init
Board::Board (Pieces *pPieces, int pScreenHeight) {
    // Get the screen height
    mScreenHeight = pScreenHeight;

    // Get the pointer to the pieces class
    mPieces = pPieces;

    // Initialize the board blocks with free positions
    InitBoard();
}

// Initialize the board blocks with free positions
void Board::InitBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            mBoard[i][j] = POS_FREE;
        }
    }
}

// Store a piece in the board by filling the blocks
// Parameters:
// pX: Horizontal position in blocks
// pY: Vertical position in blocks
// pPiece: Piece to draw
// pRotation: One of the 4 possible rotations
void Board::StorePiece (int pX, int pY, int pPiece, int pRotation) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
                mBoard[i1][j1] = POS_FILLED;
            }
        }
    }
}

// Check if the game is over because a piece has reached the upper position
// Returns true or false
bool Board::IsGameOver() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (mBoard[i][0] == POS_FILLED) {
            return true;
        }
    }
    return false;
}

// Delete a line of the board by moving all above lines down
// Parameters:
// pY: Vertical position in blocks of the line to delete
void Board::DeleteLine (int pY) {
    for (int j = pY; j > 0; j--) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            mBoard[i][j] = mBoard[i][j - 1];
        }
    }
}

// Delete all the lines that should be removed
void Board::DeletePossibleLines() {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while (i < BOARD_WIDTH) {
            if (mBoard[i][j] != POS_FILLED) {
                break;
            }
            i++;
        }
        if (i == BOARD_WIDTH) {
            DeleteLine(j);
        }
    }
}

// Returns true if the block at the given position is free, false otherwise
// Parameters:
// pX: Horizontal position in blocks
// pY: Vertical position in blocks
bool Board::IsFreeBlock (int pX, int pY) {
    return mBoard[pX][pY] == POS_FREE;
}

// Returns the horizontal position (in pixels) of the block given as a parameter
// Parameters:
// pPos: Horizontal position of the block in the board
int Board::GetXPosInPixels (int pPos) {
    return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE);
}

// Returns the vertical position (in pixels) of the block given as a parameter
// Parameters:
// pPos: Horizontal position of the block in the board
int Board::GetYPosInPixels (int pPos) {
    return (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE);
}

// Check if the piece can be stored at this position without any collision
// Returns true if the movement is possible, false otherwise
// Parameters:
// pX: Horizontal position in blocks
// pY: Vertical position in blocks
// pPiece: Piece to draw
// pRotation: One of the 4 possible rotations
bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (i1 < 0 || i1 >= BOARD_WIDTH || j1 >= BOARD_HEIGHT) {
                if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
                    return false;
                }
            } else if (j1 >= 0 && mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0 && !IsFreeBlock(i1, j1)) {
                return false;
            }
        }
    }
    return true;
}
