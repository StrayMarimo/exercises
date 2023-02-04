package Worker;

public class WorkerClass {

    // data fields
    String name, gender, number, position;
    int age;
    double salary = 1.0;

    // constructor
    WorkerClass(){}

    void setName(String _name){
        name = _name;
    }
    
    // methods 
    void setGender(String _gender){
        gender = _gender;
    }

    void setAge(int _age){
        age = _age;
    }

    void setNumber(String _number){
        number = _number;
    }

    void setPosition (String _position){
        position = _position;
    }

    void setSalary (double _salary){
        salary = _salary;
    }

    void demoteWorker(){
        salary /= 10;
    }

    void promoteWorker(){
        salary *= 10;
    }

    String getName(){
        return name;
    }

    String getGender(){
        return gender;
    }

    int getAge(){
        return age;
    }

    String getNumber(){
        return number;
    }

    String getPosition(){
        return position;
    }

    Double getSalary(){
        return salary;
    }
}
