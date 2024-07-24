#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
namespace monitor
{
    class ReadFile
    {
    public:
        explicit ReadFile(const std::string &name):_ifs(name){} //禁止隐式类型转换
        ~ReadFile(){_ifs.close();}                              //关闭文件读写
        bool ReadLine(std::vector<std::string>* args);          //按行读
        static std::vector<std::string> GetStatsLines(const std::string& stat_file,const int line_count)
        {
            std::vector<std::string> stat_line;
            std::ifstream buf(stat_file);
            for(int line_num = 0 ; line_num<line_count;++line_num)
            {
                std::string line;
                std::getline(buf,line);
                if(line.empty())
                {
                    break;
                }
                stat_line.push_back(line);
            }
            return stat_line;
        }
    private:
    std::ifstream _ifs;
    };
}