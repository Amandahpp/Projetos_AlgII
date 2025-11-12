#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream entrada("Entrada17.txt");
    ofstream saida("Saida17.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cout << "Erro ao abrir arquivos!" << endl;
        return 1;
    }

    int V1[100], V2[100];
    int tamV1 = 0, tamV2 = 0;
    char comando[20], vetor[5];
    int numero;

    while (!entrada.eof()) {
        entrada >> comando >> vetor;

        if (strcmp(comando, "adiciona") == 0) {
            entrada >> numero;
            if (strcmp(vetor, "V1") == 0) {
                V1[tamV1++] = numero;
            } else {
                V2[tamV2++] = numero;
            }
            saida << "O número " << numero << " foi adicionado no vetor " << vetor << endl;
        }
        else if (strcmp(comando, "mostra") == 0) {
            int *v; int t;
            if (strcmp(vetor, "V1") == 0) { v = V1; t = tamV1; }
            else { v = V2; t = tamV2; }

            saida << vetor << "(" << vetor << "): ";
            for (int i = 0; i < t; i++) {
                saida << v[i];
                if (i != t-1) saida << ", ";
            }
            saida << endl;
        }
        else if (strcmp(comando, "remove") == 0) {
            entrada >> numero;
            int *v; int *t;
            if (strcmp(vetor, "V1") == 0) { v = V1; t = &tamV1; }
            else { v = V2; t = &tamV2; }

            bool achou = false;
            for (int i = 0; i < *t; i++) {
                if (v[i] == numero) {
                    // remove deslocando para trás
                    for (int j = i; j < *t-1; j++) v[j] = v[j+1];
                    (*t)--;
                    achou = true;
                    break;
                }
            }
            if (achou)
                saida << "O número " << numero << " foi removido do vetor " << vetor << endl;
            else
                saida << "O número " << numero << " não pode ser removido, pois não pertence ao vetor " << vetor << endl;
        }
        else if (strcmp(comando, "qtd") == 0) {
            if (strcmp(vetor, "V1") == 0) saida << "Total de elementos no vetor V1: " << tamV1 << endl;
            else saida << "Total de elementos no vetor V2: " << tamV2 << endl;
        }
        else if (strcmp(comando, "media") == 0) {
            int *v; int t;
            if (strcmp(vetor, "V1") == 0) { v = V1; t = tamV1; }
            else { v = V2; t = tamV2; }

            float soma = 0;
            for (int i = 0; i < t; i++) soma += v[i];
            float media = (t==0) ? 0 : soma/t;
            saida << "Media dos elementos do vetor " << vetor << ": " << media << endl;
        }
    }

    entrada.close();
    saida.close();

    cout << "Processamento concluído!" << endl;
    return 0;
}
