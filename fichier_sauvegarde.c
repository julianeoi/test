//crée un fichier ds un dossier spécifique 
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>


typedef struct personnage{
	char name[64];
	char couleur;
	int tresor;
}Personnage; 


void			display_string_prompt(const char *prompt, char *buffer, int len_buffer)
{
  clear();
  attron(A_BOLD | A_UNDERLINE);
  printw(prompt);
  attroff(A_BOLD | A_UNDERLINE);
  refresh();

  nocbreak();
  echo();

  getnstr(buffer, len_buffer);
  
  cbreak();
  noecho();
}

void	 init_display()
{
  // Init ncurses display
  initscr();
  // Raw mode
  cbreak();
  // Entered key isn't printed
  noecho();
  // Activates special keys and function key 
  keypad(stdscr, TRUE);
  // Activates colors
  start_color();
}

int	close_display()
{
  endwin();
  return EXIT_SUCCESS;
}



int creer(Personnage *perso1, Personnage *perso2){
	char filename[64]; //nom du fichier de sauvegarde 
	char *path; //chemin du fichier de sauvegarde 
	FILE *fp; //pointeur pour remplir le fichier  
	display_string_prompt("saisir le nom de sauvegarde",filename,63);// ecrit une chaine au clavier et on la met ds filenanme 
	asprintf(&path,"saves/%s.got",filename); //on met le chemin du fichier de sauvegarde 
	fp = fopen(path,"w");
	for (int i=0 ; i<2 ; i++){
		if (i==0){
			fprintf(fp, "%s %c %d\n",perso1->name , perso1->couleur , perso1->tresor);
		}
		else{
			fprintf(fp, "%s %c %d\n",perso2->name , perso2->couleur , perso2->tresor);
		}
	}
	fclose(fp);
	refresh();
	getch();
	free(path);
	return EXIT_SUCCESS;
	
}

int main(){
	init_display();
	Personnage perso1 = {"clementine",'R',120};
	Personnage perso2 = {"meganne",'B',100};
	creer(&perso1,&perso2);
	close_display();
	return EXIT_SUCCESS;
}
