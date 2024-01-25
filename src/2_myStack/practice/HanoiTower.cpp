#include <iostream>
#include "ArrayStack.hpp"
#include "timer.hpp"

/*
问题描述：
有A、B、C三根柱子，其中A柱子上面有从小叠到大的n个圆盘，现要求将A柱子上的圆盘移到C柱子上去，期间只有一个原则：一次只能移一个盘子且大盘子不能在小盘子上面，求移动的步骤和移动的次数
*/

/**
 * @brief 枚举两种操作：
 *      DOMOVE 移动
 *      DOTOH  进入递归
 */
enum DoWhat
{
    DOMOVE,
    DOTOH
};

class ToDo
{
public:
    DoWhat op;             // 记录执行的操作类型
    int disks;             // 盘子数目
    char start, tmp, goal; // 记录三个盘子

    ToDo(int disks, char A, char B, char C)
    {
        op = DOTOH;
        this->disks = disks;
        start = A;
        tmp = B;
        goal = C;
    }
    ToDo(int disks, char A, char B)
    {
        op = DOMOVE;
        this->disks = disks;
        start = A;
        goal = B;
    }
};
/**
 * @brief  汉诺塔类，包含递归和栈链中实现方式
 *
 */
class HanoiTower
{
private:
    static int count; // 记录次数
    static void move(int disks, char N, char M)
    {
        std::cout << "第" << ++count << "次移动 : ";
        std::cout << "把" << disks << "号盘从" << N << "移动到" << M << std::endl;
    }

public:
    /**
     * @brief 使用递归实现
     *
     * @param n
     * @param A
     * @param B
     * @param C
     */
    static void Hanoi(int n, char A, char B, char C)
    {
        if (n == 1)
        {
            move(1, A, C); // 如果只有一个盘子,直接 A ——> C
        }
        else
        {
            Hanoi(n - 1, A, C, B);
            move(n, A, C);
            Hanoi(n - 1, B, A, C);
        }
    }

    /**
     * @brief 顺序栈实现  栈的大小为 2 * n + 1
     *
     * @param n
     * @param A
     * @param B
     * @param C
     */
    static void Hanoi_Stack(int n, char A, char B, char C)
    {
        ArrayStack<ToDo *> AStack(2 * n + 1);
        AStack.push(new ToDo(n, A, B, C)); // 初始化
        ToDo *ToDo_tmp = nullptr;
        while (AStack.length() > 0)
        {
            ToDo_tmp = AStack.pop();
            if (ToDo_tmp->op == DOMOVE)
            {
                move(ToDo_tmp->disks, ToDo_tmp->start, ToDo_tmp->goal);
            }
            else if (ToDo_tmp->disks > 0)
            {
                int n = ToDo_tmp->disks;
                char A = ToDo_tmp->start;
                char B = ToDo_tmp->tmp;
                char C = ToDo_tmp->goal;
                AStack.push(new ToDo(n - 1, A, C, B));
                AStack.push(new ToDo(n, A, C));
                AStack.push(new ToDo(n - 1, B, A, C));
            }
            delete ToDo_tmp;
        }
    }

    static void reset()
    {
        count = 0;
    }
};

int HanoiTower::count = 0; // 初始化次数为0

int main()
{
    int n = 4;
    std::cout << "递归 :" << std::endl;
    MyTimer::start();
    HanoiTower::Hanoi(n, 'A', 'B', 'C');
    MyTimer::end();
    HanoiTower::reset();

    std::cout << "顺序栈 :" << std::endl;
    MyTimer::start();
    HanoiTower::Hanoi_Stack(n, 'A', 'B', 'C');
    MyTimer::end();
    HanoiTower::reset();

    return 0;
}