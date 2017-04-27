#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// Create an explore function which uses depth first seach to check all the
//  edges connected to the input vertex
// Inputs: an integer number relating to the vertex V, the array keeping track
//  of the points visited, the adjacency list, array containing the number of
//  vists to each vertex
// Return types: True if the DFS found a cycle
// or false if the DFS on the given vertex did not find a cycle
bool Explore(int v, bool *vertices_visited, vector<vector<int> > &adj,
            bool *vertex_stack){

  // Declare a variable to keep track of the next vertex to visited
  int w;

  // Declare boolean to keep track of if a cycle occurs
  bool cycle = false;

  // Start by setting the vertices_visited value at v to true
  vertices_visited[v] = true;

  // Add this vertex to the stack
  vertex_stack[v] = true;

  // Print the vertex visited on the screen
  std::cout << "The vertex being visited: " << v + 1 << std::endl;

  // Create a for loop to explore all the edges of the vertex v
  for(int i = 0; i < adj[v].size(); i++){
    // Store the next vertex to be checked
    w = adj[v][i];

    // Check if the vertex is currently on the stack
    if(vertex_stack[w] == true){
      // If the next vertex to explore is currently on the stack, then the graph
      // contains a cycle and we return true
      std::cout << "v is " << v + 1 << " and " << w + 1
                << " is already on the stack" << std::endl;
      return true;
    }

    // If it is not on the stack check if the vertex has been visited
    if(vertices_visited[w] == false){
      // Then we visit the cycle and store the result from the cycle check 
      cycle = Explore(w, vertices_visited, adj, vertex_stack);
    }

    // Check if any of the recursive calls to explore found a cycle
    if(cycle){
      return cycle;
    }

  }
  // After we finish exploring the vertex, we remove it from the stack array
  vertex_stack[v] = false;
  return false;
}


// Function to check if the given input graph is cyclic.
// Inputs: A vector of integer vectors relating to the graph and the links
// between vertices
// Output: As specified in the problem statement, the function will output a
// 1 if the graph is cyclic, or a 0 if the graph is not cyclic
int acyclic(vector<vector<int> > &adj) {

  // boolean to keep track of whether or not a cycle exists
  bool cycle = false;
  // Create an array to keep track of which vertices have been visited
  int num_vertices = adj.size();
  bool vertices_visited [num_vertices];
  std::cout << "The size of the vertices visited array is: " << num_vertices << std::endl;

  // Initially set all the values in the vertices_visited array to false
  for(int i = 0; i < adj.size(); i++){
    vertices_visited[i] = false;
  }

  // Initialize an array to keep track of the vertices currently on the
  // recursion stack. This will track if a back loop or a cycle occurs
  bool vertex_stack [num_vertices];
  for(int i = 0; i < num_vertices; i++){
    vertex_stack[i] = false;
  }

  // Run through each of the vertices and run depth first search
  for(int i = 0; i < adj.size(); i++){

    // Make a call to the explore function
    cycle = Explore(i, vertices_visited, adj, vertex_stack);

    // Check if the graph contained a cycle
    if(cycle){
      // if a cycle was found return 1
      return 1;
    }
  }
  return 0;
}


// Main function to take input from the user on the size and shape of the
// graph and to make a call to the acyclic function to test if the graph
// contains any cycles
int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << "Making a call to the acyclic function: \n" << acyclic(adj) << std::endl;
}
