# 📋 COLA RÁPIDA - OPERADORES C++

## 🎯 REGRA GERAL

| Tipo | `const`? | Retorna | Por quê? |
|------|----------|---------|----------|
| **Matemática** (`+`, `-`, `*`) | ✅ SIM | `T` (cópia) | Cria resultado novo |
| **Comparação** (`==`, `<`, `>`) | ✅ SIM | `bool` | Só olha, não muda |
| **Atribuição** (`=`, `+=`, `-=`) | ❌ NÃO | `T&` (*this) | Modifica o objeto |

---

## 📝 EXEMPLOS BÁSICOS

```cpp
// MATEMÁTICA - const, retorna cópia
T operator+(const T& o) const {
    T result;
    result.x = x + o.x;
    return result;
}

// COMPARAÇÃO - const, retorna bool
bool operator==(const T& o) const {
    return x == o.x;
}

// ATRIBUIÇÃO - sem const, retorna *this
T& operator=(const T& o) {
    if (this != &o)
        x = o.x;
    return *this;
}

T& operator+=(const T& o) {
    *this = *this + o;  // reusa o operator+
    return *this;
}
```

---

## 🔄 POR QUE ++ PRECISA DE DUAS VERSÕES?

Porque `++x` e `x++` fazem coisas diferentes!

```cpp
int x = 5;
int a = ++x;  // a = 6, x = 6  (incrementa ANTES de usar)
int b = x++;  // b = 6, x = 7  (usa ANTES de incrementar)
```

### Implementação:

```cpp
// PRÉ-INCREMENTO: ++x
// Incrementa e retorna o objeto JÁ MODIFICADO
T& operator++() {
    x++;
    return *this;  // retorna referência (o próprio objeto)
}

// PÓS-INCREMENTO: x++
// Retorna o valor ANTIGO e depois incrementa
T operator++(int) {  // o 'int' é só para diferenciar, não é usado
    T old = *this;   // guarda cópia do estado atual
    ++(*this);       // incrementa usando o pré-incremento
    return old;      // retorna o valor ANTIGO (cópia)
}
```

### Por que as diferenças?

| Versão | Assinatura | Retorna | Motivo |
|--------|------------|---------|--------|
| `++x` | `T& operator++()` | Referência | Retorna o objeto já modificado |
| `x++` | `T operator++(int)` | Cópia | Retorna como era ANTES de modificar |

### Exemplo prático:
```cpp
vect2 v(1, 2);

std::cout << ++v;  // Imprime {2, 3} - já incrementado
std::cout << v;    // Imprime {2, 3}

std::cout << v++;  // Imprime {2, 3} - valor antigo!
std::cout << v;    // Imprime {3, 4} - agora sim incrementou
```

---

## 🔢 POR QUE [] PRECISA DE DUAS VERSÕES?

Porque você pode ter um objeto `const` ou não!

```cpp
vect2 v(1, 2);        // objeto normal
const vect2 c(3, 4);  // objeto CONST (não pode ser modificado)

v[0] = 10;   // OK! Quer modificar
c[0] = 10;   // ERRO! c é const, não pode modificar
cout << c[0]; // OK! Só quer ler
```

### Implementação:

```cpp
// VERSÃO NORMAL - permite modificar o retorno
int& operator[](int idx) {
    if (idx == 0) return _x;
    return _y;
}

// VERSÃO CONST - para objetos const, retorno também é const
const int& operator[](int idx) const {
    if (idx == 0) return _x;
    return _y;
}
```

### Por que as diferenças?

| Versão | Quando usa | Permite |
|--------|------------|---------|
| `int& operator[](int)` | Objeto normal | Ler E escrever: `v[0] = 5` |
| `const int& operator[](int) const` | Objeto const | Só ler: `cout << c[0]` |

### Exemplo prático:
```cpp
void funcao(const vect2& v) {
    // v é const aqui!
    cout << v[0];  // OK - usa versão const
    v[0] = 10;     // ERRO! - não pode modificar const
}

void outra(vect2& v) {
    // v NÃO é const
    cout << v[0];  // OK - usa versão normal
    v[0] = 10;     // OK - pode modificar
}
```

### Se você não tiver a versão const:
```cpp
class vect2 {
    int& operator[](int idx);  // só essa versão
};

const vect2 c(1, 2);
cout << c[0];  // ERRO DE COMPILAÇÃO!
               // Não existe operator[] que funcione com const
```

---

## 📊 RESUMO VISUAL

```
┌─────────────────────────────────────────────────────────────┐
│  OPERADOR       │  VERSÕES  │  DIFERENÇA                   │
├─────────────────────────────────────────────────────────────┤
│  operator++     │     2     │  ++x vs x++ (pré vs pós)     │
│  operator--     │     2     │  --x vs x-- (pré vs pós)     │
│  operator[]     │     2     │  const vs não-const          │
│  operator+      │     1     │  (ou 2 se quiser 3 + v)      │
│  operator=      │     1     │  sempre modifica             │
│  operator==     │     1     │  sempre const                │
└─────────────────────────────────────────────────────────────┘
```

---

## ✅ CHECKLIST RÁPIDO

```cpp
// OCF - Orthodox Canonical Form
T();                          // construtor padrão
T(const T& o);                // cópia
T& operator=(const T& o);     // atribuição
~T();                         // destrutor

// Matemática (const, retorna cópia)
T operator+(const T& o) const;
T operator-(const T& o) const;
T operator*(int n) const;

// Comparação (const, retorna bool)
bool operator==(const T& o) const;
bool operator<(const T& o) const;

// Atribuição (sem const, retorna *this)
T& operator+=(const T& o);
T& operator-=(const T& o);

// Incremento (duas versões!)
T& operator++();       // ++x
T operator++(int);     // x++

// Acesso (duas versões!)
int& operator[](int i);
const int& operator[](int i) const;

// Stream (EXTERNO!)
std::ostream& operator<<(std::ostream& os, const T& t);
```
