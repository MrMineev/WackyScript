#pragma once

#include <math.h>

const long double E =  2.71828182;
const long double C = 17.7589852008;

const int COMMENT_PAIN = 2;

long double rank_pain(long double pain) {
  long double res = 10 * powl(E, -(((long double)pain - C) * ((long double)pain - C)) / 16200);
  return res / 10;
}

long double painometer(std::string s) {
  long double painometer = 0;
  for (char c : s) {
    if (c == '|') { // creating of a new cell
      painometer += 1;
    } else {
      if (c != '$' && c != '+' && c != '-' && c != '[' && c != ']' && c != '{' && c != '}' && c != '|' && c != '>' && c != '<' && c != '#' && c != ';' && c != '&') {
        painometer += (COMMENT_PAIN / 100.0 * (long double)s.size());
      }
    }
  }
  return rank_pain((long double)painometer / (long double)s.size() * 100.0);
}


