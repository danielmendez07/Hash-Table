#include <iostream>
#include <list>
#include <vector>
#include <string>

// Definição da classe Mercadoria
class Mercadoria {
public:
    int codigoProduto; // Variável para armazenar o código da mercadoria
    std::string nomeProduto; // Variável para armazenar o nome da mercadoria

    // Construtor da classe Mercadoria que inicializa o código e o nome da mercadoria
    Mercadoria(int codigo, std::string nome) : codigoProduto(codigo), nomeProduto(nome) {}
};
