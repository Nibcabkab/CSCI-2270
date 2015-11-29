//Rishab Kanwal
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <ctype.h>


using namespace std;
//Declaration of the word struct
struct word{
    int num;
    string word;
};
//Cheks to see if a word is counted
bool checkWord(string word){
    bool counted = true;
    string excludedWords[50] = {"the","be","to","of","and","a","in","that","have","i","it",
    "for","not","on","with","he","as","you","do","at","this","but","his","by","from","they",
    "we","say","her","she","or","an","will","my","one","all","would","there","their","what",
    "so","up","out","if","about","who","get","which","go","me"};
    int i =0;
    while(i<50){
        if(excludedWords[i] == word)
            counted =false;
        i++;
    }
    return counted;
}
//Doubles the size of the array
word* arrayDoubler(word* wordList, int arrayLength){
    word *doubleList = new word[arrayLength*2];
    for(int x = 0; x < arrayLength; x++){
            doubleList[x] = wordList[x];
    }
    delete[] wordList;
    return doubleList;
}



int main(int argc, char* argv[]){
    word *wordList;
    word *temp;
    wordList = new word[10000];//Creates an instance of the struct word
    int currentArraySize = 100;
    int total = 20;
    int operations =0;
    ifstream infile;
    string strline;
    int arrayLength =0;
    //infile.open(argv[1]);
    //int numElements = atoi(argv[2]);
    infile.open("Hemingway_edit.txt");
    int numElements = 10;
    int uniqueWords = 0;
    int totalWords = 0;
    int timesDoubled = 0;
//Runs until the file is over splits into lines
    while(!infile.eof()){
        string word;
        getline(infile, strline);
        istringstream line(strline);
        string token;
        while(getline(line, token, ' ')){
                if(checkWord(token) && token != " " && token != ""){
                    if(uniqueWords == 0){
                      wordList[0].word = token;
                        wordList[0].num = 1;
                        uniqueWords++;
                        totalWords++;

                    }
                    else{
                        bool added = false;
                        for(int i = 0; i< uniqueWords; i++){
                            if(wordList[i].word == token){
                                wordList[i].num ++;
                                added = true;
                                totalWords++;
                                break;
                            }
                        }
                        if(!added){
                            wordList[uniqueWords].word = token;
                            wordList[uniqueWords].num = 1;
                            uniqueWords++;
                            totalWords++;

                        }
                        }
                }
                if (uniqueWords == currentArraySize+1){
                temp = arrayDoubler(wordList, currentArraySize);
                currentArraySize = currentArraySize*2;
                timesDoubled++;
                }
        }
    }
//Bubble sort(lazy) to sort the array in descending order
    int tempNum;
    string tempString;
    for(int f = 0; f < uniqueWords; f++){
        for(int j = 0; j < uniqueWords-1; j++){
            if(wordList[j].num<wordList[j+1].num){
                tempNum = wordList[j].num;
                tempString = wordList[j].word;
                wordList[j].num = wordList[j+1].num;
                wordList[j].word = wordList[j+1].word;
                wordList[j+1].num = tempNum;
                wordList[j+1].word = tempString;

            }
        }
    }
    int i = 0;
    while(i < numElements){
        cout<<wordList[i].num<<" - "<<wordList[i].word<<endl;
        i++;
    }
//Prints out the requirements for COG
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<timesDoubled<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<uniqueWords<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<totalWords<<endl;

}
