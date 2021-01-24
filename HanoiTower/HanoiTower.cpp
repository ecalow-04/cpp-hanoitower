#include <iostream>
#include <sstream>
#include <stack>

class HanoiTower {
public:
    HanoiTower(int blocks)
    {
        numBlocks = blocks;
        for (int i = numBlocks; i > 0; i--)
        {
            tower1.push(i);
        };
        std::cout << "Generated Game with 3 towers and " << numBlocks << " blocks starting on tower 1" << std::endl;
    };

    bool IsMoveValid(std::stack<int>* t1, std::stack<int>* t2)
    {
        if (t1 == t2 || t1->size() == 0)
        {
            return false;
        };
        if (t2->size() != 0)
        {
            if (t1->top() > t2->top())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    };

    bool Move(int towerFrom, int towerTo)
    {
        std::stack<int>* t1;
        std::stack<int>* t2;
        switch (towerFrom)
        {
        case 1:
            t1 = &tower1;
            break;
        case 2:
            t1 = &tower2;
            break;
        case 3:
            t1 = &tower3;
            break;
        default:
            t1 = &tower1;
        };
        switch (towerTo)
        {
        case 1:
            t2 = &tower1;
            break;
        case 2:
            t2 = &tower2;
            break;
        case 3:
            t2 = &tower3;
            break;
        default:
            t2 = &tower1;
        };
        if (IsMoveValid(t1, t2))
        {
            t2->push(t1->top());
            t1->pop();
            return true;
        }
        else
        {
            return false;
        }
    };

    bool IsComplete()
    {
        if (tower3.size() == numBlocks)
        {
            return true;
        }
        else
        {
            return false;
        };
    };
private:
    int numBlocks;
    std::stack<int> tower1;
    std::stack<int> tower2;
    std::stack<int> tower3;
};

int main()
{
    unsigned int numBlocks = 0;
    while (numBlocks < 3 || numBlocks > 8)
    {
        std::cout << "How many blocks do you want? (3-8)" << std::endl;
        std::cin >> numBlocks;
    }
    HanoiTower hanoiTower(numBlocks);
    unsigned int moveFrom;
    unsigned int moveTo;
    while (!hanoiTower.IsComplete())
    {
        std::cout << "What tower would you like to move from?" << std::endl;
        std::cin >> moveFrom;
        std::cout << "What tower would you like to move to?" << std::endl;
        std::cin >> moveTo;
        if (hanoiTower.Move(moveFrom, moveTo))
        {
            std::cout << "Successfully moved a block from stack " << moveFrom << " to stack " << moveTo << std::endl;
        }
        else
        {
            std::cout << "An error occured when trying to move a block from stack " << moveFrom << " to stack " << moveTo << " (block is probably bigger than where you are trying to move to)" << std::endl;
        }
    }
    std::cout << "You completed the hanoi tower challenge!";
    return 0;
}
