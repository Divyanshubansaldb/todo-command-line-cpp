#include <bits/stdc++.h>
using namespace std;

void helpSection()
{
    cout << "Usage :-\n$ ./todo add \"todo item\"  # Add a new todo\n$ ./todo ls               # Show remaining todos\n$ ./todo del NUMBER       # Delete a todo\n$ ./todo done NUMBER      # Complete a todo\n$ ./todo help             # Show usage\n$ ./todo report           # Statistics";
}

void outputTodos()
{
    ifstream fin;
    fin.open("todo.txt");
    vector<string> todos;
    string currenttodo;
    while (!fin.eof())
    {
        getline(fin, currenttodo);
        if (currenttodo.size())
        {
            todos.emplace_back(currenttodo);
        }
    }
    if (!todos.size())
    {
        cout << "There are no pending todos!";
        return;
    }
    for (int i = todos.size() - 1; i >= 0; i--)
    {
        cout << "[" << i + 1 << "] " << todos[i] << endl;
    }
    fin.close();
}

void generateReport()
{
    ifstream finremain, findone;
    finremain.open("todo.txt");
    findone.open("done.txt");
    int countremain(0), countdone(0);

    while (!finremain.eof())
    {
        string temp;
        getline(finremain, temp);
        if (temp.size())
        {
            countremain++;
        }
    }
    while (!findone.eof())
    {
        string temp;
        getline(findone, temp);
        if (temp.size())
        {
            countdone++;
        }
    }

    int bufferSize = sizeof "2021-01-04";
    char buffer[bufferSize];
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    strftime(buffer, bufferSize, "%Y-%m-%d", gmtm);

    cout << buffer << " Pending : " << countremain << " Completed : " << countdone;
}

void addTodo(string todoValue)
{
    ofstream fout;
    fout.open("todo.txt", ios::app);
    fout << todoValue << '\n';
    fout.close();
    cout << "Added todo: \"" << todoValue << "\"";
}

string deleteComputation(int todoNumber)
{
    if (todoNumber == 0)
    {
        return "Failed";
    }
    //Reading the todo's and storing in the vector of strings
    ifstream fin;
    fin.open("todo.txt");
    vector<string> todos;
    string currenttodo;
    while (!fin.eof())
    {
        getline(fin, currenttodo);
        if (currenttodo.size())
        {
            todos.emplace_back(currenttodo);
        }
    }
    fin.close();

    // check if not present then return
    if ((int)todos.size() < todoNumber)
    {
        return "Failed";
    }

    //deleting the todo
    ofstream fout;
    fout.open("todo.txt", ios::ate);
    for (int i = 0; i < (int)todos.size(); i++)
    {
        if (i + 1 == todoNumber)
            continue;
        fout << todos[i] << "\n";
    }
    fout.close();
    return todos[todoNumber - 1];
}

void deleteTodo(int todoNumber)
{
    if (deleteComputation(todoNumber) == "Failed")
    {
        cout << "Error: todo #" << todoNumber << " does not exist. Nothing deleted.";
    }
    else
    {
        cout << "Deleted todo #" << todoNumber;
    }
}

void markCompleted(int todoNumber)
{
    string todoValue = deleteComputation(todoNumber);
    if (todoValue == "Failed")
    {
        cout << "Error: todo #" << todoNumber << " does not exist.";
        return;
    }

    ofstream fout;
    fout.open("done.txt", ios::app);

    int bufferSize = sizeof "2021-01-04";
    char buffer[bufferSize];
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    strftime(buffer, bufferSize, "%Y-%m-%d", gmtm);

    fout << "x " << buffer << " " << todoValue << '\n';
    fout.close();

    cout << "Marked todo #" << todoNumber << " as done.";
}

int stringtonum(string s)
{
    stringstream num(s);
    int todoNumber;
    num >> todoNumber;
    return todoNumber;
}

int main(int argc, char *argv[])
{
    //Creating a todo.txt and done.txt file if they do not exist
    ofstream fout;
    fout.open("todo.txt", ios::app);
    fout.close();
    fout.open("done.txt", ios::app);
    fout.close();

    if (argc == 1)
    {
        helpSection();
    }
    else
    {
        string method = argv[1];
        if (method == "help")
        {
            helpSection();
        }
        else if (method == "ls")
        {
            outputTodos();
        }
        else if (method == "report")
        {
            generateReport();
        }
        else if (method == "add")
        {
            if (argc == 2)
            {
                cout << "Error: Missing todo string. Nothing added!";
            }
            else
            {
                addTodo(argv[2]);
            }
        }
        else if (method == "del")
        {
            if (argc == 2)
            {
                cout << "Error: Missing NUMBER for deleting todo.";
            }
            else
            {
                deleteTodo(stringtonum(argv[2]));
            }
        }
        else if (method == "done")
        {
            if (argc == 2)
            {
                cout << "Error: Missing NUMBER for marking todo as done.";
            }
            else
            {
                markCompleted(stringtonum(argv[2]));
            }
        }
        else
        {
            cout << "This operation does not exist. Please enter a valid operation!";
        }
    }
    return 0;
}
