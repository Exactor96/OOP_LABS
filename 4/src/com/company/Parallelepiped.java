package com.company;

import java.io.Serializable;

public class Parallelepiped extends Figure implements Serializable {
    private double a;
    private double b;
    private double c;


    Parallelepiped(){
        setA(0);
        setB(0);
        setC(0);
    }

    Parallelepiped(double a, double b, double c){
        setA(a);
        setB(b);
        setC(c);
    }
    @Override
    double square() {
        return 2*(a*b+a*c+b*c);
    }

    @Override
    void info() {
        System.out.println("This is Parallelepiped. Square: "+square() + " Volume: "+volume());
    }

    @Override
    double volume() {
        return a*b*c;
    }


    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }
}
