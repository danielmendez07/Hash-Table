#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Mercadoria.cpp" // Incluindo a implementação da classe Mercadoria

#define TABLE_SIZE 10 // Tamanho simples para fins de demonstração

class HashTable {
private:
    std::vector<std::list<Mercadoria>> table; // Vetor de listas de Mercadorias para armazenar os itens na tabela hash

    // Função hash simples para calcular o índice da tabela com base no código do produto
    int hashFunction(int chave) {
        return chave % TABLE_SIZE;
    }

public:
    // Construtor inicializa o vetor de listas com o tamanho especificado
    HashTable() : table(TABLE_SIZE) {}

    // Método para inserir uma nova mercadoria na tabela hash
    void inserirMercadoria(int codigo, std::string nome) {
        int index = hashFunction(codigo); // Calcula o índice usando a função hash
        table[index].push_back(Mercadoria(codigo, nome)); // Insere a mercadoria na lista correspondente ao índice calculado
    }

    // Método para remover uma mercadoria da tabela hash
    bool removerMercadoria(int codigo) {
        int index = hashFunction(codigo); // Calcula o índice usando a função hash
        // Itera sobre a lista no índice calculado para encontrar e remover a mercadoria com o código fornecido
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->codigoProduto == codigo) {
                table[index].erase(it); // Remove a mercadoria da lista
                return true; // Retorna true se a mercadoria foi removida com sucesso
            }
        }
        return false; // Retorna false se a mercadoria não foi encontrada na tabela hash
    }

    // Método para buscar uma mercadoria na tabela hash com base no código fornecido
    Mercadoria* buscarMercadoria(int codigo) {
        int index = hashFunction(codigo); // Calcula o índice usando a função hash
        // Itera sobre a lista no índice calculado para encontrar a mercadoria com o código fornecido
        for (auto& item : table[index]) {
            if (item.codigoProduto == codigo) {
                return &item; // Retorna um ponteiro para a mercadoria encontrada
            }
        }
        return nullptr; // Retorna nullptr se a mercadoria não for encontrada na tabela hash
    }

    // Método para imprimir o conteúdo da tabela hash
    void imprimir() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Slot " << i << ":";
            for (auto& item : table[i]) {
                std::cout << " (" << item.codigoProduto << ", " << item.nomeProduto << ")"; // Imprime o código e o nome da mercadoria
            }
            std::cout << std::endl;
        }
    }
};
