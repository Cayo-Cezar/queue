#include <iostream>
using namespace std; 

typedef int TipoItem; 
const int max_items = 100;

class fila {

private:

    int primeiro, ultimo;
    TipoItem* estrutura;

public: 

    fila();
    ~fila();
    bool estavazio();
    bool estacheio();
    void inserir(TipoItem item); 
    TipoItem remover();
    void imprimir(); 

};

fila::fila() {

    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_items]; 
}
fila::~fila() {

    delete [] estrutura; 

}

bool fila::estavazio() {

    return(primeiro == ultimo);

}

bool fila::estacheio() {

    return(ultimo - primeiro == max_items);

}

void fila::inserir(TipoItem item) {

    if (estacheio()) {
        cout << "A fila esta cheia\n";
        cout << "Nao pode ser inserido\n";
    }
    else {
        estrutura[ultimo % max_items] = item;
        ultimo++;
    }
}

TipoItem fila::remover() {

    if (estavazio()) {
        cout << "A fila esta vazia\n"; 
        cout << "Nenhum elemento removido\n";
        return 0;
    }
    else {
        primeiro++;
        return estrutura[(primeiro-1) % max_items];
    }

}

void fila::imprimir() {

    cout << "Fila: [ ";
    for (int i = primeiro; i < ultimo; i++) {

        cout << estrutura[i % max_items] << " ";

    }
    cout << "]\n";

}



int main()
{   
    fila fila1; 
    int opcao; 
    TipoItem item; 

    cout << "Gerador de filas\n"; 

    do {

        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n"; 
        cout << "Digite 2 para remover um elememto\n"; 
        cout << "Digite 3 para imprimir a fila\n";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido na fila!\n";
            cin >> item;
            fila1.inserir(item);
        }
        else if (opcao == 2) {
            item = fila1.remover();
            cout << "O elemento removido e: " << item << endl;
        }
        else if (opcao == 3) {
            fila1.imprimir();
        }

    } while (opcao!=0);

    return 0;
}

