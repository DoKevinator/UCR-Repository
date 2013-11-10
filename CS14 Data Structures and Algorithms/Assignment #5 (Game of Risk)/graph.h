// Course: CS 14 Spring 2013
//
// First name: Kevin
// Last name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: Steve Cook
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//graph.h


#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <list>
#include <string>
#include <map>
#include <stack>

enum COLOR { BLUE, GREEN, YELLOW, PURPLE, RED, NONE };

class Graph {
    
private:
    struct GraphNode {
        std::string name;	//name of the country
        unsigned long number_of_pieces;	//pieces in the country
        COLOR color;		//color of the country
        GraphNode* previous;	//previous used for Dijkstras
        
        std::list<GraphNode*> neighbors;	//neighbors of the node
    
        GraphNode( const std::string& nodename, unsigned long pieces, COLOR c )
        :name(nodename), number_of_pieces(pieces), color(c), previous(NULL) {
            //GraphNode constructor
        }
    };
    
    //map of nodes in the graph
    std::map< std::string, GraphNode* > nodes;
    
    //creates a node/edge
    void create_node( const std::string&, unsigned long p, COLOR c );
    void add_edge( const std::string&, const std::string& );

public:
    Graph();
    ~Graph();
    
    //loads graph from a text file
    void load_graph( const std::string& filename );
    
    //gets shortest path with Dijkstra
    std::stack<std::string> shortest_path( const std::string&, 
    									   const std::string& );
    
    void print_graph();	//prints the graph

    void reset();
};


#endif  //__GRAPH_H_

