#pragma once
#include <iostream>
class Polynom {
private:
	double* m_arr;
	int m_degree;
	static int count;
	Polynom derivative()const;
public:
	Polynom();
	Polynom(int);
	Polynom(int,double*);
	Polynom(const Polynom&);
	~Polynom();
	static int get_count();
	Polynom& operator=(const Polynom&);
	double& operator[](int);
	double operator[](int)const;
	double operator()(double)const;
	friend std::istream& operator>>(std::istream&, Polynom&);
	friend std::ostream& operator<<(std :: ostream&, const Polynom&);
	bool operator==(const Polynom&)const;
	bool operator!= (const Polynom&)const;
	Polynom operator+(const Polynom&)const;
	Polynom operator-(const Polynom&)const;
	Polynom operator*(const Polynom&)const;
	Polynom operator/(const Polynom&)const;
	Polynom operator%(const Polynom&)const;
	Polynom& operator+=(const Polynom&);
	Polynom& operator-=(const Polynom&);
	Polynom& operator*=(const Polynom&);
	Polynom& operator/=(const Polynom&);
	Polynom& operator%=(const Polynom&);
	Polynom derivative(int)const;



};
