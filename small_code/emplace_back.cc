#include <vector>
#include <string>
#include <iostream>
 
struct President
{
    std::string name;
    std::string country;
    int year;
 
    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }

    President(const President& other)
        : name(other.name), country(other.country), year(other.year)
    {
        std::cout << "I am being copyed.\n";
    }

    //President& operator=(const President& other) = default;
};
 
int main()
{
    std::vector<President> elections;
    std::cout << "emplace_back:\n";
//    elections.push_back("Nelson Mandela", "South Africa", 1994);      //编译错误，push_back没法直接构造
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);     
 
    std::vector<President> reElections;
    std::cout << "\npush_back:\n";
    //reElections.emplace_back(President("Franklin Delano Roosevelt", "the USA", 1936));
    President p("Franklin Delano Roosevelt", "the USA", 1936);
    
    reElections.push_back(p);

    elections.emplace_back(std::move(p));

 
    std::cout << "\nContents:\n";
    for (President const& president: elections) {
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
}