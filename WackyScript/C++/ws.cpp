#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "painometer/painometer.h"

std::random_device rd;
std::mt19937 gen(rd());

std::string s;
std::vector<int> cells(1, 0);
int p = 0;
long double chance_one = 0.0;

int generate() {
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  double randomNumber = dis(gen);
  int result = (randomNumber < chance_one) ? 1 : 0;
  return result;
}

void show() {
  std::cout << "P: " << p << " Cells: ";
  for (int i = 0; i < cells.size(); i++) {
    std::cout << cells[i] << " ";
  }
  std::cout << std::endl;
}

int process(int loc) {
  int t = loc;
  while (t < s.size()) {
    int working = generate();
    if (!working) { t++; continue; }
    if (p < 0) {
      printf("\n\n[ERROR]: Pointer moved to a negative cell.\n");
      show();
      exit(1);
    } else if (p > cells.size()) {
      printf("\n\n[ERROR]: Pointer moved too far.\n");
      show();
      exit(1);
    }
    char c = s[t];
    if (c == '|') cells.insert(cells.begin() + p + 1, cells[p]);
    if (c == '&') cells[p] = 1;
    if (c == '>') p++;
    if (c == '<') p--;
    if (c == '#') {
      char cc;
      std::cin >> cc;
      cells[p] = int(cc);
    }
    if (c == '$') {
      if (s[t + 1] == '+') cells[p - 1] += cells[p];
      if (s[t + 1] == '-') cells[p - 1] -= cells[p];
      cells.erase(cells.begin() + p);
      p--;
    }
    if (c == ';') std::printf("%c", char(cells[p]));
    if (c == '{') t = process(t + 1);
    if (c == '}' && cells.size() != 1) return process(loc);
    if (c == '[') t = process(t + 1);
    if (c == ']' && cells[p] != 0) return process(loc);
    t++;
  }
  return s.size();
}

int main(int a, char* b[]) {
  std::string fileName = b[1];
  std::ifstream file(fileName);

  if (file.is_open()) {
      s = std::string((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
      chance_one = painometer(s);
      std::cout << "[PAINOMETER]: " << chance_one << std::endl;

      process(0);
      if (cells.size() != 1) {
        printf("\n\n[ERROR]: Exiting with multiple active cells\n");
        show();
        exit(1);
      } else if (cells[0] != 0) {
        printf("\n\n[ERROR]: Cell one is still active\n");
        show();
        exit(1);
      }
      file.close();
  } else printf("Failed to open the file.");
  return 0;
}


