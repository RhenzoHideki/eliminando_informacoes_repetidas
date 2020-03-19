// implemente aqui seu programa ...

#include <iostream>
#include <list>
#include <fstream>
#include <string>

//Declaração das bibliotecas

using namespace std;

struct aluno {
    string nome , matricula;

    aluno() {
    }

    aluno(const string & registration , const string & umNome) {
        nome = umNome;
        matricula = registration;
    }

    // sobrecarga do operador< para o tipo Alguem
    bool operator<(const aluno & o) {
       if (matricula == o.matricula) {
            return nome < o.nome;
        }
        return matricula < o.matricula;
    }
};

bool test(aluno & a , aluno & b){
    return (a.matricula == b.matricula);
}

int main(int argc , char *argv[]){

    if (argc < 1) { //verificar argumento
        cout << "Nenhum arquivo foi passado" ;
        return 3;
    }

    //declação de variaveis
    list<aluno> lista;
    string line ;

    for (int i = 1; i < argc ; i++) {

     ifstream arq(argv[i]);      //Abertura do arquivo

     //Caso não abrir
     if (!arq.is_open()) {
         cout << "Não foi possivel abrir";
         return 4;
     }

     while (getline(arq, line)) {
         int FimLinha = line.size();
         lista.push_front(aluno( line.substr(0,8), line.substr(9,FimLinha))); //Jogando as matriculas e normas para lista
     }
     lista.sort();
     lista.unique(test); //testando

     for (auto it:lista) {
         cout << it.matricula << " " << it.nome << endl;
     }
     arq.close();
    }
    return 0;
}