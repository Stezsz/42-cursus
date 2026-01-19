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
