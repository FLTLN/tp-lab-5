#ifndef __DEAN_H_
#define __DEAN_H_

#include <group.h>

class Dean
{
public:
    Dean() {};
    ~Dean();

    void CreateGroups(std::string fname);
    void CreateStudents(std::string fname);
    void SaveGroups(std::string fname);
    void SaveStudents(std::string fname);
    void AddRandomMarks(size_t num);
    void Transfer(size_t from, size_t student, size_t to);
    void DropLowMarksStudents(float cutoff);
    void ChooseHeads();

    void PrintSummary();
private:
    std::vector<Group*> m_groups;
};

#endif // __DEAN_H_
