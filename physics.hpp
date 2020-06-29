#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <math.h>

#include <stdio.h>
#include <stdexcept>

#include "vec3.hpp"

class Physics{
public:
    class CollisionBox{
    public:
        virtual ~CollisionBox() {}
        Vec3<double>* pos = NULL;   // Pointer to the position vector of this collision box in space
        virtual bool collision_with(CollisionBox *box) = 0;
        void add_pos_ptr(Vec3<double> *p) {pos = p;}
        virtual CollisionBox *clone() const = 0;

    };
    class Rectangle: public CollisionBox{
    public:
        double width, height;
        Rectangle(double w, double h) : width(w), height(h) {};
        virtual bool collision_with(CollisionBox *box);
        virtual Rectangle *clone() const {return new Rectangle(*this);};
    };
    class Circle: public CollisionBox{
    public:
        double radius;
        Circle(double r) : radius (r) {};
        virtual bool collision_with(CollisionBox *box);
        virtual Circle *clone() const {return new Circle(*this);};
    };
    class CollisionHandler{
    public:
        static bool collision_between_rectangle_and_rectangle(Physics::Rectangle &rectangle1, Physics::Rectangle &rectangle2);
        static bool collision_between_rectangle_and_circle(Physics::Rectangle &rectangle, Physics::Circle &circle);
        static bool collision_between_circle_and_circle(Physics::Circle &circle1, Physics::Circle &circle2);
    };

    class Mass{
    public:
        double mass = 0;
        Vec3<double> pos = 0;
        Vec3<double> speed = 0;
        Mass(){};
        Mass(double mass, Vec3<double> pos, Vec3<double> speed) : mass(mass), pos(pos), speed(speed) {};
        void apply_force(Vec3<double> force, double time);
        Vec3<double> gravitational_force_with(Physics::Mass &other);
    };
};

#endif