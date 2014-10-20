#ifndef _Piece4
#define _Piece4
#include "Piece.h"

class Piece4 : public Piece{
  
  public:
  Piece4(int i,int j);
  Piece4();

  std::vector< std::vector<Color> > getPieceShape();

};
#endif
