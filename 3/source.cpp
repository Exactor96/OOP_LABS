/*1. Создать базовый класс с виртуальными функциями: норма, вывод элемента на экран.
Создать производные классы: комплексные числа, вектор из 10 элементов, матрица (3х3).
В производных классах определить: скрытые поля,
 конструктор по умолчанию,
 конструктор с параметрами,
методы для установки и получения значение полей,
метод для вывода элемента на экран, метод для расчета нормы
(для комплексных чисел - модуль в квадрате, для вектора - корень квадратный из суммы элементов по модулю,
для матрицы - максимальное значение по модулю).
2. Разработать программу, которая демонстрировала бы работоспособность всех методов  классов.
Для проверки определить массив ссылок на базовый класс, которым присваиваются адреса различных объектов.*/


#include <iostream>
#include <cmath>
using namespace std;
class Base{
    virtual void norm(){};
    virtual void print(){};
};

class complex: public Base{
    private:
    double re,im;
    public:
    complex(){
        im=re=0;
    }
    complex(double _re, double _im){
        im=_im;
        re=_re;
    }

    double getRe() {return re;}

    double getIm() {return im;}

    void setRe(double _re) {re=_re;}

    void setIm(double _im) {im=_im;}

    void print(){
        if (im<0) cout<<re<<im<<'i'<<'\n';
        else cout<<re<<'+'<<im<<'i'<<'\n';
    }
    void norm(){
    	cout<<re*re+im*im<<'\n';
	}

};

class vec: public Base{
private:
	int v[10];

public:

vec(int _v[10]){
  setV(_v);
}

vec(){
  int _v[10]={0,0,0,0,0,0,0,0,0,0};
  setV(_v);
}

void setV(int _v[10]){
  for(int i=0;i<10;i++){
    v[i]= _v[i];
  }
}

	void print(){
		for (int each: v){
			cout<<each<<' ';
		}
		cout<<'\n';
	}

    void norm(){
        double s=0;
        for (int each: v){
			s+=each;
		}
        cout<<sqrt(s)<<'\n';
    }

};

class matrix: public Base{
private:
int m[3][3];

public:

  void setM(int _m[3][3]){
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        m[i][j]=_m[i][j];
      }
    }
  }


	matrix(){
    int _m[3][3]={0,0,0,0,0,0,0,0,0};
	setM(_m);
}
	void print(){
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            cout<<m[i][j]<<' ';
	        }
	        cout<<'\n';
	    }
	}

	void norm(){
	    int mx=m[0][0];
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            if (mx < abs(m[i][j])) mx= abs(m[i][j]);
	        }

	    }
	    cout<<mx<<'\n';
	}

};


int main(){
	cout<<"COMPLEX"<<'\n';
    complex c(1,-2);
    c.print();
    c.norm();
    cout<<"vec"<<'\n';
    vec v1;
    int l[10]={0,1,2,3,4,5,6,7,8,9};
    v1.print();
    v1.setV(l);
    v1.print();
    v1.norm();
	cout<<"MATRIX"<<'\n';
    matrix m;
    m.print();
    int ml[3][3]={1,2,3,4,-55,6,7,8,-9};
    m.setM(ml);
    m.print();
    m.norm();
}
