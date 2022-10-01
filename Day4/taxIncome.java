import java.util.Scanner;

 class taxincome{
     public int tax(int n)
     {
      double tax=0;
       if(n>=1 && n<=100000){
        tax=0;
       }else if(n>=100001 && n<=500000){
        tax=(.1*(n-100000));

     } else if (n>=500001 && n<=1000000){
        tax=(.2*(n-500000))+40000;

       } else if (n>=1000001 && n<=4000000){
        tax=(.3*(n-1000000))+140000;
       } else if (n>=4000001 && n<=10000000){
        tax= (n-4000000)*.4+940000;


       }
     return (int) tax; }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the income");
    int n = sc.nextInt();
    taxincome t = new taxincome();
    System.out.println("The tax is " + t.tax(n));
  }}



