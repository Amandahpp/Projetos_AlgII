/*64 – Faça um programa que solicite ao usuário a quantidade de valores inteiros que deseja
manipular sendo um valor par, no mínimo 6 e no máximo 24, a seguir o programa deverá:
- Gerar valores aleatórios entre 20 e 500 (inclusive o 20 e o 500) para preencher o vetor, sabendo que só
serão aceitos valores que são múltiplos de 4 ou 9 ou que terminam em 5 ou 8, não sendo permitido
valores duplicados.
- Exibir os elementos na tela, separando cada elemento por uma vírgula.
- Encontrar e mostrar:
➢ O maior e o menor elemento do vetor com os endereços de memória onde se encontram no
vetor, exibindo cada elemento em uma linha diferente e os endereços de memória entre
parênteses.
➢ A média entre o maior e o menor elemento do vetor (arredondar para o primeiro número
inteiro maior que o resultado do cálculo da média).
- Realizar os seguintes ajustes:
➢ Gerar um segundo vetor com capacidade de armazenar os valores que estão no vetor e são
menores que a média calculada no item anterior.
➢ Exibir este segundo vetor com os valores em ordem decrescente.
OBS: realizar a validação da entrada de dados exibindo as mensagens correspondentes ao erro
encontrado e solicitando a entrada novamente.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include<cstring>
#include<fstream>
using namespace std;

void gerar(int tam, int *vet );
void mostraValor(int tam,int *vet);
void MaiorMenorMedia(int tam,int *vet);

main()
{
    setlocale(LC_ALL,"portuguese");

    int tam = 0;
    do
    {
        cout<< "\n Informe valor entre 5 e 15: ";
        cin>>tam;

    }while(tam<6 || tam > 24 || tam % 2 == 0 );

    int *vet = new int[tam];
    gerar(tam,vet);
    cout<<"valores do vetor: "<<endl;
    mostraValor(tam,vet);
    cout<<endl;
    MaiorMenorMedia(tam,vet);
    cout<<endl;


}
void gerar(int tam, int *vet )
{
    bool achou;
    int aux;
    //Gerar vetor sem números repetidos
     for (int *p = vet; p < vet + tam; p++) {
        do {
            aux = rand() % 500 + 20; // gera número entre 0 e 99
            achou = false;

            // verifica se já existe no vetor (até a posição atual)
            for (int *q = vet; q < p; q++) {
                if (*q == aux) {
                    achou = true;
                    break;
                }
            }
        } while (achou); // repete enquanto o número já existir

        *p = aux; // grava o número único
    }

}
void mostraValor(int tam,int *vet)
{
    for (int *p = vet; p < vet + tam; p++)
    {
        cout << *p << ",";
    }
    cout << endl;
}
void MaiorMenorMedia(int tam,int *vet)
{
    int maior= *vet, menor = *vet ;
    float total=0;
     for(int *p = vet; p < vet + tam; p++)
    {
        if(*p > maior)
        {
            maior = *p;

        }
        else if(*p < menor)
        {
            menor = *p;
        }
        total+= *p;

    }
    float media = total/tam;

    cout<<"maior valor: "<<maior<<endl;
    cout<<"menor valor: "<<menor<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"media: "<<media<<endl;
    gerarV2(tam,vet,media);

}
void gerarV2(int tam,int *vet, float media)
{
     for(int *p = vet; p < vet + tam; p++)
    {
        if(*p < media)
        {
            cout<<*p<<";";
        }
    }

}
