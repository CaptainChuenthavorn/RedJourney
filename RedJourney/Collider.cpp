#include "Collider.h"
Collider::Collider(sf::RectangleShape& body) :
    body(body)
{
}
Collider::~Collider()
{
}
bool Collider::CheckCollision(Collider other, sf::Vector2f& direction, float push)
{
    sf::Vector2f otherPosition = other.GetPosition(); //ตำแหน่งที่มาชน
    sf::Vector2f otherHalfSize = other.GetHalfSize(); //เอาจุดกึ่งกลาง
    sf::Vector2f thisPosition = GetPosition();//ตัวที่เราสนใจอยู่
    sf::Vector2f thisHalfSize = GetHalfSize();//จุดกึ่งกลางตัวที่เราสนใจ

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x); //ระยะห่างแกนx
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if (intersectX > intersectY)//check for slide in way less than 
        {
            if (deltaX > 0.0f)
            {
                Move(intersectX * (1.0 - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);
                direction.x = -1.0f;
                direction.y = 0.0f;
            }
            else
            {
                Move(-intersectX * (1.0 - push), 0.0f);
                other.Move(intersectX * push, 0.0f);
            }
        }
        else {
            if (deltaY > 0.0f)
            {
                Move(0.0f, intersectY * (1.0 - push));
                other.Move(0.0f, -intersectY * push);
                direction.x = 0.0f;
                direction.y = -1.0f;
            }
            else
            {
                Move(0.0f, -intersectY * (1.0 - push));
                other.Move(0.0f, intersectY * push);
            }
        }
        return true;
    }
    return false;
}

bool Collider::CheckCollisionAttack(Collider other)
{
    sf::Vector2f otherPosition = other.GetPosition(); //ตำแหน่งที่มาชน
    sf::Vector2f otherHalfSize = other.GetHalfSize(); //เอาจุดกึ่งกลาง
    sf::Vector2f thisPosition = GetPosition();//ตัวที่เราสนใจอยู่
    sf::Vector2f thisHalfSize = GetHalfSize();//จุดกึ่งกลางตัวที่เราสนใจ

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x); //ระยะห่างแกนx
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        return true;
    }
    return false;
}
