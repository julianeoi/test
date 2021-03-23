#include <stdio.h>
#include <stdarg.h>
 
//on veut afficher les valeurs des differents arg sauf le dernier 
//on connait le dernier parametre qui est -1
//ou on connait le nb de parametre qu'on veut utiliser
 
void essai (int premier , char deuxieme , ... ){
    int par ; //on déclare une vble ou on va mettre les parametre 
    va_list liste ; //liste va contenir les arguments 
    printf("premier : %d \n",premier);
    printf("deuxieme : %c \n", deuxieme);
    va_start (liste, deuxieme); //on met (structure, 
dernier parametre connue )
    //on initialise
    // par = var_arg(liste,int) -> permet d'acceder au parametre qui st forcement de type int 
    //var_arg : permet d'acceder à la valeur du parametre et de passer au suivant 
    while ( (par = va_arg(liste,int)) != -1 ){
        printf("parametre vble : %d \n",par);
    }
    va_end(liste); //
}
 
int main(){
    essai(1,'a',3,6,-1);
    return 0;
}
 
 
//deuxieme possibilité : on somme les parametre 
// on connait le nb de parametre  qu'on veut sommer 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define EXIT_SUCESS 0
 
int addition (int cpt, ...){
    int parametre;
    int s=0;
    va_list   liste ;  /* déclare la struture qui contiendra les parametre */
    va_start (liste , cpt); /* on l'initialise */
    for (int i=0 ; i< cpt ; i++) {
    parametre = va_arg(liste,int);
    s = s + parametre;    /* extrait un parametre */
    }
    va_end (liste); /*libere la mémoire */
    return s;
}
 
 
int main() {
    int s = addition(2,3,6);
    printf("%d",s);
    return EXIT_SUCESS;
}
 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define EXIT_SUCESS 0
 
//afficher uniquement le premier parametre 
void affiche1(char *premier,...){
    va_list liste;
    va_start (liste,premier);
    vprintf(premier,liste);
}
 
//affiche le nb de parametre qu'on a dit  
void affiche2(int cpt, ...){
    va_list liste;
    char *parametre;
    va_start(liste,cpt);
    for(int i=0; i<cpt ; i++){
        parametre = va_arg(liste,char *);
        vprintf(parametre,liste);// ecrit tout les para à la suite ss espace
        printf("\t");
    }
}
 
 
 
int main(){
    affiche1("hello","ananas"); // hello
    printf("\n");
    affiche2(2,"hello","ananas"); // hello ananas
    return 0;
}
 