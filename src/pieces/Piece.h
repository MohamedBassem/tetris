#ifndef _Piece
#define _Piece
#include <vector>
#include "../Color.h"

class Piece{
  
  public:
    int posi;
    int posj;
    int orientation;
    Color color;

    Piece(int i,int j);
    Piece();
    virtual std::vector< std::vector<Color> > getPieceShape() = 0;
    static std::vector< std::vector<Color> > rotatePieceClockwise( std::vector< std::vector<Color> > curr);
    void rotateAntiClockwise();
    void rotateClockwise();
};
#endif
