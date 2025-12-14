#include "Dust.h"

Dust::Dust(const Point& position, const Velocity& velocity,
           const Color& color, double lifetime)
    : position(position), velocity(velocity), color(color),
      lifetime(lifetime), age(0.0) {}

void Dust::update(double dt) {
    position = position + velocity.vector() * dt;
    age += dt;
}

void Dust::draw(Painter& painter) const {
    if (isAlive()) {
        double alpha = 1.0 - (age / lifetime);
        Color fadedColor(
            color.red() * alpha,
            color.green() * alpha,
            color.blue() * alpha
        );
        painter.draw(position, radius, fadedColor);
    }
}

bool Dust::isAlive() const {
    return age < lifetime;
}