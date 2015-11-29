/*Create a CodeBlocks project and add this file to the project
*/


/*
 * C++ is a useful language to learn because it forces you to pay
 * attention to variable types and memory and some of the stuff going
 * on behind the scenes that python hides.
 * The functionality for the language is included with libraries and
 * namespaces. To use the functionality associated with the iostream,
 * we need to include the iostream library. These files are also
 * called header files, or .h files.
 *
*/
#include <iostream>
#include <string>

/* All of the standard C++ functionality is included in a namespace
 * called std. To use this functionality, we need to let the program
 * know that we want it included, so you say "using namespace std".
 * There are other namespaces, but we're not going to get into that.
*/
using namespace std;

/* Here is a sample function in C++. It has two parameters, both ints,
 * and it returns an int. The function needs to have a return type, that
 * is the int in front of the name of the function. The parameters also
 * need to have their types specified, that's the word int in front of
 * the variables a and b. The return value of the function is specified
 * by the word return that preceeds the value. In this case, a+b.
 *
 */
int mySum(int a, int b){

	return a+b;
}
/*Another function example. This one takes two double arguments and
 * returns a/b, also as a double.
 */
double myDiv(double a, double b){

	return a/b;
}
/*Another function example. This one takes one double argument and
 * returns a/2, also as a double.
 */
double myHalf(double a){
    a = a/2;
    return a;
}

//create a struct data type. It's like a class, but without methods
/*A struct is a complex data type that enables variables to be grouped
 * together in one block of memory. The types in the struct can be any
 * type, including pointers to another struct. */
struct WeatherData{
    int temperature;
    double humidity;
    double windVelocity;
    string day;
};


/*C++ programs all start from a main function. From main, you can 
 * call other functions. 

 * Notice that main is an int, meaning that it does
 * return something. The return of main is usually whether the program
 * executed successfully.
 */

int main(){
	/*One of the nice features of C++ is iostreams, which is how C++
	handles input and output. The language is designed to treat IO as
	a stream of characters, and it's up to the developer to handle those
	characters accordingly. The stream can be to/from a keyboard, a file,
	a variable, and the language is designed to handle these scenarios
	generically.

	We'll look at some of the IOStream features, but there is much more
	available than what we'll examine here. For a more complete explanation,
	see: http://www.cprogramming.com/tutorial/c++-iostreams.html
	*/
	/*iostream handles io from the console, using the cout and cin commands,
	where cout writes to the console and cin reads from the console */
	cout<<"Hello World";
	/*Add another statement to print*/
	cout<<"\nI'm a C++ program\n";

    cout << "Output sentence\n"; // prints Output sentence on screen
    cout << 120;               // prints number 120 on screen
    cout << "\n";
    int x = 5;
    cout << x;                 // prints the value of x on screen
    cout << "\n";
    /*Multiple insertion operations (<<) may be chained in a single statement:*/
    cout << "This " << " is a " << "single C++ statement. \n";

    /*cin is how we read input from console*/
	//declare a double
    double i;
    cout << "Please enter an integer value: ";
	//whatever user enters is stored in i
    cin >> i;
    cout << "The value you entered is " << i;
    cout << " and its double is " << i*2 << ".\n";

	/*Variables and data types*/
	/*Just like Python and Java, C++ has variables and those variables
	 * have types. The type of a variable determines
	 * how much space the variable needs in memory. For example, an
	 * integer needs 4 bytes and a double needs 8 bytes.
	 * You need to tell C++ the type of the variable when you declare
	 * it. For example, to declare an integer:*/
	 int a = 5;
	 int b = 6;
	 //And, there are operations on variables, such as *,+,-,/
	 int result = a * b;
	 cout<<result;
	 result = a - b;
	 cout<<"\n";
	 cout<<result;
	 //call the function created above main
	 int c = mySum(a,b);
	 cout<<c<<"\n";
	 /* Control structures: if statements and for and while loops
	  *
	  */
	  if (a < 5){
		  cout<<"a < 5"<<"\n";
	  }else if (a > 5){
		  cout<<"a > 5"<<"\n";
	  }else{
		  cout<<"a = 5"<<"\n";
	  }

    // if (condition) statement1 else if statement2 else statement3
      if (i < 5){
          cout<<"i < 5"<<"\n";
      }else if (i > 5){
          cout<<"i > 5"<<"\n";
      }else{
          cout<<"i = 5"<<"\n";
      }

    // while (expression) statement
    /* C++ has a while loop, just like Java and Python, that will
    execute as long as the looping criteria is true. Here, we define
    a variable called counter and initialize it to 0. As long as the
    value of counter is less than or equal to 5, the while loop code
    between the {} will execute. In this example, a function called
    myHalf is called and returns a value, which is stored in the variable
    called half. The variable called counter is incremented by 1 each 
    time through the while loop, which is what keeps the while loop 
    from executing forever.
    */
    double half=i;
    int counter = 0;
    while(counter <= 5)
    {
        half = myHalf(i);
        //output a mix of string literals and variables
        cout << "i = " << i << "and half = " << half << "\n";
        i = half;
        counter++;
    }

	//for loop example

   /* C++ also uses objects, and another variable called a struct. 
    * Structs are similar to classes, but they
    * don't have any methods, only variables. They are a complex data
    * type that makes it possible to groups variables together in one
    * block of memory and then access those variables through the name
    * of the struct variable.
    */

    /*There is a struct declared outside of the main function, called 
     * WeatherData that contains a value for temperature, humidity, and 
     * windVelocity. We can create a WeatherData
    variable as follows:
    */
    WeatherData dp1;
    dp1.humidity = 45;
    dp1.temperature = 95;
    dp1.windVelocity = 15;
    /* The type is WeatherData and you can set individual values with 
     * the . notation. The struct is a simpler data structure than the 
     * class. Nothing is private, there are no methods, no getters and 
     * setters. But, it still provides functionality to group variables 
     * together into one variable, and what gets put into that variable 
     * is the user's design.
    */

    cout<<"humidity:"<<dp1.humidity<<" temp:"<<dp1.temperature<<" wind:"<<dp1.windVelocity<<"\n";

	/*structs are a data type, such like an int is a data type, and as
	 * such, you can create arrays of structs. Anything you can do
	 * with an array or ints or doubles, you can do with an array of 
	 * structs.
	*/
	 WeatherData wdArray[10]; //allocate memory for 10 WeatherDatas
	 /*Then, use a for loop to traverse the array.*/
	 /*Access the ith element in the array, and then the humidity 
	  * property for that element.The syntax of the C++ for loop is
	  * starting condition; ending condition; loop increment. */
	 for(int i = 0; i < 10; i++){
		cout<<wdArray[i].humidity<<endl;
	 }
	 for(int i = 0; i < 10; i++){
		wdArray[i].humidity = i+10;
		wdArray[i].temperature = i*2;
		wdArray[i].day = "monday";
		cout<<wdArray[i].humidity<<endl;
		cout<<wdArray[i].day<<endl;
	 }
	 /*The C++ tutorial link on Moodle provides a great description of
	  * variable types and declaring variables*/
	/*Since main has a return type, we need to return something. We'll
	 * just return 0 for now*/
	return 0;
}
/*Once the code is typed, you will need to build and run it. If you're 
 * using Geany on the VM, select the brick icon and select Build.
 * Notice that a command printed in the window below this one with:
 * g++ -Wall -o "Lecture3IntroductionToC++" "Lecture3IntroductionToC++.cpp"
 * This command calls the C++ compiler to create the executable from
 * the source code. The .cpp file is the source. Click the gears next
 * to the brick to run the code.
 *
 /



