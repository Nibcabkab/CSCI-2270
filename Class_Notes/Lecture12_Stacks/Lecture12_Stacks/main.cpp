#include <iostream>
#include "stack.h"

using namespace std;
/* Demo of how to use the Stack class. All methods declared in
    and implemented Slack.cpp and Slack.h. This simple test
    just creates an instance of the STack, and then does two
    pushes and two pops. Notice the order of the items that
    are popped off.
 */
int main(){
	Stack *s = new Stack(5);
	s->push("test");
	s->push("test2");
	cout<<s->pop()<<endl;
	cout<<s->pop()<<endl;

}
