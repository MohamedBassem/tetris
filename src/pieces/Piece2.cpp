#include "Piece2.h"

Piece2::Piece2(int i,int j){
  this->posi = i;
  this->posj = j;
  this->orientation = 0;
  color = Color(240,160,0);
}

Piece2::Piece2(){
}

std::vector< std::vector<Color> > Piece2::getPieceShape(){
  int shape[2][3] = {
    {0,0,1},
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
