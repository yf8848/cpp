#include <iostream>
#include <tuple>

auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>

    if(0==id){
        return std::make_tuple(3.8,'A',"张三");
    }else if(1==id){
        return std::make_tuple(2.9,'B',"李四");
    }else if(2==id){
        return std::make_tuple(1.8,'C',"王五");
    }else{
        return std::make_tuple(0.0,'D',"NULL");
    }
}

int
main(void)
{
    auto student = get_student(0);
    std::cout << "ID: 0 ,"
    << "GPA: "<<std::get<0>(student)<<", "
    << "成绩: "<<std::get<1>(student)<<", "
    << "姓名: "<<std::get<2>(student)<<"\n ";

    double gpa;
    char grade;
    std::string name;

    // 元组拆包
    std::tie(gpa, grade,name)=get_student(1);
    std::cout <<"ID: 1 ,"
    << "GPA: "<<gpa<<", "
    << "成绩: "<<grade<<", "
    << "姓名: "<<name<<"\n ";

    return 0;
}