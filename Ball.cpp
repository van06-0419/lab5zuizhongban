#include "Ball.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ball::Ball(const Point& center, const Velocity& velocity, const Color& color,
           double radius, bool isCollidable)
    : center(center), velocity(velocity), color(color), 
      radius(radius), isCollidable(isCollidable) {}

void Ball::setVelocity(const Velocity& vel) {
    this->velocity = vel;
}

Velocity Ball::getVelocity() const {
    return velocity;
}

void Ball::draw(Painter& painter) const {
    painter.draw(center, radius, color);
}

void Ball::setCenter(const Point& c) {
    this->center = c;
}

Point Ball::getCenter() const {
    return center;
}

double Ball::getRadius() const {
    return radius;
}

double Ball::getMass() const {
    return M_PI * radius * radius * radius * 4.0 / 3.0;
}

bool Ball::getIsCollidable() const {
    return isCollidable;
}