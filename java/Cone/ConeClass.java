package Cone;
import java.math.*;

public class ConeClass {
    private double radius;
    private double height;

    ConeClass() {
        this.radius = 0;
        this.height = 0;
    }

    public double getHeight() {
        return height;
    }

    public double getRadius() {
        return radius;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double computeSurfaceArea() {
        return Math.PI * radius * (radius + (Math.sqrt(height * height + radius * radius)));
    }
    
    public double computeVolume() {
        return (Math.PI * radius * radius * height) / 3;
    }
}
