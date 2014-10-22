#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include "src/Game.h"
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <GL/glut.h>

using namespace std;

const int blockSize = 40;
const int windowWidth = blockSize*10;
const int windowHeight = blockSize*15;

bool isPaused = false;
bool isStarted = false;
Game game;

void Display(void);
void specialInput(int,int,int);
void KeyboardInput(unsigned char,int,int);
void anim(int);
void print(int,int,char *);
void drawPauseSceen(string);

void Display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  
  // Print Board
  vector< vector<Color> > board = game.getBoard();
  for(int i=0;i<(int)board.size();i++){
    for(int j=0;j<(int)board[0].size();j++){
      if( Color::isEmpty(board[i][j]) ){
        glColor3d(0.2,0.2,0.2);
      }else{
        glColor3d(board[i][j].r/255.0,board[i][j].g/255.0,board[i][j].b/255.0);
      }
      glPushMatrix();

      glTranslated(j*blockSize,windowHeight - i*blockSize,0);
      glBegin(GL_QUADS);
      glVertex3d(0, 0, 0);
      glVertex3d(0, blockSize, 0);
      glVertex3d(blockSize, blockSize, 0);
      glVertex3d(blockSize, 0, 0);
      glEnd(); 
      glPopMatrix();
    }
  }

  // Print Score
  stringstream ss;
  ss << "Score : " << game.getScore();
  glColor3d(1,1,1);
  print( windowWidth - ss.str().size()*10, windowHeight - 25, (char *)ss.str().c_str() );
  

  if( isPaused ){
    drawPauseSceen("Paused");
  }

  if( !isStarted ){
    drawPauseSceen("Press S to start the game!");
  }

  if( game.isGameOver() ){
    stringstream ss;
    ss << "Your score is ";
    ss << game.getScore();
    ss << "! Press R to play again";
    drawPauseSceen(ss.str());
  }

  glPopMatrix();
  glFlush();
}

void drawPauseSceen(string text){
    glPushMatrix();
    glColor4d(0.5,0.5,0.5,0.9);
    glBegin(GL_QUADS);
    glVertex3d(0, 0, 0);
    glVertex3d(0, windowHeight, 0);
    glVertex3d(windowWidth, windowHeight, 0);
    glVertex3d(windowWidth, 0, 0);
    glEnd(); 
    glColor3d(0,0,0);
    int newX = (windowWidth - (text).size()*10)/2;
    print(newX,windowHeight/2, (char *)text.c_str());
    glPopMatrix();
}

void anim(int a){
  glutTimerFunc(1000,anim,0);
  if( isStarted && !isPaused && !game.isGameOver() ){
    game.stepDown();
    glutPostRedisplay();
  }
}

void specialInput(int thekey,int mouseX,int mouseY){
  if( !isStarted || isPaused ) return;
  switch(thekey){
    case GLUT_KEY_DOWN:
      game.stepDown();
      break;
    case GLUT_KEY_RIGHT:
      game.stepRight();
      break;
    case GLUT_KEY_LEFT:
      game.stepLeft();
      break;
  }
}


void KeyboardInput(unsigned char thekey,int mouseX,int mouseY){
  if( isStarted ){
    if( isPaused ){
      if( thekey == 'p' ){
        isPaused = false;
        anim(0);
      }
    }else{
      switch(thekey){
        case 'p':
          isPaused = true;
          break;
        case 'z':
          game.rotateLeft();
          break;
        case 'x':
          game.rotateRight();
          break;
        case 'l':
          game.stepRight();
          break;
        case 'h':
          game.stepLeft();
          break;
        case 'j':
          game.stepDown();
          break;
        case 'r':
          if(game.isGameOver()){
            game = Game();
            anim(0);
          }
          break;
      }
    }
  }else{
    if( thekey == 's' ){
      isStarted = true;
      anim(0);
    }
  }
  glutPostRedisplay();
}

void print(int x, int y, char *string){
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
  }
}

int main(int argc,char** argr){
  srand (time(NULL));

  game = Game();
  glutInit(&argc,argr);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(windowWidth,windowHeight);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Tetris");
  glutDisplayFunc(Display);
  glutSpecialFunc(specialInput);
  glutKeyboardFunc(KeyboardInput);
  glClearColor(0.0f,0.0f,0.2f,0.0f);
  gluOrtho2D(0.0,(double)windowWidth,0.0,(double) windowHeight);
  glutMainLoop();
}
