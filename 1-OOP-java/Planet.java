public class Planet {
    
    // Instance Variables
    double x = 0;
    double y = 0;
    double xVelocity = 0;
    double yVelocity = 0;
    double mass = 0;
    double Fnetx = 0;
    double Fnety = 0;
    String img = "Blank Planet";

    // Constructor
    public Planet(double x_pos, double y_pos, double vx, 
                  double vy, double m, String img_name){
    x = x_pos;
    y = y_pos;
    xVelocity = vx;
    yVelocity = vy;
    mass = m;
    img = img_name;
    }

    // Method to calculate the squared distance between two planets
    public double CalcDist(Planet a, Planet b){
        // Based on the x and y values of the planets, we can calculate the distance between then
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        double distance_squared = dx*dx + dy*dy;
        return distance_squared;
    }

    // This function will take two planets as inputs and return the force 
    // Created between them
    public double CalcPairWiseForce(Planet a, Planet b){
        
        // Calculate the distance between planets a and b
        // Make use of the calc dist function
        double d_squared = a.CalcDist( a, b);

        // Calculate the force of gravity between them
        double G = 6.67 * Math.pow(10, -11);
        double force = G * a.mass * b.mass / d_squared;

        // return the force
        return force;
    }

    // Set net force function
    // This function will take in an array of planets and set the net force of this planet to the calculated net force
    // This function will return no values
    public void SetNetForce(Planet a[]){
        // The function will have to iterate through the array to calculate the net force
        // Need to check to make sure this planet is not in the array since the planet cannot exert a net force on itself
        int size = a.length;
        double Fnet = 0;
        double dx = 0;
        double dy = 0;
        double r = 0;

        // create a for loop to run through the array
        for (int i = 0; i <=(size-1); i++){
            // make sure the planet is not equal to itself before calculating the net force
            if (this != a[i]){
                // calculate the net force here
                System.out.println("Testing the force function here");
                
                // Calculate the net force
                Fnet = CalcPairWiseForce(this, a[i]);

                // Calculate the directions of the forces
                dx = a[i].x - this.x;
                dy = a[i].y - this.y;
                r = Math.pow(CalcDist(this, a[i]), 0.5);

                // Caclulate the force directions
                this.Fnetx = Fnet*dx/r;
                this.Fnety = Fnet*dy/r;            
                System.out.println("The net forces and directions: " +this.Fnetx + "in the x-dir " +this.Fnety + " in the y dir" );
            }

        }
    }


}














