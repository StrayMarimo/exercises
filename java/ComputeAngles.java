import java.util.Scanner;

public class ComputeAngles {
	public static void main(String[] args) {
		double[] x = new double[3];
		double[] y = new double[3];
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i <3; i++) {
			System.out.printf("Enter x for point %d: ", (i + 1));
			x[i] = sc.nextDouble();
			System.out.printf("Enter y for point %d: ", (i + 1));
			y[i] = sc.nextDouble();
		}
		
		double a = computeSides(x[1], x[2], y[1], y[2]);
		double b = computeSides(x[0], x[2], y[0], y[2]);
		double c = computeSides(x[0], x[1], y[0], y[1]);

		System.out.printf("Angle A: %.2f%n", computeAngles(a,b,c));
		System.out.printf("Angle B: %.2f%n", computeAngles(b,a,c));
		System.out.printf("Angle C: %.2f%n", computeAngles(c,b,a));
	}

	public static double computeSides(double a, double b, double c, double d) {
		return Math.sqrt(Math.pow((a - b), 2) + Math.pow((c - d), 2));
	}
	
	public static double computeAngles(double a, double b, double c) {
		return Math.toDegrees(Math.acos((a * a - b * b - c * c) / (-2 * b * c)));	
	}	

}