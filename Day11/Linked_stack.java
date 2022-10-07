
//Implementation of Stack using Linked List [Insert, Delete. & Print]
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Linked_stack {
    Node top;

    Linked_stack() {
        top = null;
    }

    void push(int d) {
        Node n = new Node(d);
        if (top == null) {
            top = n;
        } else {
            n.next = top;
            top = n;
        }
    }

    void pop() {
        if (top == null) {
            System.out.println("Stack is Empty");
        } else {
            System.out.println("Deleted Element is " + top.data);
            top = top.next;
        }
    }

    void display() {
        if (top == null) {
            System.out.println("Stack is Empty");
        } else {
            Node temp = top;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Linked_stack s = new Linked_stack();
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
                    int d = sc.nextInt();
                    s.push(d);
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
