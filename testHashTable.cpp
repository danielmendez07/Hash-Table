#include <iostream>
#include <string>
#include "HashTable.cpp" // Incluindo a implementação da classe HashTable

// Função de teste para inserção de uma única mercadoria na tabela hash
void testarInsercao(HashTable& ht) {
    std::cout << "Teste 1: Inserção de Mercadoria\n";
    ht.inserirMercadoria(101, "Caneta BIC");
    // Verifica se a mercadoria foi inserida com sucesso buscando-a na tabela hash
    if (ht.buscarMercadoria(101) != nullptr) {
        std::cout << "Resultado: Sucesso\n\n"; // Se encontrou, exibe mensagem de sucesso
    } else {
        std::cout << "Resultado: Falha\n\n"; // Se não encontrou, exibe mensagem de falha
    }
}

// Função de teste para buscar uma mercadoria na tabela hash
void testarBusca(HashTable& ht) {
    std::cout << "Teste 2: Busca de Mercadoria\n";
    // Verifica se a mercadoria buscada (com código 101) existe na tabela hash
    if (ht.buscarMercadoria(101) != nullptr) {
        // Se encontrou, exibe mensagem de sucesso e o nome da mercadoria encontrada
        std::cout << "Resultado: Sucesso. Mercadoria encontrada: " << ht.buscarMercadoria(101)->nomeProduto << "\n\n";
    } else {
        std::cout << "Resultado: Mercadoria não encontrada\n\n"; // Se não encontrou, exibe mensagem de mercadoria não encontrada
    }
}

// Função de teste para remover uma mercadoria da tabela hash
void testarRemocao(HashTable& ht) {
    std::cout << "Teste 3: Remoção de Mercadoria\n";
    // Verifica se a mercadoria com código 101 pode ser removida da tabela hash
    if (ht.removerMercadoria(101)) {
        std::cout << "Resultado: Sucesso. Mercadoria removida.\n\n"; // Se foi removida, exibe mensagem de sucesso
    } else {
        std::cout << "Resultado: Falha. Mercadoria não encontrada.\n\n"; // Se não foi removida, exibe mensagem de falha
    }
}

// Função de teste para inserção de múltiplas mercadorias na tabela hash
void testarInsercaoMultipla(HashTable& ht) {
    std::cout << "Teste 4: Inserção de Múltiplas Mercadorias\n";
    // Insere três mercadorias diferentes na tabela hash
    ht.inserirMercadoria(202, "Lápis HB");
    ht.inserirMercadoria(212, "Borracha Branca");
    ht.inserirMercadoria(305, "Marcador Permanente");

    // Verifica se todas as mercadorias foram inseridas corretamente na tabela hash
    if (ht.buscarMercadoria(202) != nullptr && ht.buscarMercadoria(212) != nullptr && ht.buscarMercadoria(305) != nullptr) {
        std::cout << "Resultado: Sucesso. Todas as mercadorias foram inseridas corretamente.\n\n"; // Se todas foram encontradas, exibe mensagem de sucesso
    } else {
        std::cout << "Resultado: Falha. Alguma mercadoria não foi inserida corretamente.\n\n"; // Se alguma não foi encontrada, exibe mensagem de falha
    }
}

// Função de teste para buscar uma mercadoria que não existe na tabela hash
void testarBuscaNaoExistente(HashTable& ht) {
    std::cout << "Teste 5: Busca por Mercadoria Não Existente\n";
    // Verifica se uma mercadoria com código 999 não existe na tabela hash
    if (ht.buscarMercadoria(999) == nullptr) {
        std::cout << "Resultado: Sucesso. Mercadoria não encontrada, como esperado.\n\n"; // Se não foi encontrada, exibe mensagem de sucesso
    } else {
        std::cout << "Resultado: Falha. Encontrou uma mercadoria que não deveria existir.\n\n"; // Se foi encontrada, exibe mensagem de falha
    }
}

int main() {
    HashTable ht; // Cria uma instância da classe HashTable

    // Executa os testes
    testarInsercao(ht);
    testarBusca(ht);
    testarRemocao(ht);
    testarInsercaoMultipla(ht);
    testarBuscaNaoExistente(ht);

    ht.imprimir(); // Imprime o conteúdo da tabela hash

    return 0;
}
