#include "Graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.district = -1;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    for(int i = 1; i < vertices.size(); i++){
        cout<< vertices[i].district <<":"<<vertices[i].name<<"-->";

        for(int j = 0; j < vertices[i].adj.size(); j++){
             cout<<vertices[i].adj[j].v->name;
             if (j != vertices[i].adj.size()-1)
             cout<<"***";
         }
        cout<<endl;
    }
}
void Graph::findDistricts(){
    int district = 1;
    vector<vertex> unvisitedCities = vertices;
    int i = 1;
    while(unvisitedCities.size() != 1){
        queue<vertex*> bfq;
        vertex v;
        v = unvisitedCities[1];
        unvisitedCities[1].visited = true;
        unvisitedCities[1].district= district;
        unvisitedCities.erase(unvisitedCities.begin()+1);
        bfq.push(&unvisitedCities[1]);
        while (!bfq.empty()) {
            v = *bfq.front();
            bfq.pop();
            for(i=0;i<v.adj.size();i++) {
                if (v.adj[i].v->visited==false && v.adj[i].weight >= 1) {
                    v.adj[i].v->visited = true;
                    v.adj[i].v->district = district;
                    bfq.push(v.adj[i].v);
                    for(int p = 0; p < unvisitedCities.size(); p++){
                        if(v.adj[i].v->name == unvisitedCities[p].name){
                            unvisitedCities.erase(unvisitedCities.begin()+p-1);
                        }
                    }
                }
            }
        }
        district++;
    }
}
void Graph::findShortestPath(string startingCity, string destinationCity){
    vertex* s = NULL;
    vertex* d = NULL;
    for(int i = 0; i < vertices.size(); i++){
        if(startingCity == vertices[i].name)
            s = &vertices[i];
        else if(destinationCity == vertices[i].name)
            d = &vertices[i];
    }
    if(s == NULL|| d == NULL)
        cout<<"One or more of the cities doesn't exist"<<endl;
    else if(s->district == -1 || d->district == -1)
        cout<<"Please identify the districts before checking distances"<<endl;
    else if(d->district != d->district)
        cout<<"No safe path between cities"<<endl;
    else{
     {
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].distance = 0;
    }
    d->distance = INT_MAX;
    for(int i = 0; i < vertices.size(); i++){
        vertex *u = &vertices[i];
        u->previous = NULL;
        u->distance = INT_MAX;
        s->visited = true;
        s->distance = 0;
        vertex * minVertex;
        vector<vertex*> solved;
        while(d->visited == false){
            int minDistance = INT_MAX;
            for(int j = 0; j < solved.size(); j++){
                for(int k = 0; k < solved[j]->adj.size(); k++){
                    if(solved[j]->adj[k].v->visited == false){
                        if((solved[j]->adj[k].weight + solved[i]->distance) < minDistance){
                            minDistance = solved[j]->adj[k].weight+solved[i]->distance;
                            minVertex = solved[j]->adj[k].v;
                            solved[j]->adj[k].v->visited = true;
                        }
                        cout<<"loop 3"<<endl;
                    }
                    solved.push_back(minVertex);
                    solved[j]->adj[k].v->previous = solved[j];
                }
            }

//        cout<<","<<path[j]->name;
//        cout<<endl;
        }
        cout<<"this"<<endl;
    }
}
    }


}
