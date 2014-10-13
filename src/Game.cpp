#include "Game.h"

//Game::Game(){
  ////currentPiece = getRandomPiece();
//}

void Game::stepRight(){
  std::vector< std::vector<Color> > curr = currentPiece.getPieceShape();
  if( inBound(currentPiece.posi, currentPiece.posj + curr[0].size() + 1) ){
    currentPiece.posj++;
  }
}

void Game::stepLeft(){
  if(inBound( currentPiece.posi, currentPiece.posj - 1) ){
    currentPiece.posj--;
  }
}

void Game::stepDown(){
  if( checkDown() ){
    currentPiece.posi++;
  }else{
    currentPiece = getRandomPiece();
  }
}

bool Game::checkDown(){
  std::vector< std::vector<Color> > curr = currentPiece.getPieceShape();
  bool can = true;
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      if( i+1 == (int) curr.size() || Color::isEmpty(curr[i+1][j]) ){
        int newI = currentPiece.posi + i + 1;
        int newJ = currentPiece.posj + j;
        can &= inBound(newI, newJ) && Color::isEmpty(board[newI][newJ]);
      }
    }
  }
  return can;
}

Piece getRandomPiece(){
  return Piece(0,5);
}

bool Game::inBound(int i,int j){
  return i >= 0 && i < height && j >= 0 && j < width;
}

int Game::getScore(){
  return score;
}
