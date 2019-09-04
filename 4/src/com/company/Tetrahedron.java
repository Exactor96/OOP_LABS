package com.company;

import static java.lang.Math.sqrt;

public class Tetrahedron extends Figure{
    private double a;

    Tetrahedron(){
        setA(0);
    }

    Tetrahedron(double a){
        setA(a);
    }

    @Override
    double square() {
        return a*a*sqrt(3);
    }

    @Override
    void info() {
        System.out.println("This is Tetrahedron. Square: "+square() + " Volume: "+volume());
    }

    @Override
    double volume() {
        return a*a*a / 12.0 *sqrt(2);
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }
}
