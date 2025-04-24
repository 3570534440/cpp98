#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> names;
    //vector就像是一个模板，可以创造多种类型的向量，
    //对所容纳的元素进行限定
    names.push_back("adsf");
    //我们可以用push往它里面添加东西
    names.push_back("asfd");
    // for (int i = 0; i < names.size(); i++)
    // {
    //     std::cout << names[i] << "\n";
    // }
    std::vector<std::string>::iterator iter = names.begin();
    //begin是指向起始位置
    //begin就是对申请的iter这个迭代器进行初始化，调用这个方法
    while (iter != names.end())
    {
        std::cout << *iter << "\n"; //这个迭代器是一个指针，用*取它的值
        ++iter;                     //指向下一个元素
    }                               //end是最后一个元素的下一个，也就是底部
    return 0;
}