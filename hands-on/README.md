Hands-on
Preparação para desafio HPC 

    Escolha um dos seguintes problemas (Harmonic progression sum ou Game of Life).
    
    Para o problema escolhido execute passos a seguir:
        Identificar o laço com maior custo computacional;
        Utilizar uma diretiva OpenMP para paralelizar esse laço;
        Comparar o arquivo de saída da versão paralela com o arquivo da versão serial;
        Identificar onde está ocorrendo 'race condition';
        Incluir uma diretiva de sincronização no laço, mantendo o desempenho melhor que o da versão serial.

Execução do programa game o life:
```
cd life
make
./life < <arquivo de entrada>
```
exemplos de execução:
Caso fácil

```
./life < life.in
```

Caso médio:

```
./life < judge.in
```

Caso difícil:

```
./life < judge2.in
```

Execução do programa Harmonic Progression Sum:
```
cd sum
make
./sum < <arquivo de entrada>
```
exemplos de execução:
Caso rápido
```
./sum < sum.in
```

Caso demorado
```
./sum < sum2.in
```


