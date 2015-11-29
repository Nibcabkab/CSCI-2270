/*Rhonda Hoenigman
CSCI2270  - Spring 2015
CU Boulder
Lecture 4 and 5
*/

#include <iostream>
#include <string>
/*For the next two lectures, we're going to talk about arrays and pointers.
These notes contain several examples of arrays, pointers, and functions
that have arrays and pointers as arguments and local variables.

Arrays are a data structure found in just about every language and it's
important to understand how to manipulate them. When you declare an array in
C++, you effectively declare a pointer, which is a reference to a memory
location. So, we can't really discuss arrays without also starting to discuss
pointers. And, we'll be using pointers a lot this semester.

One of the limitations of arrays is that they have a fixed size. But, there
will be many, many times when you need your program to change the size of the
array while the program is running. You could just create the biggest possible
array, but then you've got lots of unused space. The solution is to create
arrays dynamically
*/
/*
When we create variables, memory is allocated for the variable when the program
is compiled. Memory can also be allocated dynamically for any type variable
using the new keyword for cases where you don't know memory requirements at
runtime. Once memory has been allocated in this way, it has to
be explicitly de-allocated using the delete operator.
*/

using namespace std;

/*In this example, the function takes two arguments, an array and an int.
The function returns a pointer to a newArray that is created.
*/
int* functionPtrTest(int p[], int length){
    int *newArray = new int[length*2];
    for(int i = 0; i < length; i++){
        newArray[i] = p[i];
    }
    //the second half of newArray should still be garbage
    return newArray;
}

/*Function takes a pointer argument and doesn't return anything. But, value
of *ptrTmp will change in calling function. Print address to see that memory
locations of ptrTemp and the variable ptrResult in main are the same.
*/
void displayAddress(int *ptrTmp){
    *ptrTmp = 99;
    cout<<"address of pointer inside function "<<ptrTmp<<endl;
}

/*
void function that takes one argument, an array of doubles.
*/
void myArrayFunction(double dblA[])
{
	//here, we are just initializing the array
	//the array should still be initialized when we
	//print it in main
	for(int x = 0; x < 10; x++)
		dblA[x] = 0;
}
/*Function to demonstrate that arrays are effectively pointers, we can change the
values of intA[] in the array and then see the change propagate back to the
calling function, even though this arrayTest function is a void type.*/
void arrayTest(int intA[], int length){
    for(int i = 0; i < length; i++)
        intA[i] = i;
}
/*scopeTest and pointerTest show how regular variables and pointer
behave differently in a void function. Call these functions in main
and print out the variable values to see that the pointer keeps its
value in main whereas intI2 doesn't
*/
void scopeTest(int intI2){
    cout<<"i2 = "<<intI2<<endl;
}
void pointerTest(int *ptrP){
    *ptrP = 99;
}

void pointerAndRegularTest(int *ptrA2, int intB2){
    //intB2 not returned, changes lost when function completes execution
    *ptrA2 = *ptrA2 + intB2;

    intB2 = intB2 + *ptrA2;
    cout<<"*ptrA2 in function "<<*ptrA2<<" intB2 in function "<<intB2<<endl;
    cout<<"addr of *ptrA2 in function "<<ptrA2<<" addr of intB2 in function "<<&intB2<<endl;

}

int main()
{

    //statically declared, without new and pointers, allocates on the call stack
    /*When variables are allocated on the stack, memory management is handled
    for you, the memory assigned to that variable is freed once the variable
    goes out of scope. */
    int arySize;
    arySize = 10;
    int myArray[arySize];
    for(int i = 0; i < arySize; i++)
        cout<<myArray[i]<<endl;
    /*This function modifies the values of myArray, but doesn't return a value.
    The values for myArray do change in the function, and we see the new values
    printed here. Arrays are effectively pointers, when you pass an array as
    an argument, you're passing a pointer to the first item of the array in
    memory.*/
    arrayTest(myArray, arySize);
    cout<<"output after arrayTest"<<endl;
    for(int i = 0; i < arySize; i++)
        cout<<myArray[i]<<endl;

    /*Another way to create an array is to do so dynamjcally, using
    pointers and the new operator. When you do this, memory is allocated
    on the heap, which is a much larger memory area than the stack, but
    the downside is that it isn't managed for you. When you allocate memory
    on the heap, you must also deallocate the memory explicitly. In some
    languages this is done for you, but in C/C++, you need to do this yourself.*/
    int *ptrArray = new int[5];
    cout<<"ptrArray allocated"<<endl;
    for(int x = 0; x < 5; x++){
        ptrArray[x] = x;
        cout<<ptrArray[x]<<endl;
    }

    /*
    Memory has been allocated here. Each int is 4 bytes. When we create a
    pointer that points to an existing variable, the variable is destroyed
    when it goes out of scope. For example, in a function, a local variable
    declared in the function is destroyed when the function is done executing.

    When memory is allocated dynamically, it has to be destroyed with delete
    */
    delete []ptrArray;

    /*If you try to access ptrArray, you may or may not get the values you expect
    to see. The values might still be there in memory, but you've freed the memory
    allocated to the pointer, so they also may have been overwritten. You may also
    see effects downstream with other variables and it won't be obvious that the
    problem is really that you're writing to freed memory.*/

   //if you uncomment this code, you'll see seg faults after the code runs
   //it will appear to be correct, but it's not
    /*
    cout<<"after delete of ptrArray"<<endl;
    for(int i = 0; i < 5; i++)
        cout<<ptrArray[i]<<endl;
    //can I write to it?
    for(int i = 0; i < 5; i++){
        ptrArray[i] = i;
    }
    cout<<"after ptrArray"<<endl;
*/
    /*
    What happens when memory isn't freed. Over time, the longer the program
    runs, memory is allocated, allocated, allocated. The program will
    generally start to slow down. When memory is allocated and not freed, it's called
    a memory leak.
    */
    /*When you declare an array, you're declaring a pointer. If you
    want to return an array from a function, you need to return a pointer.
    */

    int *ptrC = new int[5];
    for(int x = 0; x < 5; x++)
        ptrC[x] = x;
    /*Why would I return a pointer when I can just change ptrC? Yes, you can and anyone reading
    this code if functionPtrTest didn't return a value, would expect that ptrC might have
    different values, but still be the same shape. It's dangerous to change the shape of
    an array in a function. For example, what if ptrC has half as many elements after
    executing the function, then any loop using the size from before the function call
    will generate an array out of bounds error.*/
    int *ptrReturn = functionPtrTest(ptrC, 5);
    for(int x = 0; x < 10; x++){
        cout<<ptrReturn[x]<<endl;
    }
    delete []ptrReturn;

    /*
    More fun with pointers - they're not just for arrays.
    Just as we dynamically create arrays in memory, we can also
    dynamically allocate memory for other variable types. We need
    pointers.
    Create a pointer. Allocate the memory needed for an integer using
    new int. Once allocated, the pointer stores an address and the value
    at that address can be obtained by de-referencing the pointer.
    */
    cout<<"ptrX"<<endl;
    int *ptrX = NULL; //good practice to initialize pointers to null
    ptrX = new int;
    cout<<ptrX<<endl; //address

    int a = 5;
    int *ptrA = &a;
    cout<<ptrA<<endl;

    *ptrX = 10;
    cout<<*ptrX<<endl;

    /*
    We previously did pointers by creating two variables and the pointer
    pointed to the address of the other variable.
    */

    int intB = 5;
    int *ptrB = &intB;
    cout<<*ptrB<<endl;

    //Also works for doubles
    double *ptrD = NULL;
    ptrD = new double;

    delete ptrX;
    delete ptrD;


    //pointers, variables
    /*
    The variable is an identifier for a location in memory, and the value
    at the location is accessed using the identifier.

    Create a variable called intI that has a value of 5. That
    variable has an address in memory, and you can get that
    address using &intI.

    */
    int intI = 5;
    cout<<"address of i:"<<&intI<<" value of i: "<<intI<<endl;
    /*Previous statement should have output a large number
    starting with 0x and the number 5 as value of intI. The 0x number
    is the hexidecimal address of intI, it's the location on the memory
    stack where intI is created. If we create another variable intI2, it is also
    created in memory at a different address. The two variables could be
    created at consecutive memory locations. An integer is 4 bytes, so if the
    variables are stored consecutively, then we would see the address increase
    by four bytes.
    */
    int intI2 = 6;
    cout<<"address of i2:"<<&intI2<<" value of i2: "<<intI2<<endl;
    //There is more about hexidecimal numbering and binary in the written notes on Moodle
    /*There is another type of variable called a pointer that can be used to store an
    address in memory. The address is stores is the address of another variable, and we say
    that the pointer points to the variable whose address it stores.
    */
    int intB2 = 50;
    /*
    Declare pointer variable. It doesn't yet point to anything. To be valid, or useful,
    it needs to point to the address of another variable.
    */
	int *ptrB2;
    /*
    Store the address of intB2 as ptrB2
    */
	ptrB2 = &intB2;
    /*
    We also need to know the value of what the pointer is pointing to. To get the value,
    we say that we dereference the pointer, and use the *ptrB2 syntax. The * is like saying
    value that ptrB2 is pointing to.
    */
	cout<<"\nThe value of *ptrB2 is "<<*ptrB2;
	intB2 = intB2 + 10;
    //value that ptrB2 points to has changed
	cout<<"\nNow the value of *ptrB2 is "<<*ptrB2;

    //Let's do another example
	int *ptrC2 = &intB2;
 	/*ptrC2 is a variable that points to the memory location of intB
	*the *ptrC2 notation says that ptrC2 is a memory address.
	* The & notation is a reference operator to address of intB.
	* The * notation is a pointer deference. It says use the value
	* referenced by ptrC2.
	*/
	/*if we want the value pointed to by ptrC2, we use *ptrC2. If we want the memory location
	 * that ptrC2 points to, we use ptrC2
	 */

	cout<<"intB2 is: "<<intB2<<" and the address of intB2 is "<<&intB2<<endl;
	cout<<"*ptrC2 is: "<<*ptrC2<<" and the address of ptrC is "<<ptrC2<<endl;
	//this prints a reference to b and a reference to c, they are the same
	cout<<"The address of intB2 is: "<<&intB2<<" and the address of ptrC2 is: "<<ptrC2;

	/*If we change one of the values, the other will also change.
	 */
	//only changing intB, every variable that points to &intB will also change
	intB2 = intB2 + 10;
	cout<<"intB= "<<intB2<<" *ptrC2= "<<*ptrC2<<" *ptrB2="<<*ptrB2<<endl;

	//the same is true if we change *c, but not b. Both values will change.
	/*Careful what's changing here. You want to change the value by 1, not the address
	*/
	(*ptrC2)++;
	cout<<"intB2= "<<intB2<<" *ptrC2= "<<*ptrC2<<" *ptrB2="<<*ptrB2<<endl;
	/*But, if we make a mistake and change ptrC instead of *ptrC,
	bad things happen, sortof.
	*/
	ptrC2++; //*ptrC2++ has similar, unintended result

	cout<<"intB2= "<<intB2<<" *ptrC2= "<<*ptrC2<<" *ptrB2="<<*ptrB2<<endl;
	/*This is way pointers can make people cry. c++ is a perfectly legal
	 * operation. There was no error, and the value that it prints, 0,
	 * can also seem reasonable. We may not even recognize that it's an
	 * error and continue on our merry way coding, coding, coding. Until,
	 * 100 lines later when things just don't seem right.
	 * When we do c++, we've changed the reference of c, it no longer
	 * points to the address of b, it points to &b+1, and who knows what's
	 * there.
	 * Even scarier, it's perfectly legal, once we've changed our c value,
	 * to then write to that value. Who knows what we're writing over. All of your
	 * variables for a program are at some location in memory, and things not related
	 * to each other might actually be next to each other in memory. Meaning, you
	 * could be overwriting something in some other part of the program and not even realize
	 * that you have garbage data.
	*/
	//let's put things back to where they were
	ptrC2--;
	cout<<"intB2= "<<intB2<<" *ptrC2= "<<*ptrC2<<endl;

    /*I've been working with only integers, but other types have pointers too.
    We could create a double
    */
    double *ptrValue;
    double dblValue = 5.678;
    ptrValue = &dblValue;
    cout<<"dbValue "<<dblValue<<" *ptrValue "<<*ptrValue<<endl;

    //can an int point to a double, and vice versa?
    /*No, the type matters. It has to match otherwise, *ptrB for example
    will not read the correct number of bytes and the value will be wrong
    */
    //ptrB = &dblValue;
    //ptrValue = &intB;

    //Why don't I free ptrValue? Do we have a memory leak?

    /*Since pointers are a reference to memory, they also behave differently
    when we pass them as arguments to functions. Values changed inside the
    function are preserved outside the function because it's the same
    memory location.*/
    int *ptrTest = new int;
    *ptrTest = 10;
    pointerTest(ptrTest);
    //will print 99 because *ptrTest changes in function
    cout<<"ptrTest: "<<*ptrTest<<endl;
    /*We can see why the value changes in the function by looking at the address
    of the variable before and within the function.*/
    cout<<"address of pointer outside function: "<<ptrTest<<endl;
    displayAddress(ptrTest);
    /*We can also show how pointers and regular variables behave differently
    */
    int intRegVar = 20;
    pointerAndRegularTest(ptrTest, intRegVar);
    cout<<"*ptrTest: "<<*ptrTest<<" intRegVar: "<<intRegVar<<endl;


    return 0;
}
