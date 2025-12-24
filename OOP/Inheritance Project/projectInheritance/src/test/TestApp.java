package test;

import model.Employee;
import model.Student;

public class TestApp {
    public static void main(String[] args) {
        Employee emp1 = new Employee();
        emp1.setId(123);
        emp1.setName("Khaled");
        emp1.setNoOfChildren(2);

        System.out.println(emp1.getName());
        System.out.println(emp1.getId());
        System.out.println(emp1.getNoOfChildren());

        Employee emp2 = new Employee(124, "Mohamed",1);
        System.out.println(emp2.toString());

        Student s1 = new Student(111, "mohamed", "Computer Science");
        Student s2 = new Student(122, "ahmed", "Computer Engineering");
        System.out.println(s1.toString());
        System.out.println(s2.toString());
    }
}