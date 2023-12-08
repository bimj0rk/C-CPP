The programs were tested using two compiling applications: CodeBlocks and Microsoft Visual Studio Code.
How to install and run in Microsoft VSCode:
    1. Drag and drop the files into the VSCode folder
    2. In VSCode, select the desired program
    3. Run the program (Ctrl+Alt+N for Windows, Ctrl+Option+N for MacOS)
	4. Enter the desired data in the terminal window

How to install and run in CodeBlocks:
	1. Drag and drop the files into the CodeBlocks folder
	2. In CodeBlocks, select the desired program
	3. Build and run the program using the shortcut F9
	4. Enter the desired data in the terminal window

EX1	
	Lines 5-8
		We create 2 stacks and all of the variables needed for the problem
	Lines 9-10
		We ask the user to tell the number of brackets
	*Line 12
		If the number of brackets is even then the following lines will take place
	Lines 13-18 
		Using a 'for' loop the user will input the brackets in order pushing them into the Input stack
	Lines 20-36
		Using another 'for' loop, the program will pop the last item of the Input stack into a char variable named aux and reverse the orientation of the bracket using a switch.
		After this has happened the the new aux variable will be pushed into a second stack name reverseInput.
		Because we took the 'for' loop from 0 to n/2 (n being the original length of the stack) it will efectively split the stack into two equal stacks.
	Lines 39-43
		With the a help of another 'for' loop, taken from 0 to n/2, the program will pop the last items of both Input and reverseInput and check if they are equal.
		If they are not equal isBalanced, a bool variable declared at line 8 initialized as true, will be checked as false.
		If isBalanced is still true after the whole 'for' loop then the program will print "The brackets are balanced".
		If isBalanced is false after the whole 'for' loop then the program will print "The brackets are not balanced".
	*Line 44
		It's the alternative of line 12 and it happens if the number of brackets is odd and then the system will print "the number is odd so they cant be balanced".	
		 
EX2
	Lines 4-8
		We built a function to calculate the distance that can be travelled using the fuel and the consumption given
	Lines 11-13
		We create 2 queues and 2 integer variables in which we store the number of petrol station and the fuel consumption
	Lines 14-16
		We ask the user to write the number of petrol stations and the fuel consumption and we store them in the variables created at line 13
	Lines 17-23
		Using a 'for' loop, we store in the queues created the details for each petrol stations
	Line 25-42
		Using another 'for' loop, we compute the index of the petrol station which can be used as a starting point
		Firstly, we initialize 2 integer variables, one which stores the number of liters refueled and a counter, to count the number of petrol stations visited in a row
		In the 'for' loop, we take the number of liters given by the currnet station and compute the distance that can be run using it
		If the distance computed is smaller than the distance given by the first petrol station, we reset the counter, we dequeue every element in the petrol liters queue before it and we set the new petol level to the current peek
		Else, we substract from the current level of fuel the liters given by the petrol station and the counter rises
		In the end of the iteration, we dequeue from the distance queue
	Line 44
		We initialize a integer value that will give us the index of the petrol station which can be used to start the journey (number of petrol stations - the counter used in the 'for' loop)
	Line 46
		We print out the index

	*A possible solution for more complex inputs is to reverse the queue using a stack*

EX3
	Lines 4-21
		The main function which is required in order to find the intersection.
		We take two nodes which are the heads of the two lists and compare them using two 'while' loops.
		If the information given by the two nodes is equal, we return the information and break the loop.
		Else, we continue by moving up the second list.
		If there is no result found, we reset the pointer p2 to point to the first node in the second list and we move up the first list.
	Lines 24-25
		We initialize the 2 linked lists corresponding to the 2 roads.
	Lines 27-36
		We work on the first road.
		Firstly, we ask the user to input the length of the road (meaning how many cities does the road pass).
		Then, we ask the user to write the names of the city on the first road, in order.	
	Lines 38-47
		We repeat the process for the second road.
	Line 49
		We write down the intersection node of the two roads.
	