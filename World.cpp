#include "World.h"
#include "Painter.h"
#include <fstream>
#include <cmath>

static constexpr double timePerTick = 0.001;

std::istream& operator>>(std::istream& stream, Point& point) {
    stream >> point.x >> point.y;
    return stream;
}

std::istream& operator>>(std::istream& stream, Color& color) {
    double r, g, b;
    stream >> r >> g >> b;
    color = Color(r, g, b);
    return stream;
}

World::World(const std::string& worldFilePath) {
    std::ifstream stream(worldFilePath);
    
    stream >> topLeft >> bottomRight;
    physics.setWorldBox(topLeft, bottomRight);

    Point center;
    Point velocityVector;
    Color color;
    double radius;
    bool isCollidable;

    while (stream.peek(), stream.good()) {
        stream >> center >> velocityVector;
        stream >> color;
        stream >> radius;
        stream >> std::boolalpha >> isCollidable;

        Ball ball(center, Velocity(velocityVector), color, radius, isCollidable);
        balls.push_back(ball);
    }
}

void World::show(Painter& painter) const {
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    for (const Ball& ball : balls) {
        ball.draw(painter);
    }
}

void World::update(double time) {
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    physics.update(balls, ticks);
}