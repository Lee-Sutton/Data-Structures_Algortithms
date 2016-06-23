public class Nbody {
    public static void main(String[] args) {
        int year = 2000;

        // if the year is divisible by 400 or divisible by 4 and not 100 it is a leap year
        if (year % 4 ==0 && year % 100 !=0){
        	System.out.println (year + " is a leap year but i dont know if my code works");
        	System.out.println (" Testing out this functionality");
        }

        // If the year is not, it is not a leap year
        else {
        	System.out.println (year + " is a not leap year. It is working just fine");

        }

    }
}

