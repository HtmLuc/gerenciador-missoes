#include <iostream>
#include <string>
#include <stdio.h> 
#include <chrono>
#include <thread>
#include <ios>
#include <limits>
#include "../class/sistemaGestao.hpp"

using namespace std;

void menu();

int main(void)
{
    SistemaGestao sistema;
    int entrada, idade, codigoVoo;
    string nome, cpf;
    cout << "Bem-vindo ao sistema de gerenciamento de astronautas!" << endl;
    cout << endl << "---------------------------------------------------" << endl << endl;
    do
    {
        menu();
        cout << endl << "---------------------------------------------------" << endl << endl;
        cout << "Escolha uma das opções." << endl;
        cout << ">>> ";
        cin >> entrada;
        switch (entrada)
        {
            case 0:
                cout << "Até a próxima.";
                break;
            case 1:
                system("clear");
                cin.sync();
                cout << "Informe o CPF (somente números):" << endl << ">>> ";
                cin >> cpf;
                cin.sync();
                cout << "Informe o nome:" << endl;
                cout << ">>> ";
                cin >> nome;
                cout << "Informe a idade:" << endl;
                cout << ">>> ";
                cin >> idade;
                sistema.cadastroAstronauta(cpf, nome, idade);
                system("clear");
                break;
            case 2:
                system("clear");
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.cadastroVoo(codigoVoo);
                system("clear");
                break;
            case 3:
                system("clear");
                cin.sync();
                cout << "Informe o CPF (somente números):" << endl;
                cout << ">>> ";
                cin >> cpf;
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.adicionarAstronautaVoo(cpf, codigoVoo);
                system("clear");
                break;
            case 4:
                system("clear");
                cin.sync();
                cout << "Informe o CPF (somente números):" << endl;
                cout << ">>> ";
                cin >> cpf;
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.removerAstronautaVoo(cpf, codigoVoo);
                system("clear");
                break;
            case 5:
                system("clear");
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.lancarVoo(codigoVoo);
                system("clear");
                break;
            case 6:
                system("clear");
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.contatarVoo(codigoVoo);
                system("clear");
                break;
            case 7:
                system("clear");
                cout << "Informe o código de voo:" << endl;
                cout << ">>> ";
                cin >> codigoVoo;
                sistema.finalizarVoo(codigoVoo);
                system("clear");
                break;
            case 8:
                system("clear");
                sistema.listarVoos();
                system("clear");
                break;
            case 9:
                system("clear");
                sistema.listarAstronautasMortos();
                system("clear");
                break;
            default:
                system("clear");
                cout << "Opção inválida! Informe novamente um novo número." << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                system("clear");
                break;
        }
    } while (entrada != 0);
    return 0;
}

void menu()
{
    cout << "MENU DO GERENCIAMENTO DE ASTRONAUTAS" << endl << endl;
    cout << "0. Sair" << endl;
    cout << "1. Cadastrar Astronaura." << endl;
    cout << "2. Cadastrar Voo." << endl;
    cout << "3. Adiciconar astronaura em Voo." << endl;
    cout << "4. Remover astronauta de um Voo." << endl;
    cout << "5. Lançar um Voo." << endl;
    cout << "6. Contatar Voo." << endl;
    cout << "7. Finalizar um voo." << endl;
    cout << "8. Listar todos os Voos." << endl;
    cout << "9. Listar todos os astronautas mortos." << endl;
}