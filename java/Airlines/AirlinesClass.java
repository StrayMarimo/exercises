package Airlines;

public class AirlinesClass {

    // data fields
    private static int[] size = new int[6];
    private static int[][] onQueue = new int[60][6];

    //constructor
    AirlinesClass() {}

    // methods

    // adds a passenger to queue
    public void enqueue(int passengerID, int airlineID, boolean isPriority) {
        // if passenger is not a pwd, senior citizen, pregnant woman, etc. 
        // then add passenger at end of queue
        if (!isPriority)
            AirlinesClass.onQueue[size[airlineID]][airlineID] = passengerID;
        else { // otherwise, add passenger at begining of queue
            System.out.println("Passenger " + passengerID + " is eligible to cut in line (priority)");
            // shifts current queue by 1 to right, leaving a space at beginning
            for (int i = size[airlineID]; i > 0; i--) {
                AirlinesClass.onQueue[i][airlineID] =  AirlinesClass.onQueue[i-1][airlineID];
            }
            // add priority passenger at beginning of queue
            AirlinesClass.onQueue[0][airlineID] = passengerID;
        }

        // increment current size at airline
        size[airlineID]++;
    }

    // removes a passeger on each of the 6 queues
    public void dequeue() {
        // for every airline
        for (int i = 0; i < 6; i++) {
            if (size[i] != 0) { // if it is not empty
                if (size[i] == 1) // if only one passenger is on queue
                    AirlinesClass.onQueue[0][i] = -1; // set cell to -1, indicating no passenger is there
                else for (int j = 0; j < size[i] - 1; j++) // otherwise, shift current queue by 1 to left
                    AirlinesClass.onQueue[j][i] = AirlinesClass.onQueue[j+1][i];
                AirlinesClass.onQueue[size[i]][i] = -1; // set cell to -1, indicating no passenger is there
                size[i]--; // decrement size at current airline
            }
        }
    }

    // checks if all queues are empty
    public boolean isEmpty() {
        for (int i = 0; i < 6; i++)
            if (size[i] != 0)
                return false;
        return true;
    }
    
    // prints current status of queue
    public void printOnQueue() {
        for (int i = 0; i < 6; i++) {
            System.out.println("Queue on Airline " + i);
            for (int j = 0; j < size[i]; j++)
                System.out.print(AirlinesClass.onQueue[j][i] + " ");
                System.out.println();
        }
        System.out.println();
    }
}