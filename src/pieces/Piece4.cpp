#include "Piece4.h"

Piece4::Piece4(int i,int j){
  this->posi = i;
  this->posj = j;
  this->orientation = 0;
  color = Color(0,240,0);
}

Piece4::Piece4(){
}

std::vector< std::vector<Color> > Piece4::getPieceShape(){
  int shape[2][3] = {
    {0,1,1},
    {1,1,0}
  };
  std::vector< std::vector<Color> > p;
  for(int i=0;i<2;i++){
    p.push_back( std::vector<Color>() );
    for(int j=0;j<3;j++){
      if( shape[i][j] == 0 ){
        p[i].push_back(Color(-1,-1,-1));
      }else{
        p[i].push_back(color);
      }
    }
  }
  int tmp = orientation;
  while(tmp--){
    p = Piece::rotatePieceClockwise(p);
  }
  return p;
}
