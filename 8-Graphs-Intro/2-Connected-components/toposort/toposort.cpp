#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

// Create an explore function which uses depth first seach to check all the
// edges connected to the input vertex
// Inputs: an integer number relating to the vertex V, the array keeping track
// of the points visited, and the adjacency list
// Return types: No return types
void Explore(int v, bool *vertices_visited, vector<vector<int> > &adj,
             vector<int> &used){

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
      Explore(w, vertices_visited, adj, used);
    }
  }

  // Modify the post visit value for the current vertex
  int post_visit = used[adj.size() + 1] + 1;

  // Increment the post visit value
  used[adj.size() + 1] = post_visit;

  // Store the post visit value at v
  used[v] = post_visit;

}

/*
  Function Definition: Depth First Search function
  Inputs: * adjacency list (vector)
          * vector <int> adj - list of adjacent vertices
          * vector <int> order - vector to keep track of the post order visit number
          * int x - the start point for the depth first search
*/
void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {

  // Create an array to keep track of which vertices have been visited
  int num_vertices = adj.size();
  bool vertices_visited [num_vertices];

  // Initially set all the values in the vertices_visited array to false
  for (int i = 0; i < adj.size(); i++){
    vertices_visited[i] = false;
  }
  // To completely explore the graph we run through all of the vertices in the
  // in the adjacency list and explore them
  for(int i = 0; i < adj.size(); i++){

    // First check to make sure the vertex has not been visited
    if(!vertices_visited[i]){
        Explore(i, vertices_visited, adj, used);
    }
  }
}

vector<int> toposort(vector<vector<int> > adj) {

  // Create a vector to keep track of the post order visit to each of the vertices
  // Make a space for each vertex plus one space at the end to keep track of
  // the post visit number
  vector<int> used(adj.size() + 1, 0);

  // Create an empty vector to keep track of the topological order of the
  // vertices
  vector<int> order;

  // Make a call to depth first search to test
  dfs(adj, used, order, 0);

  // Print out the values in the used variable for testing purposes
  for (int i = 0; i < used.size(); i++){
    std::cout << used[i] << std::endl;
  }

  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
