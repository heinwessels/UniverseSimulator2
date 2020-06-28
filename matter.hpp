#ifndef MATTER_HPP
#define MATTER_HPP

#include "vec3.hpp"
#include "renderer.hpp"
#include "physics.hpp"

class Matter{
public:

    Vec3<float> pos;
    Vec3<float> speed;
    float weight;
    Physics::CollisionBox *collision_box;
    Renderer::Graphic *graphic;

    bool ignore_forces = false;

    Matter(){};
    ~Matter(){};

    Matter(Vec3<float> p, Vec3<float> sp, float w) : pos(p), speed(sp), weight(w){};
    void add_graphic(Renderer::Graphic *graphic){this->graphic = graphic;};

    // void step(Universe &universe);
};

#endif