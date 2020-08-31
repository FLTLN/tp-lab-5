#include <student.h>
#include <stdexcept>

Student::Student(std::string fio, uint64_t id)
{
    if (id == 0) {
        throw std::invalid_argument("Student::Student - id can not be 0");
    }
    if (fio == "") {
        throw std::invalid_argument("Student::Student - fio can not be \"\"");
    }

    m_fio = fio;
    m_id = id;   
};

void Student::Create(std::string fio, uint64_t id)
{
    if (id == 0) {
        throw std::invalid_argument("Student::Create - id can not be 0");
    }
    if (fio == "") {
        throw std::invalid_argument("Student::Create - fio can not be \"\"");
    }

    m_fio = fio;
    m_id = id;
}

void Student::AddMark(uint8_t mark)
{
    if (mark > 10) {
        throw std::out_of_range("Student::AddMark - mark shoul be less than 10");
    }
    
    m_marks.push_back(mark);
}

const float Student::CalculateAvg() const
{
    if (m_marks.size() == 0) {
        return 0;
    }

    float avg = 0;
    for (auto mark : m_marks) {
        avg += static_cast<float>(mark);
    }

    avg = avg / static_cast<float>(m_marks.size());
    return avg;
}
