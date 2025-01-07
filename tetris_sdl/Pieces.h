#ifndef _PIECES_
#define _PIECES_

// Class for Tetris pieces and their properties
class Pieces {
public:
    int GetBlockType(int pPiece, int pRotation, int pX, int pY);
    int GetXInitialPosition(int pPiece, int pRotation);
    int GetYInitialPosition(int pPiece, int pRotation);
};

#endif // _PIECES_
