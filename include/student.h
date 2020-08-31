#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cstdint>
#include <string>
#include <vector>

class Student
{
public:
    Student() : m_fio(""), m_id(0) {};
    Student(std::string fio, uint64_t id);

    void Create(std::string fio, uint64_t id);
    void AddMark(uint8_t mark);
    const float CalculateAvg() const;

    const std::string& GetFio() const {return m_fio; };
    const uint64_t& GetId() const {return m_id; };
    const std::vector<uint8_t> GetMarks() const {return m_marks; };

private:
    std::string m_fio;
    std::vector<uint8_t> m_marks;
    uint64_t m_id;
};

#endif // __STUDENT_H_
