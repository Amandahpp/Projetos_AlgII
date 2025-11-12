/*62 - Crie um programa que manipule através de alocação dinâmica e ponteiros um vetor “vet”
de X posições de números inteiros (a dimensão do vetor é definido pelo usuário do sistema ao
iniciar o programa, não sendo permitido vetor maior que 50 e menor que 5 posições, validar a
dimensão do vetor), o programa deve apresentar um menu com as seguintes opções:
0 – Sair
1 – Gerar valores para o vetor (gerar valores randomicamente entre 1 e 50 (inclusive) sem repetição)
2 – Localizar valor (usuário informa um determinado valor e o sistema procura se este valor pertence
ao vetor, caso pertencer exibe a mensagem: “Valor X, pertence ao vetor está no endereço de memória
xxxxxx”, caso não existir no vetor o valor informado, deve ser exibido a mensagem: “Não pertence ao
vetor” e este número deverá ser incluído em um vetor chamado “sobra” que terá a mesma dimensão do
vetor “vet”, deverá ser exibido os valores do vetor “sobra”. Caso em algum momento o vetor “sobra”
estiver cheio (todas as posições ocupadas) e for necessário fazer mais uma inclusão neste vetor, deverá
ser eliminado todos os elementos deste vetor para então possibilitar a inclusão do valor consultado.
3 – Mostrar elementos do vetor vet
4 – Mostrar elementos do vetor “sobra”
OBS: a opção 2 e 3 só poderá ser executada se a opção 1 foi acionada, a opção 4 só poderá ser
executada se a opção 2 foi executada pelo menos uma vez. Ao escolher opção inválida no menu deverá
exibir mensagem, com tal informação. Os vetores só podem ser percorridos usando aritmética de
ponteiros.
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
void mostra(int tam, int *vet);
void verifica(int tam, int *vet, int valor, int *vetSobra, int &contSobra);
void mostraSobra(int tam, int *vetSobra);
main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int tam = 0;

    int opc;
    cout<<"para gerar o vetor digite:"<<endl;
    do
    {
        cout<< "\n Informe valor entre 6 e 24: ";
        cin>>tam;

    }
    while(tam<5 || tam > 50 );
    int *vet = new int[tam];
    int *vetSobra = new int[tam];
    int valor;
    int contSobra = 0;

    do
    {
        cout<<"0- Sair"<<endl;
        cout<<"1- Gerar valores para o vetor"<<endl;
        cout<<"2- Localizar valor"<<endl;
        cout<<"3- Mostrar elementos do vetor vet"<<endl;
        cout<<"4- Mostrar elementos do vetor “sobra”"<<endl;
        cin>>opc;

        switch(opc)
        {
        case 1:
            gerar(tam,vet);
            break;
        case 2:
            /*2 – Sorteio (Exibe o vetor vet gerado na tela e permite que o usuário informe um valor qualquer dentro
            do intervalo 1 e 50 (inclusive), validar esta entrada.
            Caso o valor informado exista no vetor vet deverá apresentar a mensagem: “Valor XX está na posição YY
            do vetor e seu endereço na memória é ZZ(exibe o endereço de memória)” e este elemento deverá ser
            retirado do vetor e os elementos do vetor vet, se necessário, devem ser realocados novamente, não
            tendo posições “vazias” entre os elementos do vetor vet.
            Caso o valor não exista no vetor vet deverá exibir uma mensagem: “O valor XX não existe no vetor VET,
            será inserido no vetor auxiliar” e este valor deve ser inserido no vetor auxiliar, ao tentar fazer a
            inserção, caso o vetor auxiliar estiver completo (todas as 5 posições ocupadas) deverá exibir uma
            mensagem: “Vetor auxiliar cheio” e este vetor será zerado (eliminar todos os elementos dele) sendo
            inserido o referido valor na primeira posição. Sempre que for incluído elemento no vetor auxiliar este
            deverá ser exibido na tela.
            */
            cout<<" informe um valor para verificar se existe: ";
            cin>>valor;
            verifica(tam,vet,valor,vetSobra,contSobra);
            break;
        case 3:
            cout<<"vetor: ";
            mostra(tam,vet);
            break;

        case 4:
            cout<<"vetor sobra: ";
            mostraSobra(tam,vetSobra);
            break;

        }
    }
    while(opc != 0);
}
void gerar(int tam, int *vet )
{
    bool achou;
    int aux;
    //Gerar vetor sem números repetidos
    for (int *p = vet; p < vet + tam; p++)
    {
        do
        {
            aux = rand() % 50 + 1; // gera número entre 0 e 99
            achou = false;

            // verifica se já existe no vetor (até a posição atual)
            for (int *q = vet; q < p; q++)
            {
                if (*q == aux)
                {
                    achou = true;
                    break;
                }
            }
        }
        while (achou);   // repete enquanto o número já existir

        *p = aux; // grava o número único
    }
    cout<<"vetor gerado com sucesso!"<<endl;
}
void mostra(int tam, int *vet)
{
    for (int *p = vet; p < vet + tam; p++)
    {
        cout << *p << " ";
    }
    cout << endl;

}
void verifica(int tam, int *vet, int valor, int *vetSobra, int &contSobra)
{
    bool encontrado = false;
    for (int *p = vet; p < vet + tam; p++)
    {
        if(valor == *p)
        {
            cout<<"valor "<<valor<<",pretence ao vetor esta no enderco de memeoria "<<&p<<endl;
            encontrado= true;
            break;
        }
    }
    if(!encontrado)
    {
        cout<<"Não pertence ao vetor"<<endl;

        // Se o vetor sobra estiver cheio, limpamos ele
        if (contSobra >= tam)
        {
            cout << "Vetor sobra cheio! Limpando..." << endl;
            for (int i = 0; i < tam; i++)
                vetSobra[i] = 0; // ou outro valor padrão
            contSobra = 0;
        }

        // Armazena o novo valor
        vetSobra[contSobra++] = valor;
    }

}
void mostraSobra(int tam, int *vetSobra)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vetSobra[i] << " ";
    }
    cout << endl;
}

