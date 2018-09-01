#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool cmp_asc(Segment &a,Segment &b)
{
    return a.end< b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int n = segments.size();
  std::sort(segments.begin(),segments.end(),cmp_asc);

  int p = segments[0].end;
  points.push_back(p);

  for(int i=1;i<n;i++){

    if(p<segments[i].start||p>segments[i].end)
    {
        p=segments[i].end;
        points.push_back(p);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
