#include <stdio.h>
#include <stdlib.h>

int	somme(int a, int b){
	int s = a+b;
	return s;
}
int	reste(int a, int b){
	return a%b;
}

int main(){
	printf("%d\n",somme(1,2));
	//on met des fct qui ont le meme type 
	int (*ptr_tab[2])()={&somme,&reste};//tab contenant un pointeur sur chaque fct 
	for(int i=0; i<2 ; i++){
		printf("%d\n",ptr_tab[i](7,3)); //appelle les fct	
	}
	return 0;
}

//gcc -Wall pointeurfct.c -o pointeurfct
//./pointeurfct
