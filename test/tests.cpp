﻿#include "gtest/gtest.h"
#include "../include/dean.h"

TEST(testStudent, student_1) {
	Student* student = new Student("Oscar Wilde", "18-AMI");
	EXPECT_EQ("Oscar Wilde", student->getStudentName());
	delete student;
}

TEST(testStudent, student_2) {
	Student* student = new Student("Oscar Wilde", "18-AMI");
	EXPECT_EQ("18-AMI", student->getStudentGroup());
	delete student;
}

TEST(testStudent, student_3) {
	Student* student = new Student("Oscar Wilde", "18-AMI");
	student->setMarks();
	EXPECT_EQ(10, student->getMarks().size());
	delete student;
}

TEST(testGroup, group_1) {
	Group* group1 = new Group("AMI");
	Group* group2 = new Group("SE");
	Student* student1 = new Student("Oscar Wilde", "AMI");
	Student* student2 = new Student("Jerome Salinger", "SE");
	group1->addStudent(student1);
	group2->addStudent(student2);
	group1->appointHead();
	group2->appointHead();
	EXPECT_EQ("Oscar Wilde", group1->getHeadName());
	EXPECT_EQ("Jerome Salinger", group2->getHeadName());
	delete student1;
	delete student2;
	delete group1;
	delete group2;
}

TEST(testDean, dean_1) {

	Group* group1 = new Group("AMI");
	Group* group2 = new Group("SE");
	Student* student1 = new Student("Oscar Wilde", "AMI");
	Student* student2 = new Student("Jerome Salinger", "SE");
	group1->addStudent(student1);
	group2->addStudent(student2);
	group1->appointHead();
	group2->appointHead();
	group1->setMarks();
	group2->setMarks();
	group1->expelStudentsWithBadMarks(0.);
	group2->expelStudentsWithBadMarks(0.);
	EXPECT_EQ(1, group1->getStudents().size());
	EXPECT_EQ(1, group2->getStudents().size());
	delete student1;
	delete student2;
	delete group1;
	delete group2;
}