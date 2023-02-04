package Overriding;

class A {
    int i, j;
    
    A(int a, int b) {
        i = a;
        j = b;
    }
    
    //A() {}
    void show() {
        System.out.println("i and j: " + i + " " + j);
    }
}
