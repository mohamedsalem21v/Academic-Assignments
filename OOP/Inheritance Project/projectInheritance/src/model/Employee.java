package model;

public class Employee extends Person {
    private int noOfChildren;

    public Employee() {
    }

    public Employee(int noOfChildren) {
        super();
        this.noOfChildren = noOfChildren;
    }
    public Employee(int id, String name,int noOfChildren) {
        System.out.println("Employee constructor is called now.");
        super(id, name);
        this.noOfChildren = noOfChildren;
    }

    public void setNoOfChildren(int noOfChildren) {
        this.noOfChildren = noOfChildren;
    }
    public int getNoOfChildren() {
        return noOfChildren;
    }

    public String toString() {
        return super.toString() + "," + noOfChildren;
    }

}
