#include "bigint.hpp"

void bigint::removeLeadingZeros()
{
	while (digits.size() > 1 && digits.back() == 0)
		digits.pop_back();
}

// OCF
bigint::bigint()
{
	digits.push_back(0);
}

bigint::bigint(int n)
{
	if (n == 0)
	{
		digits.push_back(0);
		return;
	}

	while (n > 0)
	{
		digits.push_back(n % 10);
		n /= 10;
	}
}

bigint::bigint(const bigint& other)
{
	digits = other.digits;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits = other.digits;
	return *this;
}

bigint::~bigint()
{
}

// Operadores aritméticos
bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.digits.clear();

	int carry = 0;
	size_t maxSize = std::max(digits.size(), other.digits.size());

	for (size_t i = 0; i < maxSize || carry; i++)
	{
		int sum = carry;
		if (i < digits.size())
			sum += digits[i];
		if (i < other.digits.size())
			sum += other.digits[i];

		result.digits.push_back(sum % 10);
		carry = sum / 10;
	}

	result.removeLeadingZeros();
	return result;
}

// Operadores compostos
bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

// Incremento / decremento
bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp(*this);
	++(*this);
	return temp;
}

// bitshift
bigint bigint::operator<<(int shift) const
{
	if (shift <= 0 || (digits.size() == 1 && digits[0] == 0))
		return *this;

	bigint result = *this;
	result.digits.insert(result.digits.begin(), shift, 0);
	return result;
}

bigint& bigint::operator<<=(int shift)
{
	*this = *this << shift;
	return *this;
}

bigint bigint::operator>>(int shift) const
{
	if (shift <= 0)
		return *this;

	if ((size_t)shift >= digits.size())
		return bigint(0);

	bigint result;
	result.digits.clear();

	for(size_t i = shift; i < digits.size(); i++)
		result.digits.push_back(digits[i]);

	result.removeLeadingZeros();
	return result;
}

bigint bigint::operator>>(const bigint& shift) const
{
	return *this >> shift.toInt();
}

bigint& bigint::operator>>=(int shift)
{
	*this = *this >> shift;
	return *this;
}

bigint& bigint::operator>>=(const bigint& shift)
{
	*this = *this >> shift.toInt();
	return *this;
}

// Operadores de comparação
bool bigint::operator<(const bigint& other) const
{
	if (digits.size() != other.digits.size())
		return digits.size() < other.digits.size();

	// Compara do dígito mais significativo para o menos
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] != other.digits[i])
			return digits[i] < other.digits[i];
	}

	return false; // São iguais
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator==(const bigint& other) const
{
	return digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const
{
	return digits != other.digits;
}

bool bigint::operator<=(const bigint& other) const
{
	return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}


std::ostream& operator<<(std::ostream& os, const bigint& num)
{
	for (int i = num.digits.size() - 1; i >= 0; i--)
		os << num.digits[i];
	return os;
}

int bigint::toInt() const
{
	int result = 0;
	int multiplier = 1;

	for (size_t i = 0; i < digits.size(); i++)
	{
		result += digits[i] * multiplier;
		multiplier *= 10;
	}

	return result;
}
