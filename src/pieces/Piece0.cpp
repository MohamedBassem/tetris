#include "Piece0.h"

Piece0::Piece0(int i,int j){
  this->posi = i;
  this->posj = j;
  color = Color(0,235,235);
}

Piece0::Piece0(){
}

std::vector< std::vector<Color> > Piece0::getPieceShape(){
  int shape[1][4] = {
    {1,1,1,1}

  };
  std::vector< std::vector<Color> > p;
  for(int i=0;i<1;i++){
    p.push_back( std::vector<Color>() );
    for(int j=0;j<4;j++){
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
