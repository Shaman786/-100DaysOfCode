#include <iostream>
using namespace std;
struct node
{
    int data;
    node *Next;
};
Class task
{
public:
    task(INT data)
    {
        node *node = new node;
        node->DATA = data;
        node->next = node;
        used = node;
        now = node;
        last = node;
    }
    void open(INT data)
    {
        node *node = new node;
        node->DATA = data;
        node->next = used;
        last->next = node;
        used = node;
        now = used;
    } /* Core */
    void Press()
    { // press the alt button and press the tab key for pre = now; now = now-> next;} void up () {// put down Al T and Tab key if (now = used) {} else if (now = last) {used = last; last = pre; now = used ;} else {pre-> next = now-> next; now-> next = used; last-> next = now; used = now ;}} /* Core */void out () {node * P = used; cout <p-> data <""; while (p-> next! = Used) {P = p-> next; cout <p-> data <"" ;}cout <Endl ;}private: node * used; node * now; node * pre; node * last;}; int main () {int COUNT = 5; Task task (1); While (count --) {task. open (count); task. out () ;}for (Int J = 1; j <10; j ++) {for (int K = 0; k <j; k ++) {task. press ();} task. up (); task. out ();} return 0 ;}