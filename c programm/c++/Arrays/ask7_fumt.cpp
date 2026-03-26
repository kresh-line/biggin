#include <iostream>
using namespace std;

#define N 5

void readStudentInfo(string names[], double grades[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name: ";
        cin >> names[i];

        do
        {
            cout << "Enter grade: [0-100]";
            cin >> grades[i];
            if (grades[i] < 0 || grades[i] > 100)
            {
                cout << "Invalid grade. Please enter a value between 0 and 100." << endl;
            }
        } while (grades[i] < 0 || grades[i] > 100);
    }
}

void printStudentInfoReverse(string names[], double grades[], int size)
{
    cout << "Student Information:\n";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << "Name: " << names[i] << ", Grade: " << grades[i] << endl;
    }
}

double calculateAverage(double grades[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += grades[i];
    }
    return sum / size;
}

void printStudentsAboveAverage(string names[], double grades[], int size)
{
    double average = calculateAverage(grades, size);
    cout << "Average grade: " << average << endl;
    cout << "Students with grade above average:\n";
    for (int i = 0; i < size; i++)
    {
        if (grades[i] > average)
        {
            cout << "Name: " << names[i] << ", Grade: " << grades[i] << endl;
        }
    }
}

int getMAXGradeIndex(double grades[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (grades[i] > grades[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void countStudentsAboveThreshold(double grades[], int size, double threshold)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (grades[i] > threshold)
        {
            count++;
        }
    }
    cout << "Total students with grade above " << threshold << ": " << count << endl;
}

int main()
{
    string names[N];
    double grades[N];

    // Input student names and grades
    readStudentInfo(names, grades, N);

    // Print student information in reverse order
    printStudentInfoReverse(names, grades, N);

    // Calculate and print average grade
    cout << "\nStudents with grade above average:\n";
    printStudentsAboveAverage(names, grades, N);

    // Find and print student with the highest grade

    int maxIndex = getMAXGradeIndex(grades, N);
    cout << "\nStudent with the highest grade:\n";
    cout << "Name: " << names[maxIndex] << ", Grade: " << grades[maxIndex] << endl;

    // Count and print number of students with grade above 60.0
    cout << "\nStudents with grade above 60.0:\n";
    countStudentsAboveThreshold(grades, N, 60.0);
}