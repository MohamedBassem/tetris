#include "Piece.h"

Piece::Piece(int i,int j){
  this->posi = i;
  this->posj = j;
}

Piece::Piece(){

}

void Piece::rotateClockwise(){
  this->orientation++;
  this->orientation %= 4;
}

void Piece::rotateAntiClockwise(){
  this->orientation--;
  this->orientation += 4;
  this->orientation %= 4;
}


std::vector< std::vector<Color> > Piece::rotatePieceClockwise( std::vector< std::vector<Color> > curr){
  std::vector< std::vector<Color> > ret = std::vector< std::vector<Color> >(curr[0].size());
  for(int j=0;j<curr[0].size();j++){
    for(int i=curr.size()-1;i >= 0;i--){
      ret[j].push_back(curr[i][j]);
    }
  }
  return ret;
}



