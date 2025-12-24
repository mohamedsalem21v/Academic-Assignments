package test;

import model.Person;
import java.util.ArrayList;
import java.util.List;

public class PersonTest {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();

        people.add(new Person(2571, "Islam Ahmed"));
        people.add(new Person(1318, "Saad Mohamed"));
        people.add(new Person(5376, "Adil Salm"));

        for (Person p : people) {
            System.out.println(p.toString());
        }
    }
}