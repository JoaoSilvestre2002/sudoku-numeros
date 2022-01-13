#include <stdio.h>
//Joao Silvestre
#define dimensao 9

void zeraDigitos(int *dg) {
    int controle1;
    for (controle1 = 0; controle1 < dimensao; controle1++)
        dg[controle1] = 0;
}

int valida(int v[dimensao][dimensao], int flag, int *dg) {
    int controle1, j;
    for (controle1 = 0; controle1 < dimensao; controle1++) {
        for (j = 0; j < dimensao; j++) {
            if (flag) {
                dg[v[controle1][j]]++;
                if (dg[v[controle1][j]] > 1)
                    return 1;
            }
            else {
                dg[v[j][controle1]]++;
                if (dg[v[j][controle1]] > 1)
                    return 1;
            }
        }
	zeraDigitos(dg);
    }
    return 0;
}

int validaSubMatrix(int v[dimensao][dimensao], int lInicio, int lFim, int cInicio, int cFim, int *dg) {
    int controle1, j;
    for (controle1 = lInicio; controle1 < lFim; controle1++) {
        for (j = cInicio; j < cFim; j++) {
	    dg[v[j][controle1]]++;
	    if (dg[v[j][controle1]] > 1)
		return 1;
	}
    }
    zeraDigitos(dg);
    return 0;
}

int main() {

    int n, mat[dimensao][dimensao], invalid, digits[dimensao], cases, controle1, j;
    scanf("%i", &n);

    for (cases = 1; cases <= n; cases++) {
        for (controle1 = 0; controle1 < dimensao; controle1++) {
	    zeraDigitos(digits);
	    for (j = 0; j < dimensao; j++) {
		scanf("%i", &mat[controle1][j]);
		mat[controle1][j]--;
	    }
	}
	invalid = valida(mat, 1, digits) + valida(mat, 0, digits);

	for (controle1 = 0; controle1 < dimensao; controle1+=3)
            for (j = 0; j < dimensao; j+=3)
    		invalid += validaSubMatrix(mat, controle1, controle1 + 3, j, j + 3, digits);

	printf("Instancia %i\n", cases);

	if (invalid)
	    printf("NAO\n\n");
	else
	    printf("SIM\n\n");
    }
    return 0;
}