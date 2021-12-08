#include <iostream>
#include "cs225/PNG.h"
#include "graph.h"
#include "draw.h"
#include "functions.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Write your own main here
    Graph g("data/routes.dat", "data/airports.dat"); //try create a Graph object
    //Graph g("route_testcase_1.dat", "Airport_testcase_1.dat");
    
    //Graph g2;
    //cout << "Add your own tests here! Modify main.cpp" << endl;
    string id = "3364";
    //cout<<g.getVertex(id).vertex_id;
    //cout<<" ";
    Graph::Vertex v(id);
    Graph::Edge e("3364", "3366", 1046.256371);
    //g.insertVertex(v);
    //cout<<g.getFirstVertex().vertexToString();
    vector<Graph::Vertex> vs = g.getAdjacentVertex(v);
    vector<Graph::Edge> es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    cout<<""<<endl;
    g.removeEdge(e);
    es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    cout<<""<<endl;
    g.removeEdge(e);
    g.insertEdge(e);
    es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    
    //test draw functions 
    Draw draw;
    PNG * graph = draw.open();

    Functions func;
    vector<Graph::Vertex> list = func.BFS(g);
    vector<string> str_list;
    for (size_t i = 0; i < list.size(); i++) {
        str_list.push_back(list[i].vertex_id);
        cout << list[i].vertex_id << " ";
    }
    cout << endl;
    cout << "BFS size is " << list.size() << endl;

    //test drawmap
    Graph::Vertex YYC("178", 51.113899231, -114.019996643);
    Graph::Vertex FCO("1555", 41.8002778, 12.2388889);
    map<string, string> theMap = func.Dijkstra(g, YYC, FCO);
    cout << theMap.size() << endl;
    draw.drawmap("data/routes.dat", "data/airports.dat", YYC, FCO);

    // draw.open();
    // for (size_t i = 0; i < list.size() - 1; i++) {
    //     Graph::Vertex first = list[i];
    //     Graph::Vertex second = list[i+1];
    //     double x_1 = first.latitude;
    //     double y_1 = first.longitude;
    //     double x_2 = second.latitude;
    //     double y_2 = second.longitude;
    //     draw.drawpoint(graph, x_1, y_1);
    //     draw.drawpoint(graph, x_2, y_2);
    //     draw.drawline(graph, x_1, y_1, x_2, y_2);
    // }
    // draw.output(graph);


    return 0;
}
