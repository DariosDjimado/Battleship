#include <iostream>
#include "CImg.h"
#include "Bateau.h"

using namespace std;
using namespace cimg_library;

int main() {

// Usefull colors
unsigned char
  grid_color[3]={0,0,255},
  play1_color[3]={204,0,0},
  play2_color[3]={0,102,0};
  
// Declare an image to draw the grid
  CImg<unsigned char> grid(1050,600,1,3,255);
  
  for (int i = 0; i < 2;i++) grid.draw_line(0, 50 * i, 400, 50 * i, grid_color);
  for (int i = 1; i < 5; i++) grid.draw_line(100*i, 0,100*i , 50, grid_color);

  for (int i = 2; i < 13; i++) grid.draw_line(0, 50 * i, 500, 50 * i, grid_color);
  for (int i = 2; i < 13; i++) grid.draw_line(550, 50 * i, 1050, 50 * i, grid_color);
  for (int j = 1; j < 21; j++) grid.draw_line(50 * j, 100, 50 * j,600, grid_color);
 
  
// Declare a display to draw the scene
  CImgDisplay disp(grid,"Bataille Navale",0,false,false);

// Center the window on the screen
   disp.move((CImgDisplay::screen_width() - disp.width())/2,

            (CImgDisplay::screen_height() - disp.height())/2);

// Declare an image to display the scene
CImg<unsigned char> scene=grid;
// Usefull variables
int player=1;
int table[10][10];
for (int i = 0; i < 10; i++)
{
	for (int j = 0; i < 10; i++)
	{
		table[i][j] = 0;
	}
}


Grille grille;
Bateau bateauJoueur_1(&grille,0,0,4);
Bateau bateauJoueur_2(&grille,2,2,4);
Bateau bateauJoueur_3(&grille,1,4);
Bateau bateauJoueur_4(&grille,5,5,4,false);
Bateau bateauJoueur_5(&grille,2,0,4,false);
Bateau bateauJoueur_6(&grille,5,9,4,false);
grille.afficher();
for (int i = 0; i < 10; i++)
{
	for (int j = 0; j < 10; j++)
	{
		if (grille.getCaseValue(i,j)==1)scene.draw_circle(j * 50 + 25, (i+2) * 50 + 25, 25, play1_color, 1, ~0U);
	}
}

// Main loop, exit if the display window is closed or if ESC or Q key is hit
  while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {
    
    // Display the scene
    scene.display(disp);
    
    // Detect mouse click
    if (disp.button()&1) { // Left button clicked.
      int i=12*disp.mouse_y()/disp.height();
      int j=21*disp.mouse_x()/disp.width();
      
	  cout << "i  " << i << endl;
	  cout << "j  " << j << endl;
	  if (grille.tirer(i - 2, j))
	  {
		  scene.draw_line(j * 50, i * 50, j * 50 + 50, i * 50 + 50, play1_color);
		  scene.draw_line(j * 50 + 50, i * 50, j * 50, i * 50 + 50, play1_color);
	  }
	  

	  //scene.draw_circle(j*50+25, i*50+25, 25, play1_color, 1, ~0U);
    }
    disp.wait();
    
    // Handle window resize
    if (disp.is_resized()) disp.resize();
    }
    
  return 0;
}
