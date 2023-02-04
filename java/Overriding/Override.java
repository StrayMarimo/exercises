package Overriding;

public class Override {
    public static void main(String[] args) {
        B subOb = new B(1, 2, 3);

        // calls show() in B
        subOb.show();

    }
}
