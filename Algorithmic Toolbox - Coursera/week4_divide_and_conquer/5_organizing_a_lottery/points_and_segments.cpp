#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Point{
int x;
char label;
int index;
};

bool cmp(Point a, Point b)
{
    if(a.x == b.x )
        return a.label < b.label;
    return a.x < b.x;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());

  int n = (int)starts.size()+(int)ends.size()+(int)points.size();

  vector<Point> all_points(n);
  //write your code here
  int k = 0;

  for(int i = 0;i < starts.size(); i++)
  {
      all_points[k].x = starts[i];
      all_points[k].label = 'l';
      k++;
  }

  for(int i = 0;i < ends.size();i++)
  {
      all_points[k].x = ends[i];
      all_points[k].label = 'r';
      k++;
  }

  for(int i = 0; i < points.size(); i++)
  {
      all_points[k].x = points[i];
      all_points[k].label = 'p';
      all_points[k].index = i;
      k++;
  }

  std::sort(all_points.begin(),all_points.end(),cmp);

  int counter = 0;

  for(int i=0; i < n ;i++)
  {
      if(all_points[i].label == 'l')
        counter++;
      else if(all_points[i].label == 'r')
        counter--;

      else
        cnt[all_points[i].index] = counter;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
