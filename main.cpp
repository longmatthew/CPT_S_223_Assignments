// Matthew Long
// 010694984
// CptS 223 - Advanced Data Structures
// Homework assignment #1

#include "ReversibleStack.h" // You need to create ReversibleStack.h

void Display(ReversibleStack& rs)
{
	// Implement this function (use only Push, Pop and IsEmpty member functions of stack)
	// After the function completes, the stack should be unmodified (see assignment instructions)

	ReversibleStack temp_stack;
	int temp_val = 0;

	while (!rs.isEmpty())
	{
		temp_val = rs.Pop();
		temp_stack.Push(temp_val);

		cout << temp_val << " ";
	}

	cout << endl;

	rs = temp_stack;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Missing required argument for input file" << endl;
		return 0;
	}

	ReversibleStack rs;
	ifstream inFile;
	inFile.open(argv[1], ifstream::in);

	if (!inFile.is_open())
	{
		cout << "Could not open: " << argv[1] << endl;
		return 0;
	}

	while (!inFile.eof())
	{
		string line;
		getline(inFile, line);

		// Process the command here
		if (0 == line.compare(0, 6, "header"))
		{
			// Display the header line here, as the instructions describe
			cout << "Matthew Long (010694984)" << endl;
		}
		else if (0 == line.compare(0, 7, "display"))
		{
			Display(rs);
			cout << endl;
		}
		else if (0 == line.compare(0, 4, "push"))
		{
			int temp_val = 0;
			
			getline(inFile, line, ' ');

			inFile >> temp_val;

			rs.Push(temp_val);
		}
		else if (0 == line.compare(0, 3, "pop"))
		{
			rs.Pop();
		}
		else if (0 == line.compare(0, 7, "reverse"))
		{
			rs.Reverse();
		}
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
		else
		{
			cout << "Unknown command: " << line;
		}
	}

	// Complete
	inFile.close();
	cout << endl << "Done" << endl;
	return 1;
}