#include <iostream>
#include <vector>

using std::vector;
using std::pair;


// Create an explore function which uses depth first seach to check all the
// edges connected to the input vertex
// Inputs: an integer number relating to the vertex V, the array keeping track
// of the points visited, and the adjacency list
// Return types: No return types
void Explore(int v, bool *vertices_visited, vector<vector<int> > &adj){

  // Declare a variable to keep track of the next vertex to visited
  int w;

  // Start by setting the vertices_visited value at v to true
  vertices_visited[v] = true;

  // Print the vertex visited on the screen
  std::cout << "The vertex being visited: " << v + 1 << std::endl;
  // std::cout << "The visited array at v is: " << vertices_visited[v] << std::endl;

  // Create a for loop to explore all the edges of the vertex v
  for(int i = 0; i < adj[v].size(); i++){
    // Store the next vertex to be checked
    w = adj[v][i];

    // Check if the vertex w has been visited if not, Explore it
    if(vertices_visited[w] == false){
      Explore(w, vertices_visited, adj);
    }
  }
}

int reach(vector<vector<int> > &adj, int x, int y) {

  // Create an array to keep track of which vertices have been visited
  int num_vertices = adj.size();
  bool vertices_visited [num_vertices];
  std::cout << "The size of the vertices visited array is: " << num_vertices << std::endl;

  // Initially set all the values in the vertices_visited array to false
  for(int i = 0; i < adj.size(); i++){
    vertices_visited[i] = false;
  }

  // make a call to explore the input vertex x
  Explore(x, vertices_visited, adj);

  // Check if both the x and y vertices were visited aftering exploring x
  if(vertices_visited[x] && vertices_visited[y]){
    // Print the result on the screen for testing purposes
    std::cout << "Both x and y were visited" << std::endl;
    return 1;
  }

  // If both of the vertices were not visited we retun 0
  return 0;
}

int main() {
  size_t n, m;
  std::cout << "Enter n and m";
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << "\nMaking a call to the reach function\n";

  // Print the size of the vertex adj list for testing purposes
  // std::cout << "The size of the vertex vector is: " << adj.size() << std::endl;
  std::cout << "The result of the reach function is:" << reach(adj, x - 1, y - 1) << std::endl;
}
