#include<stdio.h>
#include<stdlib.h>

typedef enum
{
    engine_off=1,
    idle,
    gear1,
    gear2,
    gear3,
    reverse,
}state;

typedef enum
{
    start=1,
    stop,
    accelerate,
    deccelerate,
    go_back,
    break1,
}event;

state engine_start(state ps)
{
    if(ps==engine_off)
    {
        return idle;
    }
}

state engine_stop(state ps)
{
    if(ps==idle)
    {
        return engine_off;
    }
}

state accelerate_car(state ps)
{
    if(ps==idle)
    {
        return gear1;
    }
    else if(ps==gear1)
    {
        return gear2;
    }
    else if(ps==gear2)
    {
        return gear3;
    }
}

state deccelerate_car(state ps)
{
    if(ps==gear1)
    {
        return idle;
    }
    else if(ps==gear2)
    {
        return gear1;
    }
    else if(ps==gear3)
    {
        return gear2;
    }
}

state reverse_car(state ps)
{
    if(ps==idle)
    {
        return reverse;
    }
}

state break_applied(state ps)
{
    if(ps==gear2)
    {
        return idle;
    }
    else if(ps==gear3)
    {
        return idle;
    }
    else if(ps==reverse)
    {
        return idle;
    }
}

event read_event(int x)
{
    return x;
}

int main()
{
    char *look[40]={"engine_off","idle","gear1","gear2","gear3","reverse"};
    state ns= engine_off;;
    while(1)
    {
        int e;
        printf("Enter event\n");
        printf("1-start\n2-stop\n3-acceleration\n4-deceleration\n5-reverse\n6-break\n7-exit\n");
        scanf("%d",&e);
        if(e==7)
        {
            exit(0);
        }
        event ne=read_event(e);
        switch(ns)
        {
        case engine_off:
            {
                if(ne==start)
                {
                    ns=engine_start(ns);
                }

            }break;
        case idle:
            {
                if(ne==stop)
                {
                    ns=engine_stop(ns);
                }
                else if(ne==accelerate)
                {
                    ns=accelerate_car(ns);
                }
                else if(ne==go_back)
                {
                    ns=reverse_car(ns);
                }
            }break;
        case gear1:
            {
                if(ne==accelerate)
                {
                    ns=accelerate_car(ns);
                }
                else if(ne==deccelerate)
                {
                    ns=deccelerate_car(ns);
                }
            }break;
        case gear2:
            {
                if(ne==accelerate)
                {
                    ns=accelerate_car(ns);
                }
                else if(ne==deccelerate)
                {
                    ns=deccelerate_car(ns);
                }
                else if(ne==break1)
                {
                    ns=break_applied(ns);
                }
            }break;
        case gear3:
            {
                if(ne==deccelerate)
                {
                    ns=deccelerate_car(ns);
                }
                else if(ne==break1)
                {
                    ns=break_applied(ns);
                }
            }break;
        case reverse:
            {
                if(ne==break1)
                {
                    ns=break_applied(ns);
                }
            }break;
        default:
            {
                ns=idle;
            }break;
        }
        printf("Sate of car is: %s\n",look[ns-1]);
    }
}
