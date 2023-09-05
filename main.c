#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char txtRound[]= "logs/";
char txtRoundNumber[10]= "";
const char txtFileExtension[]=".txt";
char finalFile[60]="logs/";
int allypoints = 0, enemypoints = 0;
char resultadopartida[20];

int testLogDir(){
    printf(" nomedoarquivo = %s \n",finalFile);
    return 0;
}

int writeLog(int roundcounter,const char *logText){
    // Copia o valor de roundcounter para txtRoundNumber, a transformando em string
    snprintf(txtRoundNumber, sizeof(txtRoundNumber), "%d", roundcounter);
    // Concatena 3vezes strings à variável finalFile, no final a transformando no diretório do log.
    strcat(finalFile,txtRound);
    strcat(finalFile,txtRoundNumber);
    strcat(finalFile,txtFileExtension);
    // Cria o arquivo do log, usando a variavel finalFile
    FILE *fp = fopen(finalFile, "w");
    // Escreve no arquivo log
    fprintf(fp, "%s",logText);
    // Fecha o log
    fclose(fp);
    testLogDir();
    strcpy(finalFile,"logs/");
    return 0;
}

int checkWinnerCaseOT(int a, int b) {
    return (a > b) ? a : b;
}

int matchEnd(){
    if (allypoints == 13 && enemypoints <= 11) {
            strcpy(resultadopartida, "vitoria");
            return 1;
    }

    if (enemypoints == 13 && allypoints <= 11) {
            strcpy(resultadopartida, "derrota");
            return 1;
    }

    if (allypoints >= 12 && enemypoints >= 12) {
            if ((allypoints - enemypoints) == 2 || (enemypoints - allypoints) == 2) {
                int vencedor = checkWinnerCaseOT(allypoints, enemypoints);
                if (vencedor == allypoints) {
                    strcpy(resultadopartida, "vitoria");
                    return 1;
                } 
                else if (vencedor == enemypoints) {
                    strcpy(resultadopartida, "derrota");
                    return 1;
                }
            }
    }
    else{
        return 0;
    }
    return 0;
}

int main(void) {
    int roundNum = 1;
    char input[10];
    while (1) {
            printf("----------------- \n");
            printf("ROUND %d\n", roundNum);
            scanf("%s", input);

            for (int i = 0; input[i]; i++) {
                input[i] = tolower(input[i]);
            }

            if (strcmp(input, "w") == 0) {
                allypoints++;
                writeLog(roundNum,input);
                roundNum++;
            } else if (strcmp(input, "l") == 0) {
                enemypoints++;
                writeLog(roundNum,input);
                roundNum++;
            }
            else{
                writeLog(roundNum,input);
            }
            

            printf("%dx%d\n", allypoints,enemypoints);

            if(matchEnd()!=0){
                break;
            }
            
        }

printf("resultado da partida = %s", resultadopartida);

return 0;
}