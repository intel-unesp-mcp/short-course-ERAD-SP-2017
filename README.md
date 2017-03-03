# short-course-ERAD-SP-2017

Preparação para desafio HPC - parte teórica

* Arquiteturas paralelas
  * Paralelismo e Concorrência
  * Tipos de Arquiteturas Paralelas 
  * Arquiteturas Paralelas Híbridas
* Arquitetura HPC Intel 
  * Intel Xeon 
  * Intel Xeon Phi 1º geração - Knights Corner (KNC)
  * Intel Xeon Phi 2º geração - Knights Landing (KNL)
* Introdução ao OpenMP
  * Diretivas para definição de regiões paralelas
  * Diretivas para divisão de trabalho de laços
  * Race conditions
  * Diretivas para sincronização
* Perfilamento
  * Intel Advisor (Threading Workflow) 
* Sincronização
  * Dependências de dados entre threads
  * Identificando race conditions com Intel Thread Inspector
  * Otimizações para diminuir o impacto das dependências de dados
* Otimização Para KNL
  * Explorando o modelo NUMA (clustering modes)
  * Uso de MCDRAM
  
Preparação para desafio HPC - Hands-on

* Escolha um dos seguintes problemas (Harmonic progression sum e Game of Life). Para o problema escolhido execute passos a seguir:
   * Identificar o laço com maior custo computacional;
   * Utilizar uma diretiva OpenMP para paralelizar esse laço;
   * Comparar o arquivo de saída da versão paralela com o arquivo da versão serial;
   * Identificar onde está ocorrendo 'race condition';
   * Incluir uma diretiva de sincronização no laço, mantendo o desempenho melhor que o da versão serial.
