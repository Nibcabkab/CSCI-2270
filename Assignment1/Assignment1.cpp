//Rishab Kanwal
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>



using namespace std;

struct item
{
	string type;
	bool wanted;
    int price;
};


int main(int argc, char* argv[]){
    item *itemlist = new item[99];
    int operations =0;
    ifstream infile;
    string strline;
    //infile.open(argv[1]);
    infile.open("messageboard.txt");
    int i = 0;
    int c = 0;
    //Opens and reads the file
    while(!infile.eof()){
        getline(infile, strline);
        string type = strline.substr(0, strline.find_first_of(','));
        string want = strline.substr(strline.find_first_of(',')+2);
        bool wanted;
        if (want[0] == 'f')
            wanted = false;
        else
            wanted = true;
        int price = atoi(strline.substr(strline.find_last_of(',')+2).c_str());
        //Assigns values to struct for first line
        if (i==0){
            itemlist[i].type = type;
            itemlist[i].wanted = wanted;
            itemlist[i].price = price;
            operations++;
        }
        //Otherwise runs the code with read checking
        else{
        //Runs secondary loop
         for(int n = 0; n < i; n++){
             //Checks if the current item is for sale or wanted
             operations++;
            if(wanted == true){
                //Check if wanted item is in price range
                if(type == itemlist[n].type && wanted != itemlist[n].wanted && price>=itemlist[n].price){
                    cout<<type<<" "<<itemlist[n].price<<" "<<endl;
                    c++;
                    //Removes item from the array and moves items back
                    for(int p = n; p < i-1; p++){
                            itemlist[p] = itemlist[p+1];
                            operations++;
                            }
                    i -=2;

                }
                //If a match is not found adds item to the array
                else{
                    itemlist[i].type = type;
                    itemlist[i].wanted = wanted;
                    itemlist[i].price = price;
                    operations++;
                    }

            }
        else{
                //Checks if wanted item is in the price range
            if(type == itemlist[n].type && wanted != itemlist[n].wanted && price<=itemlist[n].price){
                cout<<type<<" "<<price<<" "<<endl;
                c++;
                //Removes item from array and moves item back
                for(int p = n; p < i-1; p++){
                        itemlist[p] = itemlist[p+1];
                        operations++;
                        }
                        i-=2;

                }
                //If a match is not found then it adds the item to the array
                else{
                    itemlist[i].type = type;
                    itemlist[i].wanted = wanted;
                    itemlist[i].price = price;
                    operations++;
                    }
            }
         }
        }
        i++;
    }

    cout<<"#"<<endl;
    //Displays items that are still left over
    for(int l = 0; l < i; l++){
        if(itemlist[l].wanted==true)
            cout<<itemlist[l].type<<", "<<"wanted"<<", "<<itemlist[l].price<<endl;
        else
            cout<<itemlist[l].type<<", "<<"for sale"<<", "<<itemlist[l].price<<endl;

    }
    cout<<"#"<<endl;
    //Displays the number of operations
    cout<<"operations:"<<operations<<endl;
//    cout<<i<<endl;
//    cout<<c<<endl;
    }




