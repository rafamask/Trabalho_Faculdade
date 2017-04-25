#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX = 3;

struct cad {
    int mat;
    char nome[30];
    float sal;
};

struct lista {
    int fim;
    cad memo[MAX];
};

void menu(){
    cout << "1- INSERIR\n";
    cout << "2- REMOVER\n";
    cout << "3- LISTAR\n";
    cout << "4- BUSCAR PELA MATRICULA (INFORMAR TODOS OS DADOS)\n";
    cout << "5- ALTERAR UM DOS CAMPOS\n";
    cout << "6- CALCULAR MEDIA DOS SALARIOS\n";
    cout << "7- SAIR\n";
}

bool cheia(lista l){
    if(l.fim == MAX-1){
        return true;
    }else{
        return false;
    }
}

bool vazia(lista l){
    if(l.fim == -1){
        return true;
    }else{
        return false;
    }
}

bool inserir(lista &l){
    if(cheia(l)){
        return false;
    }else if(l.fim<MAX-1){
        l.fim++;
            cout << "Matricula: ";
            cin >> l.memo[l.fim].mat;
            cout << "\n\n";
            cout << "Nome: ";
            cin >> l.memo[l.fim].nome;
            cout << "\n\n";
            cout << "Salario: ";
            cin >> l.memo[l.fim].sal;
            cout << "\n\n";
        return true;
    }
}

bool remover(lista &l, int pos){
    if(vazia(l)){
        return false;
    }else{
        for(int i=pos; i<l.fim+1; i++){
            l.memo[i] = l.memo[i+1];
            l.fim--;
        }
    }
}

bool listar(lista &l){
    if(vazia(l)){
        return false;
    }else{
            for(int i=0; i<l.fim+1; i++){
                cout << "\n\n";
                cout << "Matricula: " << l.memo[i].mat;
                cout << "\n\n";
                cout << "Nome: " << l.memo[i].nome;
                cout << "\n\n";
                cout << "Salario: " << l.memo[i].sal;
                cout << "\n\n";
            }
        return true;
    }
}

void alterar(lista &l, int valor){
    int x;

    for(int i=0; i<l.fim+1; i++){
        if(valor == l.memo[i].mat){
            cout << "Insira o numero do campo a ser alterado (ex: 1- matricula, 2- nome, 3- salario): ";
            cin >> x;
            cout << "\n\n";
            switch(x){
            case 1:
                cout << "Inserir nova matricula: ";
                cin >>  l.memo[i].mat;
            break;

            case 2:
                cout << "Inserir novo nome: ";
                cin >> l.memo[i].nome;
            break;

            case 3:
                cout << "Inserir novo salario: ";
                cin >> l.memo[i].sal;
            break;

            default:
                cout << "Erro!";
            }
        }
    }
}

void calc_media(lista &l){
    float soma, media, cont;
    cont = 0;
    for(int i=0; i<l.fim+1; i++){
        soma += l.memo[i].sal;
        cont++;
    }
    media = soma/cont;
    cout << media;
}

void busca(lista &l, int &valor){
    for(int i=0; i<l.fim+1; i++){
        if(valor == l.memo[i].mat){
            cout << "Matricula: " << l.memo[i].mat;
            cout << "\n";
            cout << "Nome: " << l.memo[i].nome;
            cout << "\n";
            cout << "Salario: " << l.memo[i].sal;
            cout << "\n\n";
            break;
        }else{
            cout << "Dados nao encontrados!";
        }
    }
}

int main()
{
    lista l;
    l.fim = -1;
    int opc, pos, valor;

    menu();

    do{
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: //inserir
            if(cheia(l)){
                cout << "Lista cheia!" << endl;
                menu();
            }else{
                inserir(l);
                menu();
            }
            break;

            case 2: //remover
                if(vazia(l)){
                    cout << "Lista vazia!" << endl;
                    menu();
                }else{
                    menu();
                    cout << "Qual posicao? ";
                    cin >> pos;
                    remover(l,pos);
                }
            break;

            case 3: //listar
                if(vazia(l)){
                    cout << "Lista vazia!" << endl;
                    menu();
                }else{
                    menu();
                    listar(l);
                }
            break;

            case 4: //busca
                    cout << "Insira um valor: ";
                    cin >> valor;
                    busca(l,valor);
                    menu();
            break;

            case 5: //alterar um dos campos pela matrícula
                cout << "Insira uma matricula: ";
                cin >> valor;
                alterar(l, valor);
                menu();
            break;

            case 6: //calculo da média dos salários
                cout << "Media dos salarios: ";
                calc_media(l);
            break;

            case 7: //sair
                return 0;
            break;

            default:
                menu();
                cout << "Opcao invalida!";
        }
            }while(opc != 7);

    return 0;
}
