#ifndef _Piece3
#define _Piece3
#include "Piece.h"

class Piece3 : public Piece{
  
  public:
  Piece3(int i,int j);
  Piece3();

  std::vector< std::vector<Color> > getPieceShape();

};
#endif
