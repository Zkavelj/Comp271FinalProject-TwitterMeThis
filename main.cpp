#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class GraphNode{
public:
    int UserID;
    GraphNode* next;
    GraphNode(){
        UserID != 0;        //saying UserID is not equal to zero, but it's a big number
        next = NULL;}};

//class for storing graph as adjacency list
class Graph{
    //List of headnodes containing list of connected UserID
    GraphNode* headnodes[];
    int n;
    int visited[];
public:
    Graph();        //Constructor to initialize all headnodes[] to null
    void create();      //To create graph
    void BFS(int s);};        //Breath-first search

Graph::Graph(){
    for(int i = 0; i < n; i++){
        headnodes[i] = NULL;}}

//Function to create an empty graph
//the empty graph has the total number of UserID and followers as zero
void Graph::create(){
    //Method to create a graph represented by adjacency list
    GraphNode *curr, *prev;
    int n1, i, j, UserID, done = false;
    //cout << "Enter the no. of vertices: " << endl;
    //cin >> n;
    for(i = 0; i < n; i++){
        if(!(headnodes[i] = new GraphNode)){     //Allocate memory for new node
            //cout << "Insufficient memory" << endl;;
            exit(0);}
        headnodes[i] -> UserID = i + 1;
        //cout << "Enter the no. of UserID connected to" << (i + 1) << ": " << endl;
        //cin >> n1;
        prev = headnodes[i];
        for(j = 0; j < n1; j++){
            if(!(curr = new GraphNode)){
                //cout << "Insufficient memory" << endl;
                exit(0);}
            done = false;
            do{
                //cout << "Enter UserID no. of connected UserID: " << endl;
                //cin >> UserID;
                if(UserID > n && UserID < 1){
                    //cout << "UserID out of range" << endl;
                    //cout << endl << "Valid range: " << n;
                    }
                else{
                    curr -> UserID = UserID;
                    prev -> next = curr;
                    prev = curr;
                    done = true;}}
            while(!done);}
        if(n1 == 0){
            prev -> next = NULL;}}
    return;}

//Function for breadth-first search
void Graph::BFS(int v)
{
    queue q;
    GraphNode* curr;
    visited[v] = true;
    //cout << " " << headnodes[v] -> UserID;
    q.addq(headnodes[v]);
    while(!q.emptyq()){
        curr = q.deleteq();
        curr = curr -> next;
        while(curr != NULL){
            if(!visited[curr -> UserID - 1]){
                q.addq(headnodes[curr -> UserID -1]);
                //cout << "\t" << curr -> UserID;
                visited[curr -> UserID - 1] = true;}
            curr = curr -> next;}}
    return;}

int main()
{
    ifstream thisfile;      //input file stream
    ofstream outfile;       //output file stream
    string file_name;       //a string called filename
    cout << "Hello Twitter!" << endl;
    cout << "What is the name of the file: ";       //console output name of file
    getline(cin, file_name);         //user input the name of the file
    thisfile.open(file_name.c_str());       //c-style string, open the input file
    while(thisfile.fail()){
        //if the user input wrong file then
        //console asks the user to input the correct file
        cout << file_name << " " << "file not found" << endl;
        cout << "Enter in another file: ";
        getline(cin, file_name);
        thisfile.open(file_name.c_str());}
    if(thisfile.is_open())      //if thisfile is open
    int v2 =  rand() % 100 + 20;    //the number of tweets generated between 20 and 100
    outfile.open("Tweeters.txt");     //open an output text file
    outfile << "Top Users: " << endl;
    Graph g;
    g.create();
    thisfile.clear();       //clear the input file
    outfile.clear();        //clear the output file
	thisfile.close();       //close the input file
    outfile.close();        //close the output file
    cout << endl;       //space
    cout << "Output file created" << endl;       //console output, output file is created
    cout << "Done, good job!" << endl;      //words of encouragements
    return 0;}
