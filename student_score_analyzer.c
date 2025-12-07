#include <stdio.h>

struct Student {
    char name[50];
    int maths, science, english;
    int total;
    float average;
    char grade;
};

// Function to assign grade
char getGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Taking input
    for (i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i+1);
        scanf("%s", s[i].name);

        printf("Enter Maths marks: ");
        scanf("%d", &s[i].maths);

        printf("Enter Science marks: ");
        scanf("%d", &s[i].science);

        printf("Enter English marks: ");
        scanf("%d", &s[i].english);

        // Calculate total & average
        s[i].total = s[i].maths + s[i].science + s[i].english;
        s[i].average = s[i].total / 3.0;
        s[i].grade = getGrade(s[i].average);
    }

    // Class statistics
    float classAvg = 0;
    int highest = s[0].total;
    int lowest = s[0].total;
    int pass = 0, fail = 0;

    for (i = 0; i < n; i++) {
        classAvg += s[i].average;

        if (s[i].total > highest) highest = s[i].total;
        if (s[i].total < lowest) lowest = s[i].total;

        if (s[i].grade == 'F') fail++;
        else pass++;
    }

    classAvg /= n;

    // Display details
    printf("\n\n========== STUDENT REPORT ==========\n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s\n", s[i].name);
        printf("Maths: %d | Science: %d | English: %d\n",
        s[i].maths, s[i].science, s[i].english);
        printf("Total: %d\n", s[i].total);
        printf("Average: %.2f\n", s[i].average);
        printf("Grade: %c\n", s[i].grade);
    }

    // Class analysis
    printf("\n========== CLASS ANALYSIS ==========\n");
    printf("Class Average: %.2f\n", classAvg);
    printf("Highest Total Marks: %d\n", highest);
    printf("Lowest Total Marks: %d\n", lowest);
    printf("Pass Count: %d\n", pass);
    printf("Fail Count: %d\n", fail);

    return 0;
}
