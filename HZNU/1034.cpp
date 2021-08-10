//
// Created by smallflyfly on 2021/8/9.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Student {
    //for convenience public
public:
    char name[51];
    int cls;
    int score;

//    Student(char* name, int cls, int score){
////        memset(this->name, '\0', sizeof(char));
////        strcpy(this->name, name);
//        this->name = name;
//        this->cls = cls;
//        this->score = score;
//    }

};

bool cmp1(const Student &s1, const Student &s2) {
    if (s1.score != s2.score) {
        return s1.score > s2.score;
    }
    if (s1.cls != s2.cls) {
        return s1.cls > s2.cls;
    }
    return strcmp(s2.name, s1.name) > 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[51];
        int cls, score;
        vector<Student> students;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s %d %d", &s, &cls, &score);
            Student student{};
            strcpy(student.name, s);
            student.cls = cls;
            student.score = score;
            students.push_back(student);
        }
        sort(students.begin(), students.end(), cmp1);
        for (int i = 0; i < students.size(); ++i) {
            printf("%s %d %d\n", &students[i].name, students[i].cls, students[i].score);
        }
        if (T > 0) {
            printf("\n");
        }
    }

    return 0;

}