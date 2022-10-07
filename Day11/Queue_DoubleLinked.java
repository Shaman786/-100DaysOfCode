
//Implementation of Queue using Double Linked List [Insert, Delete. & Print]
import java.util.*;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int d) {
        data = d;
        next = null;
        prev = null;
    }
}

class Queue_DoubleLinked {
    Node front;
    Node rear;

    Queue_DoubleLinked() {
        front = null;
        rear = null;
    }

    void insert(int d) {
        Node n = new Node(d);
        if (front == null) {
            front = n;
            rear = n;
        } else {
            rear.next = n;
            n.prev = rear;
            rear = n;
        }
    }

    void delete() {
        if (front == null) {
            System.out.println("Queue is Empty");
        } else {
            System.out.println("Deleted Element is " + front.data);
            if (front == rear) {
                front = null;
                rear = null;
            } else {
                front = front.next;
                front.prev = null;
            }
        }
    }

    void display() {
        if (front == null) {
            System.out.println("Queue is Empty");
        } else {
            Node temp = front;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        try (Scanner sc = new Scanner(System.in)) {
            Queue_DoubleLinked q = new Queue_DoubleLinked();
            int ch;
            do {
                System.out.println("1. Insert");
                System.out.println("2. Delete");
                System.out.println("3. Display");
                System.out.println("4. Exit");
                System.out.println("Enter your choice");
                ch = sc.nextInt();
                switch (ch) {
                    case 1:
                        System.out.println("Enter the element to be inserted");
                        int d = sc.nextInt();
                        q.insert(d);
                        break;
                    case 2:
                        q.delete();
                        break;
                    case 3:
                        q.display();
                        break;
                    case 4:
                        System.out.println("Exit");
                        break;
                    default:
                        System.out.println("Invalid Choice");
                }
            } while (ch != 4);
        }
    }

}
