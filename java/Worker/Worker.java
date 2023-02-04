package Worker;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Worker {

    // creates a worker and returns it 
    static WorkerClass addWorker() {
        WorkerClass worker = new WorkerClass();
        Scanner sc = new Scanner(System.in);
        double salary = 0.0;

        // ask user for input and pass it to the invoked method

        System.out.print("Enter name: ");
        worker.setName(sc.nextLine());

        System.out.print("Enter gender: ");
        worker.setGender(sc.next());

        System.out.print("Enter age: ");
        worker.setAge(sc.nextInt());
        sc.nextLine();

        System.out.print("Enter contact number: ");
        worker.setNumber(sc.nextLine());

        System.out.print("Enter job position: ");
        worker.setPosition(sc.nextLine());

        do {
            System.out.print("Enter salary: ");
            salary = sc.nextDouble();
        } while (salary <= 0);
        worker.setSalary(salary);

        // returns worker of type BASB_Worker
        return worker;
    }
    
    // method to display details of each worker from a given list of objects
    static void displayWorkers(List<Object> workers) {
        System.out.println();
        // iterate to list
        for (Object w : workers) {
            WorkerClass worker = (WorkerClass) w; // cast the object to BASB_Worker

            // display worker object data
            System.out.println("Worker: " + worker.getName());
            System.out.println(" Gender: " + worker.getGender());
            System.out.println(" Age: " + worker.getAge());
            System.out.println(" Contact number: " + worker.getNumber());
            System.out.println(" Job position: " + worker.getPosition());
            System.out.println(" Salary: " + worker.getSalary());
            System.out.println();
        }
    }

    // method to return the index of a chosen worker from a given list of objects
    static int chooseWorker(List<Object> workers) {
        Scanner sc = new Scanner(System.in);
        int worker = -1;

        // repeat block until user inputs input within bounds
        do {
            // display choices of workers
            for (int i = 1; i <= workers.size(); i++)
                System.out.printf(" %d - %s%n", i, ((WorkerClass) workers.get(i - 1)).getName());
            System.out.print("Select worker within the choices: ");
            worker = sc.nextInt();
        } while (worker <= 0 || worker > workers.size());

        // returns index of worker with type int
        return worker - 1;
    }

    // method to promote or demote a worker, returns the worker with updated salary
    static WorkerClass changeSalary(Object w, String action) {
        WorkerClass worker = (WorkerClass) w; // cast the object to BASB_Worker

        System.out.println();
        if (action == "promote")
            worker.promoteWorker(); // invokes promoteWorker method
        else
            worker.demoteWorker(); // invokes demoteWorker method

        // displays modified data
        System.out.println("New salary of " + worker.getName()
                + ": " + worker.getSalary());

        return worker; // returns worker of type BASB_Worker
    }

    // main 
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        List<Object> workers = new ArrayList<Object>();
        int answer = 0, worker = -1;
        
        // repeat block until user inputs 5
        do {
            // asks what user wants to do
            System.out.println("-------------------------------------------------------------");
            System.out.println("  1 - add a worker\t2 - display all workers");
            System.out.println("  3 - promote worker/s\t4 - demote worker/s");
            System.out.println("  5 - terminate program");
            System.out.print("Choose action: ");
            answer = sc.nextInt();

            switch (answer) {
                case 1: // calls addWorker method and appends return value to list
                    workers.add(addWorker()); 
                    break;
                case 2: // calls displayWorker method and passes the current list of workers
                    if (workers.size() > 0)
                        displayWorkers(workers);
                    else System.out.println("Add workers first");
                    break;
                case 3: // calls chooseWorker method to get index of the worker that will be promoted
                    if (workers.size() > 0) {
                        worker = chooseWorker(workers);
                        // changes the data of chosen worker by the return vlaue of changeSalary method
                        workers.set(worker, changeSalary(workers.get(worker), "promote"));
                    } else System.out.println("Add workers first");
                    break;
                case 4: // calls chooseWorker method to get index of the worker that will be demoted
                    if (workers.size() > 0) {
                        worker = chooseWorker(workers);
                         // changes the data of chosen worker by the return vlaue of changeSalary method
                        workers.set(worker, changeSalary(workers.get(worker), "demote"));
                    } else System.out.println("Add workers first");
                    break;
                case 5: // terminates program
                    break;
                default: // catch invalid inputs
                    System.out.println("Invalid input. Try again.");
            }
            
        } while (answer != 5);

        sc.close();

    }
}
