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
	Lines 4-8
		We construct a Graph sructure, containing the number of vertices and the distance between the source given and a vertex
	Line 10
		We start writing the findNoOFDiceThrows function, which is at origin a version of BFS, which, given the fact that the edges of graph have equal weight, is the most efficient way of serching and returning the number of dice throws
	Lines 11-13
		We mark all of the vertices as not visited
	Line 15
		We initialise a graph variable
	Lines 17-19
		We mark the 0 node as visited and enqueue it 
	Lines 21-44
		We start BFS
		If the first vertex is also the destination vertex, we break
		Else, we dequeue it and enqueue its adjacent vertices
		In a for loop, we take each vertex and analyse it
		If the vertex has not been visited, we compute its distance and mark it as visited
		We also check for a snake or ladder at the top or bottom
		Finally, we return the distance - the number of dice throws we need in order to reach it
	Lines 46-50
		We initialise our parameters: number of snakes and ladders, the board and we fill the board with numbers from 0 to 100
	Line 52
		We read from keyboard the number of snakes and ladders
	Lines 54-59
		We read our start and end coordinates for the snakes and ladders
	Line 61
		We output the number of throws

EX2
	Line 5
		We create our node class which will serve as a foundation for the binary tree
	Lines 7-13
		We define a node with info of it, links to its left and right childs, a node constructor and a function which will return the in-order traversal of the binary tree
	Lines 15-19
		We build the constructor of the node
	Lines 21-26
		We build the in-order traversal of the binary tree
		If the tree is empty we return 0, else we output the in-order
	Lines 28-38
		We define a class of the current max node, which will help us in finding the BST with the largest sum
		It is defined as having a max node, a min node, a max size and the sum of the previous nodes
	Line 40
		We start defining the MaxBST class which will return the BST with the biggest sum
	Lines 42-54
		We define the biggestBSTSubtree function as private
		If there is no root in the passed binary tree, we return the function of 0
		We define two variables of class currentMaxNode defined above, which will search for the biggest BST subtree in the left and right subtree
		If the current maxNode on the left subtree is smaller than the root and the minNode on the right subtree is larger that the root, we return a currentMaxNode function which has as parameters the minimum between the root and the minNode of the left subtree, the max between the root and the maxRoot on the right subtree, the sum of the sizes of the left and right subtree plus one and the sum between the left, right subtrees and the root
		If none of the conditions above are met, we return an object of currentMaxNode with arguments int_min, int_max, the maximum between the left and right sizes and the max between the left and right sums
	Lines 55-59
		We define getBiggestSubtree, which is the public passing of the biggestBSTSubtree described above
	Lines 61-79
		We test the program with the binary tree described in the problen

EX3
	Line 3
		We implement a function that helps to transform an array into a heap
	Lines 4-6
		We initialise left, right and root variables
	Lines 8-10
		We modify the root based on comparisons between it and its left and right childs
	Lines 12-16
		If the root is not the largest element, we heapify the array, that is we transform it into a heap
	Line 18
		We implement a funtion that takes care of the heap sort
	Lines 19-20
		We heapify the given array
	Lines 22-26
		We extract the elements from the heap one by one: we substract the current root from the heap, we move the current root to back of the array and re-heapify the remaining heap
	Line 28
		Main program of the exercise
	Line 29-31
		We ask the user to input the number of elements of the array that needs to be sorted
	Lines 33-39
		We ask the user to input the elements of the array
	Line 41
		We run the heapSort function defined at lines 18-26 for the array
	Line 43-47
		We print the sorted array

	 