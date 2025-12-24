package model;

public class Student extends Person {
    private String major;

    public Student(int id, String name, String major) {
        super(id, name);
        this.major = major;
    }

    public void setMajor(String major) { this.major = major; }
    public String getMajor() { return major; }

    @Override
    public String toString() {
        return super.toString() + " major: " + major;
    }


}
