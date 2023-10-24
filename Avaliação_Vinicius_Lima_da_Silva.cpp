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

class Interface_Paciente {
public:
    int opcao;
    vector<Paciente*> pacientes;

    int localizaCpf(vector<Paciente*> pacientes, string cpf) {
        int i = 0;
        for (auto el : pacientes) {
            if (el->getCpf() == cpf) {
                return i;
            }
            i++;
        }
        return -1;
    }

    void menu() {
        do {
            cout << "--Cadastro de Pacientes-- " << endl;
            cout << "1. Incluir" << endl;
            cout << "2. Excluir (Inserir CPF)" << endl;
            cout << "3. Alterar (Inserir CPF)" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar (Inserir CPF)" << endl;
            cout << "0. Voltar" << endl;
            cin >> opcao;

            string auxNome, auxCPF, auxDataNascimento;

            if (opcao == 1) {
                cout << "Informe o nome: ";
                getline(cin >> ws, auxNome);

                cout << "Informe o CPF: ";
                getline(cin >> ws, auxCPF);

                cout << "Informe a Data de Nascimento: ";
                getline(cin >> ws, auxDataNascimento);

                Paciente* paciente = new Paciente(auxCPF, auxDataNascimento, auxNome);

                pacientes.push_back(paciente);
            } else if (opcao == 2) {
                cout << "Informe o CPF do paciente que deseja excluir: ";
                getline(cin >> ws, auxCPF);
                int indice = localizaCpf(pacientes, auxCPF);
                if (indice != -1) {
                    delete pacientes[indice]; // Liberar memória do paciente excluído
                    pacientes.erase(pacientes.begin() + indice);
                    cout << "Cadastro de paciente excluído com sucesso!" << endl;
                } else {
                    cout << "Paciente com CPF " << auxCPF << " não encontrado." << endl;
                }
            } else if (opcao == 3) {
    cout << "Informe o CPF do paciente que deseja alterar: ";
    getline(cin >> ws, auxCPF);
    int indice = localizaCpf(pacientes, auxCPF);
    
    if (indice != -1) {
        cout << "Paciente encontrado. O que você deseja alterar?" << endl;
        cout << "1. Nome" << endl;
        cout << "2. Data de Nascimento" << endl;
        cout << "Escolha uma opção (1/2): ";
        int escolha;
        cin >> escolha;
        
        if (escolha == 1) {
            cout << "Informe o novo nome: ";
            getline(cin >> ws, auxNome);
            pacientes[indice]->setNome(auxNome);
            cout << "Nome do paciente atualizado com sucesso!" << endl;
        } else if (escolha == 2) {
            cout << "Informe a nova Data de Nascimento: ";
            getline(cin >> ws, auxDataNascimento);
            pacientes[indice]->setDataNascimento(auxDataNascimento);
            cout << "Data de Nascimento do paciente atualizada com sucesso!" << endl;
        } else {
            cout << "Opção inválida. Nenhum dado foi alterado." << endl;
        }
    } else {
        cout << "Paciente com CPF " << auxCPF << " não encontrado. Nenhum dado foi alterado." << endl;
    }
}
 else if (opcao == 4) {
                for (auto el : pacientes) {
                    cout << "Nome: " << el->getNome() << endl;
                    cout << "CPF: " << el->getCpf() << endl;
                    cout << "Data de nascimento: " << el->getDataNascimento() << endl;
                    cout << endl;
                }
            } else if (opcao == 5) {
                cout << "Informe o CPF que deseja localizar: ";
                getline(cin >> ws, auxCPF);
                int indice = localizaCpf(pacientes, auxCPF);
                if (indice != -1) {
                    cout << "Paciente encontrado:" << endl;
                    cout << "Nome: " << pacientes[indice]->getNome() << endl;
                    cout << "CPF: " << pacientes[indice]->getCpf() << endl;
                    cout << "Data de Nascimento: " << pacientes[indice]->getDataNascimento() << endl;
                } else {
                    cout << "Paciente com CPF " << auxCPF << " não encontrado." << endl;
                }
            } else if (opcao == 0) {
                return;
            } else {
                cout << "OPCAO INVALIDA!" << endl;
            }
        } while (opcao != 0);
    }
};
class Interface_Medico {
    public:
    int opcao;
    vector<Medico*> medicos;

    int localizaCrm(vector<Medico*> medicos, string crm) {
        int i = 0;
        for (auto el : medicos) {
            if (el->getCrm() == crm) {
                return i;
            }
            i++;
        }
        return -1;
    }

    void menu() {
        do {
            cout << "--Cadastro de Medicos--" << endl;
            cout << "1. Incluir" << endl;
            cout << "2. Excluir (Inserir CRM)" << endl;
            cout << "3. Alterar (Inserir CRM)" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar (Inserir CRM)" << endl;
            cout << "0. Voltar" << endl;
            cin >> opcao;

            string auxNome, auxCrm, auxEspecialidade;

            if (opcao == 1) {
                cout << "Informe o nome: ";
                getline(cin >> ws, auxNome);

                cout << "Informe o CRM: ";
                getline(cin >> ws, auxCrm);

                cout << "Informe a Especialidade: ";
                getline(cin >> ws, auxEspecialidade);

                Medico* medico = new Medico(auxCrm, auxEspecialidade, auxNome);

                medicos.push_back(medico);
            } else if (opcao == 2) {
                cout << "Informe o CRM do médico que deseja excluir: ";
                getline(cin >> ws, auxCrm);
                int indice = localizaCrm(medicos, auxCrm);
                if (indice != -1) {
                    delete medicos[indice]; // Liberar memória do médico excluído
                    medicos.erase(medicos.begin() + indice);
                    cout << "Cadastro de médico excluído com sucesso!" << endl;
                } else {
                    cout << "Médico com CRM " << auxCrm << " não encontrado." << endl;
                }
            } else if (opcao == 3) {
    cout << "Informe o CRM do médico que deseja alterar: ";
    getline(cin >> ws, auxCrm);
    int indice = localizaCrm(medicos, auxCrm);
    
    if (indice != -1) {
        cout << "Médico encontrado. O que você deseja alterar?" << endl;
        cout << "1. Nome" << endl;
        cout << "2. Especialidade" << endl;
        cout << "Escolha uma opção (1/2): ";
        int escolha;
        cin >> escolha;
        
        if (escolha == 1) {
            cout << "Informe o novo nome: ";
            getline(cin >> ws, auxNome);
            medicos[indice]->setNome(auxNome);
            cout << "Nome do médico atualizado com sucesso!" << endl;
        } else if (escolha == 2) {
            cout << "Informe a nova Especialidade: ";
            getline(cin >> ws, auxEspecialidade);
            medicos[indice]->setEspecialidade(auxEspecialidade);
            cout << "Especialidade do médico atualizada com sucesso!" << endl;
        } else {
            cout << "Opção inválida. Nenhum dado foi alterado." << endl;
        }
    } else {
        cout << "Médico com CRM " << auxCrm << " não encontrado. Nenhum dado foi alterado." << endl;
    }
} else if (opcao == 4) {
                for (auto el : medicos) {
                    cout << "Nome: " << el->getNome() << endl;
                    cout << "CRM: " << el->getCrm() << endl;
                    cout << "Especialidade: " << el->getEspecialidade() << endl;
                    cout << endl;
                }
            } else if (opcao == 5) {
                cout << "Informe o CRM que deseja localizar: ";
                getline(cin >> ws, auxCrm);
                int indice = localizaCrm(medicos, auxCrm);
                if (indice != -1) {
                    cout << "Médico encontrado:" << endl;
                    cout << "Nome: " << medicos[indice]->getNome() << endl;
                    cout << "CRM: " << medicos[indice]->getCrm() << endl;
                    cout << "Especialidade: " << medicos[indice]->getEspecialidade() << endl;
                } else {
                    cout << "Médico com CRM " << auxCrm << " não encontrado." << endl;
                }
            } else if (opcao == 0) {
                return;
            } else {
                cout << "OPCAO INVALIDA!" << endl;
            }
        } while (opcao != 0);
    }

};

int main() {
    Interface_Paciente interface_paciente;
    Interface_Medico interface_medico;

    int escolha;
    do {
        cout << "--Escolha a opcao--"<<endl;
        cout << "1- Pacientes"<<endl;
        cout <<"2- Medicos"<< endl;
        cout <<"0- Sair" << endl;
        cin >> escolha;

        if (escolha == 1) {
            interface_paciente.menu();
        } else if (escolha == 2) {
            interface_medico.menu();
        } else if (escolha != 0) {
            cout << "Opção inválida!" << endl;
        }
    } while (escolha != 0);

    cout << "Saindo..." << endl;
    return 0;
}

