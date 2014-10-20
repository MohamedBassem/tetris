#ifndef _Piece6
#define _Piece6
#include "Piece.h"

class Piece6 : public Piece{
  
  public:
  Piece6(int i,int j);
  Piece6();

  std::vector< std::vector<Color> > getPieceShape();

};
#endif
