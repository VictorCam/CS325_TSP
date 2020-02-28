#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "count: " << argc << endl;

  for (int i = 0; i < argc; i++) {
    cout << "commands: " << argv[i] << endl;
  }
  return 0;
}
