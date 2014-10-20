#ifndef _Piece2
#define _Piece2
#include "Piece.h"

class Piece2 : public Piece{
  
  public:
  Piece2(int i,int j);
  Piece2();

  std::vector< std::vector<Color> > getPieceShape();

};
#endif
