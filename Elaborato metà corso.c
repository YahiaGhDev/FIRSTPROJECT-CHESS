//
//  main.c
//  tris
//
//  Created by Yahia Ghallale on 03/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIMR 3
#define DIMC 3


int controllo_coordinate(int vx[], int vy[], int x, int y, int k ){
    int i;
    if(x > 2 || x < 0 || y>2 || y<0){
        return 0;
    }else{
        for (i=0; i<k; i++) {
            if(vx[i] == x && vy[i] == y) {
                return 0;
                
            }
            
        }
    }
    
    return 1;
    
}



int casi_vittoria(int mat[][DIMC]){
    int i;
    for (i =0; i<DIMR; i++) {
        if (mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2] && mat[i][0] == 0) {
            return 0;
        }
        
        else if (mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i] && mat[0][i] == 0) {
            return 0;
        }

        else if (mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2] && mat[i][0] == 1) {
            return 1;
        }
        
        else if (mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i] && mat[0][i] == 1) {
            return 1;
        }
    }
    
    return 3;
}


int casi_vittoria_obliquo1(int mat[][DIMC]){
    int i=0, j=0;
    if(mat[i][j] == 0 && mat[i][j] == mat[i+1][j+1] && mat[i][j] == mat[i+2][j+2]){
        return 0;
    }
    
    if(mat[i][j] == 1 && mat[i][j] == mat[i+1][j+1] && mat[i][j] == mat[i+2][j+2]){
        return 1;
    }
    
    return 3;
}

int casi_vittoria_obliquo2(int mat[][DIMC]){
    int i=0, j=2;
    if(mat[i][j] == 0 && mat[i][j] == mat[i+1][j-1] && mat[i][j] == mat[i+2][j-2]){
        return 0;
    }
    
    if(mat[i][j] == 1 && mat[i][j] == mat[i+1][j-1] && mat[i][j] == mat[i+2][j-2]){
        return 1;
    }
    
    return 3;
}





          

void inserimento(int m[][DIMC], int numero_giocate){
    int i = 0;
    int coordinate_x[9];
    int coordinate_y[9];
    int n1,n2;
    
    do {
        if(i==0){
            do{
                printf("giocatore 1 inserisci coordinate (tra 0 e 2): ");
                scanf("%d%d", &n1, &n2);
                if(controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) != 0){
                    coordinate_x[i] = n1;
                    coordinate_y[i] = n2;
                    m[n1][n2] = 0;
                }else{
                    printf("coordinate gia inserite o errate, inserire nuovi valori\n");
                }
            }while(controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) == 0);
        }
        else if(i%2 == 0){
            do {
                printf("giocatore 1 inserisci coordinate (tra 0 e 2): ");
                scanf("%d%d", &n1, &n2);
                if(controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) != 0){
                    coordinate_x[i] = n1;
                    coordinate_y[i] = n2;
                    m[n1][n2] = 0;
                }else{
                    printf("coordinate gia inserite o errate, inserire nuovi valori\n");
                }
            } while (controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) == 0);
            
            }else{
                
                do {
                    printf("giocatore 2 inserisci coordinate (tra 0 e 2): ");
                    scanf("%d%d", &n1, &n2);
                    if(controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) != 0){
                        coordinate_x[i] = n1;
                        coordinate_y[i] = n2;
                        m[n1][n2] = 1;
                    }else{
                        printf("coordinate gia inserite o errate, inserire nuovi valori\n");
                    }
                } while (controllo_coordinate(coordinate_x, coordinate_y, n1, n2, i) == 0);
                
                
                
            }
        
        i = i+1;
        
        if(i > 4){
            if(casi_vittoria(m) == 0 || casi_vittoria_obliquo1(m) == 0 || casi_vittoria_obliquo2(m) == 0){
                printf("-----VINCE IL GIOCATORE 1-----\n");
                break;
            }
            if(casi_vittoria(m) == 1 || casi_vittoria_obliquo2(m) == 1 || casi_vittoria_obliquo1(m) == 1){

                printf("-----VINCE IL GIOCATORE 2-----\n");
                break;
            }
            
        }
        
        
       
        
       
            
    }while (i < 9);
    
    if(casi_vittoria(m) == 3 && casi_vittoria_obliquo1(m) == 3 && casi_vittoria_obliquo2(m) == 3){
        printf("-----PAREGGIO-----\n");
    }
    
    for (int i=0; i<DIMR; i++) {
        for (int j=0; j<DIMC; j++) {
            if (m[i][j] == 0 || m[i][j] == 1) {
                printf("%3d", m[i][j]);
            }else{
                printf("%3s", "x");
            }
        }
        printf("\n");
    }
    

    
    
}







int main(void) {
    
    int matr[DIMR][DIMC];
    char domanda[2];
    do{
        
        inserimento(matr,9);
        printf("Vuoi rigiocare? (rispondere con si o no): ");
        scanf("%s", domanda);
        
    }while(strcmp(domanda, "si") == 0);
    
    
    return 0;
}
