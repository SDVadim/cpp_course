#include <cmath>
#include <iostream>
#include <vector>

struct Point {
double x;
double y;
};

struct Rectangle {
Point left_top;
Point right_bottom;
};

double findSquare(Rectangle rectangle) {
  Point l = rectangle.left_top;
  Point r = rectangle.right_bottom;
  double width = std::abs(l.x - r.x);
  double height = std::abs(l.y - r.y);
  return width * height;
}

Rectangle getCross(Rectangle r1, Rectangle r2) {
  if (r2.left_top.x < r1.left_top.x) {
    std::swap(r1, r2);
  }
  if (r2.left_top.x > r1.right_bottom.x || r2.right_bottom.y > r1.left_top.y || r2.left_top.y < r1.right_bottom.y) {
    return Rectangle{Point{0, 0}, Point{0, 0}};
  }
  Point l_t;
  if (r2.left_top.y > r1.left_top.y) {
    l_t = Point{r2.left_top.x, r1.left_top.y};
  }
  else {
    l_t = Point{r2.left_top.x, r2.left_top.y};
  }

  Point r_b;
  if (r2.right_bottom.x > r1.right_bottom.x && r2.right_bottom.y > r1.right_bottom.y) {
    r_b = r2.right_bottom;
  } else if (r2.right_bottom.x < r1.right_bottom.x && r2.right_bottom.y > r1.right_bottom.y) {
    r_b = Point{r1.right_bottom.x, r2.right_bottom.y};
  } else if (r2.right_bottom.x < r1.right_bottom.x && r2.right_bottom.y < r1.right_bottom.y) {
    r_b = r1.right_bottom;
  } else {
    r_b = Point{r2.right_bottom.x, r1.right_bottom.y};
  }
  return Rectangle{l_t, r_b};
}

double getSquare(std::vector<Rectangle>& rectangles) {
  Rectangle r1 = rectangles[0];
  Rectangle r2 = rectangles[1];
  Rectangle curr = getCross(r1, r2);
  for (std::size_t i = 2; i < rectangles.size(); ++i) {
    r2 = rectangles[i];
    curr = getCross(curr, r2);
  }
  std::cout << findSquare(curr);
  return findSquare(curr);
}

int main() {
  Rectangle r1 = Rectangle{Point{1, 10}, Point{10, 0}};
  Rectangle r2 = Rectangle{Point{0, 1}, Point{5, 9}};
  Rectangle r3 = Rectangle{Point{2, 6}, Point{5, 12}};
  std::vector<Rectangle> v;
  v.push_back(r1);
  v.push_back(r2);
  v.push_back(r3);
  std::cout << findSquare(r1) << '\n';
  getSquare(v);
}