#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

///Letra = 0, Digito = 1, Simbolo = 2, Espaço = 3, Outro = 4
int matrizTransicao[8][5] = {
                     1,   3,  5,  0,  6,
                     1,   1,  2,  2,  2,
                     -1, -1, -1, -1, -1,
                     4,   3,  4,  4,  4,
                     -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1,
                     7,   7,  7,  7,  6,
                     -1, -1, -1 , -1 ,-1
                            };

///Estados de aceitação
int vetorAceitacao[8] = {
                         false,  // 0
                         false,  // 1
                         true,   /// 2 Aceitacao ID
                         false,  // 3
                         true,   /// 4 Aceitacao NUM
                         true,   /// 5 Aceitacao SIMBOLO
                         false,  // 6
                         true    /// 7 Aceitacao ERRO
                         };

///Matriz de avanço
int matrizAvanco[8][5] = {
                        true, true, true, true, true,
                        true, true, false, true, false,
                        -1, -1, -1, -1, -1,
                        false, true, false, true, false,
                        -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1,
                        false, false, false, true, true,
                        -1, -1, -1, -1, -1
                        };

int charToCodigo(char x){
    int ch;

    if( (int)x >= 97 && (int)x <=122){ //a-z
        ch = 0; // Letra
    }
    else if( (int)x >= 65 && (int)x <= 90){//A-Z
        ch = 0;  // Letra
    }
    else if( (int)x >= 48 && (int)x <= 57){ // 0 - 9
        ch = 1; // Digito
    }
    else if(x == '=' || x == '+' || x == '-' || x == '/' || x == ';' || x == '*'){ // = ou + ou - ou / ou ; ou *
        ch = 2; // Simbolo
    }
    else if(x == ' ' || x == '\n' || x == 13){ //Espaco em branco ou \n ou CR = carriage return
        ch = 3; // Espaço
    }
    else{
        ch = 4; //ERRO
    }
    return ch;
}

int main(){
    FILE *arquivo_entrada; // Arquivo de entrada
    FILE *arquivo_saida; // Arquivo de saida

    int estado = 0;

    char x;
    char saida;

    int ch; //Outro

    arquivo_entrada = fopen("entrada.txt","r"); // Abrindo arquivo entrada.txt no modo de leitura
    if (arquivo_entrada == NULL){
      printf("Erro na abertura do arquivo entrada.txt.\n");
      exit(-1);
    }

    arquivo_saida = fopen("saida.txt","w"); // Abrindo arquivo saida.txt no modo de escrita
    if (arquivo_saida == NULL){
      printf("Erro na abertura do arquivo saida.txt.\n");
      exit(-1);
    }

    x = getc(arquivo_entrada); // Leia o caractere do arquivo e armazene em x
    do{ // Enquanto nao for o final do arquivo..
        estado = 0;

        while(!vetorAceitacao[estado] && x!=EOF){ // Ainda não é aceitacao e nao tem erro

            ch = charToCodigo(x);

            if(matrizAvanco[estado][ch] == true && x!=EOF){
                putc(x, arquivo_saida);
                saida = x;
                x = getc(arquivo_entrada);
            }

            estado = matrizTransicao[estado][ch];

        }

        if(x != EOF){
            switch(estado){
                case 2:
                    fprintf(arquivo_saida, " <<ID>> ");
                    break;
                case 4:
                    fprintf(arquivo_saida, " <<NUM>> ");
                    break;
                case 5:
                    fprintf(arquivo_saida, " <<%c>> ", saida);
                    break;
                case 7:
                    fprintf(arquivo_saida, " <<ERR>> ");
                    break;
            }
        }

    } while(x != EOF);


    fclose(arquivo_entrada);

    fclose(arquivo_saida);

    return 0;
}
