#ifndef __GROUP_H_
#define __GROUP_H_

#include <cstdint>
#include <string>
#include <vector>
#include <student.h>

class Group
{
public:
    Group() : m_title(""), m_spec(""), m_head_id(0) {};
    Group(std::string title, std::string spec);
    ~Group();
    void DeleteAllStudents();
    
    void Create(std::string title, std::string spec);

    const std::string& GetTitle() const {return m_title; };
    const std::string& GetSpec() const {return m_spec; };

    void AddStudent(std::string fio, uint64_t id);
    void AddStudent(Student* student);
    void ChooseHead(size_t head_index);

    const size_t CountStudents() const {return m_students.size(); };
    const size_t Fing(uint64_t id) const;
    const size_t Fing(std::string fio) const;
    const size_t GetHead() const;

    Student& operator[](const int index) {return *m_students[index]; };

    const float CalculateAvg() const;
    void DropStudent(size_t index);
    void AddMark(size_t index, uint8_t mark);

private:
    std::string m_title;
    std::string m_spec;
    std::vector<Student*> m_students;
    uint64_t m_head_id;
};

#endif // __GROUP_H_
