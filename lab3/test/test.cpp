#include <gtest/gtest.h>
#include "../include/triangle.hpp"
#include "../include/square.hpp"
#include "../include/rectangle.hpp"
#include "../include/array.hpp"
#include "../include/point.hpp"

// ---------- TESTS FOR POINT ----------
TEST(PointTest, ConstructorsAndOperators) {
    Point p1(1, 2);
    EXPECT_DOUBLE_EQ(p1.get_x(), 1);
    EXPECT_DOUBLE_EQ(p1.get_y(), 2);

    Point p2(p1);
    EXPECT_DOUBLE_EQ(p2.get_x(), 1);
    EXPECT_DOUBLE_EQ(p2.get_y(), 2);

    Point p3 = p1 + Point(2, 3);
    EXPECT_DOUBLE_EQ(p3.get_x(), 3);
    EXPECT_DOUBLE_EQ(p3.get_y(), 5);

    Point p4 = p3 - Point(1, 1);
    EXPECT_DOUBLE_EQ(p4.get_x(), 2);
    EXPECT_DOUBLE_EQ(p4.get_y(), 4);
}

// ---------- TRIANGLE ----------
TEST(TriangleTest, CorrectTriangle) {
    Triangle t;
    std::stringstream ss;
    ss << "0 0  4 0  0 3";
    ss >> t;

    EXPECT_TRUE(t.isCorrect());
    EXPECT_NEAR((double)t, 6.0, 1e-7);   // площадь 6
    Point c = t.getCenter();
    EXPECT_NEAR(c.get_x(), 4.0/3, 1e-7);
    EXPECT_NEAR(c.get_y(), 1.0, 1e-7);
}

// ---------- SQUARE ----------
TEST(SquareTest, CorrectSquare) {
    Square s;
    std::stringstream ss;
    ss << "0 0  2 0  2 2  0 2";
    ss >> s;

    EXPECT_TRUE(s.isCorrect());
    EXPECT_DOUBLE_EQ((double)s, 4.0);  // площадь 2×2
    Point c = s.getCenter();
    EXPECT_DOUBLE_EQ(c.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(c.get_y(), 1.0);
}

// ---------- RECTANGLE ----------
TEST(RectangleTest, CorrectRectangle) {
    Rectangle r;
    std::stringstream ss;
    ss << "0 0  3 0  3 2  0 2";
    ss >> r;

    EXPECT_TRUE(r.isCorrect());
    EXPECT_DOUBLE_EQ((double)r, 6.0);
    Point c = r.getCenter();
    EXPECT_DOUBLE_EQ(c.get_x(), 1.5);
    EXPECT_DOUBLE_EQ(c.get_y(), 1.0);
}

// ---------- ARRAY ----------
TEST(ArrayTest, AddAndRemove) {
    Array arr;

    Square* s = new Square(Point(0,0), Point(2,0), Point(2,2), Point(0,2));
    Triangle* t = new Triangle();

    std::stringstream ss;
    ss << "0 0  4 0  0 3";
    ss >> *t;

    arr.push_back(s);
    arr.push_back(t);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_NEAR(arr.totalArea(), 4.0 + 6.0, 1e-7);

    arr.remove(0);
    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_NEAR(arr.totalArea(), 6.0, 1e-7);

    arr.clear();
    EXPECT_TRUE(arr.empty());
}
