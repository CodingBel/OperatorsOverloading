#include<iostream>

class Complex {
public:
	Complex();
	Complex(int, double);

	Complex operator+ (const Complex)const;
	bool operator== (const Complex)const;
	friend std::ostream& operator<< (std::ostream&, Complex);
	int getReal()const;
	double getImg()const;

private:
	int real{};
	double img{};
};

Complex::Complex() {
	this->real = 0;
	this->img = 0.0;
}

Complex::Complex(int real, double img) {
	this->real = real;
	this->img = img;
}

Complex Complex::operator+ (const Complex input)const {
	Complex temp{};

	temp.real = this->real + input.real;
	temp.img = this->img + input.img;

	return temp;
}

bool Complex::operator== (const Complex input) const {
	if (this->real == input.real && this->img == input.img)
		return true;
	else
		return false;
}

std::ostream& operator<< (std::ostream& Zout, const Complex input) {
	Zout << input.real << " " << input.img << std::endl;
	return Zout;
}

int Complex::getReal() const {
	return this->real;
}

double Complex::getImg() const {
	return this->img;
}

int main() {
	Complex c1(3, 1.1);
	Complex c2(2, 2.5);

	Complex c3 = c1 + c2;
	//Complex c3 = c1.operator+(c2); // Similar as teh line above 
	std::cout << c3.getReal() << " " << c3.getImg() << std::endl;

	Complex c4(5, 3.6);
	std::cout << "Checking equality returns: " << (c4 == c3) << std::endl;

	Complex c5(2, 4.9);
	std::cout << "\nUsing the overloaded operato<< we get: " << std::endl;
	std::cout << c5 << std::endl;

	return 0;
}

