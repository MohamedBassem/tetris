#include "Game.h"

Game::Game(){
  score = 0;
  currentPiece = getRandomPiece();
}

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
    fixCurrentPiece();
    currentPiece = getRandomPiece();
  }
}

void Game::fixCurrentPiece(){
  std::vector< std::vector<Color> > curr = currentPiece.getPieceShape();
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      if( !Color::isEmpty(curr[i][j]) ){
        board[currentPiece.posi + i][currentPiece.posj + j] = curr[i][j];
      }
    }
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

std::vector< std::vector<Color> > Game::getBoard(){
  std::vector< std::vector<Color> > ret;
  ret.resize(height);
  for(int i=0;i<height;i++){
    ret[i].resize(width);
    for(int j=0;j<width;j++)
      ret[i][j] = board[i][j];
  }
  return ret;
}

Piece Game::getRandomPiece(){
  return Piece(0,5);
}

bool Game::inBound(int i,int j){
  return i >= 0 && i < height && j >= 0 && j < width;
}

int Game::getScore(){
  return score;
}
