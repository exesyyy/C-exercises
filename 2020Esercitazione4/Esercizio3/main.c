/*
Il Sudoku è un gioco per appassionati di enigmistica. Consiste nel riempire una matrice 9x9 con numeri da 1 a 9 in modo che:
- ogni riga contenga tutti i numeri da 1 a 9
- ogni colonna contenga tutti i numeri da 1 a 9
- ognuno dei 9 quadrati 3x3 che costituiscono la matrice contengano tutti i numeri da 1 a 9
https://it.wikipedia.org/wiki/Sudoku

Il tuo scopo è quello di scrivere un programma che verifichi se un sudoku è valido. La funzione 
controlla_sudoku ritorna 1 se la soluzione proposta è corretta, 0 altrimenti. Potete implementare funzioni ausiliarie se lo 
ritenete necessario.
(vale 2 punti questo esercizio)
*/



#include <stdio.h>

void leggi_soluzione(int tab[9][9]) {
    int r, c;
    for (r=0; r<9; r++)
        for (c=0; c<9; c++)
            scanf("%d", &tab[r][c]);    
}
void ordina_array(int vet[], int dim) {     /*funzione che ordina un array*/

    int i, ord;

    for(ord = 0; ord < dim - 1; ord++) {
        for(i = dim - 1; i > ord; i--) {
            if(vet[i] < vet[i - 1]) {
                int temp;
                temp = vet[i];
                vet[i] = vet[i - 1];
                vet[i - 1] = temp;
            }
        }
    }

}

int checkArrays(int v1[], int v2[], int dim1, int dim2) {   /*controlla che 2 array abbiano gli stessi esatti elementi*/
    
    int i, found;
    
    found = 1;
    
    ordina_array(v2, dim2);
    
    for(i = 0; i<dim1 && found; i++) {
        
        if(v1[i] != v2[i]) {
            found = 0;
        }
    }
    
    return found;
}


int controlla_righe(int tab[9][9]) {        

    int r,c, flag;
    int numeri[9] = {1,2,3,4,5,6,7,8,9};

    flag = 1;

    for(r=0; r<9 && flag; r++) {

        int supp[9] = {0,0,0,0,0,0,0,0,0};
        int i = 0;

        for(c = 0; c<9; c++) {
            supp[i] = tab[r][c];
            i++;
        }

        if(!checkArrays(numeri,supp,9,9)) {
            flag = 0;
        }
    
    }

    return flag;

}

int controlla_colonne(int tab[9][9]) {

    int r,c, flag;
    int numeri[9] = {1,2,3,4,5,6,7,8,9};

    flag = 1;

    for(c=0; c<9 && flag; c++) {

        int supp[9] = {0,0,0,0,0,0,0,0,0};
        int i = 0;

        for(r = 0; r<9; r++) {
            supp[i] = tab[r][c];
            i++;
        }

        if(!checkArrays(numeri,supp,9,9)) {
            flag = 0;
        }
    
    }

    return flag;

}

int controlla3x3(int tab[9][9]) {

    int row, col, flag;
    int numeri[9] = {1,2,3,4,5,6,7,8,9};
    
    flag = 1;

    for (row = 0; row<9 && flag; row = row + 3){
        for (col = 0; col<9 && flag; col = col + 3){
            
            int supp[9] = {0,0,0,0,0,0,0,0,0};
            int i = 0;
            
            for (int r = row; r < row + 3; r++){
                for (int c = col; c < col + 3; c++){
                    supp[i] = tab[r][c];
                    i++;
                }
            }
            if(!checkArrays(numeri,supp,9,9)) {
                flag = 0;
            }
        }
    }                

    return flag;
}


int controlla_sudoku(int tab[9][9]) {

    return controlla_righe(tab) && controlla_colonne(tab) && controlla3x3(tab);

}

int main() {
    int sud[9][9];
    
    leggi_soluzione(sud);
    
    if (controlla_sudoku(sud))
        printf("SI");
    else
        printf("NO");
    
    return 0;
}