/* Date.java */

import java.io.*;

class Date {

  /* Put your private data fields here. */
  private int m;
  private int d;
  private int y;

  /** Constructs a date with the given month, day and year.   If the date is
   *  not valid, the entire program will halt with an error message.
   *  @param month is a month, numbered in the range 1...12.
   *  @param day is between 1 and the number of days in the given month.
   *  @param year is the year in question, with no digits omitted.
   */
  public Date(int month, int day, int year) {
    // first check if the date is valid
    if(isValidDate(month, day, year)){
      m = month;
      d = day;
      y = year;
    }
    // if the date is not valid exit the program
    else{
      // print an error message
      System.out.println("The date: " + month + "/" + day + "/" + year + " is not a valid date...");
      System.out.println("The program will now exit...");
      System.exit(0);
    }

  }

  /** Constructs a Date object corresponding to the given string.
   *  @param s should be a string of the form "month/day/year" where month must
   *  be one or two digits, day must be one or two digits, and year must be
   *  between 1 and 4 digits.  If s does not match these requirements or is not
   *  a valid date, the program halts with an error message.
   */
  public Date(String s) {
    // first we need to split the string into its components
    String [] parts = s.split("/");
    // convert the parts to ints and store them to the appropriate variable month/day/year
    m = Integer.parseInt(parts[0]);
    d = Integer.parseInt(parts[1]);
    y = Integer.parseInt(parts[2]);

    // check to make sure the date is valid
    // if the date is not valid, exit the program
    if(isValidDate(m, d, y) == false){
      System.exit(0);
    }

  }

  /** Checks whether the given year is a leap year.
   *  @return true if and only if the input year is a leap year.
   */
  public static boolean isLeapYear(int year) {
    if(year % 400 == 0){
      return true;
    }

    if(year % 100 == 0){
      return false;
    }

    if(year % 4 == 0) {
      return true;
    }
    return false;                        
  }

  /** Returns the number of days in a given month.
   *  @param month is a month, numbered in the range 1...12.
   *  @param year is the year in question, with no digits omitted.
   *  @return the number of days in the given month.
   */
  public static int daysInMonth(int month, int year) {
    // based on the month, we can find how many days are in the month
    // first check all the days with 31 days
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
      return 31;
    }

    // next check the months with 30 days
    if(month == 4 || month == 6 || month == 9 || month == 11){
      return 30;
    }

    // now we check february
    // make a call to the leap year function to check if it is a leap year
    if(month == 2 && isLeapYear(year)){
      return 29;
    }

    if(month == 2 && isLeapYear(year) == false){
      return 28;
    }
    // if none of the above statements have returned a value, the month is not valid.
    // The function must return a value so i will return 0
    return 0;
  }

  /** Checks whether the given date is valid.
   *  @return true if and only if month/day/year constitute a valid date.
   *
   *  Years prior to A.D. 1 are NOT valid.
   */
  public static boolean isValidDate(int month, int day, int year) {
    // define booleans for the day, month and year to check if it is valid
    // initially set them all to be false
    boolean m_valid = false;
    boolean y_valid = false;
    boolean d_valid = false;

    // is the month between 1 and 12
    if(month <= 12 && month >= 1){
      // the month is valid
      m_valid = true;
    }

    // is the year greater than or equal to zero
    if(year >= 0){
      y_valid = true;
    }

    // lastly check the days
    // is the number of days given valid?
    if(day >=0 && day <= daysInMonth(month,year)){
      d_valid = true;
    }

    // if the days, month, and year is valid, the date is valid
    if(d_valid && m_valid && y_valid){
      return true;
    }
    // otherwise we return false
    return false;                        
  }

  /** Returns a string representation of this date in the form month/day/year.
   *  The month, day, and year are expressed in full as integers; for example,
   *  12/7/2006 or 3/21/407.
   *  @return a String representation of this date.
   */
  public String toString() {
    // 

    return m + "/" + d + "/" + y;
  }

  /** Determines whether this Date is before the Date d.
   *  @return true if and only if this Date is before d. 
   */
  public boolean isBefore(Date test_date) {
    // first check the year
    // if the year is less then return true
    if(this.y < test_date.y){
      return true;
    }

    // if the year is equal we have to check the month
    if(this.y == test_date.y){
      // check the months
      // if the month of this is less than the month of d we return true
      if(this.m < test_date.m){
        return true;
      }
                // if the months are equal we have to check if the day is less
      if(this.m == test_date.m && this.d < test_date.d){
          return true;
      }
    }

    // if none of the above tests have returned true, this date must be after d
    return false;                       
  }

    /** Determines whether this Date is equal to the Date d.
   *  @return true if and only if this Date is equal to d. 
   */
  public boolean isEqual(Date d) {
    // check if the date is before
    if(this.y == d.y && this.m == d.m && this.d == d.d){
      return true;
    }

    // if the dates aren't equal return false
    return false; 
  }

  /** Determines whether this Date is after the Date d.
   *  @return true if and only if this Date is after d. 
   */
  public boolean isAfter(Date d) {
    // check if the date is before
    if(this.isBefore(d)){
      return false;
    }

    // check if the dates are equal
    if(this.isEqual(d)){
      return false;
    }

    // if this date is neither before nor equal to the date d, then it must be after
    return true;
  }

  /** Returns the number of this Date in the year.
   *  @return a number n in the range 1...366, inclusive, such that this Date
   *  is the nth day of its year.  (366 is used only for December 31 in a leap
   *  year.)
   */
  public int dayInYear() {
    // define variable to hold the number of the day in the year
    int dayNum = 0;
    // use a for loop to add up all the days from the month before this.month
    for(int i = 0; i < this.m; i++){
        // add up all the days in the months before this.month
        dayNum = dayNum + daysInMonth(i, this.y);
    }

    // add the current day in this month
    dayNum = dayNum + this.d;

    // return the counted number of days
    return dayNum;
  }

  /** Returns the number of days from the common era up to this date 
  */
  public int daysFromAD(){
    // Declare variable to store the total number of days
    int total_days = 0;
    // start by adding up all the days in the years before the current year
    // create a for loop to run through all the years before the current year and add the days
    for(int i = 1; i < this.y; i++){
      // check if the year is a leap year 
      if(isLeapYear(i)){
        // if it is a leap year add 366
        total_days = total_days + 366;
      }
      else{
        // if it is not a leap year add 365
        total_days = total_days + 365;
      }
    }
    // now add the days in the current year
    total_days = total_days + this.dayInYear();
    return total_days;

  }

  /** Determines the difference in days between d and this Date.  For example,
   *  if this Date is 12/15/2012 and d is 12/14/2012, the difference is 1.
   *  If this Date occurs before d, the result is negative.
   *  @return the difference in days between d and this date.
   */
  public int difference(Date d) {
    // use the daysFromAD function to find the difference between the two dates
    return this.daysFromAD() - d.daysFromAD(); 
  }

  public static void main(String[] argv) {
    System.out.println("\nTesting constructors.");
    Date d1 = new Date(1, 1, 1);
    System.out.println("Date should be 1/1/1: " + d1);
    d1 = new Date("2/4/2");
    System.out.println("Date should be 2/4/2: " + d1);
    d1 = new Date("2/29/2000");
    System.out.println("Date should be 2/29/2000: " + d1);
    d1 = new Date("2/29/1904");
    System.out.println("Date should be 2/29/1904: " + d1);

    d1 = new Date(12, 31, 1975);
    System.out.println("Date should be 12/31/1975: " + d1);
    Date d2 = new Date("1/1/1976");
    System.out.println("Date should be 1/1/1976: " + d2);
    Date d3 = new Date("1/2/1976");
    System.out.println("Date should be 1/2/1976: " + d3);

    Date d4 = new Date("2/27/1977");
    Date d5 = new Date("8/31/2110");


    System.out.println("\nTesting before and after.");
    System.out.println(d2 + " after " + d1 + " should be true: " + 
                       d2.isAfter(d1));
    System.out.println(d3 + " after " + d2 + " should be true: " + 
                       d3.isAfter(d2));
    System.out.println(d1 + " after " + d1 + " should be false: " + 
                       d1.isAfter(d1));
    System.out.println(d1 + " after " + d2 + " should be false: " + 
                       d1.isAfter(d2));
    System.out.println(d2 + " after " + d3 + " should be false: " + 
                       d2.isAfter(d3));

    System.out.println(d1 + " before " + d2 + " should be true: " + 
                       d1.isBefore(d2));
    System.out.println(d2 + " before " + d3 + " should be true: " + 
                       d2.isBefore(d3));
    System.out.println(d1 + " before " + d1 + " should be false: " + 
                       d1.isBefore(d1));
    System.out.println(d2 + " before " + d1 + " should be false: " + 
                       d2.isBefore(d1));
    System.out.println(d3 + " before " + d2 + " should be false: " + 
                       d3.isBefore(d2));

    System.out.println("\nTesting difference.");
    System.out.println(d1 + " - " + d1  + " should be 0: " + 
                       d1.difference(d1));
    System.out.println(d2 + " - " + d1  + " should be 1: " + 
                       d2.difference(d1));
    System.out.println(d3 + " - " + d1  + " should be 2: " + 
                       d3.difference(d1));
    System.out.println(d3 + " - " + d4  + " should be -422: " + 
                       d3.difference(d4));
    System.out.println(d5 + " - " + d4  + " should be 48762: " + 
                       d5.difference(d4));

    System.out.println("\nTesting Days in Year.");
    System.out.println(d1 + " should be 365: " + d1.dayInYear());
    System.out.println(d2 + " should be 1: " + d2.dayInYear());
    System.out.println(d4 + " should be 58: " + d4.dayInYear());
    
  }
}