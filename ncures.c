#include <ncurses.h>

int main(){
	initscr(); //initialise
	attron(A_UNDERLINE);
	printw("hello"); //ecrit
	attroff(A_UNDERLINE); 
	refresh(); //permet de l'afficher 
	getch();// on attend un char pour quitter
	endwin(); //on restaure les parametre initiaux du terminal 
}
//mise en forme

//A_NORMAL : normal (permet d'annuler tout les mises en forme)
//A_STANDOUT : meilleur surlignement 
//A_REVERSE : inversion video
//A_DIM : a moitié brillant 
//A_BOLD : en gras
//A_UNDERLINE : souligné 
//A_INVIS : mode invisible 

//fct attron permet d'appliquer les mises en formes passer en parametre 
//fct attrof d'annuler la mise en forme passe en parametre 
