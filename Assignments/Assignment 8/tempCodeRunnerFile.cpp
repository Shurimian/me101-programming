void reassignSpots(int statuses[], string names[])
{
    int spaceReassignedTo = 0;
    for (int index = 25; index < 49; index++)
    {
        if (statuses[index] == 2)
        {
            spaceReassignedTo = lowestValidSpace(statuses, 2);
            if (spaceReassignedTo < 25)
            {   
                
                cout << names[index] << statuses[index] << endl;
                assignParking(statuses, names, names[index], statuses[index]);
                deleteParking(names[index], statuses, names);
            }
        }
    }
}