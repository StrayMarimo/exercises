package LongPrimes;
import java.math.BigInteger;

public class Superclass {
    // data fields declaration
    private int k;
    private BigInteger primes[];

    // default constructor
    public Superclass() {

    }

    // overloaded constructor
    public Superclass(int k) {
        this.k = k;
        primes = new BigInteger[k];
    }
    
    // accessors
    public int getK() {
        return k;
    }

    public BigInteger[] getPrimes() {
        return primes;
    }


    // mutators
    public void setK(int k) {
        this.k = k;
        primes = new BigInteger[k];
    }

    public void setPrimes() {
        BigInteger maxNum = new BigInteger(Long.MAX_VALUE + "");
        int primeCtr = 0;
        while (primeCtr < k) {
            maxNum = maxNum.add(new BigInteger("1"));
            if (maxNum.isProbablePrime(1)) {
                primes[primeCtr] = maxNum;
                primeCtr++;
            }
        }
    }

    // methods
    public void displayPrimes() {
        for (BigInteger num: primes) 
            System.out.println("\t" + num);
    }

    // overloads displayPrimes method
    public void displayPrimes(int size) {
        System.out.print( "the first " + size + " prime numbers after " + Long.MAX_VALUE + " are:\n");
        System.out.println(toString(size));
    }

    // definition of overloaded toString method
    String toString(int size){
        String message = "";

        for (BigInteger num: primes)
            message+= "\t" + num.toString() + "\n";
        
        return message;
    }

}



