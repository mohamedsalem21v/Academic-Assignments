import java.util.Scanner;

public class assignment2
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a,b,c,d,e;
        System.out.print("Enter first number: ");
        a = input.nextInt();
        System.out.print("Enter second number: ");
        b = input.nextInt();
        System.out.print("Enter third number: ");
        c = input.nextInt();
        System.out.print("Enter fourth number: ");
        d = input.nextInt();
        System.out.print("Enter fifth number: ");
        e = input.nextInt();

        double avg = (double)(a+b+c+d+e)/5;
        System.out.printf("The average is: %.2f\n" , avg);
        input.close();
    }
}