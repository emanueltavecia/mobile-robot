# Interpretador de comandos para Robô Móvel
- Repositório onde se encontra o código fonte e a documentação do funcionamento do interpretador de comandos de um robô móvel desenvolvido no IFSC Campus Araranguá.

## Dados do projeto
- Desenvolvido no Instituto Federal de Santa Catarina (IFSC) Campus Araranguá;
- Curso Técnico Integrado em Eletromecânica;
- Disciplina de Projeto Integrador III;
- Equipe: Emanuel Cardoso Tavecia ([@emanueltavecia](https://github.com/emanueltavecia)), Bernardo Fernandes Spillere e Gabriel Dutra dos Santos;
- Orientador: Werther Alexandre de Oliveira Serralheiro.

## Documentação

- Este projeto utiliza a plataforma Arduino.

- Você deve digitar um código no monitor serial iniciado por uma letra, que será a função a ser executada (f ou b), seguida de três números: o primeiro é o tempo em segundos que o robô irá se mover; o segundo é a velocidade da roda esquerda; e o terceiro é a velocidade da roda direita.
  - Obs 1: As informações do código devem ser separadas por vírgula (,);
  - Obs 2: A letra da função é case-insensitive;
  - Obs 3: As velocidades tem valor mínimo de 1 e máximo de 5.
    - Velocidade 1: 500 rpm;
    - Velocidade 2: 600 rpm;
    - Velocidade 3: 700 rpm;
    - Velocidade 4: 800 rpm;
    - Velocidade 5: 1000 rpm;

- A letra corresponde à função que será executada. Você tem as seguintes opções:

  - f - para frente
    - Exemplo:
      ```
      f,4,3,5
      ```
    - Nesse exemplo o robô se move para frente por 4 segundos. A roda esquerda gira na velocidade 3, e a roda direita gira na velocidade 5.
    - Obs: Usando velocidades diferentes para cada roda, o robô fará uma trajetória curva, mas se usar a mesma velocidade para as duas rodas, o robô se move sem fazer curvas.

  - b - para trás
    - Exemplo:
      ```
      b,7,2,4
      ```
    - Nesse exemplo o robô se move para trás por 7 segundos. A roda esquerda gira na velocidade 2, e a roda direita gira na velocidade 4.
    - Obs: Usando velocidades diferentes para cada roda, o robô fará uma trajetória curva, mas se usar a mesma velocidade para as duas rodas, o robô se move sem fazer curvas.

  - h - ajuda
    - Exemplo:
      ```
      h
      ```
    - Digitando "h" no monitor serial você recebe ajuda para usar os comandos.
