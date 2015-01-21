// Matthew Long
// 010694984
// CptS 223 - Advanced Data Structures
// Homework assignment #1

#include "ReversibleStack.h" // You need to create ReversibleStack.h

void Display(ReversibleStack& rs)
{
	// Implement this function (use only Push, Pop and IsEmpty member functions of stack)
	// After the function completes, the stack should be unmodified (see assignment instructions)

	ReversibleStack temp_stack; // Create a temporary object to hold values from rs object.
	int temp_val = 0; // Temporary int holder.

	// while rs is not empty; pop the top value from int and place it in temporary int holder
	// then push the temp int onto the temporary stack. Display values as they are popped.
	while (!rs.isEmpty())
	{
		temp_val = rs.Pop();
		temp_stack.Push(temp_val);

		cout << temp_val << " ";
	}

	cout << endl;

	// Place the values from the temporary stack back onto the original stack.
	while (!temp_stack.isEmpty())
	{
		rs.Push(temp_stack.Pop());
	}
}

int main(int argc, char* argv[])
{
	// Error handling, in case number of arguments is not equal to two.
	// $ prog in1.txt; etc.
	if (argc < 2)
	{
		cout << "Missing required argument for input file" << endl;
		return 0;
	}

	ReversibleStack rs; // Creation of stack object.
	ifstream inFile; // Declaration of input file stream.
	inFile.open(argv[1], ifstream::in); // Open file from parameters; set to input stream.

	// Error handling, should the file not open - display message.
	if (!inFile.is_open())
	{
		cout << "Could not open: " << argv[1] << endl;
		return 0;
	}

	// While the file has not reached eof, perform stack operations based on the
	// line we are reading from.
	while (!inFile.eof())
	{
		string line; // String variable to gather line input.
		getline(inFile, line); // Get line input.

		// Process the command here
		if (0 == line.compare(0, 6, "header")) // Should the read line be 'header' then display header.
		{
			// Display the header line here, as the instructions describe
			cout << "Matthew Long (010694984)" << endl;
		}
		// Should the read line be 'display' then display the contents of the stack.
		else if (0 == line.compare(0, 7, "display"))
		{
			Display(rs);
			cout << endl;
		}
		// Should the read line be 'push' then push the integer onto the stack.
		else if (0 == line.compare(0, 4, "push"))
		{
			std::stringstream linestream(line); // Create a string stream and read in the line from the file.

			int temp_val = 0; // Create a temporary int variable to store the int value from the stream.
			string temp_string; // Create a temporary string variable to store the string value from the stream.

			linestream >> temp_string >> temp_val; // Place the lines string and int values in the temporary variables.

			rs.Push(temp_val); // Place the int variable on the stack.
		}
		// Should the read line be 'pop' then we will pop an item off the stack.
		else if (0 == line.compare(0, 3, "pop"))
		{
			rs.Pop();
		}
		// Should the read line be 'reverse' then we will reverse the order in which the stack is implemented.
		else if (0 == line.compare(0, 7, "reverse"))
		{
			rs.Reverse();
		}
		// Should the read line be 'isempty' we will display whether or not the stack is currently empty.
		else if (0 == line.compare(0, 7, "isempty"))
		{
			if (rs.isEmpty())
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
		// Finally, should the read line be a command that has not already been listed, then
		// we will display an error message.
		else
		{
			cout << "Unknown command: " << line;
		}
	}

	// Complete
	inFile.close(); // Close the input file.
	cout << endl << "Done" << endl; // Indicate that our program has completed.
	return 1;
}
