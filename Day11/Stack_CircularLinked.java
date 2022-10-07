
//Implementation of Stack using Circular Linked List [Insert, Delete. & Print]
import java.util.*;

public class Stack_CircularLinked {
    Node top;

    Stack_CircularLinked() {
        top = null;
    }

    void push(int d) {
        Node n = new Node(d);
        if (top == null) {
            top = n;
            top.next = top;
        } else {
            n.next = top.next;
            top.next = n;
            top = n;
        }
    }

    void pop() {
        if (top == null) {
            System.out.println("Stack is Empty");
        } else {
            System.out.println("Deleted Element is " + top.next.data);
            if (top.next == top) {
                top = null;
            } else {
                top.next = top.next.next;
            }
        }
    }

    void display() {
        if (top == null) {
            System.out.println("Stack is Empty");
        } else {
            Node temp = top.next;
            while (temp != top) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.print(temp.data + " ");
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Stack_CircularLinked s = new Stack_CircularLinked();
        int ch;
        do {
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.println("Enter your choice");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter the element to be inserted");
                    s.push(sc.nextInt());
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                case 4:
                    System.out.println("Exit");
                    break;
                default:
                    System.out.println("Invalid Choice");
            }
        } while (ch != 4);
        sc.close();
    }

}
