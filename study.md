Mapa Mental Rank 04

1️⃣ N-Queens

Tipo: Backtracking

Fluxo:

Começa na coluna 0

Testa todas as linhas da coluna

Checa segurança (is_safe → mesma linha ou diagonal)

Se seguro → coloca rainha, chama recursão para próxima coluna

Ao terminar coluna n → imprime solução

Backtrack → remove rainha

Pontos críticos:

Diagonais: abs(col - i) == abs(row - tab[i])

Array tab[col] = row guarda posição

Dica: Pense coluna por coluna, não linha por linha.

2️⃣ Permutações de String

Tipo: Backtracking

Fluxo:

Ordena a string

Para cada posição, tenta todas letras não usadas

Marca letra como usada, preenche resultado, chama recursão

Ao chegar no final → imprime resultado

Backtrack → desmarca letra

Pontos críticos:

Evitar repetição usando array used

Sempre gerar em ordem lexicográfica

Dica: Visualize como árvore de escolhas por índice.

3️⃣ Subset Sum (Power Set)

Tipo: Combinatória / Backtracking

Fluxo:

Para cada número → incluir ou não no subset

Se subset completo → checa soma

Se soma == target → imprime subset

Recursão para próximos elementos

Pontos críticos:

Recursão com parâmetro len ou index

Array temporário para subset parcial

Dica: Cada elemento tem dois caminhos, desenhe árvore binária.

4️⃣ Parênteses Balanceados

Tipo: Backtracking / String Manipulation

Fluxo:

Conta parênteses desbalanceados (ft_balance)

Remove parênteses de forma recursiva (ft_backtrack)

Se string balanceada → imprime

Pontos críticos:

Minimizar número de remoções

Cada posição → tentar remover ou manter

Dica: Conte sempre quantos abertos e fechados faltam.

5️⃣ Travelling Salesman (TSP)

Tipo: Backtracking / Permutação

Fluxo:

Começa em cidade 0

Marca cidades visitadas

Recursivamente tenta cidades não visitadas

Ao visitar todas → soma distância + volta para cidade 0

Atualiza menor distância (best_route)

Pontos críticos:

Backtracking = marca/desmarca cidade

Acumula distância ao longo da recursão

Dica: Tamanho pequeno (<=10) → força bruta ok.

6️⃣ ft_popen / picoshell

Tipo: Pipes + Fork + Exec

Fluxo ft_popen:

Criar pipe

Fork → filho dup2 para STDOUT/STDIN

Executa comando

Pai fecha lado não usado, retorna FD

Fluxo picoshell:

Para cada comando → criar pipe com próximo

Fork → conecta entrada/saída

Exec

Pai espera todos filhos

Pontos críticos:

Fechar FDs não usados

Lidar com último comando sem pipe

Dica: Pense fluxo de dados entre processos, STDOUT → pipe → STDIN.

7️⃣ Sandbox

Tipo: Segurança / Time Limit

Fluxo:

Fork → executa função isolada

Alarm → mata se ultrapassa timeout

Waitpid → pega status da execução

Pontos críticos:

Tratar sinais (SIGALRM)

Status: exit code ou signal

Dica: Controle tempo + segurança → função isolada do processo pai.

8️⃣ JSON Parser

Tipo: Parser recursivo

Fluxo:

Peek → decide tipo (", {, dígito)

Parse String → ler até "

Parse Int → usar fscanf

Parse Map → recursivo { key:value, ... }

Free JSON → liberar memória

Pontos críticos:

Alocação dinâmica (strdup, realloc)

Checar erros / EOF

Dica: Cada token tem função → parser recursivo.

9️⃣ Expressão Matemática (Parser de Soma e Multiplicação)

Tipo: Parser recursivo

Fluxo:

Expr → Term + Expr ou Term

Term → Factor * Term ou Factor

Factor → número ou (Expr)

Avaliação pós-parse → árvore de execução

Pontos críticos:

Precedência: * antes de +

Criar árvore de nodes (ADD, MULTI, VAL)

Dica: Pense top-down parsing → construir árvore e depois avaliar.


1️⃣ N-Queens (Backtracking)
Coluna 0 → testar todas linhas
       ↓
  is_safe? ──> não → próxima linha
       ↓ sim
  Coloca rainha
       ↓
  Próxima coluna (recursão)
       ↓
  Coluna == n? → imprime solução
       ↓
Backtrack → remove rainha
Dica: Diagonal = abs(col-i) == abs(row-tab[i])

2️⃣ Permutações de String
Ordena string → inicio
       ↓
Para cada letra não usada:
       ↓
Marca usada → coloca no resultado
       ↓
Chama recursão para próxima posição
       ↓
Resultado completo? → imprime
       ↓
Backtrack → desmarca letra


💡 Dica: Array used controla repetição, gera ordem lexicográfica

3️⃣ Subset Sum
Elemento i:
   ├── Incluir no subset
   │       ↓
   │   Recursão i+1
   │
   └── Não incluir
           ↓
       Recursão i+1


✅ Ao final, soma == target → imprime subset
💡 Dica: Cada elemento = 2 caminhos → árvore binária

4️⃣ Parênteses Balanceados
Conta parênteses desbalanceados → balance
       ↓
Para cada '(' ou ')':
   ├── Remover → recursão +1 change
   └── Manter
       ↓
Balance == 0? → imprime string


💡 Dica: Minimizar remoções

5️⃣ Travelling Salesman (TSP)
Começa cidade 0 → visited[0] = true
       ↓
Para cada cidade não visitada:
   ├── Marca visitada
   ├── Soma distância acumulada
   └── Recursão
       ↓
Se todas visitadas → soma distância + volta para 0
       ↓
Atualiza best_route


💡 Dica: <=10 cidades → força bruta

6️⃣ ft_popen / picoshell
Criar pipe
       ↓
Fork → filho dup2 (STDIN/STDOUT)
       ↓
Exec comando
       ↓
Pai fecha lado não usado
       ↓
Retorna FD


💡 Dica: Conectar STDOUT → pipe → STDIN do próximo comando

7️⃣ Sandbox
Fork → filho executa função
       ↓
Alarm(timeout)
       ↓
Pai espera filho (waitpid)
       ↓
Exceção?
   ├── SIGALRM → timeout → kill filho
   └── Exit code != 0 → falha


💡 Dica: Isola execução e controla tempo

8️⃣ JSON Parser
Peek → decide tipo
   ├── '"' → parse_string
   ├── dígito ou '-' → parse_int
   └── '{' → parse_map (recursivo)
       ↓
Map:
   ├── ler key (string)
   ├── espera ':'
   ├── parse value (parser recursivo)
   └── aceitar ',' ou '}'


💡 Dica: Liberar memória (strdup, realloc)

9️⃣ Expressão Matemática (Parser)
Expr → Term (+ Expr ou Term)
Term → Factor (* Term ou Factor)
Factor → número ou (Expr)
       ↓
Construir árvore:
   ├── ADD
   ├── MULTI
   └── VAL
       ↓
Eval_tree → recursivamente


💡 Dica: Precedência: * > +

Rank 04 – Cheatsheet Mental
1. N-Queens

Representação: tab[col] = row → posição da rainha em cada coluna.

is_safe: checa se nenhuma rainha está na mesma linha ou diagonal.

Mesma linha: tab[i] == row

Diagonal: abs(i - col) == abs(tab[i] - row)

Backtracking:

Coloca rainha na coluna col.

Se safe, vai para col+1.

Se col == n → imprime solução.

Dica: visualize a árvore de recursão e como o array cresce.

2. Permutations

Sorted primeiro (para saída lexicográfica).

Recursão com used[i] → marca se caractere já está na permutação.

Fluxo:

Para cada índice i não usado:

Coloca str[i] em result[dep]

Marca usado[i] = 1

Recurse dep+1

Desmarca usado[i]

Dica: trace permutações pequenas manualmente.

3. Subset Sum (powerset)

Array res guarda subset atual.

Backtracking: incluir ou não cada elemento.

Checa soma → se soma == target → imprime.

Fluxo:

Escolhe elemento i: incluir → recurse

Não incluir → recurse

Terminar quando i == size.

4. Parentheses Balance

Contar parênteses: unclosed e unopened.

Remover parênteses inválidos recursivamente:

Para cada parêntese, tenta remover

Chama recursão com changes+1

Quando ft_balance == 0 → imprime

Dica: visualize árvore de decisões (remover ou não cada parêntese).

5. TSP (Traveling Salesman)

Array de pontos (x, y)

Visited[] marca cidades já visitadas

Fluxo:

Marca cidade atual como visitada

Recurse para todas cidades não visitadas

Quando todas visitadas → soma distância de volta à cidade inicial

Guarda mínimo (best_route)

Dica: desenhe 3-5 pontos e percorra manualmente.

6. Pipe / Shell

picoshell: múltiplos comandos ligados por pipe

Fluxo:

Para cada comando:

Se próximo existe → cria pipe

fork()

Filho dup2 para stdin/stdout correto

execvp(cmd)

Pai fecha pipe anterior e espera filhos

Dica: memorize ordem de pipe, fork, dup2, execvp, close.

7. Sandbox

Fork + alarm + waitpid

Filho: f() + exit(0)

Pai:

Configura alarm(timeout)

waitpid

Se timeout → kill(pid, SIGKILL)

Saídas: nice function / bad function (exit code / sinal)

8. JSON Parser

Tipos: MAP / STRING / INTEGER

Fluxo de parser:

peek → decide tipo

parse_string: entre "..."

parse_int: scanf %d

parse_map: { key : value, ... }

Free: recursivo para MAP e STRING

Serialize: recursivo, imprime {} ou "string" ou integer

9. Expression Parser

Nó: ADD / MULTI / VAL

Recursão: expr → term → factor

factor: número ou (expr)

term: factor * factor ...

expr: term + term ...

Eval_tree: recursivo, percorre esquerda/direita
