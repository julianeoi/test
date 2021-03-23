#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
//quand on appuie lancer les fct aussi


//premier menu 
#define OPTION_0 "addition\n"
#define OPTION_1 "reste\n"

int somme(void) {
  int a,b;
  printf("rentrer la valeur de a: ");
  scanf("%d",&a);
  printf("rentrer la valeur de b:");
  scanf("%d",&b);
  int s = a+b;
  printf("la somme est %d",s);
  return s;
}

int reste(void) {
  int a,b;
  printf("rentrer la valeur de a");
  scanf("%d",&a);
  printf("rentrer la valeur de b");
  scanf("%d",&b);
  int r = a%b;
  printf("le reste est %d",r);
  return r;
}


const char *option_name[3]={OPTION_0,OPTION_1,NULL}; //NULL , condition d'arret 
const int (*p[2])()={&somme,&reste};


int	display_menu()
{
  int	touche; 
  int	selected_option;

  selected_option = 0;
  while (touche != 10 && touche != 27)
    {
      clear();
      
      attron(A_BOLD | A_UNDERLINE);
      printw("Select an option:\n");
      attroff(A_BOLD | A_UNDERLINE);
      
      for (int i= 0; option_name[i]; i++)
	{
	  if (i == selected_option)
	    {
	      attron(A_REVERSE);
	      printw(option_name[i]);
	      attroff(A_REVERSE);
	    }
	  else
	    printw(option_name[i]);
	}
      
      refresh();
      touche = getch();

      if (touche == KEY_UP && selected_option > 0)
	selected_option--;
      if (touche == KEY_DOWN && selected_option < 1)
	selected_option++;
    }

  if (touche == 27)
    return -1;
  
  return selected_option;
}

int	main()
{
  int	result;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  result = display_menu(); //retourne l'indice de la fct à utiliser
  clear();
  printw("Press any key to continue ...\n");
  refresh();
  getch();
  endwin();
  p[result](); //apelle la fct
  return 0;
}
