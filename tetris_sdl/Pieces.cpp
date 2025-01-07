#include "Pieces.h"

// Pieces definition
char mPieces[7][4][5][5] = {
    // Square
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        }
    },
    // I
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },
    // L
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },
    // Additional pieces (L mirrored, N, N mirrored, T) follow the same structure
    {
        // ...
    }
};

// Initial positions of the pieces
int mPiecesInitialPosition[7][4][2] = {
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    },
    {
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}
    },
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    {
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}
    },
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    }
};

// Return the type of a block
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY) {
    return mPieces[pPiece][pRotation][pX][pY];
}

// Return the horizontal displacement
int Pieces::GetXInitialPosition(int pPiece, int pRotation) {
    return mPiecesInitialPosition[pPiece][pRotation][0];
}

// Return the vertical displacement
int Pieces::GetYInitialPosition(int pPiece, int pRotation) {
    return mPiecesInitialPosition[pPiece][pRotation][1];
}
