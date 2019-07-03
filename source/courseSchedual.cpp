#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it
possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is
possible. Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take
course 0 you should also have finished course 1. So it is impossible.
*/

struct course {
    int name;
    // count number of in coming edges
    int prerequisite_count;
    // keep a record of all out going edges
    vector<int> upperLevelCourses;

    course(const int& n) : name{n}, prerequisite_count{0} {}
};

bool canFinish(int numCourses,
               vector<pair<int, int>>&
                   prerequisites) {  // first recognize this is a graph problem

    // we build a graph where nodes are course
    // and the edges are their dependencies
    vector<course> course_list{};
    for (int i = 0; i < numCourses;
         ++i) {  // create a fast look up table for all courses
        course_list.push_back(course(i));
    }

    for (int i = 0; i < prerequisites.size(); ++i) {  // connect courses
        pair<int, int> c = prerequisites[i];
        // note that course c.second must be finished
        // before taking course c.first
        course_list[c.first].prerequisite_count++;
        course_list[c.second].upperLevelCourses.push_back(c.first);
    }

    // we can only begin to take those courses have 0 prerequisite_count
    // in other words, we collect nodes that has no incoming edges
    // we call them the "base courses"
    vector<int> base_courses;
    for (int i = 0; i < numCourses; ++i) {
        if (course_list[i].prerequisite_count == 0) {
            base_courses.push_back(course_list[i].name);
        }
    }

    int baseCourse_count = base_courses.size();
    // if there's no base_courses, then,
    // obviously, we can't complete any of them
    if (baseCourse_count == 0) {
        return false;
    }
    // finally, we traverse from the base_courses
    // and create new base_courses by decrementing the prerequisite_count
    // of those have base_courses as their prerequisites
    // until we don't have any more base courses to process
    for (int i = 0; i < base_courses.size(); ++i) {
        for (int j = 0;
             j < course_list[base_courses[i]].upperLevelCourses.size(); ++j) {
            int upper_course =
                course_list[base_courses[i]].upperLevelCourses[j];
            course_list[upper_course].prerequisite_count--;
            if (course_list[upper_course].prerequisite_count ==
                0) {  // new base courses created,
                // we increment the counter for base course
                base_courses.push_back(upper_course);
                baseCourse_count++;
            }
        }
    }

    // the courses can be completed if and only if
    // the prerequisite_count for all courses can be
    // reduced to 0 in this process
    return baseCourse_count == numCourses;
}

int main() {
    int ncourse = 5;
    vector<pair<int, int>> courses{
        {0, 3}, {0, 1}, {1, 2}, {3, 2}, {3, 4},
        //{4, 0} // introduce a cycle that alters the result
    };

    cout << canFinish(ncourse, courses) << '\n';

    return 0;
}
