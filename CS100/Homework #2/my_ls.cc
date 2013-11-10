/*
* Course: CS 100 Fall 2013 *
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@well.cs.ucr.edu
*
* Assignment: Homework #2
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA. */

//my_ls.cc

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <ctime>
#include <iostream>

using namespace std;

void print_permissions( struct stat& buf ) {
	cout << "-";

	//OWNER PERMISSIONS
	if ( S_IRUSR & buf.st_mode ) 
		cout << "r";
  	else 
  		cout << "-";
  	if ( S_IWUSR & buf.st_mode ) 
  		cout << "w";
  	else 
  		cout << "-";
  	if ( S_IXUSR & buf.st_mode ) 
  		cout << "x";
 	else 
 		cout << "-";

 	//GROUP PERMISSIONS
  	if ( S_IRGRP & buf.st_mode ) 
  		cout << "r";
  	else 
  		cout << "-";
  	if ( S_IWGRP & buf.st_mode ) 
  		cout << "w";
  	else 
  		cout << "-";
  	if ( S_IXGRP & buf.st_mode ) 
  		cout << "x";
  	else 
  		cout << "-";
  
  	//OTHER PERMISSIONS
  	if ( S_IROTH & buf.st_mode ) 
  		cout << "r";
  	else 
  		cout << "-";
  	if ( S_IWOTH & buf.st_mode ) 
  		cout << "w";
  	else 
  		cout << "-";
  	if ( S_IXOTH & buf.st_mode ) 
  		cout << "x";
  	else 
  		cout << "-";

  	cout << " ";
}

void print_file( char* path, struct stat& buf ) {
	print_permissions(buf);

	time_t now = buf.st_mtime;
	std::tm * ptm = std::localtime(&now);
	char buffer[32];
	
	strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm); 

	cout << '\t' << buf.st_nlink << '\t' 
		 << buf.st_size << '\t'
		 << buffer << '\t'
		 << path << endl; 
}

void print_directory( char* path, int depth ) {

	unsigned char isFile = 0x8;
	unsigned char isDir = 0x4;
	DIR* dir;
	struct dirent* entry;

	if ( (dir = opendir (path)) != NULL) {

		// print all the files and directories within directory
		while ((entry = readdir (dir)) != NULL) {

			if( (entry -> d_name)[0] == '.') {
				continue;
			}

			for( int i = 0; i < depth; i++ ) {
				cout << "\t";
			}

			if( entry -> d_type == isFile ) {
				cout << entry -> d_name << endl;	
			} else {
				cout << endl;
				cout << "./" << entry -> d_name << ":" << endl;
			}
		 	
		 	if( entry -> d_type == isDir ) {
				strcat(path, "/");
				strcat(path, entry -> d_name);
				print_directory( path, depth + 1 );
			}

		}

		closedir (dir);

	} else {
		//could not open directory 
		cout << "Error: could not open directory." << endl;
		return;
	}
}


void print_default_dir( string path, int depth ) {
	unsigned char isFile = 0x8;
	unsigned char isDir = 0x4;
	DIR* dir;
	struct dirent* entry;

	if ( (dir = opendir (path.c_str())) != NULL) {

		// print all the files and directories within directory
		while ((entry = readdir (dir)) != NULL) {

			if( (entry -> d_name)[0] == '.') {
				continue;
			}

			for( int i = 0; i < depth; i++ ) {
				cout << "\t";
			}

			if( entry -> d_type == isFile ) {
				cout << entry -> d_name << endl;	
			} else {
				cout << endl;
				cout << "./" << entry -> d_name << ":" << endl;
			}
		 	
		 	if( entry -> d_type == isDir ) {
		 		path += "/";
		 		path += entry -> d_name;
				print_default_dir( path, depth + 1 );
			}

		}

		closedir (dir);

	} else {
		//could not open directory 
		cout << "Error: could not open directory." << endl;
		return;
	}
}


int main(int argc, char** argv) {
	
	if (argc > 1) {
    	char *path = argv[1];
    	struct stat buf;

    	if ( stat(path, &buf) != -1 ) {
    		if( S_ISREG(buf.st_mode) ) {
    			print_file( path, buf );
    		} else if( S_ISDIR(buf.st_mode) ) {
    			print_directory( path, 0 );
    		}

    	} else {
      		cerr << "Error " << errno << " opening " << path << endl;
    	}

 	} else {
    	//no parameter case
    	//char* path = ".";		//this causes a bus error
    	//strcat(path, ".");	//this causes a segfault
    							//so confused...

 		string tmp = ".";
    	print_default_dir(tmp,0);
 	}

	//3 options
	//no arugument: print all files in current directory
	//if argument is directoy, print name, then indent and print files in N
	//if argument is file, print file attributes
	
	
	return 0;
}














