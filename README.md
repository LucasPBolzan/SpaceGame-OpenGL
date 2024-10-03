# SpaceGame

## Descrição Geral
Este jogo foi desenvolvido usando a biblioteca OpenGL e GLFW. O jogador controla uma nave espacial com o objetivo de coletar estrelas espalhadas pelo cenário. A nave é controlada pelo teclado, e o jogo termina quando todas as estrelas disponíveis forem coletadas. Há também um planeta orbitando automaticamente no espaço, fornecendo movimento dinâmico ao cenário.

## Requisitos
- **Linguagem**: C++
- **Bibliotecas**:
  - GLFW: Biblioteca para criar janelas e lidar com entradas de teclado/mouse.
  - OpenGL: Para renderizar gráficos 2D.

## Estrutura Geral

### 1. Elementos Gráficos do Jogo
- **Nave espacial**: Controlada pelo jogador usando as teclas direcionais.
- **Estrelas**: Objetos coletáveis no espaço. O jogador deve coletar todas as estrelas para vencer o jogo.
- **Planetas estáticos**: Dois planetas fixos são desenhados no cenário.
- **Planeta em órbita**: Um planeta em movimento automático que orbita ao redor de um ponto fixo.
- **Fundo estelar**: Uma simulação de estrelas no fundo para ambientar o espaço.

### 2. Objetivo
O jogador controla uma nave espacial e deve coletar todas as estrelas (5 no total) distribuídas pelo cenário. O jogo termina quando todas as estrelas forem coletadas.

## Controles
- **Tecla para mover a nave**:
  - **Seta Esquerda**: Move a nave para a esquerda.
  - **Seta Direita**: Move a nave para a direita.
  - **Seta Cima**: Move a nave para cima.
  - **Seta Baixo**: Move a nave para baixo.

## Lógica do Jogo

### 1. Movimento da Nave
A nave é desenhada em coordenadas 2D e pode se mover nas direções X e Y conforme a entrada do usuário via teclas direcionais. A cada pressionamento de tecla, a posição da nave é atualizada, e a nave é renderizada na nova posição.

### 2. Gerenciamento das Estrelas
- As estrelas são geradas em posições aleatórias no cenário, com coordenadas X e Y variando entre -1 e 1.
- Cada estrela tem um estado `collected` (coletada ou não). Inicialmente, todas as estrelas estão disponíveis para coleta.
- Ao colidir com a nave, a estrela é considerada coletada, e o contador de estrelas coletadas é incrementado.
- Quando todas as estrelas forem coletadas, o jogo termina automaticamente.

### 3. Detecção de Colisão
A detecção de colisão entre a nave e as estrelas é feita verificando a distância euclidiana entre o centro da nave e o centro de cada estrela. Se essa distância for menor que um determinado raio, a colisão é detectada, e a estrela é marcada como coletada.

### 4. Movimento do Planeta Orbitante
Um dos planetas no cenário orbita ao redor de um ponto fixo, gerando movimento automático e contínuo. Esse movimento é baseado em funções trigonométricas (seno e cosseno) para garantir uma órbita circular suave.

## Funções Principais

### 1. `generateStars()`
Gera as estrelas em posições aleatórias no cenário. Cada estrela é criada com coordenadas X e Y entre -1 e 1 e adicionada ao vetor `stars`.

### 2. `drawStar(float x, float y)`
Desenha uma estrela na posição fornecida usando coordenadas 2D.

### 3. `drawSpaceship()`
Desenha a nave espacial controlada pelo jogador nas coordenadas atuais.

### 4. `drawPlanet(float x, float y, float radius, float r, float g, float b)`
Desenha um planeta na posição especificada com o raio e a cor fornecidos.

### 5. `renderScene()`
Responsável por renderizar todos os elementos gráficos do jogo: plano de fundo, estrelas, nave espacial e planetas.

### 6. `checkCollision(float x1, float y1, float x2, float y2, float radius)`
Verifica se há uma colisão entre dois objetos usando a distância entre suas coordenadas. É usada para verificar se a nave colidiu com uma estrela.

### 7. `processInput(GLFWwindow* window)`
Lida com as entradas do teclado, movimentando a nave para cima, baixo, esquerda ou direita.

### 8. `update()`
Atualiza o estado do jogo, como o movimento do planeta orbitante e verifica se há colisões entre a nave e as estrelas.

## Finalização do Jogo
- O jogo termina automaticamente quando todas as estrelas forem coletadas. O jogador pode acompanhar o progresso das estrelas coletadas pelo console, onde o número de estrelas coletadas é impresso a cada coleta.

## Fluxo do Jogo
1. **Início do Jogo**: A janela é criada, as estrelas são geradas em posições aleatórias, e a nave está posicionada em uma coordenada inicial fixa.
2. **Movimentação**: O jogador pode mover a nave pelo espaço, coletando estrelas.
3. **Coleta de Estrelas**: Cada estrela coletada desaparece do cenário e aumenta o contador de estrelas coletadas.
4. **Fim do Jogo**: Quando todas as estrelas são coletadas, o jogo encerra automaticamente.

## Melhorias Futuras
- **HUD (Heads-Up Display)**: Adicionar uma interface gráfica que exiba o número de estrelas coletadas em tempo real.
- **Níveis de Dificuldade**: Implementar mais níveis com diferentes obstáculos e mais estrelas.
- **Efeitos Visuais**: Melhorar os gráficos adicionando animações, partículas ou luzes.
- **Som**: Adicionar efeitos sonoros para quando a nave coleta estrelas ou se movimenta.

## Conclusão
Este jogo é um exemplo simples de como usar OpenGL com GLFW para criar um ambiente interativo em 2D, com movimentação de objetos, coleta de itens e detecção de colisão.
