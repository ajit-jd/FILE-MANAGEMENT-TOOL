#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

void read(const char* file_name);
void write(const char* file_name);
void append(const char* file_name);

int main() {
    char file_name[30];
    cout << "Enter the name of the file you want to create: ";
    cin.getline(file_name, 30); // Use getline to handle spaces in file names
    write(file_name);   // Write data to the file
    append(file_name); // Append data to the file
    read(file_name);    // Read and display data from the file

    return 0;
}

// Function to write data to the file
void write(const char* file_name) {
    //ofstream show_data(file_name); // Open file in write mode
    //declaration
    char content[50];
    fstream write_data;
    write_data.open(file_name,ios::out);
    if (write_data.is_open()) {
            cout<<"Enter the text that you want include in file: ";
            fgets(content,50,stdin);
        write_data<<content;
        write_data.close();
        cout << "Data written to the file successfully." << endl;
    } else {
        cout << "Failed to open the file for writing." << endl;
    }
}

// Function to read and display the content of the file
void read(const char* file_name) {
    fstream read_file;
    read_file.open(file_name, ios::in); // Open file in read mode

    if (!read_file.is_open()) {
        cout << "Failed to open the file for reading." << endl;
        return;
    }

    string line;
    cout << "Contents of the file:" << endl;
    while (getline(read_file, line)) {
        cout << line << endl; // Print each line
    }

    read_file.close();
}


// Function to append data to the file
void append(const char* file_name) {

    char appendtxt[50];
    char ch;
    cout<<"Want to append more text (y/n): ";
    cin>>ch;

    if(ch=='y')
    {
        fstream make_append(file_name,ios::app); // Open file in append mode
        if (make_append.is_open()) {
                cout<<"Enter the text that you want to append: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cin.getline(appendtxt,50);
                //fgets(appendtxt,50,stdin);
           // string appstr = "This is the second text.";
            make_append << appendtxt;

            make_append.close();
            cout << "Data appended to the file successfully." << endl;
            }
        else {
            cout << "Failed to open the file for appending." << endl;
        }
    }
    else{
        cout<<"You don't want to append! ok"<<endl;
    }
}
