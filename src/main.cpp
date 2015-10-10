#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string rot(const string& input, size_t count)
{
  return input.substr(count, input.length() - count) + input.substr(0, count);
}

vector<string> rotations(const string& input)
{
  vector<string> rs;

  for (size_t i = 0; i < input.length(); ++i)
  {
    rs.push_back(rot(input, i));
  }

  return rs;
}

vector<string> sorted_rotations(vector<string>& rotations)
{
  sort(rotations.begin(), rotations.end());

  return rotations;
}

string last_column(const vector<string> rotations)
{
  string last;

  for_each(rotations.begin(), rotations.end(), [&](const string& str){ last += str.back(); });

  return last;
}

pair<string, size_t> encode(string input)
{
  vector<string> rs = rotations(input);
  vector<string> sorted = sorted_rotations(rs);
  string last = last_column(sorted);
  size_t index = distance(sorted.begin(), find(sorted.begin(), sorted.end(), input));

  return make_pair(last, index);
}

string decode(pair<string, size_t> encoded)
{
  vector<string> rs(encoded.first.size());

  for (size_t i = 0; i < encoded.first.size(); ++i)
  {
    for (size_t j = 0; j < encoded.first.size(); ++j)
    {
      rs[j].insert(0, 1, encoded.first[j]);
    }

    sort(rs.begin(), rs.end());
  }

  return rs[encoded.second];
}

int main()
{
  string input = "banana";
  pair<string, size_t> encoded = encode(input);
  cout << "Encoded: " << encoded.first << ", index: " << encoded.second << endl;
  cout << "Decoded: " << decode(encoded) << endl;

  return 0;
}

