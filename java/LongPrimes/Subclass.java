package  LongPrimes;
import java.math.BigInteger;

public class Subclass extends Superclass{

   
    // default constructor
    public Subclass(){

    }

    // overloaded constructor
    public Subclass(int k) {
        super(k);
    }

    // to access accessors from superclass
    public int getK() {
        return super.getK();
    }

    public BigInteger[] getPrimes() {
        return super.getPrimes();
    }

    // to access mutators from superclass
    public void setK(int k) {
        super.setK(k);
    }

    public void setPrimes() {
        super.setPrimes();
    }

    
}
