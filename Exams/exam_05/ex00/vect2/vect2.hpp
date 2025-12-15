/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:13:50 by tborges-          #+#    #+#             */
/*   Updated: 2025/11/03 16:31:57 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_H
#define VECT2_H

#include <iostream>

class vect2
{
	private:
		int _x;
		int _y;

	public:
		// OCF
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		// Operadores aritméticos
		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(int scalar) const;
		vect2 operator-() const;

		// Operador compostos
		vect2& operator+=(const vect2& other);
		vect2& operator-=(const vect2& other);
		vect2& operator*=(int scalar);

		// Incremento / Decremento
		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		// Acesso por índice
		int& operator[](int idx);
		const int& operator[](int idx) const;

		// Comparação
		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v);
vect2 operator*(int scalar, const vect2& v);

#endif
