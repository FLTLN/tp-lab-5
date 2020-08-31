#include <dean.h>

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

Dean::~Dean() 
{
    for (auto group : m_groups) {
        group->DeleteAllStudents();
        delete group;
    }
};

void Dean::CreateGroups(std::string fname)
{
    std::string line;
    std::ifstream myfile (fname);
    if (myfile.is_open()) {
        while ( std::getline (myfile, line) ) {   
            Group* group = new Group;
            
            line = line.substr(0, line.size() - 1);
            std::stringstream check1(line); 
            std::string intermediate;
            std::vector <std::string> tokens;  
            while(std::getline(check1, intermediate, ';')) { 
                tokens.push_back(intermediate); 
            }

            try {
                group->Create(tokens[0], tokens[1]);
            }
            catch(const std::exception& e) {
                std::invalid_argument("Dean::CreateGroups - invalid file format");
            }
            
            m_groups.push_back(group);
        }
        myfile.close();
    }
    else throw std::invalid_argument("Dean::CreateGroups - unable to open file");
}

void Dean::CreateStudents(std::string fname)
{
    std::string line;
    std::ifstream myfile (fname);
    if (myfile.is_open()) {
        while ( std::getline (myfile,line) ) {   
            
            line = line.substr(0, line.size() - 1);
            std::stringstream check1(line); 
            std::string intermediate;
            std::vector <std::string> tokens;  
            while(std::getline(check1, intermediate, ';')) { 
                tokens.push_back(intermediate); 
            }

            size_t group_index = m_groups.size();
            
            try {
                for (size_t i = 0; i < m_groups.size(); i++) {
                    if (m_groups[i]->GetTitle() == tokens[2]) {
                        group_index = i;
                    }
                }
            }
            catch(const std::exception& e) {
                throw std::invalid_argument("Dean::CreateStudents - invalid file format");
            }

            if (group_index == m_groups.size()) {
                throw std::invalid_argument("Dean::CreateStudents - no matching grop found");
            }
            
            m_groups[group_index]->AddStudent(tokens[0], std::stoi(tokens[1]));  
        }
        myfile.close();
    }
    else throw std::invalid_argument("Dean::CreateStudents - unable to open file");
}

void Dean::SaveGroups(std::string fname)
{
    std::string line;
    std::ofstream myfile (fname);
    if (myfile.is_open()) {
        for (auto group : m_groups) {
            line = group->GetTitle() + ";" + group->GetSpec() + "\n";
            myfile << line;
        }
        myfile.close();
    } else throw std::invalid_argument("Dean::SaveGroups - unable to open file");
}

void Dean::SaveStudents(std::string fname)
{
    std::string line;
    std::ofstream myfile (fname);
    if (myfile.is_open()) {
        for (auto group : m_groups) {
            for (size_t i = 0; i < m_groups.size(); i++) {
                line = (*group)[i].GetFio() + ";" + std::to_string((*group)[i].GetId()) + ";" + group->GetTitle() + "\n";
                myfile << line;
            }
        }
        myfile.close();
    } else throw std::invalid_argument("Dean::SaveGroups - unable to open file");   
}

void Dean::AddRandomMarks(size_t num)
{
    for (auto group : m_groups) {
        for (size_t i = 0; i < group->CountStudents(); i++) {
            for (size_t j = 0; j < num; j++) {
                (*group)[i].AddMark(rand() % 11);
            }
        }
    }
}

void Dean::Transfer(size_t from, size_t student_index, size_t to)
{
    m_groups[to]->AddStudent(&(*m_groups[from])[student_index]);
    m_groups[from]->DropStudent(student_index);
}

void Dean::DropLowMarksStudents(float cutoff)
{
   for (auto group : m_groups) {
        std::vector<uint64_t> ids;
        for (size_t i = 0; i < group->CountStudents(); i++) {
            if ((*group)[i].CalculateAvg() < cutoff) {
                ids.push_back((*group)[i].GetId());
            }
        }
        for (auto id : ids) {
            group->DropStudent(group->Fing(id));
        } 
    } 
}

void Dean::ChooseHeads()
{
    for (auto group : m_groups) {
        group->ChooseHead(rand() % group->CountStudents());
    }
}

void Dean::PrintSummary()
{
    std::cout << std::endl;
    std::cout << "Summary" << std::endl;
    std::cout << std::endl;
    for (auto group : m_groups) {
        std::cout << "Group title  : " << group->GetTitle() << std::endl;
        std::cout << "spec         : " << group->GetSpec() << std::endl;
        std::cout << "students num : " << group->CountStudents() << std::endl;
        std::cout << "avg mark     : " << group->CalculateAvg() << std::endl;
        auto head_id = group->GetHead();
        if (head_id < group->CountStudents())
        {
            std::cout << "group head   : " << std::endl;
            std::cout << "    Student name : " << (*group)[head_id].GetFio() << std::endl;
            std::cout << "    id           : " << (*group)[head_id].GetId() << std::endl;
            std::cout << "    avg mark     : " << (*group)[head_id].CalculateAvg() << std::endl;
        } else {
            std::cout << "group head   : none" << std::endl;
        }
        
        
        std::cout << std::endl;
        std::cout << "student list : " << std::endl;
        std::cout << std::endl;

        for (size_t i = 0; i < group->CountStudents(); i++)
        {
            std::cout << "    Student name : " << (*group)[i].GetFio() << std::endl;
            std::cout << "    id           : " << (*group)[i].GetId() << std::endl;
            std::cout << "    avg mark     : " << (*group)[i].CalculateAvg() << std::endl;
            std::cout << std::endl;
        }
    }
}
