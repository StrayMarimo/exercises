package Course;

public class Course {
    public static void main(String[] args) {
      CourseClass course1 = new CourseClass("Data Structures");
      CourseClass course2 = new CourseClass("Database Systems");
  
      course1.addStudent("Peter Jones");
      course1.addStudent("Brian Smith");
      course1.addStudent("Anne Kennedy");
  
      course2.addStudent("Peter Jones");
      course2.addStudent("Steve Smith");
  
      System.out.println("Number of students in course1: "
        + course1.getNumberOfStudents());
      String[] students = course1.getStudents();
      for (int i = 0; i < course1.getNumberOfStudents(); i++)
        System.out.print(students[i] + ", ");
      
      System.out.println();
      System.out.print("Number of students in course2: "
        + course2.getNumberOfStudents());
    }
  }
