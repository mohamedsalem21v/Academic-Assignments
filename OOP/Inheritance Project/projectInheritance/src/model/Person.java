package model;

public class Person
{
    private int id;
    private String name;

    public Person() {
        id =  0;
        name = "";
    }
    public Person(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void setId(int id) {
        this.id = id;
    }
    public int  getId() {
        return this.id;
    }

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return this.name;
    }

    public String toString() {
        return id + "," + name;
    }
}
