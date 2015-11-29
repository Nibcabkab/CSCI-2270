#include <iostream>
#include <vector>
#include "Graph.h"
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;


int main(int arg, char* argv[]){
    Graph zombieTownList;
    ifstream infile;
    infile.open(argv[1]);
    string strline;
    int currentLine = 0;
    string token;
    vector<string> cityList;
    while(!infile.eof()){
        getline(infile, strline);
        istringstream line(strline);
        if(currentLine == 0){
            while(getline(line, token, ',')){
                cityList.push_back(token);
            }
            for(int i = 0; i < cityList.size(); i++){
                zombieTownList.addVertex(cityList[i]);
            }
        }
        else{
            int currentCity = 0;
            string currentVertex;
            while(getline(line, token, ',')){
                if(currentCity == 0){
                    currentVertex = token;
                }
                else{
                    zombieTownList.addEdge(currentVertex, cityList[currentCity], atoi(token.c_str()));
                }
                currentCity++;
            }
        }
        currentLine++;
    }

    while(true){
        string input;
        cout << "======Main Menu=====" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest distance" << endl;
        cout << "5. Extra credit" << endl;
        cout << "6. Quit" << endl;
        getline(cin, input);
        int inputInt = stoi(input);
        switch (inputInt) {
            case 1:
                zombieTownList.displayEdges();
                break;
            case 2:
                zombieTownList.findDistricts();
                break;
            case 3:{
                    string startingCity;
                    string endingCity;
                    cout << "Enter a starting city:" << endl;
                    getline(cin, startingCity);
                    cout << "Enter an ending city:" << endl;
                    getline(cin, endingCity);
                    zombieTownList.findShortestPath(startingCity, endingCity);
                }
                break;
            case 4:{
                    string startingCity;
                    string endingCity;
                    cout << "Enter a starting city:" << endl;
                    getline(cin, startingCity);
                    cout << "Enter an ending city:" << endl;
                    getline(cin, endingCity);
                    zombieTownList.findShortestPath(startingCity, endingCity);
                }
                break;
            case 5:
                cout<<"Nope"<<endl;
                break;
            case 6:
                exit(EXIT_SUCCESS);
            default:
                cout << "Invalid input";
        }
    }
}
