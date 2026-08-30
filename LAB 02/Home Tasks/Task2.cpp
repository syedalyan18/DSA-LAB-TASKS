
#include <iostream>
using namespace std;

void insertMark(int**& student, int*& courses, float*& avg, int studentIndex, int newMark) {
    int oldSize = courses[studentIndex];
    int newSize = oldSize + 1;

    int* newRow = new int[newSize];
    for (int i = 0; i < oldSize; i++) {
        newRow[i] = student[studentIndex][i];
    }
    newRow[oldSize] = newMark;

    delete[] student[studentIndex];
    student[studentIndex] = newRow;
    courses[studentIndex] = newSize;

    int sum = 0;
    for (int i = 0; i < newSize; i++) {
        sum += newRow[i];
    }
    avg[studentIndex] = static_cast<float>(sum) / newSize;
}

int main() {
    int n;
    cout << "Enter number of Students: ";
    cin >> n;

    int** student = new int*[n];
    int* courses = new int[n];
    float* avg = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " - Courses: ";
        cin >> courses[i];
        student[i] = new int[courses[i]];
        cout << " -> marks: ";
        int sum = 0;
        for (int j = 0; j < courses[i]; j++) {
            cin >> student[i][j];
            sum += student[i][j];
        }
        avg[i] = (float)(sum) / courses[i];
    }

    int max = 0;
    int min = 0;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " average: " << avg[i] << endl;
    }

    for (int i = 1; i < n; i++) {
        if (avg[max] < avg[i])
            max = i;
        if (avg[min] > avg[i])
            min = i;
    }
    cout << "Highest average: Student " << max + 1 << " | Lowest average: Student " << min + 1 << endl;

    int studentNum, newMark;
    cout << "\nEnter student number to add a course (1-" << n << "): ";
    cin >> studentNum;
    if (studentNum >= 1 && studentNum <= n) {
        cout << "Enter new mark: ";
        cin >> newMark;
        insertMark(student, courses, avg, studentNum - 1, newMark);
        cout << "Updated Student " << studentNum << " average: " << avg[studentNum - 1] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] student[i];
    }
    delete[] student;
    delete[] courses;
    delete[] avg;

    return 0;
}