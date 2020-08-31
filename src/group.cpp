#include <group.h>
#include <student.h>
#include <stdexcept>

Group::Group(std::string title, std::string spec)
{
    if (title == "") {
        throw std::invalid_argument("Group::Group - title can not be \"\"");
    }
    if (spec == "") {
        throw std::invalid_argument("Group::Group - title can not be \"\"");
    }

    m_title = title;
    m_spec = spec;
}

Group::~Group()
{
    while (m_students.size() != 0) {
        delete m_students[0];
        m_students.erase(m_students.begin());
    }
}

void Group::DeleteAllStudents()
{
    while (m_students.size() != 0) {
        delete m_students[0];
        m_students.erase(m_students.begin());
    }
}

void Group::Create(std::string title, std::string spec)
{
    if (title == "") {
        throw std::invalid_argument("Group::Create - title can not be \"\"");
    }
    if (spec == "") {
        throw std::invalid_argument("Group::Create - title can not be \"\"");
    }
    
    m_title = title;
    m_spec = spec;
}

void Group::AddStudent(std::string fio, uint64_t id)
{
    Student* student = new Student(fio, id);

    for (auto existing_student : m_students) {
        if ( student->GetId() == existing_student->GetId()) {
            throw std::invalid_argument("Group::AddStudent - can not add student with same id");
        }
    }
    m_students.push_back(student);
}

void Group::AddStudent(Student* student)
{
    m_students.push_back(student);
}

void Group::ChooseHead(size_t head_index)
{
    if (head_index >= m_students.size()) {
        throw std::out_of_range("Group::ChooseHead - invalid index");
    }    

    m_head_id = m_students[head_index]->GetId();
}

const size_t Group::Fing(uint64_t id) const
{
    for (size_t i = 0; i <  m_students.size(); i++) {
        if (id == m_students[i]->GetId()) {
            return i;
        }
    }
    return m_students.size() + 1;
}

const size_t Group::Fing(std::string fio) const
{
    for (size_t i = 0; i <  m_students.size(); i++) {
        if (fio == m_students[i]->GetFio()) {
            return i;
        }
    }
    return m_students.size() + 1;
}

const size_t Group::GetHead() const 
{
    if (m_head_id == 0) {
        return m_students.size() + 1;
    }
    return Fing(m_head_id); 
};

const float Group::CalculateAvg() const
{
    if (m_students.size() == 0) {
        return 0;
    }

    float avg = 0;
    for (auto student : m_students)
    {
        avg += student->CalculateAvg();
    }
    return avg / static_cast<float>(m_students.size());
}

void Group::DropStudent(size_t index)
{
    if (index >= m_students.size()) {
        throw std::out_of_range("Group::DropStudent - invalid index");
    } 
    if (m_students[index]->GetId() == m_head_id) {
        m_head_id = 0;
    }
    
    m_students.erase(m_students.begin() + index);
}

void Group::AddMark(size_t index, uint8_t mark)
{
    if (index >= m_students.size()) {
        throw std::out_of_range("Group::AddMark - invalid index");
    } 
    m_students[index]->AddMark(mark);
}
