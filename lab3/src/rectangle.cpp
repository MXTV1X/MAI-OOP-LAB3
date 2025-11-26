#include "../include/rectangle.hpp"
#include <cmath>

static double vec_len2(const Point& a) {
    return a.get_x()*a.get_x() + a.get_y()*a.get_y();
}

static Point vec(const Point& a, const Point& b) {
    return Point(b.get_x() - a.get_x(), b.get_y() - a.get_y());
}

Rectangle::Rectangle() : Figure(4) {}

Point Rectangle::getCenter() const {
    Point sum(0,0);
    for (size_t i = 0; i < size; ++i) sum += points[i];
    return Point(sum.get_x() / size, sum.get_y() / size);
}

bool Rectangle::isCorrect() const {
    // предполагаем, что точки заданы по периметру: A B C D (по порядку)
    // проверим, что AB ⟂ BC и AB параллельно CD и BC параллельно AD; и стороны положительной длины
    const double EPS = 1e-6;
    Point A = points[0], B = points[1], C = points[2], D = points[3];
    Point AB = vec(A,B), BC = vec(B,C), CD = vec(C,D), DA = vec(D,A);

    // прямой угол AB·BC == 0
    double dot1 = AB.get_x()*BC.get_x() + AB.get_y()*BC.get_y();
    if (std::fabs(dot1) > EPS) return false;

    // проверки на равенство противоположных сторон по длине
    if (std::fabs(vec_len2(AB) - vec_len2(CD)) > EPS) return false;
    if (std::fabs(vec_len2(BC) - vec_len2(DA)) > EPS) return false;

    // также проверить, что не вырождено (площ>eps)
    double area = static_cast<double>(*this);
    if (area < EPS) return false;

    return true;
}

Rectangle::operator double() const {
    // площадь = |AB| * |BC| для правильного прямоугольника (используем длины)
    Point A = points[0], B = points[1], C = points[2];
    Point AB = vec(A,B), BC = vec(B,C);
    double lenAB = std::sqrt(vec_len2(AB));
    double lenBC = std::sqrt(vec_len2(BC));
    return lenAB * lenBC;
}
