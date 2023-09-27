#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute, string palavra) {
    for(char letra : palavra) {
        if(chute == letra) {
            return true;
        }
    }
    return false;
}

bool nao_acertou() {
    for (char letra : PALAVRA_SECRETA) {
        if(!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

void imprime_cabecalho() {
    cout << "*****************" << endl;
    cout << "* JOGO DA FORCA *" << endl;
    cout << "*****************" << endl;
    cout << endl;
}

void imprime_erros() {
    cout << "Chutes errados: ";
        for(char letra : chutes_errados) {
            cout << letra << " ";
        }
    cout << endl;
}

void imprime_palavra() {
    for (char letra : PALAVRA_SECRETA) {
            if(chutou[letra]) {
                cout << letra << " ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
}

void chuta() {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    chutou[chute] = true;

    if (letra_existe(chute, PALAVRA_SECRETA)) {
        cout << "Voce acertou! A letra " << chute << " esta na palavra!" << endl;
    }
    else {
        cout << "Voce errou! A letra " << chute << " nao esta na palavra!" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

void le_arquivo() {
    ifstream arquivo;
    arquivo.open("palavras.txt");
    int quantidade_palavras;
    arquivo >> quantidade_palavras;
    cout << "O arquivo possui " << quantidade_palavras << " palavras" << endl;
    for(int i = 0; i < quantidade_palavras; i++) {
        string palavra_lida;
        arquivo >> palavra_lida;
        cout << "Na linha " << i+1 << ": " << palavra_lida << endl;
    }
}

int main () {
    imprime_cabecalho();

    le_arquivo();

    while (nao_acertou() && nao_enforcou()) {
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    cout << "Fim de jogo!" << endl;
    if (nao_acertou()) {
        cout << "Voce perdeu! Tente novamente!" << endl;
        cout << "A palavra secreta era " << PALAVRA_SECRETA << endl;
    }
    else {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;
        cout << "A palavra secreta era " << PALAVRA_SECRETA << endl;
    }
}
