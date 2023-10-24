#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente {
private:
    string cpf;
    string data_nascimento;

public:
    string nome;

    Paciente(string _cpf, string _data_nascimento, string _nome) {
        this->nome = _nome;
        this->setCpf(_cpf);
        this->setDataNascimento(_data_nascimento);
    }

    string getCpf() {
        return this->cpf;
    }

    string getDataNascimento() {
        return this->data_nascimento;
    }

    string getNome() {
        return this->nome;
    }

    void setCpf(string _cpf) {
        this->cpf = _cpf;
    }

    void setDataNascimento(string _data_nascimento) {
        this->data_nascimento = _data_nascimento;
    }

    void setNome(string _nome) {
        this->nome = _nome;
    }
};

class Medico {
    private:
    string crm;
    string especialidade;

    public:
    string nome;

    Medico (string _crm, string _especialidade, string _nome){
        this-> nome = _nome;
        this-> setCrm(_crm);
        this-> setEspecialidade(_especialidade);
    }

    string getCrm (){
        return this-> crm;
    }
    string getEspecialidade(){
        return this-> especialidade;
    }
    string getNome(){
        return this-> nome;
    }

    void setCrm (string _crm){
        this-> crm = _crm;
    }
    void setEspecialidade(string _especialidade){
        this-> especialidade = _especialidade;
    }
    void setNome(string _nome){
        this-> nome = _nome;
    }
};