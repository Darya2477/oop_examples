#include <iostream>

struct Vector2D
{
    int m_x = 0;
    int m_y = 0;

    Vector2D add(Vector2D other)
    {
    return Vector2D{m_x + other.m_x, m_y + other.m_y };
    }
    
    Vector2D operator + (Vector2D other)
    {
        return Vector2D{m_x + other.m_x, m_y + other.m_y };
    }
};

// Vector2D add(Vector2D lhs, Vector2D rhs)
// {
//    return Vector2D{lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y };
// }

int main(int argc, char** argv)
{
    Vector2D vec_1{1,2};
    Vector2D vec_2{3,4};
    //vec_2.add(vec_1);
    //Vector2D result = add(vec_1, vec_2);
    vec_2 = vec_2 + vec_1;
    std::cout << vec_2.m_x << " " << vec_2.m_y << std::endl;
    return 0;
}