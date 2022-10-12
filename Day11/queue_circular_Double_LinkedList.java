
// Implementation of Queue using Circular Double Linked List [Insert, Delete. &
// Print]
import java.util.*;

class queue_circular_Double_LinkedList {
    class Node {
        int data;
        Node next;
        Node prev;
    }

    Node front, rear;

    queue_circular_Double_LinkedList() {
        front = rear = null;
    }

    void insert(int data) {
        Node temp = new Node();
        temp.data = data;
        if (front == null) {
            front = rear = temp;
            front.next = rear.next = null;
            front.prev = rear.prev = null;
        } else {
            rear.next = temp;
            temp.prev = rear;
            rear = temp;
            rear.next = front;
            front.prev = rear;
        }
    }

    void delete() {
        if (front == null) {
            System.out.println("Queue is Empty");
        } else if (front == rear) {
            front = rear = null;
        } else {
            front = front.next;
            front.prev = rear;
            rear.next = front;
        }
    }

    void print() {
        Node temp = front;
        if (front == null) {
            System.out.println("Queue is Empty");
        } else {
            while (temp.next != front) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.print(temp.data + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        queue_circular_Double_LinkedList q = new queue_circular_Double_LinkedList();
        int choice, data;
        while (true) {
            System.out.println(" 1. Insert ");
            System.out.println(" 2. Delete ");
            System.out.println(" 3. Print ");
            System.out.println(" 4. Exit ");
            System.out.print(" Enter your choice : ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print(" Enter the data : ");
                    data = sc.nextInt();
                    q.insert(data);
                    break;
                case 2:
                    q.delete();
                    break;
                case 3:
                    q.print();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println(" Invalid Choice ");
            }
            System.out.println();
        }
    }
}
