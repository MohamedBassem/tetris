#include "Piece.h"
#include <iostream>

using namespace std;

int shape[2][4] = {
  {0,0,0,0},
  {1,1,1,1}
};

Piece::Piece(int i,int j){
  this->posi = i;
  this->posj = j;
}

std::vector< std::vector<Color> > Piece::getPieceShape(){
  std::vector< std::vector<Color> > p;
  for(int i=0;i<2;i++){
    p.push_back( std::vector<Color>() );
    for(int j=0;j<4;j++){
      if( shape[i][j] == 0 ){
        p[i].push_back(Color(-1,-1,-1));
      }else{
        p[i].push_back(color);
      }
    }
  }
  return p;
}
