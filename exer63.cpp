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
void mostraSobra(int *vetSobra);
void decrescenteVET(int tam, int *vet);
void decrescenteVetSobra( int *vetSobra);

main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int tam = 0;

    int opc;

    int *vet = new int[tam];
    int *vetSobra = new int[5];
    int valor;
    int contSobra = 0;

    do
    {
        cout<<"0- Sair"<<endl;
        cout<<"1- Gerar valores para o vetor"<<endl;
        cout<<"2- Sorteio"<<endl;
        cout<<"3- Exibir vetores"<<endl;
        cin>>opc;

        switch(opc)
        {
        case 1:
            cout<<"para gerar o vetor digite:"<<endl;
            do
            {
                cout<< "\n Informe valor entre 5 e 50: ";
                cin>>tam;

            }
            while(tam<5 || tam > 50 );
            gerar(tam,vet);
            break;
        case 2:

            do
            {
                cout<<" informe um valor para verificar se existe: ";
                cin>>valor;
            }
            while(valor<1 ||valor>50);
            verifica(tam,vet,valor,vetSobra,contSobra);

            break;
        case 3:
            cout<<"vetor: ";
            mostra(tam,vet);
            cout<<"decrescente: ";
            decrescenteVET(tam,vet);
            mostra(tam,vet);
            cout<<"vetor sobra: ";
            mostraSobra(vetSobra);
            cout<<"decrescente: ";
            decrescenteVetSobra(vetSobra);
            mostraSobra(vetSobra);
            cout<<endl;
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
            aux = rand() % 50 + 1;
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
    bool encontrado = false;
    for (int *p = vet; p < vet + tam; p++)
    {
        if(valor == *p)
        {
            cout<<"Valor "<<valor<<" está na posição "<< p<<" do vetor e seu endereço na memória é " <<&p<<endl;
            encontrado= true;
            // Remove o elemento encontrado (desloca todos os próximos)
            for (int *q = p; q < vet + tam - 1; q++)
            {
                *q = *(q + 1);
            }

            tam--; // reduz o tamanho lógico do vetor
            break;
        }
    }
    if(!encontrado)
    {
        cout<<"O valor "<<valor<<" não existe no vetor VET será inserido no vetor auxiliar"<<endl;

        // Se o vetor sobra estiver cheio, limpamos ele
        if (contSobra >= 5)
        {
            cout << "Vetor sobra cheio! Limpando..." << endl;
            for (int i = 0; i < 5; i++)
                vetSobra[i] = 0; // ou outro valor padrão
            contSobra = 0;
        }

        // Armazena o novo valor
        vetSobra[contSobra++] = valor;
    }

}
void mostraSobra(int *vetSobra)
{
    for (int i = 0; i < 5; i++)
    {
        cout << vetSobra[i] << " ";
    }
    cout << endl;
}
void decrescenteVET(int tam, int *vet)
{
    int aux;
    for (int *p = vet; p < vet + tam - 1; p++)
    {
        for (int *q = p + 1; q < vet + tam; q++)
        {
            if ( *p < *q)
            {
                aux = *p;
                *p = *q;
                *q = aux;
            }
        }
    }
}
void decrescenteVetSobra( int *vetSobra)
{
    int aux;
    for (int *p = vetSobra; p < vetSobra + 5 - 1; p++)
    {
        for (int *q = p + 1; q < vetSobra + 5; q++)
        {
            if ( *p < *q)
            {
                aux = *p;
                *p = *q;
                *q = aux;
            }
        }
    }
}
