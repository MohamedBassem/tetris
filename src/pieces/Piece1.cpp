#include "Piece1.h"

Piece1::Piece1(int i,int j){
  this->posi = i;
  this->posj = j;
  color = Color(0,0,240);
}

Piece1::Piece1(){
}

std::vector< std::vector<Color> > Piece1::getPieceShape(){
  int shape[2][3] = {
    {1,0,0},
    {1,1,1}
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
