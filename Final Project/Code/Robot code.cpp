
//function to start printing braille
void Start(ifstream & fin, int & totalLetter, int & totalPages)
{
	fin >> totalLetters >> totalPages;

	eraseDisplay();

	displayBigTextLine(1, "Total Pages: %d", totalPages);
	displayBigTextLine(4, "Total Letters: %d", totalLetters);

	wait1Msec(2000);

	do 
	{
		displaystring(9, "Place paper and Press Enter!");

		while (!getButtonPress(buttonEnter))
		{}

		while (getButtonPress(buttonEnter))
		{}

	} while (SensorValue[S1] != (int)colorWhite;

	time1[T1] = 0;
}

//Function to update display every letter printed with line and page number
void updateDisplay(int totalLetters, int line, int page, string letter)
{
	int lettersPrinted = 0;

	eraseDisplay();

	displayCenteredTextLine(1, "Letters Printed");
	
  displayCenteredTextLine(2, "%d / %d", lettersPrinted++, totalLetters);
	
  //find way to upload image on screen
  displayCenteredBigTextLine(7, "%s", letter);

	displayCenteredTextLine(16, "Line: %d Page: %d", line, page)
}

//Function to inform user to replace paper
void replacePaper()
{
	//add sound (medium)

	eraseDisplay();

	displayBigTextLine(5, "Page Complete! Replace Paper.")
	do
	{
		displayBigTextLine(9, "Replace paper and Press Enter!");

		while (!getButtonPress(buttonEnter))
		{}

		while (getButtonPress(buttonEnter))
		{}

	} while (SensorValue[S1] != (int)colorWhite;
}

//Function to stop printing braille or stop if error encountered
void errorOrShutdown()
{
	//add error sound (loud)
	
	//ButtonLeft is to stop printing braille
	if (getButtonPress(ButtonLeft))
	{
	  //add small beep sound
	 	eraseDisplay();
    displayCenteredTextLine(1, "Press Enter Button to resume")
    displayCenteredTextLine(4, "Press Right Button to restart")
  }
  //otherwise will be error
  else
  {
    displayCenteredTextLine(7, "ERROR: motor jammed!")

  }
  
  displayCenteredTextLine(10, "Press Down Button to end Print")
	
	
  while (!getButtonPress(buttonAny))
	{}
	
	//find way too go to beginning of program if right button is pressed 
  while (getButtonPress(buttonRight))
	{}
    
  //find way to go to printDone(), then shutdown robot  
  while (getButtonPress(buttonDown))
	{}
		
	while (getButtonPress(buttonEnter))
	{}
}

//Function to inform user when the print is done
void printDone()
{
	//add sound (loud)

	eraseDisplay();
	displayCenteredBigTextLine(2, "Print Done!")

	wait1Msec(2000);
	
	double totalHours = 0; 
  int minutes = 0;
	
	totalHours = time1[T1] / 1000.0 * 60;
	int hours = time1[T1] / 1000 * 60;
	
  minutes = (totalHours - hours) * 100;
	
	displayCenteredTextLine(5, "Time taken: %d hours, %d minutes", hours, minutes)

	wait1Msec(1000);

	displayCenteredTextLine(8, "Press down button to exit")

	time1[T2] = 0;

	while (!getButtonPress(buttonDown) || time1[T2] < 1000 * 60)
	{}

	while (getButtonPress(buttonDown) || time1[T2] < 1000 * 60)
	{}
}



