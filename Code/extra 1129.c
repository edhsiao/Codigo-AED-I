#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,i,j;
    int questao[5];

    do
    {
        scanf("%d",&n);
        if(n!=0)
        {
                for (i=0;i<n;i++)
                {
                    for(j=0;j<5;j++)
                        scanf("%d",&questao[j]);
                    if(questao[0]<=127 && questao[1]>127 && questao[2]>127 && questao[3]>127 && questao[4]>127)
                    printf("A\n");
                    else if(questao[0]>127 && questao[1]<=127 && questao[2]>127 && questao[3]>127 && questao[4]>127)
                    printf("B\n");
                    else if(questao[0]>127 && questao[1]>127 && questao[2]<=127 && questao[3]>127 && questao[4]>127)
                    printf("C\n");
                    else if(questao[0]>127 && questao[1]>127 && questao[2]>127 && questao[3]<=127 && questao[4]>127)
                    printf("D\n");
                    else if(questao[0]>127 && questao[1]>127 && questao[2]>127 && questao[3]>127 && questao[4]<=127)
                    printf("E\n");
                    else
                    printf("*\n");

                }
        }
    }
    while (n!=0);
}
