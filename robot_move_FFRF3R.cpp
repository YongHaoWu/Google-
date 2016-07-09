/* 设计一个机器人，实现前进，向右转以及输出当前位置的功能（面经题，之前是乌龟来着），一开始在原点坐标，不能去负的坐标，去的话报错。 */
/* follow1：输入指令，如 FFRRF3R，F就是前进，R就是向右转，2R就是RRR。输出这个指令之后所处的位置。 */
/* follow2：在指令里面会出现2（FFR）这种情况，就是FFRFFR。 */

#include <iostream>
using namespace std;
struct position{
    int x;
    int y;
    int direction;
    position(): x(0),y(0),direction(0){};
};

void print_position(position &robot_position)
{
    cout<<"("<<robot_position.x<<", "<<robot_position.y<<") "<<robot_position.direction<<endl;
}

void move(position &robot_position, bool move_forward)
{
    if(move_forward) {
        switch(robot_position.direction) {
            case 0: robot_position.y++; break;
            case 1: robot_position.x++; break;
            case 2:
                    if(robot_position.y == 0)
                        cerr<<"error <0 "<<endl;
                    else
                        robot_position.y--;
                    break;
            case 3:
                    if(robot_position.x == 0)
                        cerr<<"error <0 "<<endl;
                    else
                        robot_position.x--;
                    break;
            default: break;
        }
    }else {
        robot_position.direction++;
        if(robot_position.direction == 4)
            robot_position.direction = 0;
    }
}

void go(position &robot_position, bool has_nested, int &num, bool is_forward, int &cnt)
{
    int tmp = has_nested?1:num;
    while(tmp--) {
        if(!is_forward)
            cout<<"turn right"<<endl;
        move(robot_position, is_forward);
        print_position(robot_position);
    }
    if(has_nested)
        ++cnt;
    else
        num = 1;
}

int main()
{
    string str;
    cin>>str;
    position robot_position;
    int num = 1, cnt = 0;
    bool has_nested = false;
    for(int i=0; str[i]; ++i) {
        switch(str[i]) {
            case '(':
                has_nested = true;
                cnt = 0;
                break;
            case ')':
                if(num != 1) {
                    num--;
                    i = i-cnt-1;
                }else {
                    has_nested = false;
                }
                break;
            case 'F':
                go(robot_position, has_nested, num, 1, cnt);
                break;
            case 'R':
                go(robot_position, has_nested, num, 0, cnt);
                break;
            default:
                num = str[i] - '0';
                break;
        }
    }
    return 0;
}
