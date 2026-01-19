# 📚 RESUMO COMPLETO - EX00

## Índice
1. [VECT2 - Vetor 2D](#1-vect2---vetor-2d)
2. [POLYSET - Herança Múltipla e Polimorfismo](#3-polyset---herança-múltipla-e-polimorfismo)

---

# 1. VECT2 - Vetor 2D

## 📋 O que é pedido
Criar uma classe `vect2` representando um vetor matemático 2D com inteiros.

## 📁 Arquivos esperados
- `vect2.hpp`
- `vect2.cpp`

## 🎯 Funcionalidades obrigatórias
| Operação | Descrição |
|----------|-----------|
| `+` | Soma de vetores |
| `-` | Subtração de vetores |
| `*` | Multiplicação por escalar (dos dois lados!) |
| `[]` | Acesso por índice (0=x, 1=y) |
| `<<` | Impressão no formato `{x, y}` |
| `==` / `!=` | Comparação |

## 🔧 Implementação

### Header (vect2.hpp)
```cpp
#ifndef VECT2_H
#define VECT2_H

#include <iostream>

class vect2
{
private:
    int _x;
    int _y;

public:
    // OCF (Orthodox Canonical Form)
    vect2();
    vect2(int x, int y);
    vect2(const vect2& other);
    vect2& operator=(const vect2& other);
    ~vect2();

    // Aritméticos
    vect2 operator+(const vect2& other) const;
    vect2 operator-(const vect2& other) const;
    vect2 operator*(int scalar) const;

    // Acesso por índice
    int& operator[](int idx);
    const int& operator[](int idx) const;  // ⚠️ VERSÃO CONST!

    // Comparação
    bool operator==(const vect2& other) const;
    bool operator!=(const vect2& other) const;
};

// ⚠️ FUNÇÕES EXTERNAS (fora da classe)
std::ostream& operator<<(std::ostream& os, const vect2& v);
vect2 operator*(int scalar, const vect2& v);  // Para 3 * v funcionar
#endif
```

### Implementação (vect2.cpp)
```cpp
#include "vect2.hpp"

// OCF
vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}
vect2& vect2::operator=(const vect2& other) {
    if (this != &other) { _x = other._x; _y = other._y; }
    return *this;
}
vect2::~vect2() {}

// Aritméticos
vect2 vect2::operator+(const vect2& other) const {
    return vect2(_x + other._x, _y + other._y);
}
vect2 vect2::operator-(const vect2& other) const {
    return vect2(_x - other._x, _y - other._y);
}
vect2 vect2::operator*(int scalar) const {
    return vect2(_x * scalar, _y * scalar);
}

// Acesso por índice
int& vect2::operator[](int idx) {
    if (idx == 0) return _x;
    return _y;
}
const int& vect2::operator[](int idx) const {
    if (idx == 0) return _x;
    return _y;
}

// Comparação
bool vect2::operator==(const vect2& other) const {
    return _x == other._x && _y == other._y;
}
bool vect2::operator!=(const vect2& other) const {
    return !(*this == other);
}

// ⚠️ EXTERNOS
std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}
vect2 operator*(int scalar, const vect2& v) {
    return vect2(v[0] * scalar, v[1] * scalar);
}
```

## ⚠️ PONTOS IMPORTANTES PARA LEMBRAR

1. **Duas versões do operator[]**: uma normal e uma `const`!
2. **operator<< é externo** (friend ou usa operator[])
3. **Multiplicação dos dois lados**: `v * 3` E `3 * v` devem funcionar
4. **Formato de saída**: `{x, y}` com espaço após a vírgula
5. **Usar lista de inicialização** no construtor

---

# 2. POLYSET - Herança Múltipla e Polimorfismo

## 📋 O que é pedido
1. Implementar `searchable_array_bag` e `searchable_tree_bag`
2. Implementar classe `set` que wraps um `searchable_bag`

## 📁 Arquivos esperados
- `searchable_array_bag.hpp` / `.cpp`
- `searchable_tree_bag.hpp` / `.cpp`
- `set.hpp` / `.cpp`

## 🏗️ Hierarquia de Classes

```
        bag (abstract)
         │
    ┌────┴────┐
    │         │
array_bag  tree_bag     searchable_bag (abstract)
    │         │              │
    └────┬────┴──────────────┘
         │
searchable_array_bag    searchable_tree_bag
         │                    │
         └────────┬───────────┘
                  │
                 set (wrapper)
```

## 🔧 Implementação

### Classes Existentes (fornecidas)

**bag.hpp** (interface abstrata):
```cpp
class bag {
public:
    virtual void insert(int) = 0;
    virtual void insert(int*, int) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
};
```

**searchable_bag.hpp** (interface abstrata):
```cpp
class searchable_bag : virtual public bag {
public:
    virtual bool has(int) const = 0;
};
```

### Parte 1: searchable_array_bag

**searchable_array_bag.hpp**:
```cpp
#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
public:
    searchable_array_bag();
    searchable_array_bag(const searchable_array_bag& other);
    searchable_array_bag& operator=(const searchable_array_bag& other);
    ~searchable_array_bag();

    bool has(int value) const;
};
#endif
```

**searchable_array_bag.cpp**:
```cpp
#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other)
    : array_bag(other) {}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other) {
    if (this != &other)
        array_bag::operator=(other);
    return *this;
}

searchable_array_bag::~searchable_array_bag() {}

// Busca linear simples
bool searchable_array_bag::has(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value)
            return true;
    }
    return false;
}
```

### Parte 1: searchable_tree_bag

**searchable_tree_bag.hpp**:
```cpp
#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
private:
    static bool search_node(node* n, int value);  // ⚠️ Função auxiliar

public:
    searchable_tree_bag();
    searchable_tree_bag(const searchable_tree_bag& other);
    searchable_tree_bag& operator=(const searchable_tree_bag& other);
    ~searchable_tree_bag();

    bool has(int value) const;
};
#endif
```

**searchable_tree_bag.cpp**:
```cpp
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other)
    : tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
    if (this != &other)
        tree_bag::operator=(other);
    return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}

// Busca binária na árvore (recursiva)
bool searchable_tree_bag::search_node(node* n, int value) {
    if (n == NULL) return false;
    if (n->value == value) return true;
    if (value < n->value)
        return search_node(n->l, value);
    else
        return search_node(n->r, value);
}

bool searchable_tree_bag::has(int value) const {
    return search_node(tree, value);
}
```

### Parte 2: set (wrapper)

**set.hpp**:
```cpp
#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag* _bag;  // ⚠️ Ponteiro! NÃO ownership

public:
    set(searchable_bag& bag);
    set(const set& other);
    set& operator=(const set& other);
    ~set();

    void insert(int value);
    void insert(int* array, int size);
    bool has(int value) const;
    void print() const;
    void clear();

    searchable_bag& get_bag() const;
};
#endif
```

**set.cpp**:
```cpp
#include "set.hpp"

set::set(searchable_bag& bag) : _bag(&bag) {}
set::set(const set& other) : _bag(other._bag) {}

set& set::operator=(const set& other) {
    if (this != &other)
        _bag = other._bag;
    return *this;
}

set::~set() {}  // ⚠️ NÃO deleta o bag!

// ⚠️ DIFERENÇA DO SET: não insere duplicatas!
void set::insert(int value) {
    if (!_bag->has(value))
        _bag->insert(value);
}

void set::insert(int* array, int size) {
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

bool set::has(int value) const { return _bag->has(value); }
void set::print() const { _bag->print(); }
void set::clear() { _bag->clear(); }
searchable_bag& set::get_bag() const { return *_bag; }
```

## ⚠️ PONTOS IMPORTANTES PARA LEMBRAR

1. **Herança virtual** em `searchable_bag : virtual public bag` resolve o problema do diamante
2. **Herança múltipla**: `searchable_array_bag` herda de `array_bag` E `searchable_bag`
3. **OCF obrigatório** em todas as classes
4. **set NÃO possui ownership** do bag (não deleta no destrutor)
5. **set.insert** verifica se já existe antes de inserir (diferença de bag)
6. **tree_bag** usa busca binária (mais eficiente)
7. **array_bag** usa busca linear

---

# 📝 CHECKLIST PRÉ-EXAME

## Orthodox Canonical Form (OCF)
- [ ] Construtor padrão
- [ ] Construtor de cópia
- [ ] Operador de atribuição (com `if (this != &other)`)
- [ ] Destrutor

## Boas Práticas
- [ ] Métodos que não modificam objeto → `const`
- [ ] Passar objetos grandes por referência → `const Type&`
- [ ] Retornar referência em `operator=`, `operator+=`, etc.
- [ ] Include guards (`#ifndef` / `#pragma once`)

## Operadores Externos
```cpp
// Dentro da classe (pode acessar membros privados)
Type operator+(const Type& other) const;

// Fora da classe (usa métodos públicos)
std::ostream& operator<<(std::ostream& os, const Type& obj);
Type operator*(int scalar, const Type& v);  // comutatividade
```

## Padrões Comuns
```cpp
// Comparação: definir < e == e derivar o resto
bool operator>(const T& o) const  { return o < *this; }
bool operator!=(const T& o) const { return !(*this == o); }
bool operator<=(const T& o) const { return !(*this > o); }
bool operator>=(const T& o) const { return !(*this < o); }

// Operadores compostos
T& operator+=(const T& o) { *this = *this + o; return *this; }

// Pre/Post incremento
T& operator++()    { /* modifica */ return *this; }  // ++x
T operator++(int)  { T t(*this); ++(*this); return t; } // x++
```

---

# 🧠 DICAS FINAIS

1. **Leia o subject com atenção** - cada palavra importa
2. **Compile frequentemente** - não espere terminar tudo
3. **Teste com o main fornecido** primeiro
4. **Cuidado com const** - versão const e não-const de métodos
5. **Herança múltipla** - cuidado com ambiguidades
6. **Não esqueça os includes** corretos
7. **Formatos de saída** - espaços, vírgulas, chaves importam!
---

# 🎯 REGRAS PRÁTICAS - COMO LEMBRAR

## 🔑 REGRA DO CONST - "Modifica ou não modifica?"

### Pergunta: O método MODIFICA o objeto?

```
                    ┌─────────────────────┐
                    │  O método modifica  │
                    │    o objeto?        │
                    └──────────┬──────────┘
                               │
              ┌────────────────┴────────────────┐
              ▼                                 ▼
           NÃO                                 SIM
     ┌─────────────┐                    ┌─────────────┐
     │  USA CONST  │                    │  SEM CONST  │
     └─────────────┘                    └─────────────┘

     Exemplos:                          Exemplos:
     - operator+   → const              - operator=   → sem const
     - operator==  → const              - operator+=  → sem const
     - print()     → const              - operator++  → sem const
     - has()       → const              - insert()    → sem const
     - operator[]  → DUAS VERSÕES!      - clear()     → sem const
```

### Resumo mental rápido:
| Se o método... | Então... |
|----------------|----------|
| Só OLHA os dados | `const` no final |
| MUDA os dados | Sem `const` |
| Retorna referência para modificar | DUAS versões |

## 🔑 REGRA DAS DUAS VERSÕES - "Posso modificar o que retorna?"

### Quando preciso de DUAS versões do mesmo método?

**Pergunta**: O método retorna uma **referência** que o usuário pode querer **modificar**?

```cpp
// Exemplo: operator[]

// Se eu fizer: v[0] = 10;  → Preciso da versão NÃO-const
int& operator[](int idx);

// Se eu fizer: const vect2 v(1,2); cout << v[0];  → Preciso da versão CONST
const int& operator[](int idx) const;
```

### Quando isso acontece?
| Situação | Precisa de 2 versões? |
|----------|----------------------|
| `operator[]` | ✅ SIM |
| `at()`, `get()` que retorna referência | ✅ SIM |
| `operator+` | ❌ NÃO (retorna cópia) |
| `operator==` | ❌ NÃO (retorna bool) |
| `print()` | ❌ NÃO (retorna void) |

### Template mental:
```cpp
// Versão normal (objeto pode ser modificado pelo retorno)
TIPO& metodo(params) { return _membro; }

// Versão const (objeto const, retorno const)
const TIPO& metodo(params) const { return _membro; }
```

## 🔑 REGRA DO RETORNO - "O que eu retorno?"

```
┌────────────────────────────────────────────────────────────────┐
│                     TIPO DE RETORNO                            │
├────────────────────────────────────────────────────────────────┤
│                                                                │
│  operator=, +=, -=, *=, ++x, --x                              │
│  ─────────────────────────────────                            │
│  Retorna: REFERÊNCIA para *this                               │
│  Tipo:    T&                                                   │
│  Por quê? Permite encadeamento: a = b = c                     │
│                                                                │
│  ─────────────────────────────────                            │
│  operator+, -, *, x++, x--                                    │
│  ─────────────────────────────────                            │
│  Retorna: CÓPIA (objeto novo)                                 │
│  Tipo:    T                                                    │
│  Por quê? Não modifica o original                             │
│                                                                │
│  ─────────────────────────────────                            │
│  operator==, !=, <, >, <=, >=                                 │
│  ─────────────────────────────────                            │
│  Retorna: bool                                                │
│                                                                │
│  ─────────────────────────────────                            │
│  operator<<  (stream)                                          │
│  ─────────────────────────────────                            │
│  Retorna: std::ostream&                                        │
│  Por quê? Permite encadeamento: cout << a << b                │
│                                                                │
└────────────────────────────────────────────────────────────────┘
```

## 🔑 REGRA DO PARÂMETRO - "Cópia ou referência?"

```
┌─────────────────────────────────────────────────────────────┐
│  TIPO DO PARÂMETRO                                          │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  Tipo primitivo (int, char, bool, float)?                   │
│  → Passa por VALOR: func(int x)                            │
│                                                             │
│  Objeto/Classe?                                             │
│  → Passa por REFERÊNCIA CONST: func(const Type& x)         │
│                                                             │
│  Precisa modificar o original?                              │
│  → Passa por REFERÊNCIA: func(Type& x)                     │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

## 🔑 REGRA DO OPERADOR EXTERNO - "Dentro ou fora da classe?"

### Quando o operador vai FORA da classe?

| Operador | Dentro ou Fora? | Por quê? |
|----------|-----------------|----------|
| `+`, `-`, `*`, `/` | DENTRO | Acessa membros privados |
| `==`, `!=`, `<`, `>` | DENTRO | Acessa membros privados |
| `=`, `+=`, `-=` | DENTRO | Modifica o próprio objeto |
| `<<` (ostream) | **FORA** | Primeiro param é ostream, não *this |
| `3 * v` (escalar à esquerda) | **FORA** | Primeiro param é int, não objeto |

### Padrão para operator<< :
```cpp
// SEMPRE ASSIM (decora isso!)
std::ostream& operator<<(std::ostream& os, const Tipo& obj) {
    os << /* conteudo */;
    return os;
}
```

### Padrão para multiplicação comutativa:
```cpp
// v * 3 → dentro da classe
Tipo Tipo::operator*(int scalar) const { ... }

// 3 * v → FORA da classe
Tipo operator*(int scalar, const Tipo& v) {
    return v * scalar;  // reusa o de dentro!
}
```

## 📋 CHEAT SHEET RÁPIDO

```cpp
class Tipo {
public:
    // === OCF (Orthodox Canonical Form) ===
    Tipo();                              // construtor padrão
    Tipo(const Tipo& o);                 // cópia
    Tipo& operator=(const Tipo& o);      // atribuição
    ~Tipo();                             // destrutor

    // === ARITMÉTICOS (criam objeto novo) ===
    Tipo operator+(const Tipo& o) const; // ← const!
    Tipo operator-(const Tipo& o) const;
    Tipo operator*(int n) const;

    // === COMPOSTOS (modificam *this) ===
    Tipo& operator+=(const Tipo& o);     // ← sem const, retorna ref
    Tipo& operator-=(const Tipo& o);

    // === INCREMENTO ===
    Tipo& operator++();                  // ++x (retorna ref)
    Tipo operator++(int);                // x++ (retorna cópia)

    // === COMPARAÇÃO ===
    bool operator==(const Tipo& o) const;
    bool operator<(const Tipo& o) const;
    // ... derivar os outros

    // === ACESSO (duas versões!) ===
    int& operator[](int i);              // versão normal
    const int& operator[](int i) const;  // versão const

    // === GETTERS (só leitura) ===
    int getValue() const;                // ← const!
    void print() const;                  // ← const!
};

// === EXTERNOS ===
std::ostream& operator<<(std::ostream& os, const Tipo& t);
Tipo operator*(int n, const Tipo& t);    // para n * t
```

## 🧪 TESTE MENTAL RÁPIDO

Antes de escrever qualquer método, faça essas 3 perguntas:

### 1️⃣ "Esse método MODIFICA o objeto?"
- NÃO → adiciona `const` no final
- SIM → sem `const`

### 2️⃣ "O que esse método RETORNA?"
- Modifica e continua usando → `T&` (referência)
- Cria algo novo → `T` (cópia)
- Só compara → `bool`
- Nada → `void`

### 3️⃣ "Preciso de DUAS versões?"
- Retorna referência para dado interno? → SIM, duas versões
- Caso contrário → NÃO

## 🎮 EXEMPLOS LADO A LADO

```cpp
// ❌ ERRADO                          // ✅ CORRETO

// Falta const (não modifica!)
bool operator==(const T& o) {         bool operator==(const T& o) const {
    return x == o.x;                      return x == o.x;
}                                     }

// Retorno errado (deve ser ref)
T operator=(const T& o) {             T& operator=(const T& o) {
    x = o.x;                              x = o.x;
    return *this;                         return *this;
}                                     }

// Falta versão const do []
int& operator[](int i) {              int& operator[](int i) { return arr[i]; }
    return arr[i];                    const int& operator[](int i) const { return arr[i]; }
}

// operator<< dentro da classe        // operator<< FORA da classe
void operator<<(ostream& os) {        ostream& operator<<(ostream& os, const T& t) {
    os << x;                              os << t.x;
}                                         return os;
                                      }
```
