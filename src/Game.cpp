#include "Game.h"
#include <cstdio>
#include <stdlib.h>

Game::Game(){
  score = 0;
  currentPiece = getRandomPiece();
  for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
      board[i][j] = Color(-1,-1,-1);
  _isGameOver = false;
}

void Game::stepRight(){
  if( isGameOver() ) return;
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  if( inBound(currentPiece->posi, currentPiece->posj + curr[0].size()) ){
    currentPiece->posj++;
    if( isIntersect() )
      currentPiece->posj--;
  }
}

void Game::stepLeft(){
  if( isGameOver() ) return;
  if(inBound( currentPiece->posi, currentPiece->posj - 1) ){
    currentPiece->posj--;
    if( isIntersect() )
      currentPiece->posj++;
  }
}

void Game::rotateRight(){
  if( isGameOver() ) return;
  currentPiece->rotateClockwise();
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  if( !inBound(currentPiece->posi, currentPiece->posj + curr[0].size() + 1) ){
    currentPiece->rotateAntiClockwise();
    return;
  }

  bool can = true;
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      int newI = currentPiece->posi + i;
      int newJ = currentPiece->posj + j;
      can &= inBound(newI, newJ) && Color::isEmpty(board[newI][newJ]);
    }
  }
  if(!can){
    currentPiece->rotateAntiClockwise();
  }
}


void Game::rotateLeft(){
  if( isGameOver() ) return;
  currentPiece->rotateAntiClockwise();
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  if( !inBound(currentPiece->posi, currentPiece->posj + curr[0].size() + 1) ){
    currentPiece->rotateClockwise();
    return;
  }

  bool can = true;
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      int newI = currentPiece->posi + i;
      int newJ = currentPiece->posj + j;
      can &= inBound(newI, newJ) && Color::isEmpty(board[newI][newJ]);
    }
  }
  if(!can){
    currentPiece->rotateClockwise();
  }
}

void Game::stepDown(){
  if( isGameOver() ) return;
  if( checkDown() ){
    currentPiece->posi++;
  }else{
    fixCurrentPiece();
    removeFullRows();
    currentPiece = getRandomPiece();
    _isGameOver = !checkDown();
  }
}

void Game::fixCurrentPiece(){
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      if( !Color::isEmpty(curr[i][j]) ){
        board[currentPiece->posi + i][currentPiece->posj + j] = curr[i][j];
      }
    }
  }
}

bool Game::checkDown(){
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  bool can = true;
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      if( !Color::isEmpty(curr[i][j]) && (i+1 == (int) curr.size() || Color::isEmpty(curr[i+1][j])) ){
        int newI = currentPiece->posi + i + 1;
        int newJ = currentPiece->posj + j;
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
    for(int j=0;j<width;j++){
      ret[i][j] = board[i][j];
    }
  }

  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      if( !Color::isEmpty(curr[i][j]) ){
        ret[currentPiece->posi + i][currentPiece->posj + j] = curr[i][j];
      }
    }
  }
  return ret;
}

void Game::removeFullRows(){
  int removed = 0;
  for(int i=height-1;i>=0;i--){
    bool full = true;
    for(int j=0;j<width;j++)
      full &= !Color::isEmpty(board[i][j]);
    if(full){
      removed ++;
      for(int j=i;j>0;j--)
        for(int k=0;k<width;k++)
          board[j][k] = board[j-1][k];
      i++;
    }
  }
  score += removed*10;
}

Piece* Game::getRandomPiece(){
  int pieceType = rand()%6;
  int starti=1,startj=width/2 - 2;
  switch(pieceType){
    case 0: return new Piece0(starti,startj);
    case 1: return new Piece1(starti,startj);
    case 2: return new Piece2(starti,startj);
    case 3: return new Piece3(starti,startj);
    case 4: return new Piece4(starti,startj);
    case 5: return new Piece5(starti,startj);
    case 6: return new Piece6(starti,startj);
  }
  return new Piece0(0,5);
}

bool Game::inBound(int i,int j){
  return i >= 0 && i < height && j >= 0 && j < width;
}

int Game::getScore(){
  return score;
}

bool Game::isGameOver(){
  return _isGameOver;
}

bool Game::isIntersect(){
  std::vector< std::vector<Color> > curr = currentPiece->getPieceShape();
  bool intersect = false;
  for(int i=0;i<(int)curr.size();i++){
    for(int j=0;j<(int)curr[i].size();j++){
      int newI = currentPiece->posi + i;
      int newJ = currentPiece->posj + j;
      intersect |= (!Color::isEmpty(curr[i][j]) && !Color::isEmpty(board[newI][newJ]));
    }
  }
  return intersect;
}

int Game::getWidth(){
  return width;
}

int Game::getHight(){
  return height;
}
