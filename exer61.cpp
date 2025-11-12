/*61 – Escrever um programa que gere um vetor V[20] com valores no intervalo de 0 a 100, sem
números repetidos, ordene os valores do vetor em ordem crescente e escreva no arquivo texto
chamado “exer_61.txt”, escrevendo também o endereço de memória de cada um dos
elementos, conforme o exemplo:
0x61fe00 – 5
0x61fe04 – 8
0x61fe08 – 10
0x61fe0c - 15
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
void crescente(int tam, int *vet);
int main()
{
    int tam = 20;
    int *vet = new int [tam];

    gerar(tam,vet);
    cout<<"vetor:";
    mostraValor(tam,vet);
    cout<<endl;
    cout<<"crescente:";
    crescente(tam,vet);
    mostraValor(tam,vet);
    delete[] vet;
}
void gerar(int tam, int *vet )
{
    bool achou;
    int aux;
    //Gerar vetor sem números repetidos
     for (int *p = vet; p < vet + tam; p++) {
        do {
            aux = rand() % 100; // gera número entre 0 e 99
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
        cout << *p << " ";
    }
    cout << endl;
}
void crescente(int tam, int *vet)
{
    ofstream escrita;

    int aux;
    int *p = vet;
    escrita.open("exer_61.txt", ios::out);
    for (int *p = vet; p < vet + tam - 1; p++)
    {
        for (int *q = p + 1; q < vet+tam; q++)
        {
            if ( *p > *q)
            {
                aux = *p;
                *p = *q;
                *q = aux;

            }

        }
         escrita<<*p<<" ";
         escrita<<&p<<"\n";

    }
    escrita.close();
}
