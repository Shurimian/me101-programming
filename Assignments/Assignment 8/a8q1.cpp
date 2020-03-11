// Chamath Wijesekera and Emily Tou - ME 101
// Assignment 8 Question 1

/* 
ARRAY IMPLEMENTATIONN

Composed of a 2D array consisting of a row for status and a row for name. Columns will be 50 elements long to represent 50 parking spaces. 

Parking Current
    Composed of two 1D arrays consisting of 50 items each to represent the parking spaces. Each array stores data as follows:
        Array 1 - Occupation
          1 = staff
          0 = student
          -1 = empty 
        Array 2 - Name

Parking Add / Parking Remove
    Composed of a 2D array consisting of three rows. Each row stores data as follows:
        Array 1 - Occupation
          1 = staff
          0 = student
        Array 2 - Name
        Array 3 - Change
          1 = add to parking
          -1 = remove from parking

Empty parking spots will be represented as "-1" in the current parking occupation array 
*/