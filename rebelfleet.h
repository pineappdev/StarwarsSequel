#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include <cassert>
#include <type_traits>

using Speed = int;
using ShieldPoints = int;
using AttackPower = int;

// Main class of rebel fleet, all others should inherit it
class RebelStarship {
protected:
    const Speed speed;
    ShieldPoints shield_points;
    virtual void checkSpeed();

public:
    RebelStarship(ShieldPoints shield_points, Speed speed);

    ShieldPoints getShield() const;
    Speed getSpeed() const;

    void takeDamage(AttackPower damage);
    bool isAlive() const;

    virtual ~RebelStarship() = default;
};

class Attacker : public RebelStarship {
    AttackPower attack_power;
public:
    AttackPower getAttackPower() const;
    Attacker(ShieldPoints shield_points, Speed speed, AttackPower attack_power);
    virtual ~Attacker() = default;
};

class Explorer : public RebelStarship {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(299796)&& speed <= static_cast<Speed>(2997960) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    Explorer(ShieldPoints, Speed);
};

Explorer* createExplorer(ShieldPoints shield_points, Speed speed);

class StarCruiser : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(99999)&& speed <= static_cast<Speed>(299795) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};

StarCruiser* createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power);


class XWing : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(299796)&& speed <= static_cast<Speed>(2997960) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    XWing(ShieldPoints, Speed, AttackPower);
};

XWing* createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power);

#endif // _REBELFLEET_H_
