#ifndef _Piece1
#define _Piece1
#include "Piece.h"

class Piece1 : public Piece{
  
  public:
  Piece1(int i,int j);
  Piece1();

  std::vector< std::vector<Color> > getPieceShape();

};
#endif
