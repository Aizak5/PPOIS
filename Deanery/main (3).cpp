#include "gtest/gtest.h"
#include "StudentTest.h"
#include "CourseTest.h"
#include "GradeTest.h"
#include "TranscriptTest.h"
#include "ExamTest.h"
#include "DeanOfficeTest.h"
#include "DeanTest.h"
#include "TeacherTest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

