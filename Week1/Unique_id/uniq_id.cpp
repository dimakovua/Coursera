#include <string>
#include <vector>
using namespace std;
#define GET(line) a##_##line
#define NAME(line) GET(line)
#define UNIQ_ID NAME(__LINE__)
int main() {
  int UNIQ_ID = 0;
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}