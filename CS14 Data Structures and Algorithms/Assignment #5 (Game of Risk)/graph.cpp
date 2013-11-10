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

//graph.cpp

#include "graph.h"
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

Graph::Graph() {
	//default constructor
}

Graph::~Graph() {		//destructor
	for( map<string,GraphNode*>::iterator i = nodes.begin();
		 i != nodes.end(); i++ ) {
		delete i -> second;
	}
}


stack<string> Graph::shortest_path( const string& start,
									   const string& end ) {

	stack<string> path;
	
	if (nodes.count(start) == 0 || nodes.count(end) == 0) {
		cerr << endl;
		cerr << "Error: invalid country " << endl;
		return path;
	}


	if ( nodes.find(start) -> second -> color ==
		 nodes.find(end) -> second -> color ) {
		cerr << endl;
		cerr << "Error: starting and ending territories are of the same color "
			 << endl;
		return path;
	}
	
	//use Dijkstra's algorithm.
	map<GraphNode*, unsigned long> distances;
	
	for( map<string,GraphNode*>::iterator i = nodes.begin(); 
		 i != nodes.end(); i++ ) {
		distances.insert( pair<GraphNode*,unsigned long>( i -> second, 
																 ULLONG_MAX) );
	}	//initialize all node distances to "infinity"
	
	GraphNode* start_node = nodes.find(start) -> second;
	distances.find( start_node ) -> second = 0;
	//make the starting node distance 0
	
	queue<GraphNode*> Q;
	Q.push(start_node);
	//push start node onto the queue
	
	while( Q.size() != 0 ) {
		GraphNode* current = Q.front();
		Q.pop();	//get the current node
		
		for( list<GraphNode*>::iterator i = current -> neighbors.begin(); 
			 i != current -> neighbors.end(); i++ ) {
			unsigned long t = distances.find(current) -> second + 
							  (*i) -> number_of_pieces;
			//compare the updated distance to the current distance
			if( t < distances.find(*i) -> second
				&& nodes.find(start) -> second -> color 
				!= distances.find(*i) -> first -> color ) {
				distances.find(*i) -> second = t;
				(*i) -> previous = current;
				Q.push(*i);
			} 
		}
	}

	if ( distances.find(nodes.find(end) -> second) -> first -> previous 
		 == NULL ) {
		cerr << endl;
		cerr << "Error: no possible path from the start and end countries "
		     << endl;
		return path;
	}
	
	path.push( nodes.find(end) -> second -> name );
	//makes a stack of the pathway in strings to output later
	while( path.top() != nodes.find(start) -> second -> name ) {
		path.push( nodes.find( path.top() ) -> second -> previous -> name ); 
	}
	
	return path;
	
}



void Graph::load_graph( const string& filename ) {
	ifstream ipfile;	//file stream for input
	ipfile.open( filename.c_str() );
	
	if( ipfile.fail() ) {
		cerr << "Could not find input file." << endl;
		exit(1);	//error if it cannot find file to input from
	}
	
	string input;
	
	while (ipfile >> input) {
		if (input == "node") {	//we know the input is a node at this point
			string nodename;
			unsigned long pieces = 0;
			COLOR color;
			
			ipfile >> nodename;
			
			if( nodename.at(0) != '"') {
				cerr << "Error: Format of text in file is invalid." << endl;
				exit(1);	//if theres no quotation, file is in wrong format
			}
			
			if (nodename.at( nodename.size()-1 ) != '"') {
				string temp = nodename;
					//loops until we get the entire country name in quotataions
				while (temp.at(temp.size()-1) != '"') {
					ipfile >> temp;
					nodename = nodename + ' ' + temp;
				}
			}
			//gets rid of the quotation marks of the country name
			nodename = nodename.substr(1);
			nodename = nodename.substr(0, nodename.size() -1);
			
			ipfile >> pieces;	//gets the pieces from input
			
			string temp_color;
			ipfile >> temp_color;
				//converts the color into an enumerated value
			if (temp_color == "blue") {
				color = BLUE;
			} else if( temp_color == "green") {
				color = GREEN;
			} else if( temp_color == "red") {
				color = RED;
			} else if( temp_color == "yellow") {
				color = YELLOW;
			} else if( temp_color == "purple") {
				color = PURPLE;
			} else {
				cerr << "Error: Format of text does not specify color." <<endl;
				exit(1);	//color isnt specified right 
			}
			
			//if the node doesnt already exist, make it.
			if (nodes.count(nodename) == 0) {
				create_node( nodename, pieces, color);
			} else {
				//if the node already exists, rewrite over the node
				map<string,GraphNode*>::iterator i;
				i = nodes.find( nodename ); 
				i -> second -> number_of_pieces = pieces;
				i -> second -> color = color;
			}
			
		} else if( input == "edge" ) {	//we know its an edge case at this point
			string nodename1, nodename2;
			
			ipfile >> nodename1;
			
			if( nodename1.at(0) != '"') {
				cerr << "Error: Format of text in file is invalid." << endl;
				exit(1);	//if quotations not there, file is in wrong format
			}
			
			if (nodename1.at( nodename1.size()-1 ) != '"') {
				string temp = nodename1;
				//loops until it gets the entire country name
				while (temp.at(temp.size()-1) != '"') {
					ipfile >> temp;
					nodename1 = nodename1 + ' ' + temp;
				}
			}
			//gets rid of the quotations in country name
			nodename1 = nodename1.substr(1);
			nodename1 = nodename1.substr(0, nodename1.size()-1);
			
			ipfile >> nodename2;
			
			if( nodename2.at(0) != '"') {
				cerr << "Error: Format of text in file is invalid." << endl;
				exit(1);	//if quotations not there, file is in wrong format
			}
			
			if (nodename2.at( nodename2.size()-1 ) != '"') {
				string temp = nodename2;
				//loops until it gets entire country 2 name
				while (temp.at(temp.size()-1) != '"') {
					ipfile >> temp;
					nodename2 = nodename2 + ' ' + temp;
				}
			}
			//gets rid of quotations for country 2's name
			nodename2 = nodename2.substr(1);
			nodename2 = nodename2.substr(0, nodename2.size()-1);
			
			if (nodes.count(nodename1) == 0) {
				create_node( nodename1, 0, NONE);
			}	//if country1 doesnt exist, make it
			
			if (nodes.count(nodename2) == 0) {
				create_node( nodename2, 0, NONE);
			}	//if country2 doesnt exist, make it
			
			add_edge( nodename1, nodename2 );
			//adds edge between country 1 and country 2
		}
	}
	
	ipfile.close();
}



void Graph::create_node( const string& s, unsigned long p, COLOR c ) {
	GraphNode* newnode = new GraphNode( s, p, c );
	nodes.insert( pair<string,GraphNode*>( s, newnode ) );
}	//makes a new node and puts it into the map



void Graph::add_edge( const std::string& n1, const std::string& n2 ) {
	
	map<string,GraphNode*>::iterator node1 = nodes.find(n1);
	map<string,GraphNode*>::iterator node2 = nodes.find(n2);
	
	node1 -> second -> neighbors.push_back( node2 -> second );
	node2 -> second -> neighbors.push_back( node1 -> second );
	//adds the nodes as neighbors
}	//this is an undirected graph


void Graph::reset() {
	for(map<string,GraphNode*>::iterator i = nodes.begin();
		i != nodes.end(); i++ ) {
		i -> second -> previous = NULL;
	}
}

void Graph::print_graph() {
	//loops through map to output name of node
	for( map<string,GraphNode*>::iterator i = nodes.begin(); 
		 i != nodes.end(); i++ ) {
		cout << i -> second -> name << endl;
			//outputs all of it's neighbor's names
		for( list<GraphNode*>::iterator j = i -> second -> neighbors.begin();
			 j != i -> second -> neighbors.end(); j++ ) {
			cout << " - " << (*j) -> name << endl;
		}
	}
}


