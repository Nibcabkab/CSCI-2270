#include <iostream>
#include <string>

using namespace std;
/* So far we've talked about variables types, such as integers,
 * floats, strings, booleans. I have on occasion mentioned objects,
 * such as strings and said that they were built from the string class.
 * We used those types in code to represent something in our code.
 * For example, we could have an integer that represented a number of
 * minutes, or a float that represented the similarity score for two
 * strings.
 *
 * But, how would you represent something such as a bicycle? We want
 * one data type that is a bicycle, and so far, we haven't discussed
 * anything that would allow us to do that, represent something as
 * complex as a bicycle. This is the value of object-oriented
 * programming, we can build an object that's type is Bicycle. It's not
 * an integer or a float or a string, it's a Bicycle.
 *
 * When you think about what objects are in the real-world, they have
 * properties and behaviors, generally. For example, real bicycles have
 * properties such as current speed, color, manufacturer. They also
 * have behaviors such as rolling, speeding up, slowing down. In code,
 * those properties can be represented using variable types that we've
 * already discussed, for example, current speed could be an integer.
 * Properties could also be other objects, for example, the Bicycle
 * object could have a Rider property, where the Rider is another object
 * The behavior of objects are captured as methods, which are similar
 * to functions in Python. These are the actions that the object can
 * take, or the things that it can do, which may need to a change in
 * it's properties. For example, if the Bicycle behavior is to speed up,
 * then this will change its current speed property.
 *
 * Objects are built from structs and classes in C++.
    You can think of structs and classes as templates
 * for objects, or blueprints for objects, they define the outline for
 * the object, and the specifics
 * for individual instances of the object are introduced when the object
 * is created and as it executes. For example, the Bicycle class could have
 * a property (aka variable) called color, but color is only set to a
 * specific value, such as red, blue, orange, for instances of the
 * Bicycle object.
 *
 * The Bicycle also has things that it does, such as move. The class
 definition for a Bicycle contains methods for controlling the values
 of the Bicycles properties. For example, the Bicycle might have a
 property called speed and you could change the value of that
 property through a method called pedal.
*/

/*The Automobile class is what defines instances of the
 * Automobile object. The class defines what
 * the properties are of the object and what the methods
 * are for the object.
 */
class Automobile {
	/* Define the properties of the Automobile. These are
	 * called instance variables, each instance of Automobile
	 * that we create will have values for these variables.
	 *
	 * What are all the properties of an automobile?
	 */
private:
    string make;
	string model;
	int year;
	int currentSpeed;
    string condition;
    string VIN;

	/*These variables are declared as private, which means
	 * that only methods inside this class can access them.
	 Unlike a struct where the member variables were all
	 public and you could access them with x->name = "x", to
	 access the name variable of a struct called x, with private
	 variables there needs to be an intermediary function and it
	 is this function that changes the value of the variables.
	 */
public:
    //create a new instance of Automobile setting year, make, model
	Automobile(string ma, string mo, int y){
		make = ma;
		model = mo;
		year = y;
	}
    //create a new instance of Automobile setting year, make, model, condition
    Automobile(string ma, string mo, int y, string co){
		make = ma;
		model = mo;
		year = y;
		condition = co;
	}

    Automobile(){
        /*
        Create an instance of Automobile with fixed set of parameters.
        */
		make = "Outback";
		model = "Subaru";
		year = 2014;
		condition = "new";

    }
    /*
    There are three examples of constructors and each one can be used
    to create an instance of Automobile using a different set of
    arguments. This is called overloading. Multiple constructors are
    created with different types and numbers of arguments and the
    compiler will use the one that matches the call.

    */

	/*
	 * This is an instance method, it will run on the specific
	 * instance of the object upon which it has been called.
	 * This particular method is an example of a getter, it
	 * gets a value from the object.
	 */
	int getSpeed(){
		return currentSpeed;
	}
	/*
	 * If we can get the speed, we may also want to set the speed.
	 * This is called a setter. Notice that the setter doesn't
	 * return a value, but it does have an argument. Whatever
	 * value is passed in to the method is used to set the value
	 * of an instance variable.

        Here is where it is nice to control what the value can
        be set to. For example, we can set restrictions such as
        speed > 0, or speed < 200. If the value of the speed
        argument does not meet these criteria, then the instance
        variable speed is not changed. You could do this check in
        main before calling the setSpeed method, but this is much
        cleaner. The functionality related to the class is encapsulated
        in the class.
	 */
	void setSpeed(int speed){
        if(speed < 0)
            cout<<"Speed can't be negative"<<endl;
        else if(speed > 200)
            cout<<"That car doesn't go that fast"<<endl;
        else
            currentSpeed = speed;
	}
	/*
	The names of these methods is not by accident. Getting variables
	from a class instance and setting variables are handled using
	getter and setter methods. The names of these methods start with
	get and set.

	You will generally want a get and set for each instance variable that
	you want to access.
	*/
	void setCondition(string co){
        condition = co;
	}
    //you probably won't need a setMake, setModel, but this is how they look
	void setMake(string ma){
        make = ma;
	}

	void setModel(string mo){
        model = mo;
	}
    string getMake(){
        return make;
    }
    string getModel(){
        return model;
    }
};
//What would the class look like for a Bicycle, Person, Student
//How would you add an accelerate method to Automobile?
int main()
{
        /* Create a new instance of the Automobile object
		 * This calls the constructor in the Automobile
		 * class, giving it the values for make, model, and year
		 */
		Automobile subaru("Subaru", "Outback", 2010);
		//create another Automobile, called prius
		//Calls the constructor with different values
		Automobile prius("Toyota", "Prius", 2005);

        Automobile car();

        Automobile truck("Ford", "F150", 1991, "needs work");

		/*
		 * To access properties in the Automobile instance, we need
		 * what is called a getter, it is a method of the Automobile
		 * that can access a specific property for that instance
		 * only. For example,
		 */
		int speed = subaru.getSpeed();
		cout<<speed<<endl;
		/*The getSpeed method is defined in the Automobile
		 * class. We will also want to set the speed, using
		 * the setSpeed method defined in the class.
		 */
		subaru.setSpeed(65);
		//now get the speed again
		speed = subaru.getSpeed();
		cout<<speed<<endl;
		/*but, setting the subaru speed doesn't change the
		 * prius speed. The Prius speed hasn't been set yet, so
		 it might be garbage if you check it.

		 We could change one of the constructors to set the initial
		 speed.
		 */
		speed = prius.getSpeed();
		cout<<speed<<endl;

		/*
		 * What are some of the things that an automobile can do?
		 */

        truck.setCondition("restored");

        //What about an array of Automobiles
        Automobile autos[10]; //this is the default constructor
	//add print in constructor
        //you can call the constructor again, or use other set methods
        for(int x = 0; x < 10; x++)
            autos[x] = Automobile("Ford", "truck", 1990+x, "needs work");


    return 0;
}
