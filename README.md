# Algoritmos de Ordenação e Busca em C

Este repositório contém implementações em C de quatro algoritmos diferentes: **Bogo Sort**, **Shell Sort**, **Jump Search** e **Busca por Interpolação**. Cada algoritmo é acompanhado por um script em Python para análise e visualização dos resultados.

## 🌟 Bogo Sort

O Bogo Sort é um algoritmo de ordenação notoriamente ineficiente. Ele embaralha aleatoriamente os elementos até que a lista esteja ordenada. Devido à sua natureza exponencial, é impraticável para conjuntos de dados de tamanho significativo.

## 🐚 Shell Sort

O Shell Sort é um algoritmo de ordenação que melhora a eficiência do algoritmo de ordenação por inserção, especialmente para conjuntos de dados de grande tamanho. Ele divide o conjunto em intervalos menores e aplica o algoritmo de ordenação por inserção a esses subconjuntos.

## 🛤️ Jump Search

O Jump Search é um algoritmo de busca eficiente para conjuntos de dados ordenados. Ao pular blocos fixos, reduz o número de comparações necessárias para encontrar um elemento. É útil em grandes conjuntos de dados quando a busca binária não é prática.

## 🎯 Busca por Interpolação

A Busca por Interpolação é um algoritmo de busca eficiente para conjuntos de dados uniformemente distribuídos. Ajusta a estimativa interpolada da posição do elemento desejado com base na distribuição dos valores, oferecendo uma complexidade média mais eficiente.

## 🚀 Executando os Algoritmos

Cada algoritmo é executado para conjuntos de dados de tamanhos crescentes, medindo o tempo de execução em diferentes cenários: melhor caso (array já ordenado) e pior caso (array em ordem inversa). Os resultados são salvos em arquivos (`melhorcaso.txt` e `pirocaso.txt`) e visualizados usando scripts em Python.

## 📈 Executando os Scripts Python

Os scripts em Python usam a biblioteca Matplotlib para criar gráficos que ilustram o desempenho dos algoritmos nos diferentes casos. Eles leem os arquivos de resultados gerados pelo código C e geram visualizações para melhor compreensão do desempenho.

## 🛠️ Requisitos

- Compilador C
- Python 3
- Biblioteca Matplotlib (instalada via `pip install matplotlib`)

## ℹ️ Como Usar

1. Compile os códigos C usando um compilador apropriado.
2. Execute os binários gerados.
3. Execute os scripts Python para visualização dos resultados.

## 📌 Observações

- Certifique-se de ter as dependências instaladas para executar os scripts Python.
- Os scripts Python assumem que os arquivos de resultados (`melhorcaso.txt` e `pirocaso.txt`) estão presentes no mesmo diretório.

Sinta-se à vontade para contribuir, relatar problemas ou sugerir melhorias! 🚀
