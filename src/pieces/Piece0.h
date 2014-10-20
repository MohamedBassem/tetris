#ifndef _Piece0
#define _Piece0
#include "Piece.h"

class Piece0 : public Piece{
  
  public:
  Piece0(int i,int j);
  Piece0();

  std::vector< std::vector<Color> > getPieceShape();
  

};
#endif
