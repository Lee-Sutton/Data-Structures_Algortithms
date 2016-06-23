public class main {
    public static void main(String[] args) {

    	// Declare a planet
        Planet Earth = new Planet(1, 2, 3, 4, 5, "Planet name");
        Planet Pluto = new Planet(5, 8, 3, 4, 5, "Planet name");
        System.out.println("Some of the planet parameters" + Earth.x + Earth.y);

        // try using the calc distance method
        // need to include Earth. so the method CalcDist is recognized from the Planet class
        double distance = Earth.CalcDist(Earth, Pluto);		
        System.out.println("The distance between Earth and Pluto is " + distance);

        // Try using the Pair wise force method
        double force = 	Earth.CalcPairWiseForce(Earth, Pluto);
        System.out.println("The Force created between Earth and Pluto is: " + force);

        // Test out the print function here
        Planet[] a = {Earth, Pluto};

        Earth.SetNetForce(a);

    }
}

