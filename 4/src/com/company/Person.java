package com.company;
import java.io.Serializable;
public class Person implements Serializable{
    private String  firstName;
    private String  lastName;
    private int     age;

    Person(){
        firstName=null;
        lastName=null;
        age=0;
    }
    public String getFirstName() {
        return firstName;
    }
    public void setFirstName(String value) {
        firstName = value;
    }
    public String getLastName() {
        return lastName;
    }
    public void setLastName(String value) {
        lastName = value;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int value) {
        age = value;
    }

    @Override
    public String toString() {
        return "[Person: firstName = " + firstName +
                ", lastName = " + lastName +
                ", age = " + age + "]";
    }
}