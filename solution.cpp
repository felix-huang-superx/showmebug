#include <iostream>
#include <string>
/*(1)请在这里书写你的代码[{"id":1733235182736,"flag":"1","action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"_start":"startFlag","customFlag":"asdf_gdsd_012s_32d6"}]*/
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
/*请在这里书写你的代码[{"id":1733235182736,"action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"endFlag":"END_","customFlag":"asdf_gdsd_012s_32d6"}]*/
using namespace std;

/*(2)请在这里书写你的代码[{"id":1733235257097,"flag":"2","action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"_start":"startFlag","customFlag":"asdf_gdsd_012s_32d6"}]*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

// 合并区间函数
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.empty()) {
        return result;
    }
    // 按区间开始位置排序
    sort(intervals.begin(), intervals.end(), compareIntervals);
    result.push_back(intervals[0]);
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= result.back().end) {
            result.back().end = max(result.back().end, intervals[i].end);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

// 辅助函数，将输入字符串解析为区间向量
vector<Interval> parseInput(const string& inputStr) {
    vector<Interval> intervals;
    istringstream iss(inputStr);
    string token;
    while (getline(iss, token, ' ')) {
        int start, end;
        sscanf(token.c_str(), "%d,%d", &start, &end);
        if (start > end) {
            swap(start, end);
        }
        intervals.push_back(Interval(start, end));
    }
    return intervals;
}

// 辅助函数，将区间向量格式化为输出字符串
string formatOutput(const vector<Interval>& intervals) {
    string result;
    for (size_t i = 0; i < intervals.size(); ++i) {
        result += to_string(intervals[i].start) + "," + to_string(intervals[i].end);
        if (i < intervals.size() - 1) {
            result += " ";
        }
    }
    return result;
}
/*请在这里书写你的代码[{"id":1733235257097,"action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"endFlag":"END_","customFlag":"asdf_gdsd_012s_32d6"}]*/
/*
  以下为示例代码，仅供参考。请根据题目要求定义好方法及参数。
  The following is sample code for reference only.
  Please define the methods and parameters according to the requirements of the question.
*/
string solution(const string& input)
{
  /*(3)请在这里书写你的代码[{"id":1733235366774,"flag":"3","action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"_start":"startFlag","customFlag":"asdf_gdsd_012s_32d6"}]*/

    vector<Interval> intervals = parseInput(input);
    vector<Interval> merged = mergeIntervals(intervals);
    string output = formatOutput(merged);
  return output;
/*请在这里书写你的代码[{"id":1733235366774,"action":"implement","text":"实现功能","iconLabel":"答题区","commentStartLabel":"请在这里书写你的代码","hideCodeBlock":true,"endFlag":"END_","customFlag":"asdf_gdsd_012s_32d6"}]*/
}