#pragma once

#include <vector>
#include <iostream>
#include <string>

class bigint
{
	private:
		std::vector<int> digits;

		void removeLeadingZeros();

	public:
		// OCF
		bigint();
		bigint(int n);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		// Operadores aritméticos
		bigint operator+(const bigint& other) const;

		// Operadores compostos
		bigint& operator+=(const bigint& other);

		// Incremento / decremento
		bigint& operator++();
		bigint operator++(int);

		// bitshift
		bigint operator<<(int shift) const;
		bigint& operator<<=(int shift);
		bigint operator>>(int shift) const;
		bigint operator>>(const bigint& shift) const;
		bigint& operator>>=(int shift);
		bigint& operator>>=(const bigint& shift);

		// Operadores de comparação
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;


		friend std::ostream& operator<<(std::ostream& os, const bigint& num);
		int toInt() const;
};
