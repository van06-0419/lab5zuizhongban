#pragma once
#include "Point.h"
#include "Velocity.h"
#include "Color.h"
#include "Painter.h"

class Dust {
public:
    Dust(const Point& position, const Velocity& velocity, 
         const Color& color, double lifetime);
    
    void update(double dt);
    void draw(Painter& painter) const;
    bool isAlive() const;

private:
    Point position;
    Velocity velocity;
    Color color;
    double lifetime;
    double age;
    static constexpr double radius = 2.0;
};