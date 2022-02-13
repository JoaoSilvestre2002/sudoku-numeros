 #include <math.h>
#include <stdio.h>
//Joao Silvestre
#define maximo 10
#define dimensao 9
void digitnule(int *gd) {
    int controle1;
    for (controle1 = 0; controle1 < maximo; controle1++)
    gd[controle1] = 0;
}

int funcao(int v[dimensao][dimensao], int x, int *gd) {
    int controle2, controle1;
    for (controle1 = 0; controle1 < dimensao; controle1++) {
        for (controle2 = 0; controle2 < dimensao; controle2++) {
            if (x) {
                gd[v[controle1][controle2]]++;
                if (gd[v[controle1][controle2]] > 1 && v[controle1][controle2] != 0)
                    return 1;
            }
            else {
                gd[v[controle2][controle1]]++;
                if (gd[v[controle2][controle1]] > 1 && v[controle2][controle1] != 0)
                    return 1;
            }
        }
	digitnule(gd);
    }
    return 0;
}

int confirm2matrix(int v[dimensao][dimensao], int lInicio, int lFim, int cInicio, int cFim, int *gd) {
    int controle1, controle2;
    digitnule(gd);
    for (controle1 = lInicio; controle1 < lFim; controle1++) {
        for (controle2 = cInicio; controle2 < cFim; controle2++) {
	    gd[v[controle2][controle1]]++;
	    if (gd[v[controle2][controle1]] > 1 && v[controle1][controle2] != 0)
		return 1;
	}
	digitnule(gd);
    }
    return 0;
}

int main() {

    int number, principalmatriz[dimensao][dimensao], negacao, digits[maximo], circunstancia, controle2, controle1;
    scanf("%i", &number);

    for (circunstancia = 1; circunstancia <= number; circunstancia++) {
        for (controle1 = 0; controle1 < dimensao; controle1++) {
	    digitnule(digits);
	    for (controle2 = 0; controle2 < dimensao; controle2++) {
		scanf("%i", &principalmatriz[controle1][controle2]);
		//principalmatriz[controle1][controle2]--;
	    }
	}
	negacao = funcao(principalmatriz, 1, digits) + funcao(principalmatriz, 0, digits);

	for (controle1 = 0; controle1 < dimensao; controle1+=3)
            for (controle2 = 0; controle2 < dimensao; controle2+=3)
    		negacao += confirm2matrix(principalmatriz, controle1, controle1 + 3, controle2, controle2 + 3, digits);

	printf("Instancia %i\n", circunstancia);

	if (negacao)
	    printf("NAO\n\n");
	else
	    printf("SIM\n\n");
    }
    return 0;
}
