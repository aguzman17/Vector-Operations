#include <iostream>
using namespace std;

class Vector
{
  protected:
      int size;
      double *p;
  public:
    Vector(int s);
    Vector(const Vector& vec);
    ~Vector();
    Vector operator= (const Vector& c);
    Vector operator+= (const Vector& c);
    Vector operator-= (const Vector& c);
    Vector operator*= (double &c);
    Vector operator/= (double &c);
	void print();
};
Vector::Vector(int s)
{
  size = s;
  p = new double[size];
}
Vector::Vector(const Vector& vec)
{
  size = vec.size;
  p = new double[size];

  for(int i = 0 ; i < size; i++)
  {
    p[i]=vec.p[i];
  }
}
Vector::~Vector()
{
	delete p;
	p = NULL;
}
Vector Vector:: operator=(const Vector& c)
{

	for (int i = 0; i < size; i++)
	{
		p[i] = c.p[i];
	}
	return *this;
}
Vector Vector:: operator+=(const Vector& c)
{
	for (int i = 0; i < size; i++)
	{
		p[i] += c.p[i];
	}
	return *this;
}
Vector Vector:: operator-=(const Vector& c)
{
	for (int i = 0; i < size; i++)
	{
		p[i] -= c.p[i];
	}
	return *this;
}
Vector Vector:: operator*=(double &c)
{
	for (int i = 0; i < size; i++)
	{
		*(p+i) *= c;
	}

	return *this;
}
Vector Vector:: operator/=(double &c)
{
	for (int i = 0; i < size; i++)
	{
		*(p+i) /= c;
	}

	return *this;
}
void Vector:: print()
{
	for (int i = 0 ; i < size ; i++)
	{
		cout << p[i] << " ";
	}
}
class Scanline : public Vector
{
    Scanline(int s) : Vector(s)
    {};
    int CalcAll();
};
int Scanline::CalcAll()
{
  int sum= 0;

  for (int i = 0; i <  size ; i++)
  {
    sum += p[i];
  }
 return sum;
}
int main()
{
	Vector v(4);

	v.print();

	return 0;
}
