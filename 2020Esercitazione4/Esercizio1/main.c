/*
Scrivere un programma che acquisito un array di double da standard input.
lo stampi (un elemento per riga) in ordine decrescente. Il programma acquisisce
inizialmente un numero intero che rappresenta la dimensione dell'array.
Quindi acquisisce l'array elemento per elemento. Si può assumere che l'array abbia al masssimo 50
elementi e, in caso l'intero inserito inizialmente sia maggione di 50 o minore di 0,
va ripetuta la lettura fino ad ottenere un valore valido.

*/



#include <stdio.h>

/*questa funzione legge la dimensione dell'array e i suoi elementi. Nel caso in cui la dimensione non sia
valida (<0 oppure >50) allora si ripete la lettura. La funzione ritorna la 
dimensione acquisita in input. Ricorda che per leggere un double, la scanf
ha bisogno del segnaposto %lf */

int leggi_array(double vet[]) {

    int dim, i;
    
    do {
        scanf("%d", &dim);
    }while(dim < 0 || dim > 50);

    for(i = 0; i < dim; i++) {
        scanf("%lf", &vet[i]);
    }

    return dim;
}


void ordina_array(double vet[], int dim) {

    int i, ord;

    for(ord = 0; ord < dim - 1; ord++) {
        for(i = dim - 1; i > ord; i--) {
            if(vet[i] > vet[i - 1]) {
                double temp;
                temp = vet[i];
                vet[i] = vet[i - 1];
                vet[i - 1] = temp;
            }
        }
    }

}


void stampa_array(double vet[], int dim) {
    int i;
    for (i=0; i<dim; i++)
        printf("%.2f\n", vet[i]);
}


int main() {
    double myarr[50];
    
    int d;
    
    d=leggi_array(myarr);
    ordina_array(myarr, d);
    stampa_array(myarr, d);
    
    return 0;
}