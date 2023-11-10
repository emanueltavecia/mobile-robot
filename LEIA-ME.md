# Interpretador de comandos para Robô Móvel

**Repositório onde se encontra o código fonte e a documentação do funcionamento do interpretador de comandos de um robô móvel desenvolvido por estudantes do IFSC Campus Araranguá.**

## Índice

- [Dados do projeto](#dados-do-projeto)
- [Documentação](#documentação)
  - [Configuração e Requisitos](#configuração-e-requisitos)
  - [Instruções de uso](#instruções-de-uso)
    - [Resumo](#resumo)
- [Licença](#licença)

## Dados do projeto
- Desenvolvido no Instituto Federal de Santa Catarina (IFSC) Campus Araranguá
- Curso Técnico Integrado em Eletromecânica
- Disciplina de Projeto Integrador III
- Equipe: Emanuel Cardoso Tavecia ([@emanueltavecia](https://github.com/emanueltavecia)), Bernardo Fernandes Spillere e Gabriel Dutra dos Santos
- Orientador: Werther Alexandre de Oliveira Serralheiro

## Documentação

- Este projeto utiliza a plataforma Arduino.

### Configuração e Requisitos

Antes de usar o interpretador de comandos para o robô móvel, é importante configurar corretamente o ambiente e os requisitos do projeto. Siga as instruções abaixo:

- **Biblioteca Arduino Stepper**
  - Os motores de passo são controlados usando a biblioteca Arduino "Stepper". Certifique-se de ter essa biblioteca instalada em seu ambiente de desenvolvimento. Se você ainda não a possui, você pode instalá-la a partir do Gerenciador de Bibliotecas do Arduino IDE.

- **Conexão dos Motores de Passo**
  - Os motores de passo do robô estão conectados às seguintes portas do Arduino:
    - Motor de Passo Esquerdo:
      - Step → Porta 2 do Arduino
      - Direction → Porta 3 do Arduino
    - Motor de Passo Direito:
      - Step → Porta 4 do Arduino
      - Direction → Porta 5 do Arduino
  
  ![Representação esquemática das ligações.](.github/schematic-representation.png "Representação esquemática das ligações")

- **Fazer o upload do código [`interpreter.ino`](interpreter.ino) para o seu Arduino**

### Instruções de uso

- Você deve digitar um código no **monitor serial** iniciado por uma letra, que será a função a ser executada (F, B, L ou R), seguida de dois números: o primeiro é a duração em segundos que o robô irá se mover; e o segundo é a velocidade das rodas.
  - Obs 1: As informações do código devem ser **separadas por vírgula (,)**
  - Obs 2: A letra da função é case-insensitive
  - Obs 3: A velocidade tem valor mínimo de 1 e máximo de 5
    - Velocidade 1: 500 rpm
    - Velocidade 2: 600 rpm
    - Velocidade 3: 700 rpm
    - Velocidade 4: 800 rpm
    - Velocidade 5: 1000 rpm

- A letra corresponde à função que será executada. Você tem as seguintes opções:

  - **F - para frente**
    - Exemplo:
      ```
      F,4,5
      ```
    - Nesse exemplo o robô se move para frente por 4 segundos. As rodas giram na velocidade 5.

  - **B - para trás**
    - Exemplo:
      ```
      B,7,4
      ```
    - Nesse exemplo o robô se move para trás por 7 segundos. As rodas giram na velocidade 4.

  - **L - girar para esquerda**
    - Exemplo:
      ```
      L,5,3
      ```
    - Nesse exemplo o robô gira para esquerda por 5 segundos. As rodas giram na velocidade 3.

  - **R - girar para direita**
    - Exemplo:
      ```
      R,2,2
      ```
    - Nesse exemplo o robô gira para direita por 2 segundos. As rodas giram na velocidade 2.

  - **h - ajuda**
    - Exemplo:
      ```
      H
      ```
    - Enviando "h" no monitor serial você recebe ajuda para usar os comandos.

#### Resumo

| Função | Duração | Veloc. | Código |
| :---: | :---: | :---: | :---: |
| F | 4 segundos | 5 | `F,4,5` |
| B | 7 segundos | 4 | `B,7,4` |
| L | 5 segundos | 3 | `L,5,3` |
| R | 2 segundos | 2 | `R,2,2` |

## Licença

Este projeto é licenciado sob a [Licença MIT](LICENSE).

Copyright © 2023 [Emanuel Cardoso Tavecia](https://github.com/emanueltavecia), Bernardo Fernandes Spillere, e Gabriel Dutra dos Santos.

A Licença MIT é uma licença permissiva de código aberto que permite usar, modificar e distribuir livremente este software, desde que você inclua o aviso de direitos autorais original e o texto da Licença MIT em sua distribuição.
