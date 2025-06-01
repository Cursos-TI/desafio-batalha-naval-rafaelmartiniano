⚓ ***Batalha Naval: Desafio de Programação em C***

Bem-vindo ao seu desafio de Batalha Naval! Este projeto é a sua chance de mergulhar no mundo da programação C, explorando o poder das matrizes e vetores para construir um jogo clássico. Dividido em três níveis progressivos, você adicionará funcionalidades e complexidade a cada etapa, aprimorando suas habilidades de codificação.

🏅 **Nível 1: Novato — As Primeiras Manobras**
Comece sua jornada dominando o básico do posicionamento de navios e a representação do tabuleiro.

🎯 Objetivos:
Defina o Tabuleiro: Use uma matriz para representar seu tabuleiro de Batalha Naval, inicializando todas as posições com 0 para indicar água.
Posicione Navios: Posicione dois navios (com tamanho fixo, por exemplo, 3 posições) no tabuleiro: um na vertical e outro na horizontal.
Marque os Navios: Represente as posições ocupadas pelos navios com o valor 3 na sua matriz.
Exiba o Mapa: Imprima o tabuleiro no console, mostrando claramente onde está a água (0) e onde estão seus navios (3).
➡️ Entrada e Saída:
Entrada: As coordenadas dos navios são definidas diretamente no seu código, usando variáveis.
Saída: O console exibirá o tabuleiro com os navios posicionados.
🏅 Nível 2: Aventureiro — Navegando em Águas Profundas
Expanda seu território! Neste nível, seu tabuleiro cresce, e você aprenderá a posicionar navios em novas e desafiadoras direções.

🚀 O que há de novo:
Tabuleiro 10x10: Redimensione seu tabuleiro para uma matriz 10x10.
Quatro Navios: Posicione um total de quatro navios.
Desafio Diagonal: Inclua dois navios posicionados na diagonal (tanto principal quanto secundária).
Validação Essencial: Certifique-se de que todos os navios estejam dentro dos limites do tabuleiro e, crucialmente, que não se sobreponham.
➡️ Entrada e Saída:
Entrada: Coordenadas e orientações dos navios continuarão sendo fixadas no código.
Saída: Uma representação completa do tabuleiro 10x10 será impressa, mostrando 0 (água) e 3 (navios).
🏅 Nível 3: Mestre — Arsenal de Habilidades
O combate se torna estratégico! Você implementará habilidades especiais com áreas de efeito únicas para uma nova camada de tática.

✨ O Desafio Final:
Habilidades Especiais: Crie três matrizes separadas para definir as áreas de efeito de habilidades:
Cone: Uma área em forma de triângulo, expandindo-se a partir do ponto de origem para baixo.
Cruz: Uma área em forma de cruz, centrada no ponto de origem.
Octaedro (Losango): Uma área em forma de losango, também centrada no ponto de origem.
Representação Interna: Dentro das matrizes de habilidade, 1 indica uma posição afetada e 0 uma posição não afetada.
Integração ao Tabuleiro: Escolha um ponto de origem no tabuleiro principal para cada habilidade. A matriz da habilidade será sobreposta e centralizada nesse ponto.
Visualização Distinta: As posições do tabuleiro afetadas por uma habilidade (indicadas por 1 na matriz de habilidade) devem ser marcadas com um novo valor, como 5.
Lógica Dinâmica: Use loops aninhados e condicionais para construir as matrizes de habilidade e sobrepô-las ao tabuleiro.
➡️ Entrada e Saída:
Entrada: As posições das habilidades no tabuleiro são definidas diretamente no código.
Saída: O programa exibirá o tabuleiro final no console, usando caracteres claros para cada elemento:
~: Água (0)
#: Navio (3)
X: Área de Habilidade (5)
Exemplos de Matrizes de Habilidade (Submatriz):
Habilidade Cone:

0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
Habilidade Cruz:

0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
Habilidade Octaedro (Losango):

0 0 1 0 0
0 1 1 1 0
0 0 1 0 0
## 🛠️ Como Baixar e Testar o Jogo
Quer ver o seu Batalha Naval em ação? Siga estes passos simples para clonar o repositório, compilar e executar o jogo no seu computador!

📥 1. **Faça o Download do Projeto:**
Abra seu terminal (ou Prompt de Comando/PowerShell no Windows) e use o comando git clone para baixar o projeto:

Bash

git clone https://github.com/SEU_USUARIO_GITHUB/SEU_REPOSITORIO.git
⚠️ Importante: Substitua https://github.com/SEU_USUARIO_GITHUB/SEU_REPOSITORIO.git pelo link real do seu repositório GitHub.

Após o download, acesse a pasta do projeto:

Bash

cd SEU_REPOSITORIO
⚠️ Importante: Substitua SEU_REPOSITORIO pelo nome da pasta que foi criada (geralmente o nome do seu repositório).

⚙️ **2. Prepare-se para a Batalha (Compilação):**
Para que seu computador entenda e execute o código em C, você precisará compilá-lo. Certifique-se de ter um compilador C instalado no seu sistema (o GCC é uma excelente opção e é gratuito).

No terminal, digite o seguinte comando para compilar o jogo:

Bash

gcc batalha_naval.c -o batalha_naval
O que isso faz? Este comando pega o arquivo batalha_naval.c (seu código fonte) e o transforma em um programa executável chamado batalha_naval.

▶️ 3. Hora de Jogar! (Execução):
Com o programa compilado, você já pode iniciar a visualização do seu tabuleiro e suas habilidades! No terminal, digite:

Bash

./batalha_naval
E pronto! O programa executará, exibindo o tabuleiro com os navios e as áreas de efeito das habilidades.

📋 **Requisitos Fundamentais (Comuns a Todos os Níveis):**
Entrada de Dados Fixa: Todos os valores (coordenadas, tamanhos, posições de habilidade) são definidos diretamente no código via variáveis. Não há entrada de usuário.
Estrutura com Matrizes: A representação do tabuleiro e das áreas de efeito deve ser feita com matrizes.
Exibição Clara: Os resultados devem ser impressos no console de forma organizada e fácil de entender.
Performance Eficiente: O código deve rodar de forma fluida, sem atrasos perceptíveis.
Documentação: Mantenha o código bem documentado, com comentários que expliquem a lógica e o propósito de cada parte.
Legibilidade: Priorize um código limpo, organizado e fácil de ler, com nomes de variáveis descritivos e indentação consistente.
Boa sorte em sua missão, comandante! Que suas habilidades de programação o guiem à vitória neste desafio de Batalha Naval!

Atenciosamente,
**Rafael Martiniano (Aluno de Gestão em Tecnologia da Informação - Faculdade Estácio)**
