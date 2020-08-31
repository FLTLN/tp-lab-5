#include <student.h>
#include <group.h>
#include <dean.h>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#define STUDENT_DEMO 0
#define GROUP_DEMO 0

int main()
{

#if STUDENT_DEMO == 1
    Student s1;

    std::cout << "Create uninitialized student" << std::endl;

    std::cout << "Get info" << std::endl;
    std::cout << "FIO " << s1.GetFio() << std::endl;
    std::cout << "ID " << s1.GetId() << std::endl;

    std::string fio = "Pupkov A.V.";
    uint64_t id = 12;

    std::cout << "Initialize student with" << std::endl;
    std::cout << "FIO " << fio << std::endl;
    std::cout << "ID " << id << std::endl;

    s1.Create(fio, id);

    std::cout << "Get info" << std::endl;
    std::cout << "FIO " << s1.GetFio() << std::endl;
    std::cout << "ID " << s1.GetId() << std::endl;

    std::cout << "Add 4 8 2 marks" << std::endl;

    s1.AddMark(4);
    s1.AddMark(8);
    s1.AddMark(2);

    std::cout << "Get avg mark" << std::endl;
    std::cout << std::to_string(s1.CalculateAvg()) << std::endl;
#endif // STUDENT_DEMO

#if GROUP_DEMO == 1
    Group group;
    group.Create("Title", "Spec");
    group.AddStudent("Vasua", 23);
    group.AddStudent("Tanya", 125);
    group.AddStudent("Petua", 189);
    group.AddStudent("Fedya", 78);
    group.AddStudent("Fedya", 89);

    std::cout << "Count " << group.CountStudenst() << std::endl;
    std::cout << group[2].GetFio() << std::endl;
    std::cout << group[2].GetId() << std::endl;

    std::cout << "Find 125 " << group.Fing(125) << std::endl;
    group.DropStudent(group.Fing(125));

    std::cout << "Count " << group.CountStudenst() << std::endl;
    std::cout << "Find 125 " << group.Fing(125) << std::endl;

    std::cout << "Find head " << group.GetHead() << std::endl;
    group.ChooseHead(2);
    std::cout << "Student 2 " << group[group.Fing(23)].GetFio() << std::endl;
    std::cout << "Student 2 " << group[group.Fing(189)].GetFio() << std::endl;
    std::cout << "Student 2 " << group[group.Fing(89)].GetFio() << std::endl;

    std::cout << "Find head " << group.GetHead() << std::endl;
    std::cout << "Find head " << group[group.GetHead()].GetId() << std::endl;

    Group group2("title2", "spec2");
    group2.AddStudent("Vasua", 34);
    group2.AddStudent("Tanya", 12);

    group2.AddMark(0, 3);
    group2.AddMark(0, 5);
    group2.AddMark(1, 10);
    group2.AddMark(1, 8);
    std::cout << std::to_string(group2.CalculateAvg()) << std::endl;
#endif // GROUP_DEMO

    Dean dean;

    dean.CreateGroups("groups.csv");
    dean.CreateStudents("students.csv");
    std::cout << "Create from files" << std::endl;
    dean.PrintSummary();
    std::cout << "Choose heads" << std::endl;
    dean.ChooseHeads();
    dean.AddRandomMarks(10);
    std::cout << "Add marks" << std::endl;
    dean.PrintSummary();

    dean.DropLowMarksStudents(6);
    std::cout << "Drop students" << std::endl;
    dean.PrintSummary();

    dean.Transfer(0, 0, 1);
    std::cout << "Transfer students" << std::endl;
    dean.PrintSummary();

    dean.SaveGroups("groups2.csv");
    dean.SaveStudents("students2.csv");

    return 0;
}