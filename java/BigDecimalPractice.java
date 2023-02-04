import java.math.*;

public class BigDecimalPractice {
	public static void main(String[] args) {
		MathContext mc = new MathContext(10000, RoundingMode.HALF_UP);
		for (int i = 100; i <= 1000; i+=100) {
			BigDecimal result = BigDecimal.ZERO;
			for (int j = 0; j <= i; j++) {
				BigDecimal factorial = calculateFactorial(new BigDecimal(j));
				BigDecimal term = BigDecimal.ONE.divide(factorial, mc);
				result = result.add(term);
			}

			System.out.printf("i = %d, e = %.25f%n", i, result);
		} 		
	}

	public static BigDecimal calculateFactorial(BigDecimal n) {
		if (n.equals(BigDecimal.ZERO))
			return BigDecimal.ONE;
		else
			return n.multiply(calculateFactorial(n.subtract(BigDecimal.ONE)));
	}
}