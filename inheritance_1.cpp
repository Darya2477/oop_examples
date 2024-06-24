#include <iostream>

//в структуре все методы и поля публичные и модификатор при наследовании - public по умолчанию
//в классе все методы и поля приватные и модификатор при наследовании - private по умолчанию 

// при public наследовании модификаторы не меняются 
// при protected наследовании public поля или методы станут protected
// при private наследовании public и protected поля или методы станут private

class GamePerson{
    void move(int x, int y)
    {
        x_position +=x;
        y_position +=y;
    }

    int get_health() const{
        return health;
    }
protected:
    int x_position = 0;
    int y_position = 0;
    int health = 100;
};

class Player: public GamePerson
{
    public:
        void save(Player& player)
        {
            if (player.health < 100)
                player.health +=10;
        }
};

class Enemy: public GamePerson
{
    public:
    void set_fire(Player& player)
    {
        //
    }
};

int main()
{
    Player p;
    Enemy e;

}