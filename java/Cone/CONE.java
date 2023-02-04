package Cone;
import java.util.Scanner;
public class CONE {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ConeClass Cone1 = new ConeClass();
        ConeClass Cone2 = new ConeClass();

        System.out.println(Cone1.getRadius() + " " + Cone1.getHeight() + " " 
        + Cone1.computeSurfaceArea() + " " + Cone1.computeSurfaceArea());

        Cone2.setHeight(sc.nextDouble());
        Cone2.setRadius(sc.nextDouble());

        System.out.println(Cone2.getRadius() + " " + Cone2.getHeight() + " " 
        + Cone2.computeSurfaceArea() + " " + Cone2.computeSurfaceArea());



    }
}
