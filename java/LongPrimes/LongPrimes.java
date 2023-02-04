package LongPrimes;
import java.util.Scanner;
public class LongPrimes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("This program prints the first k prime numbers greater than the max value of the long integer");
        System.out.print("For example, ");

        // calls overloaded constructor with one parameter
        Subclass sampleObj = new Subclass(5);
        sampleObj.setPrimes(); // calls inherited method

        // calls overloaded displayPrimes method in superclass
        sampleObj.displayPrimes(5);
        
        // calls default constructor
        Subclass userObj = new Subclass();

        System.out.print("Now, you try. Enter k: ");
        int k = sc.nextInt();
        userObj.setK(k); // calls inherited method
        sc.close();

        userObj.setPrimes(); // calls inherited method
        userObj.displayPrimes(); // calls default method in superclass
        
    }
}