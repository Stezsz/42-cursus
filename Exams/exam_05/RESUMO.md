# 📚 RESUMO COMPLETO - EX00

## Índice
1. [VECT2 - Vetor 2D](#1-vect2---vetor-2d)
2. [POLYSET - Herança Múltipla e Polimorfismo](#3-polyset---herança-múltipla-e-polimorfismo)

---

# 1. VECT2 - Vetor 2D

## 🔧 Implementação

### Header (vect2.hpp)
```cpp
#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int _x;
		int _y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(int scalar) const;
		vect2 operator-() const;

		vect2& operator+=(const vect2& other);
		vect2& operator-=(const vect2& other);
		vect2& operator*=(int scalar);

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		int& operator[](int idx);
		const int& operator[](int idx) const;

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v);
vect2 operator*(int scalar, const vect2& v);

#endif
```

### Implementação (vect2.cpp)
```cpp
#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0)
{
}

vect2::vect2(int x, int y) : _x(x), _y(y)
{
}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y)
{
}

vect2& vect2::operator=(const vect2& other)
{
	if(this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

vect2::~vect2()
{
}

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(_x + other._x, _y + other._y);
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(_x - other._x, _y - other._y);
}

vect2 vect2::operator*(int scalar) const
{
	return vect2(_x * scalar, _y * scalar);
}

vect2 vect2::operator-() const
{
	return vect2(-_x, -_y);
}

vect2& vect2::operator+=(const vect2& other)
{
	*this = *this + other;
	return *this;
}

vect2& vect2::operator-=(const vect2& other)
{
	*this = *this - other;
	return *this;
}

vect2& vect2::operator*=(int scalar)
{
	*this = *this * scalar;
	return *this;
}

vect2& vect2::operator++()
{
	++_x;
	++_y;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return temp;
}

vect2& vect2::operator--()
{
	--_x;
	--_y;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return temp;
}

int& vect2::operator[](int idx)
{
	if(idx == 0)
		return _x;
	return _y;
}

const int& vect2::operator[](int idx) const
{
	if(idx == 0)
		return _x;
	return _y;
}

bool vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}

bool vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return os;
}

vect2 operator*(int scalar, const vect2& v)
{
	return vect2(v[0] * scalar, v[1] * scalar);
}

```
---

# 2. POLYSET - Herança Múltipla e Polimorfismo

## 🔧 Implementação

### Parte 1: searchable_array_bag

**searchable_array_bag.hpp**:
```cpp
#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "../array_bag.hpp"
#include "../searchable_bag.hpp"

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

searchable_array_bag::searchable_array_bag() : array_bag()
{
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other) : array_bag(other)
{
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this != &other)
		array_bag::operator=(other);
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{
}

bool searchable_array_bag::has(int value) const
{
	for (int i = 0; i < size; i++)
	{
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

#include "../tree_bag.hpp"
#include "../searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		static bool search_node(node* n, int value);

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
#include <cstdlib>

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool searchable_tree_bag::search_node(node* n, int value)
{
	if (n == 0)
		return false;

	if (n->value == value)
		return true;

	if (value < n->value)
		return search_node(n->l, value);
	else
		return search_node(n->r, value);
}

bool searchable_tree_bag::has(int value) const
{
	return search_node(tree, value);
}
```

### Parte 2: set (wrapper)

**set.hpp**:
```cpp
#ifndef SET_HPP
#define SET_HPP

#include "../searchable_bag.hpp"

class set
{
private:
	searchable_bag* _bag;

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

set::set(searchable_bag& bag) : _bag(&bag)
{
}

set::set(const set& other) : _bag(other._bag)
{
}

set& set::operator=(const set& other)
{
	if (this != &other)
		_bag = other._bag;
	return *this;
}

set::~set()
{
}

void set::insert(int value)
{
	if (!_bag->has(value))
		_bag->insert(value);
}

void set::insert(int* array, int size)
{
	for (int i = 0; i < size; i++)
		insert(array[i]);
}

bool set::has(int value) const
{
	return _bag->has(value);
}

void set::print() const
{
	_bag->print();
}

void set::clear()
{
	_bag->clear();
}

searchable_bag& set::get_bag() const
{
	return *_bag;
}
```

## 🔑 REGRA DO RETORNO - "O que eu retorno?"

```
╔══════════════════════════════════════════════════════════════╗
║                    OPERADORES C++                            ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  TIPO          │ const? │ RETORNA      │ EXEMPLO             ║
║  ─────────────────────────────────────────────────────────── ║
║  + - *         │  SIM   │ T (cópia)    │ T operator+(T&) const║
║  == < > != <=  │  SIM   │ bool         │ bool op==(T&) const ║
║  = += -= *=    │  NÃO   │ T& (*this)   │ T& operator=(T&)    ║
║                                                              ║
╠══════════════════════════════════════════════════════════════╣
║                    DUAS VERSÕES                              ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  ++x (pré)  │ T& operator++()      │ modifica, retorna *this║
║  x++ (pós)  │ T operator++(int)    │ guarda cópia, retorna  ║
║             │                      │ o antigo               ║
║  ─────────────────────────────────────────────────────────── ║
║  []         │ int& op[](int)       │ v[0] = 5 (modificar)   ║
║  [] const   │ const int& op[](int) const │ só leitura       ║
║                                                              ║
╠══════════════════════════════════════════════════════════════╣
║                      OCF                                     ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  T()                    │ construtor padrão                  ║
║  T(const T& o)          │ cópia                              ║
║  T& operator=(const T&) │ atribuição (if this != &o)         ║
║  ~T()                   │ destrutor                          ║
║                                                              ║
╠══════════════════════════════════════════════════════════════╣
║                    EXTERNOS                                  ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  ostream& operator<<(ostream& os, const T& t)                ║
║  T operator*(int n, const T& v)  // para 3 * v               ║
║                                                              ║
╚══════════════════════════════════════════════════════════════╝
```
---
```
┌────────────────────────────────────────┐
│         OPERADORES - RESUMO            │
├────────────────────────────────────────┤
│ + - *    → const, ret T                │
│ == < >   → const, ret bool             │
│ = += -=  → sem const, ret T& (*this)   │
├────────────────────────────────────────┤
│ ++x → T& operator++()                  │
│ x++ → T operator++(int) {guarda cópia} │
├────────────────────────────────────────┤
│ []  → int& op[](int)                   │
│ []c → const int& op[](int) const       │
├────────────────────────────────────────┤
│ OCF: T(), T(const T&), op=, ~T()       │
├────────────────────────────────────────┤
│ << → EXTERNO! ostream& op<<(os, t)     │
└────────────────────────────────────────┘
```
