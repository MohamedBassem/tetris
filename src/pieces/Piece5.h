#ifndef _Piece5
#define _Piece5
#include "Piece.h"

class Piece5 : public Piece{
  
  public:
  Piece5(int i,int j);
  Piece5();
  
  std::vector< std::vector<Color> > getPieceShape();

};
#endif
