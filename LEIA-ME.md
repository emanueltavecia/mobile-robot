# Robô Móvel
- Repositório onde se encontra o código fonte e a documentação do funcionamento do Robô Móvel desenvolvido no IFSC Campus Araranguá.

## Dados do projeto
- Desenvolvido no Instituto Federal de Santa Catarina (IFSC) Campus Araranguá;
- Curso Técnico Integrado em Eletromecânica;
- Disciplina de Projeto Integrador III;
- Equipe: Emanuel Cardoso Tavecia ([@emanueltavecia](https://github.com/emanueltavecia)), Bernardo Fernandes Spillere e Gabriel Dutra dos Santos;
- Orientador: Werther Alexandre de Oliveira Serralheiro.

## Documentação

- Este projeto utiliza a plataforma Arduino.

- Você deve digitar um código no monitor serial iniciado por uma letra, que será a função a ser executada, seguida de um número, que será correspondente à rodas do robô ou seu ângulo de rotação. A letra da função é case-insensitive.

- A letra corresponde à função que será executada pelo robô. Você tem as seguintes opções:

  - v - velocidade;
    - O número que compõe o código representa a velocidade do robô, sendo o valor mínimo de 1 e o valor máximo de 5. Exemplo:
      ```
      v3
      ```
    - Nesse exemplo o robô será configurado para girar na velocidade 3.
    - Obs: com esse código apenas é definido a velocidade que o robô irá funcionar. Para fazer ele se mover você deve usar uma das seguintes opções.

  - f - para frente
    - O número que compõe o código representa a quantidade de voltas que o motor irá se mover para frente, exemplo:
      ```
      f4
      ```
    - Nesse exemplo o robô vai para frente. A rodas giram 4 voltas.

  - b - para trás
    - O número que compõe o código representa a quantidade de voltas que o motor irá se mover para trás, exemplo:
      ```
      b7
      ```
    - Nesse exemplo o robô vai para trás. A rodas giram 7 voltas.

  - Ainda não disponível:

    - r - rotacionar
      - O número que compõe o código representa o ângulo que o robô irá rotacionar, exemplo:
        ```
        r-50
        ```
      - Nesse exemplo o robô vai girar -50°, ou seja, 50° no sentido horário. Se o número for positivo, o robô irá girar para o sentido anti-horário.
